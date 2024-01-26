#pragma once
#include <stdint.h>
#include <windows.h>

namespace vmt
{
	template <typename hook_type>
	_declspec(noinline) hook_type vmt(uintptr_t address, uintptr_t hook_function, int index) {
		auto vtable = *(uintptr_t**)address;
		int vtable_size = 0;
		do vtable_size += 1;
		while (*(uintptr_t*)(uintptr_t(vtable) + (vtable_size * 8)));

		auto original_virtual_function = (void*)vtable[index];

		uintptr_t* fake_vtable = new uintptr_t[vtable_size * 8];

		for (int i = 0; i < vtable_size; i++) {
			if (i == index)//0x66
			{
				defines::address = *(uintptr_t*)(uintptr_t(vtable) + (i * 8));
				continue;
			}
			fake_vtable[i] = *(uintptr_t*)(uintptr_t(vtable) + (i * 8));
		}
		fake_vtable[index] = hook_function;

		*(uintptr_t**)address = fake_vtable;
		return hook_type(original_virtual_function);
	}

	void ReadVirtual(LPVOID src, LPVOID dest, size_t sz)
	{
		if (IsBadReadPtr(src, sz))
		{
			RtlZeroMemory(dest, sz);
			return;
		}
		RtlCopyMemory(dest, src, sz);
	}

	void WriteVirtual(LPVOID src, LPVOID dest, size_t sz)
	{
		if (IsBadReadPtr(src, sz))
			return;
		DWORD oldProtect = 0;
		VirtualProtect(src, sz, PAGE_EXECUTE_READWRITE, &oldProtect);
		RtlCopyMemory(src, dest, sz);
		VirtualProtect(src, sz, oldProtect, &oldProtect);
	}

}
