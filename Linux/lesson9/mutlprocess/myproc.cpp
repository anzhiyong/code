#include<iostream>
#include<vector>
#include<unistd.h>

using namespace std;


void SubProcessRun()
{
  while(true)
  {
    cout<<"I am is a Sub process, pid:" << getpid() << ", ppid:" << getppid() <<endl; 
  }
}

int main()
{
  vector<pid_t> allchild;
  for(int i = 0; i<10; i++)
  {
    pid_t id = fork();
    if(id == 0)
    {
      SubProcessRun();
    }
    allchild.push_back(id);
  }
  for(auto child: allchild)
  {
    cout<< child;
  }
  cout<<endl;

  return 0;
}
