// WinVersion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define BUILD_WINDOWS

#include <Windows.h>
#include <VersionHelpers.h>
#include <stdio.h>

int main() {
	OSVERSIONINFO version = { sizeof(version) };
	::GetVersionEx(&version);

	printf("Version: %u.%u.%u\n",
		version.dwMajorVersion, version.dwMinorVersion, version.dwBuildNumber);

	if (IsWindows10OrGreater())
		printf("Windows 10\n");
	else if (IsWindows8Point1OrGreater())
		printf("Windows 8.1\n");
	else if (IsWindows8OrGreater())
		printf("Windows 8\n");
	else if (IsWindows7SP1OrGreater())
		printf("Windows 7 SP 1\n");
	else if (IsWindows7OrGreater())
		printf("Windows 7\n");
	else
		printf("Vista or older\n");

	return 0;
}
