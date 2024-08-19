#include <iostream>
#include <windows.h>
#include<stdio.h>
#include<time.h>
using namespace std;

int money = 0;
CRITICAL_SECTION lock;
HANDLE semaphore;

DWORD WINAPI dad1(LPVOID x)
{
	
	for (int i = 0; i < 100000; i++) {
        EnterCriticalSection(&lock);
		money++;
        LeaveCriticalSection(&lock);
	}
	
	return 0;
}

DWORD WINAPI mom1(LPVOID)
{
	
	for (int i = 0; i < 100000; i++) {
        EnterCriticalSection(&lock);
		money++;
        LeaveCriticalSection(&lock);
	}
	
	return 0;
}

DWORD WINAPI dad(LPVOID x)
{
    
	for (int i = 0; i < 100000; i++) {
        WaitForSingleObject(semaphore,1);
		money++;
        ReleaseSemaphore(semaphore,1,NULL);
	}
	return 0;
}

DWORD WINAPI mom(LPVOID)
{
	
	for (int i = 0; i < 100000; i++) {
        WaitForSingleObject(semaphore,1);
		money++;
        ReleaseSemaphore(semaphore,1,NULL);
	}
	
	return 0;
}

int main()
{
    InitializeCriticalSection(&lock);
	semaphore=CreateSemaphore(0,1,1,0);
    
	
	HANDLE thread_dad,thread_dad1;
	HANDLE thread_mom,thread_mom1;

    clock_t  clock1,clock2;
    double diff_clock1;

	cout << money << endl;

	thread_dad = CreateThread(NULL, 0, dad, 0, 0, NULL);//信号量机制的线程
	thread_mom = CreateThread(NULL, 0, mom, 0, 0, NULL);

    
    clock1=clock();
	WaitForSingleObject(thread_dad, INFINITE);
	WaitForSingleObject(thread_mom, INFINITE);
    clock2=clock();
    diff_clock1=(double)(clock2-clock1)/(CLOCKS_PER_SEC);
    cout<<"Semaphore Time is "<<diff_clock1<<'s'<<endl;
	cout << money << endl;
    CloseHandle(semaphore);

    thread_dad1 = CreateThread(NULL, 0, dad1, 0, 0, NULL);//采取锁机制的线程
	thread_mom1 = CreateThread(NULL, 0, mom1, 0, 0, NULL);

    clock1=clock();
    WaitForSingleObject(thread_dad1, INFINITE);
	WaitForSingleObject(thread_mom1, INFINITE);
    clock2=clock();

    diff_clock1=(double)(clock2-clock1)/(CLOCKS_PER_SEC);
    cout<<"clock Time is "<<diff_clock1<<'s'<<endl;
	cout <<money << endl;
	
    DeleteCriticalSection(&lock);
	return 0;
}
