#include "types.h"
#include "user.h"
#include "proc_stat.h"
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf(0, "incorrect no of arguments\n");
    }
    else
    {
        int pid = 0;
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            pid = pid * 10 + (argv[1][i] - '0');
            // printf(0,"%d\n",pid);
        }
        printf(0, "set : pid = %d \n", pid);

        struct proc_stat p1;
        if (getpinfo(pid, &p1))
        {
            printf(0, "\tpid = %d\n", p1.pid);
            printf(0, "\truntime = %d\n", p1.runtime);
            printf(0, "\tnumber of time choosen to run = %d\n", p1.num_run);
            printf(0, "\tcurrent queue = %d\n", p1.current_queue);
            printf(0, "\tticks\n");
            int i = 0;
            while (i < 5)
            {
                printf(0, "\t\t[%d]: %d\n", i, p1.ticks[i]);
                i++;
            }
        }
        else
        {
            printf(1, "getpinfo error");
        }

    }
    exit();
}