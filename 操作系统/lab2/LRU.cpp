#include<bits/stdc++.h>

using namespace std;

const int MemCapacity = 3;
int FIFOQueue[MemCapacity] = {0};

int pageInMainMem(int page)
{
	for (int i = 0; i < MemCapacity; i++) {
		if (FIFOQueue[i] == page)
			return i;
	}
	return -1;
}

void lru(int index)
{
    if(index==0)
        return;
    else
    {
        int temp=FIFOQueue[index];
        for(int i=index;i>0;i--)
        {
            FIFOQueue[i] = FIFOQueue[i-1];
        }
        FIFOQueue[0]=temp;
    }
}

void foldPage(int page)
{
	for (int i = MemCapacity - 1; i > 0; i--)
		FIFOQueue[i] = FIFOQueue[i - 1];
	FIFOQueue[0] = page;
}


int main()
{
    int pageFootprints[] = {1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6};
	int pageNum = sizeof pageFootprints / sizeof pageFootprints[0];


	int RequestCount = 0;
	bool request;

    int index;

    cout<<("时刻   访问页面   主存状态   缺页中断   调入页\n");
	for (int i = 0; i < pageNum; i++) {
		printf("%3d      ", i);
		printf("    %2d    ", pageFootprints[i]);
		request = false;
        index=pageInMainMem(pageFootprints[i]);
		if ( index== -1) {
			foldPage(pageFootprints[i]);
			RequestCount++;
			request = true;
		}
        else
        {
            lru(index);
        }

		for (int j = 0; j < MemCapacity; j++)
			printf("%2d", FIFOQueue[j]);

		if (request) {
			printf("           +   ");
			printf("     %d", pageFootprints[i]);
		}
		
		printf("\n");

	}

	printf("缺页中断次数 = %d\n", RequestCount);
	printf("缺页率 = %d/%d = %.2f%%\n", RequestCount, pageNum, (float)RequestCount/pageNum*100);
    return 0;
}