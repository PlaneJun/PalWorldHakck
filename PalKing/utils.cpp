#include "utils.h"
#include <string>
#include <vector>
#include <stdint.h>
#include <windows.h>
#include <Psapi.h>
#include "global.h"

#define InRange(x, a, b) (x >= a && x <= b) 
#define GetBits(x) (InRange(x, '0', '9') ? (x - '0') : ((x - 'A') + 0xA))
#define GetByte(x) ((BYTE)(GetBits(x[0]) << 4 | GetBits(x[1])))

uintptr_t utils::GetBase()
{
	return *(uintptr_t*)(__readgsqword(0x60) + 0x10);
}

PBYTE utils::FindPattern(uintptr_t StartAddress, uintptr_t EndAddress, const char* Pattern)
{
	PBYTE ModuleStart = (PBYTE)StartAddress;
	if (!ModuleStart)
		return nullptr;

	PBYTE ModuleEnd = (PBYTE)EndAddress;
	if (!ModuleEnd)
		return nullptr;

	PBYTE FirstMatch = nullptr;
	const char* CurPatt = Pattern;
	for (; ModuleStart < ModuleEnd; ++ModuleStart)
	{
		bool SkipByte = (*CurPatt == '\?');
		if (SkipByte || *ModuleStart == GetByte(CurPatt))
		{
			if (!FirstMatch)
				FirstMatch = ModuleStart;
			SkipByte ? CurPatt += 2 : CurPatt += 3;
			if (CurPatt[-1] == 0)
				return FirstMatch;
		}
		else if (FirstMatch)
		{
			ModuleStart = FirstMatch;
			FirstMatch = nullptr;
			CurPatt = Pattern;
		}
	}
	return nullptr;
}

uint8_t* utils::FindPatternEx(uintptr_t ModuleBase, uintptr_t StartAddress, uintptr_t EndAddress, const char* Pattern)
{
	uint8_t* ModuleStart = reinterpret_cast<uint8_t*>(ModuleBase);
	if (!ModuleStart)
		return nullptr;

	// 获取模块大小
	MODULEINFO moduleInfo;
	if (!GetModuleInformation(GetCurrentProcess(), reinterpret_cast<HMODULE>(ModuleStart), &moduleInfo, sizeof(MODULEINFO)))
		return nullptr;

	uint8_t* ModuleEnd = ModuleStart + moduleInfo.SizeOfImage - 0x1000;

	if (StartAddress > reinterpret_cast<uintptr_t>(ModuleStart) && StartAddress < reinterpret_cast<uintptr_t>(ModuleEnd))
		ModuleStart = reinterpret_cast<uint8_t*>(StartAddress);
	else
		ModuleStart += 0x1000;

	if (EndAddress < reinterpret_cast<uintptr_t>(ModuleEnd) && EndAddress > StartAddress)
		ModuleEnd = reinterpret_cast<uint8_t*>(EndAddress);

	while (true) {
		MEMORY_BASIC_INFORMATION info{};
		// 调用VirtualQueryEx函数，获取此时正在搜索的起始地址所在的内存块信息
		if (VirtualQueryEx(INVALID_HANDLE_VALUE, (LPCVOID)ModuleStart, &info, sizeof(info))) {
			// 如果内存块的保护属性是可执行只读
			if (info.Protect == PAGE_EXECUTE_READ) {
				auto temp = FindPattern((uintptr_t)info.BaseAddress, (uintptr_t)info.BaseAddress + info.RegionSize - 1, Pattern);
				if (temp) { return temp; }
			}
		}

		// 将搜索起始地址更新为当前内存块的结束地址
		ModuleStart += info.RegionSize;
		// 如果搜索起始地址已经超过了搜索范围，则退出循环
		if (ModuleStart >= ModuleEnd)
			break;
	}
	return nullptr;
}

uintptr_t utils::PatternScan(uintptr_t pModuleBaseAddress, const char* sSignature, int pIndex, bool sRelativeAdr)
{
	static auto patternToByte = [](const char* pattern) { auto bytes = std::vector<int>{}; const auto start = const_cast<char*>(pattern); const auto end = const_cast<char*>(pattern) + strlen(pattern); for (auto current = start; current < end; ++current) { if (*current == '?') { ++current; if (*current == '?') ++current; bytes.push_back(-1); } else bytes.push_back(strtoul((const char*)current, &current, 16)); } return bytes; };

	const auto dosHeader = (PIMAGE_DOS_HEADER)pModuleBaseAddress;
	const auto ntHeaders = (PIMAGE_NT_HEADERS)((uint8_t*)pModuleBaseAddress + dosHeader->e_lfanew);

	const auto sizeOfImage = ntHeaders->OptionalHeader.SizeOfImage;
	auto patternBytes = patternToByte(sSignature);
	const auto scanBytes = reinterpret_cast<uint8_t*>(pModuleBaseAddress);

	const auto s = patternBytes.size();
	const auto d = patternBytes.data();

	for (auto i = 0ul; i < sizeOfImage - s; ++i) {
		bool found = true; for (auto j = 0ul; j < s; ++j) { if (scanBytes[i + j] != d[j] && d[j] != -1) { found = false; break; } }
		if (found)
		{
			if (sRelativeAdr)
			{
				return ((uintptr_t)((UINT_PTR)(reinterpret_cast<uintptr_t>(&scanBytes[i])) + *(PINT)((UINT_PTR)(reinterpret_cast<uintptr_t>(&scanBytes[i])) + ((pIndex)-sizeof(INT))) + (pIndex)));
			}
			else
			{
				return reinterpret_cast<uintptr_t>(&scanBytes[i]);
			}
		}
	}

	return NULL;
}

void utils::cFixName(char* Name)
{
	for (int i = 0; Name[i] != '\0'; i++)
	{
		if (Name[i] == '_')
		{
			if (Name[i + 1] == '0' ||
				Name[i + 1] == '1' ||
				Name[i + 1] == '2' ||
				Name[i + 1] == '3' ||
				Name[i + 1] == '4' ||
				Name[i + 1] == '5' ||
				Name[i + 1] == '6' ||
				Name[i + 1] == '7' ||
				Name[i + 1] == '8' ||
				Name[i + 1] == '9')
				Name[i] = '\0';
		}
	}

	return;
}

void utils::FreeObjName(uintptr_t add)
{
	if (!add)return;
	auto func = reinterpret_cast<__int64(__fastcall*)(__int64)>(global::function::lpfnFreeObject);
	func((__int64)add);
}

std::string utils::GetNameByIndex(FName Index)
{
	if (Index.Index == 0) return " ";

	auto fnGetNameByIdx = reinterpret_cast<FString * (__fastcall*)(FName*, FString*)>(global::function::lpfnGetNameByIndex);
	FString result;

	fnGetNameByIdx(&Index, &result);
	if (!result.IsValid()) return " ";
	auto tmp = result.ToString();
	char return_string[1024];
	memcpy((void*)return_string, (const void*)std::string(tmp.begin(), tmp.end()).c_str(), (size_t)1024);

	FreeObjName((uintptr_t)result.c_str());
	cFixName(return_string);
	return return_string;
}

std::string utils::WChar2Ansi(LPCWSTR pwszSrc)
{
	int nLen = WideCharToMultiByte(CP_ACP, 0, pwszSrc, -1, NULL, 0, NULL, NULL);
	if (nLen <= 0) return std::string("");
	char* pszDst = new char[nLen];
	if (NULL == pszDst) return std::string("");
	WideCharToMultiByte(CP_ACP, 0, pwszSrc, -1, pszDst, nLen, NULL, NULL);
	pszDst[nLen - 1] = 0;
	std::string strTemp(pszDst);
	delete[] pszDst;
	return strTemp;
}