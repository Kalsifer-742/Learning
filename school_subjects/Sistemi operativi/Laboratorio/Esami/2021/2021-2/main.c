#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

void leaf_main(int target)
{
    char buffer[32];

    int leaf = fork();
    if (leaf == 0)
    {
        sprintf(buffer, "%d\n", getpid());
        write(target, buffer, strlen(buffer));
    }
}

void leaf_killer(int sig_n)
{

}

void manager_main(int target, int n)
{
    char buffer[32];
    sprintf(buffer, "%d\n", getpid());
    write(target, buffer, strlen(buffer));

    for (int i = 0; i < n; i++)
    {
        leaf_main(target);
    }

    signal(SIGUSR1, leaf_killer);

    while(1);
}

int target;
int main(int argc, char** argv)
{
    if (argc != 3)
    {
        printf("ERROR: missing parameters\n");  
        return 3;
    }

    int n = atoi(argv[2]);
    if (n == 0)
    {
        printf("ERROR: n must be a valid number\n");        
        return 4;
    }
    else if (n < 1 || n > 10)
    {
        printf("ERROR: n must be beetween 1 and 10\n");
        return 4;
    }

    char* target_file = argv[1];
    if (open(target_file, O_RDONLY) == -1)
    {
        perror("ERROR");
        return 5;
    }
    
    //all controls on input passed
    target = open(target_file, O_RDWR | O_CREAT | O_APPEND | O_TRUNC);
    char buffer[32];

    sprintf(buffer, "%d\n", getpid());
    
    write(target, buffer, strlen(buffer));

    int manager = fork();
    if (manager == 0)
    {
        manager_main(target, n);
    }
    else
    {
        close(target);
    }

    return 0;
}