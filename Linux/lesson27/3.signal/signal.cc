#include <iostream>
#include <signal.h>

int main()
{
    //1.信号捕捉
    //2.忽略
    //3.自定义睡眠
    ::signal(2, SIG_IGN);//ignore :忽略：本身就是一种信号捕捉的方式，动作是忽略
    ::signal(2, SIG_DFL);//default:默认


    return 0;
}