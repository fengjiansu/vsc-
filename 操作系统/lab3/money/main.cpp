#include <windows.h>
#include <iostream>

using namespace std;

int money = 0;
CRITICAL_SECTION lock;

DWORD WINAPI dad(LPVOID x)
{
	//EnterCriticalSection(&lock);
	for (int i = 0; i < 100000; i++) {
		money++;
	}
	//LeaveCriticalSection(&lock);
	return 0;
}

DWORD WINAPI mom(LPVOID)
{
	EnterCriticalSection(&lock);
	for (int i = 0; i < 100000; i++) {
		money++;
	}
	LeaveCriticalSection(&lock);
	return 0;
}

// Project > Settings... > C/C++ > Code Generation > Use run-time library > Debug Multithreaded
int main()
{
	InitializeCriticalSection(&lock);
	
	HANDLE thread_dad;
	HANDLE thread_mom;

	cout << money << endl;

	thread_dad = CreateThread(NULL, 0, dad, 0, 0, NULL);
	thread_mom = CreateThread(NULL, 0, mom, 0, 0, NULL);

	WaitForSingleObject(thread_dad, INFINITE);
	WaitForSingleObject(thread_mom, INFINITE);

	cout << money << endl;

	DeleteCriticalSection(&lock);
	return 0;
}
