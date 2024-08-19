#include <Windows.h>
#include <iostream>

using namespace std;

int main()
{
	char directory[1000];
	GetCurrentDirectory(sizeof directory, directory);
	cout << directory << endl;

	HANDLE file = CreateFile( // 新建、打开文件都是用这个函数
		"a.txt",
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		CREATE_NEW,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);

	
	char buf[] = "abc";
	WriteFile(
		file,
		buf,
		sizeof buf - 1,
		NULL,
		NULL
	);

	


	CloseHandle(file);
	MoveFile("a.txt", "../a.txt");
	return 0;
}
