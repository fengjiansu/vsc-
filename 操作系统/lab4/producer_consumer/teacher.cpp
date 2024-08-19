#include <windows.h>
#include <iostream>

using namespace std;

class Semaphore {
public:
	Semaphore(int initial_count, int max_count)
	{
		native_semaphore = CreateSemaphore(NULL, initial_count, max_count, NULL);
	}

	~Semaphore()
	{
		CloseHandle(native_semaphore);
	}

	void p()
	{
		WaitForSingleObject(native_semaphore, INFINITE);
	}

	void v()
	{
		ReleaseSemaphore(native_semaphore, 1, NULL);
	}
private:
	HANDLE native_semaphore;
};

const int buffer_size = 5;

class Buffer {
public:
	Buffer()
	:
	mutex(1, 1),
	semaphore_white_cell(buffer_size, buffer_size),
	semaphore_black_cell(0, buffer_size)
	{
		num = 0;
		head = 0;
		tail = 0;
	}

	~Buffer()
	{
	}

	bool put(int x)
	{
		semaphore_white_cell.p();
		mutex.p();

		
		//cout << "thread " << GetCurrentThreadId() << " put " << x << "\t";


		cells[tail] = x;
		tail = (tail + 1) % buffer_size;
		//cout << "ok" << endl;

		num++;

		mutex.v();
		semaphore_black_cell.v();
		
		return true;
	}

	bool get(int* p)
	{
		semaphore_black_cell.p();
		mutex.p();
		
		//cout << "thread" << GetCurrentThreadId() << " get\t";

		*p = cells[head];
		head = (head + 1) % buffer_size;
		num--;
		//cout << "ok(" << *p << ")" << endl;

		mutex.v();
		semaphore_white_cell.v();

		return true;
	}


private:
	int cells[buffer_size];
	int head;
	int tail;
	int num;

	Semaphore mutex;
	Semaphore semaphore_white_cell;
	Semaphore semaphore_black_cell;
};


Buffer s, t;


DWORD WINAPI a(LPVOID)
{
	for (int i = 0; i < 10; i++) {
		bool ok = s.put(i);
	}
	return 0;
}

DWORD WINAPI b(LPVOID)
{
	for (int i = 0; i < 10; i++) {
		int x;
		
		bool ok = s.get(&x);
		ok = t.put(i);
	}
	return 0;
}

DWORD WINAPI c(LPVOID)
{
	for (int i = 0; i < 10; i++) {
		int x;
		
		bool ok = t.get(&x);
		cout << x << endl;
	}
	return 0;
}


int main()
{

	HANDLE thread_a = CreateThread(NULL, 0, a, 0, 0, NULL);
	HANDLE thread_b = CreateThread(NULL, 0, b, 0, 0, NULL);
	HANDLE thread_c = CreateThread(NULL, 0, c, 0, 0, NULL);

	WaitForSingleObject(thread_a, INFINITE);
	WaitForSingleObject(thread_b, INFINITE);
	WaitForSingleObject(thread_c, INFINITE);

	return 0;
}
