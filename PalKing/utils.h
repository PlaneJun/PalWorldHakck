#pragma once
#include <string>
#include <stdint.h>
#include <windows.h>
#include "engine.h"

namespace utils
{
	uintptr_t GetBase();

	PBYTE FindPattern(uintptr_t StartAddress, uintptr_t EndAddress, const char* Pattern);

	uint8_t* FindPatternEx(uintptr_t ModuleBase, uintptr_t StartAddress, uintptr_t EndAddress, const char* Pattern);

	uintptr_t PatternScan(uintptr_t pModuleBaseAddress, const char* sSignature, int pIndex, bool sRelativeAdr = false);

	void cFixName(char* Name);

	void FreeObjName(uintptr_t add);

	std::string GetNameByIndex(FName Index);

	std::string WChar2Ansi(LPCWSTR pwszSrc);

}