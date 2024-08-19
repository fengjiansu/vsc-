#include <windows.h>
#include <iostream>
#include <ctime>

using namespace std;

int money = 0;
CRITICAL_SECTION lock;
HANDLE semaphore;

void dad()
{
	for (int i = 0; i < 100000; i++) {
		money++;
	}
}

void mom()
{
	for (int i = 0; i < 100000; i++) {
		money++;
	}
}

DWORD WINAPI dad_lock(LPVOID x)
{
	for (int i = 0; i < 100000; i++) {
		EnterCriticalSection(&lock);
		money++;
		LeaveCriticalSection(&lock);
	}
	return 0;
}

DWORD WINAPI mom_lock(LPVOID)
{
	for (int i = 0; i < 100000; i++) {
		EnterCriticalSection(&lock);
		money++;
		LeaveCriticalSection(&lock);
	}
	return 0;
}

DWORD WINAPI dad_semaphore(LPVOID x)
{
	for (int i = 0; i < 100000; i++) {
		WaitForSingleObject(semaphore, INFINITE);
		money++;
		ReleaseSemaphore(semaphore, 1, NULL);
	}
	return 0;
}

DWORD WINAPI mom_semaphore(LPVOID)
{
	for (int i = 0; i < 100000; i++) {
		WaitForSingleObject(semaphore, INFINITE);
		money++;
		ReleaseSemaphore(semaphore, 1, NULL);
	}
	return 0;
}

// Project > Settings... > C/C++ > Code Generation > Use run-time library > Debug Multithreaded

void test_single_thread()
{
	money = 0;
	cout << money << endl;

	clock_t c_start = clock();

	dad();
	mom();

	clock_t c_end = clock();
	
	cout << money << endl;
	cout << "time: " << c_end - c_start << endl;
}

void test_lock()
{
	InitializeCriticalSection(&lock);
	
	HANDLE thread_dad;
	HANDLE thread_mom;

	money = 0;
	cout << money << endl;

	clock_t c_start = clock();

	thread_dad = CreateThread(NULL, 0, dad_lock, 0, 0, NULL);
	thread_mom = CreateThread(NULL, 0, mom_lock, 0, 0, NULL);

	WaitForSingleObject(thread_dad, INFINITE);
	WaitForSingleObject(thread_mom, INFINITE);

	clock_t c_end = clock();

	cout << money << endl;
	cout << "time: " << c_end - c_start << endl;

	DeleteCriticalSection(&lock);
}

void test_semaphore()
{
	semaphore = CreateSemaphore(NULL, 1, 1, NULL);
	
	HANDLE thread_dad;
	HANDLE thread_mom;

	money = 0;
	cout << money << endl;

	clock_t c_start = clock();

	thread_dad = CreateThread(NULL, 0, dad_semaphore, 0, 0, NULL);
	thread_mom = CreateThread(NULL, 0, mom_semaphore, 0, 0, NULL);

	WaitForSingleObject(thread_dad, INFINITE);
	WaitForSingleObject(thread_mom, INFINITE);

	clock_t c_end = clock();

	cout << money << endl;
	cout << "time: " << c_end - c_start << endl;

	CloseHandle(semaphore);
}

int main()
{
	test_single_thread();
	test_lock();
	test_semaphore();
	return 0;
}
