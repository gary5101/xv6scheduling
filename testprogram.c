#include "types.h"
#include "user.h"

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
        int pid = fork();
        if (pid == 0)
        {
            timewaste(times_loop[i]+4);
            // pinfo(i+4);
            exit();
        }
    }
    exit();
}