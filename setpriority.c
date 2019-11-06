#include "types.h"
#include "user.h"
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf(0, "incorrect no of arguments\n");
    }
    else
    {
        int pid = 0, priority = 0;
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            pid = pid*10 + (argv[1][i] - '0');
            // printf(0,"%d\n",pid);
        }
        for (int i = 0; i < strlen(argv[2]); i++)
        {
            priority = priority*10 + (argv[2][i] - '0');
        }
        printf(0,"set : pid = %d priority = %d\n",pid,priority);
        set_priority(pid, priority);
    }
    exit();
}