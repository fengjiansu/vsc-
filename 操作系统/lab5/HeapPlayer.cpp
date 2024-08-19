#include <windows.h>
#include <iostream>
#include <ctime>
using namespace std;

HANDLE heap;
HANDLE a_heap;
HANDLE b_heap;

DWORD WINAPI common_heap(LPVOID x)
{
    for (int i = 0; i < 100000; i++) {
	    void* p = HeapAlloc(heap, 0, 100);
		HeapFree(heap, 0, p);
    }	
	return 0;
}

DWORD WINAPI heapA(LPVOID x)
{
	for (int i = 0; i < 100000; i++) {
	    void* p = HeapAlloc(a_heap, 0, 100);
		HeapFree(a_heap, 0, p);
	}
	return 0;
}

DWORD WINAPI heapB(LPVOID x)
{
	for (int i = 0; i < 100000; i++) {
	    void* p = HeapAlloc(b_heap, 0, 100);
		HeapFree(b_heap, 0, p);
	}
	return 0;
}

int main()
{
	clock_t  clock1,clock2;
    double diff_clock1;

	heap= GetProcessHeap();
	a_heap = HeapCreate(HEAP_NO_SERIALIZE, 1000, 2000);
	b_heap = HeapCreate(HEAP_NO_SERIALIZE, 1000, 2000);

	
	HANDLE a_thread = CreateThread(NULL, 0, common_heap, 0, 0, NULL);
	HANDLE b_thread = CreateThread(NULL, 0, common_heap, 0, 0, NULL);

	clock1=clock();

	WaitForSingleObject(a_thread, INFINITE);
	WaitForSingleObject(b_thread, INFINITE);

	clock2=clock();
	diff_clock1=(double)(clock2-clock1)/(CLOCKS_PER_SEC);
    cout<<"CommonHeap Time is "<<diff_clock1<<'s'<<endl;

	HANDLE a_thread_new = CreateThread(NULL, 0, heapA, 0, 0, NULL);
	HANDLE b_thread_new = CreateThread(NULL, 0, heapB, 0, 0, NULL);

	clock1=clock();

	WaitForSingleObject(a_thread_new, INFINITE);
	WaitForSingleObject(b_thread_new, INFINITE);

	clock2=clock();
	diff_clock1=(double)(clock2-clock1)/(CLOCKS_PER_SEC);
    cout<<"IndividualHeap Time is "<<diff_clock1<<'s'<<endl;


    return 0;
}
