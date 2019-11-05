#include "types.h"
#include "user.h"
#include "proc_stat.h"
void timewaste(volatile int k)
{
    volatile int count = 0;
    for (volatile int i = 0; i < k * 100000000; i++)
    {
        count++;
        count--;
    }
}
void pinfo()
{
    struct proc_stat p;
    if (getpinfo(&p))
    {
        printf(0, "pid = %d\n", p.pid);
        printf(0, "runtime = %d\n", p.runtime);
        printf(0, "number of time choosen to run = %d\n", p.num_run);
        printf(0, "current queue = %d\n", p.current_queue);
        printf(0, "ticks\n");
        int i = 0;
        while (i < 5)
        {
            printf(0, "[%d]: %d\n", i, p.ticks[i]);
            i++;
        }
    }
    else
    {
        printf(1, "getpinfo error");
    }
    return;
}
int main()
{
    int p = fork();
    if (p == 0)
    {
        set_priority(59);
        timewaste(2);
        pinfo();
        exit();
    }
    else
    {
        
        p = fork();
        if (p == 0)
        {
            set_priority(1);
            timewaste(4);
            pinfo();
            exit();
        }
        else
        {
            p = fork();
            if (p == 0)
            {
                timewaste(3);
                pinfo();
                exit();
            }
            int wtime, rtime;
            for (int i = 0; i < 3; i++)
            {
                int a = waitx(&wtime, &rtime);
                printf(0, "pid %d has %d waittime %d runtime\n", a, wtime, rtime);
            }
        }
    }
    exit();
}