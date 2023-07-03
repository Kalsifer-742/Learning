#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <pthread.h>
#include <fcntl.h>
#define MAX_CHILDS 5
#define READ 0
#define WRITE 1

//global
char input_string[64];
pid_t childs[5];
int child_n = 0;
int pipe_fd[2];
char log_file_path[] = "/tmp/log.txt";

void* thread_main(void*);
void handler(int sig_n)
{
    if (sig_n == SIGUSR1 || sig_n == SIGUSR2)
    {
        pthread_t t_id;
        pthread_create(&t_id, NULL, thread_main, &sig_n);
    }
    else if (sig_n == SIGCHLD)
    {
        if (child_n > 0)
        {
            child_n--;
        }
    }
    else if (sig_n == SIGTERM)
    {
        for (int i = 0; i < child_n; i++)
        {
            kill(childs[i], SIGKILL);
        }
        kill(getpid(), SIGKILL);
        //exit(0);
    }
}

void* thread_main(void* parameter)
{
    char buffer[128];

    int log_file = open(log_file_path, O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR);
    sprintf(buffer, "[THREAD] generated by signal %d\n", *(int *)parameter);
    write(log_file, buffer, strlen(buffer));
    
    sprintf(buffer, "[THREAD] sending message to childrens\n");
    write(log_file, buffer, strlen(buffer));

    for (int i = 0; i < child_n; i++)
    {
        int char_n = sprintf(buffer, "pid: %d - n: %d - string: %s", childs[i], i, input_string);
        //char_n * sizeof(char) always 1
        //sizeof(char) always 1
        write(pipe_fd[WRITE], &char_n, sizeof(int));
        write(pipe_fd[WRITE], buffer, char_n);
        
    }

    sprintf(buffer, "[THREAD] terminating thread\n");
    write(log_file, buffer, strlen(buffer));

    pthread_exit(0);
}

//memset(buffer, 0, sizeof(buffer));
//memset(buffer, 0, strlen(buffer));
//buffer[0] = '\0';
void child_main()
{
    char buffer[128];
    printf("[CHILD] PID: %d\n", getpid());
    
    int char_n;
    read(pipe_fd[READ], &char_n, sizeof(int));

    read(pipe_fd[READ], buffer, char_n);
    printf("[CHILD] received message: %s", buffer);

    exit(0);
}

int main()
{
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    signal(SIGCHLD, handler);
    signal(SIGTERM, handler);
    pipe(pipe_fd);
    creat(log_file_path, S_IRUSR | S_IWUSR);

    printf("[MAIN] PID: %d\n", getpid());

    while (true)
    {
        char buffer[64];
        int bytes_read = read(STDIN_FILENO, buffer, 64);
        if (bytes_read == -1)
        {
            fprintf(stderr, "[MAIN] error reading from stdin");
        }
        
        int value = atoi(buffer);
        if (value != 0)
        {
            if (child_n <= MAX_CHILDS)
            {                
                childs[child_n] = fork();
                if (childs[child_n] == 0)
                {
                    child_main();
                }
                child_n++;
            }
        }
        else
        {
            //è una string e non un numero
            strncpy(input_string, buffer, bytes_read);
            printf("[MAIN] new string: %s", input_string);
        }
    }

    return 0;
}