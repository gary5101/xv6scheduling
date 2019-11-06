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
        printf(0, "\tpid = %d\n", p.pid);
        printf(0, "\truntime = %d\n", p.runtime);
        printf(0, "\tnumber of time choosen to run = %d\n", p.num_run);
        printf(0, "\tcurrent queue = %d\n", p.current_queue);
        printf(0, "\tticks\n");
        int i = 0;
        while (i < 5)
        {
            printf(0, "\t\t[%d]: %d\n", i, p.ticks[i]);
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
    // int p = fork();
    // if (p == 0)
    // {
    //     set_priority(59);
    //     timewaste(2);
    //     pinfo();
    //     exit();
    // }
    // else
    // {

    //     p = fork();
    //     if (p == 0)
    //     {
    //         set_priority(1);
    //         timewaste(4);
    //         pinfo();
    //         exit();
    //     }
    //     else
    //     {
    //         p = fork();
    //         if (p == 0)
    //         {
    //             timewaste(3);
    //             pinfo();
    //             exit();
    //         }
    //         int wtime, rtime;
    //         for (int i = 0; i < 3; i++)
    //         {
    //             int a = waitx(&wtime, &rtime);
    //             printf(0, "pid %d has %d waittime %d runtime\n", a, wtime, rtime);
    //         }
    //     }
    // }
    // set_priority(3, 1);
    for (int i = 0; i < 5; i++)
    {
        int child = fork();
        if (child == 0)
        {
            switch (i)
            {
            case 1:
                timewaste(3);
                break;
            case 2:
                timewaste(2);
                break;
            case 3:
                timewaste(5);
                break;
            case 4:
                timewaste(4);
                break;
            default:
                timewaste(4);
                break;
            }
            pinfo();
            exit();
        }
        else
        {
            switch (i)
            {
            case 1:
                // set_priority(5,20);
                break;
            case 2:
                // set_priority(6,59);
                break;
            case 4:
                // set_priority(8,21);
                break;
            default:
                break;
            }
        }
    }
    // int wtime, rtime;
    // for (int i = 0; i < 5; i++)
    // {
    //     int a = waitx(&wtime, &rtime);
    //     printf(0, "pid %d has waittime = %d runtime = %d\n", a, wtime, rtime);
    // }
    exit();
}