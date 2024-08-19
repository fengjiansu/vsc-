#include <Windows.h>
#include <iostream>

using namespace std;

int main()
{

	char buf[1000];
	GetCurrentDirectory(sizeof buf, buf);
	cout << buf << endl;
	
	BOOL ok;

	ok = CreateDirectory("a", NULL);
	if (ok) {
		cout << "ok a" << endl;
	}

	ok = CreateDirectory("a\\b", NULL);
	if (ok) {
		cout << "ok a\\b" << endl;
	}

	SetCurrentDirectory("a\\b");
	ok = CreateDirectory("c", NULL);
	if (ok) {
		cout << "ok a\\b\\c" << endl;
	}

	CopyFile("..\\..\\main.cpp", "haha.cpp", TRUE);
	CopyFile("..\\..\\main.cpp", ".\\haha2.cpp", TRUE);
	DeleteFile(".\\haha2.cpp");
	MoveFile(".\\haha.cpp", "..\\hehe.cpp");
	
	return 0;
}
