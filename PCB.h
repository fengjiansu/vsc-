#include"global.h"
struct PCB
{
        char name[10];                  //作业名
        int arrive_time;                //到达时间
        int run_time;                   //运行时间
        int priority;                   //优先权
        int start_time;                 //开始时间
        int finish_time;                //完成时间
        int service_time;               //服务时间
        int turnaround_time;            //周转时间
        float weighted_turnaround_time; //带权周转时间
        char status[10];                //进程状态
};
struct PCB pcb[101];
//作业初始化
void input(struct PCB *p, int N)
{
        int i;
        printf("输入作业名 到达时间 服务时间 优先权：");
        for (i = 0; i < N; i++)
        {
                printf("\n");
                scanf("%s", p[i].name);
                scanf("%d%d%d", &p[i].arrive_time, &p[i].service_time, &p[i].priority);
                p[i].start_time = 0;
                p[i].run_time = 0;
                p[i].finish_time = 0;
                p[i].turnaround_time = 0;
                p[i].weighted_turnaround_time = 0.00;
                strcpy(p[i].status, "W");
                printf("%s\t%d\t%d\t%d", p[i].name, p[i].arrive_time, p[i].service_time, p[i].priority);
        }
}

//排序函数
void sort(PCB *pcb, int N)
{
        for (int i = 0; i < N; i++)
        {
                int min = pcb[i].arrive_time;
                int minIndex = i;
                for (int j = i + 1; j < N; j++)
                {
                        if (pcb[j].arrive_time < min)
                        {
                                min = pcb[j].arrive_time;
                                minIndex = j;
                        }
                        /* else if (pcb[j].arrive_time == min)
                        {
                                if (pcb[j].priority > pcb[minIndex].priority)
                                {
                                        minIndex = j;
                                }
                        }*/
                }
                struct PCB temp = pcb[i];
                pcb[i] = pcb[minIndex];
                pcb[minIndex] = temp;
        }
}
void output(PCB *p, int N)
{
        int j;
        sort(p, N);
        printf("\n进程信息：");
        printf("\n作业名 到达时间 服务时间 开始时间 结束时间 周转时间 带权周转时间 运行状态\n");
        for (j = 0; j < N; j++)
        {
                if (strcmp(p[j].status, "F") == 0)
                { //如果进程为F状态，这样输出
                        printf("%s\t", p[j].name);
                        printf("%2d\t%3d\t%4d\t%5d\t%6d\t\t%.2f\t%4s\n",
                               p[j].arrive_time, p[j].run_time, p[j].start_time, p[j].finish_time,
                               p[j].turnaround_time, p[j].weighted_turnaround_time, p[j].status);
                }
        }
}