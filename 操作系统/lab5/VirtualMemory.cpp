#include <windows.h>
#include <iostream>
#include <time.h>

using namespace std;

struct Cell {
	char data[128];
};

const int TOTAL_ROWS = 2500;
const int TOTAL_COLS = 2500;

int main()
{
	clock_t  clock1,clock2;
    double diff_clock1;

	clock1=clock();
	Cell* p = (Cell*)malloc(TOTAL_ROWS * TOTAL_COLS * sizeof(Cell));
	if (p) {
		cout << "ok" << endl;
	}
	else {
		cout << "oops" << endl;
	}
	
	for (int i = 0; i < TOTAL_ROWS; i++) {
		for (int j = 0; j < TOTAL_COLS; j++) {
			if (i == j) {
				for (int n = 0; n < 128; n++) {
					(p + (i * TOTAL_COLS) + j)->data[n] = 'A';
				}
			}
		}
	}
	clock2=clock();
	diff_clock1=(double)(clock2-clock1)/(CLOCKS_PER_SEC);
	cout<<"malloc Time is "<<diff_clock1<<'s'<<endl;


	clock1=clock();
	p = (Cell*)VirtualAlloc(NULL, TOTAL_ROWS * TOTAL_COLS * sizeof(Cell),
		MEM_RESERVE, PAGE_READWRITE);
	if (p) {
		cout << "ok" << endl;
	}
	else {
		cout << "oops" << endl;
	}

	
	for (int i = 0; i < TOTAL_ROWS; i++) {
		for (int j = 0; j < TOTAL_COLS; j++) {
			if (i == j) {
				VirtualAlloc(p + (i * TOTAL_COLS) + j, sizeof(Cell), MEM_COMMIT, PAGE_READWRITE);

				for (int n = 0; n < 128; n++) {
					(p + (i * TOTAL_COLS) + j)->data[n] = 'A';
				}
			}
		}
	}
	clock2=clock();
	diff_clock1=(double)(clock2-clock1)/(CLOCKS_PER_SEC);
	cout<<"VirtualAlloc Time is "<<diff_clock1<<'s'<<endl;


	return 0;
}
