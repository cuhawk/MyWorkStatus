// KillProcess.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <stdio.h>

int Error(const char* msg) {
	printf("%s (%u)\n", msg, ::GetLastError());
	return 1;
}

int main(int argc, const char* argv[]) {
	if (argc < 2) {
		printf("Usage: KillProcess <pid>\n");
		return 0;
	}

	int pid = atoi(argv[1]);
	HANDLE hProcess = ::OpenProcess(PROCESS_TERMINATE, FALSE, pid);
	if(!hProcess)
		return Error("Failed to open process");

	if (::TerminateProcess(hProcess, 0))
		printf("Process %u terminated\n", pid);
	else
		Error("Failed to terminate process\n");
	::CloseHandle(hProcess);

	return 0;
}

