#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

const std::string myenv="HELLO=AAAAAAAAAAAAAAAAAAAA";

extern char **environ;
int main()
{
    putenv((char*)myenv.c_str());
    pid_t id = fork();
    if(id == 0)
    {
        char *const argv[] = {
            (char*)"other",
            nullptr
        };

        //(void)argv;
        char *const env[] = {
            (char*)"HELLO=bite",
            (char*)"HELLO1=bite1",
            (char*)"HELLO2=bite2",
            (char*)"HELLO3=bite3"
        };

        execvpe("./other", argv, environ);

        //execvp(argv[0], argv);
        //execlp("ls", "ls", "--color", "-aln", nullptr);


        //execv("/usr/bin/ls", argv);
        // child
        //execl("/bin/ls", "ls", "-l", "--color", "-a", nullptr);
        //execl("./other", "other", nullptr);
        //execl("/usr/bin/python", "python", "test.py", nullptr);
        //execl("/usr/bin/bash", "bash", "test.sh", nullptr);
        exit(1);
    }
    // father
    pid_t rid = waitpid(id, nullptr, 0);
    if(rid > 0)
    {
        printf("等待子进程成功!\n");
    }
    //printf("我是myexec, pid: %d\n", getpid());

    ////execl("./other", "other", nullptr);

    //printf("execl return val: %d\n", n);
    //execl("/usr/bin/top", "top", nullptr);
    return 0;
}
