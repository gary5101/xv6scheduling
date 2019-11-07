#include "types.h"
#include "user.h"
#include "proc_stat.h"

// void pinfo(int a)
// {
//     struct proc_stat p;
//     if (getpinfo(a,&p))
//     {
//         printf(0, "\tpid = %d\n", p.pid);
//         printf(0, "\truntime = %d\n", p.runtime);
//         printf(0, "\tnumber of time choosen to run = %d\n", p.num_run);
//         printf(0, "\tcurrent queue = %d\n", p.current_queue);
//         printf(0, "\tticks\n");
//         int i = 0;
//         while (i < 5)
//         {
//             printf(0, "\t\t[%d]: %d\n", i, p.ticks[i]);
//             i++;
//         }
//     }
//     else
//     {
//         printf(1, "getpinfo error");
//     }
//     return;
// }

void timewaste(int times)
{
    volatile int k=0;
    for (int i = 0; i < times * 100000000; i++)
    {
        k++;
        k--;
    }
}
int main()
{
    int times_loop[10] = {10, 13, 4, 6, 9, 5, 8, 9, 12, 14};
    for (int i = 0; i < 10; i++)
    {
        int f = fork();
        if (f == 0)
        {
            timewaste(times_loop[i]);
            // pinfo(i+4);
            exit();
        }
    }
    exit();
}