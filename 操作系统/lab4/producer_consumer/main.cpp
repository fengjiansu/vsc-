#include <windows.h>
#include <iostream>

using namespace std;



class Semaphore{
	private:
	HANDLE semaphore;
	public:
		Semaphore(int currentsize,int maxsize )
		{
			semaphore=CreateSemaphore(NULL,currentsize,maxsize,NULL);
		}
		~Semaphore()
		{
			CloseHandle(semaphore);
		}
		void p()
		{
			WaitForSingleObject(semaphore,INFINITE);
		}
		void v(int currentsize)
		{
			ReleaseSemaphore(semaphore,currentsize,NULL);
		}
};

const int size = 5;

class Buffer {
private:
	int cells[size];
	int in;//in
	int out;//out

	Semaphore mutex;
	Semaphore empty;
	Semaphore full;
public:
	Buffer()
	:               


	mutex(1,1),//mutex 互斥信号量 保证多个进程互斥使用缓冲池资源 初值为1
	empty(size,size),//empty 代表空缓冲区 初值为n
	full(0,size)//full 代表慢缓冲区  初值为0
	{
		in = 0;
		out = 0;
	}

	~Buffer()
	{
		
	}

	void put(int x)
	{
		empty.p();//P(empty)
		mutex.p();//P(mutex)

		
		//cout << "thread " << GetCurrentThreadId() << " put " << x << "\t";


		cells[out] = x;
		out = (out + 1) % size;
		mutex.v(1);
		full.v(1);
		
	}

	void get(int* p)
	{
		full.p();//P(full)
		mutex.p();//P(mutex)
		//cout << "thread" << GetCurrentThreadId() << " get\t";


		*p = cells[in];
		in = (in + 1) % size;

		mutex.v(1);
		empty.v(1);
	}



};


Buffer a,b;

DWORD WINAPI x(LPVOID)
{
	for (int i = 0; i < 10; i++) {
		a.put(i);
	}
	return 0;
}

DWORD WINAPI y(LPVOID)
{
	for (int i = 0; i < 10; i++) {
		int temp;
		a.get(&temp);
		b.put(i);

	}
	return 0;
}

DWORD WINAPI z(LPVOID)
{
	for (int i = 0; i < 10; i++) {
		int x;
	    b.get(&x);
		cout<<x<<endl;

	}
	return 0;
}

int main()
{

	HANDLE thread_x = CreateThread(NULL, 0, x, 0, 0, NULL);
	HANDLE thread_y = CreateThread(NULL, 0, y, 0, 0, NULL);
	HANDLE thread_z = CreateThread(NULL, 0, z, 0, 0, NULL);

	

	WaitForSingleObject( thread_x, INFINITE);
	WaitForSingleObject( thread_y, INFINITE);
	WaitForSingleObject( thread_z, INFINITE);
	



	return 0;
}
