// SingleInstance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <stdio.h>

int Error(const char* msg) {
	printf("%s (%u)\n", msg, ::GetLastError());
	return 1;
}

int main() {
	HANDLE hMutex = ::CreateMutex(nullptr, FALSE, L"SingleInstanceMutex");
	if (!hMutex) {
		return Error("Failed to create mutex");
	}

	if (::GetLastError() == ERROR_ALREADY_EXISTS) {
		printf("Second instance... exiting.\n");
		return 0;
	}

	printf("First instance running... press ENTER to quit\n");
	char dummy[4];
	gets_s(dummy);

	::CloseHandle(hMutex);
	return 0;
}

