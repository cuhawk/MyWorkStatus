// Strings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <stdio.h>
#include <strsafe.h>

int main() {
	WCHAR buffer[128];
	::StringCchPrintf(buffer, _countof(buffer), L"This is my string from process %u", ::GetCurrentProcessId());

	::MessageBox(nullptr, buffer, L"Strings Demo", MB_OK | MB_ICONINFORMATION);

	WCHAR path[MAX_PATH];
	::GetSystemDirectory(path, _countof(path));
	printf("System directory: %ws\n", path);

	WCHAR computerName[MAX_COMPUTERNAME_LENGTH];
	DWORD len = _countof(computerName);
	if (::GetComputerName(computerName, &len))
		printf("Computer name: %ws (%u)\n", computerName, len);

	return 0;
}

