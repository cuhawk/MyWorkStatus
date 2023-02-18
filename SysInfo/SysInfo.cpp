// SysInfo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <Psapi.h>
#include <stdio.h>

int main() {
    // static system information

    SYSTEM_INFO si;
    ::GetNativeSystemInfo(&si);

    printf("Number of Logical Processors: %u\n", si.dwNumberOfProcessors);
    printf("Page size: %u Bytes\n", si.dwPageSize);
    printf("Processor Mask: 0x%zX\n", si.dwActiveProcessorMask);
    printf("Minimum process address: 0x%p\n", si.lpMinimumApplicationAddress);
    printf("Maximum process address: 0x%p\n", si.lpMaximumApplicationAddress);

    WCHAR name[64];
    DWORD size = _countof(name);
    if (::GetComputerName(name, &size))
        printf("Computer Name: %ws\n", name);
    
    size = _countof(name);
    if(::GetUserName(name, &size))
        printf("User Name: %ws\n", name);

    CONSOLE_CURSOR_INFO ci;
    if (::GetConsoleCursorInfo(::GetStdHandle(STD_OUTPUT_HANDLE), &ci)) {
        ci.bVisible = FALSE;
        ::SetConsoleCursorInfo(::GetStdHandle(STD_OUTPUT_HANDLE), &ci);
    }

    PERFORMANCE_INFORMATION pi;
    printf("\n");

    for (;;) {
        if (!::GetPerformanceInfo(&pi, sizeof(pi)))
            break;
        printf("Processes: %4u\n", pi.ProcessCount);
        printf("Threads: %5u\n", pi.ThreadCount);
        printf("Handles: %7u\n", pi.HandleCount);
        printf("Committed: %7zu KB\n", pi.CommitTotal >> 10);
        printf("Kernel Pool: %5zu KB\n", pi.KernelTotal >> 10);
        ::Sleep(500);
        printf("\r\033[5A");
    }

    return 0;
}
