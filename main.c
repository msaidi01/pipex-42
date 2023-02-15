#include <sys/wait.h>
#include<stdio.h>
#include <unistd.h>
int main()
{
   int id = fork();
   if (!id)
        printf("im child\n");
   if (!id)
        printf("im child\n");
    else
    {
        waitpid(id, 0, 0);
        printf("im parent\n");
    }
}
