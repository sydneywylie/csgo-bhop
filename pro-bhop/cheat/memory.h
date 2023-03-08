#pragma once
#include "Windows.h"
#include <iostream>

class Memory
{
private:
	DWORD id = 0; // id of process
	HANDLE process = NULL; // handle to process

public:
	Memory(const char* processName);
	~Memory();

	DWORD GetProcessId();
	HANDLE GetProcessHandle();

	uintptr_t GetModuleAdress(const char* moduleName);

	template <typename T>
	T Read(uintptr_t adress)
	{
		T value;
		ReadProcessMemory(this->process, (LPCVOID)adress, &value, sizeof(T), NULL);
		return value;
	}

	template <typename T> 
	bool Write(uintptr_t adress, T value)
	{
		return WriteProcessMemory(this->process, (LPVOID)adress, &value, sizeof(T), NULL);
	}
};