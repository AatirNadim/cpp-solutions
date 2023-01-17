// Write a program in C++ where 2 child process (fork()) are manipulating the same variable and if one process changes, the value should reflect in other process


#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <iostream>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/mman.h>

using namespace std;

int main()
{
    int x = 0;
    int* p = (int*) mmap(NULL, sizeof (int) , PROT_READ | PROT_WRITE,
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    cout<<"Original value --> "<<*p<<endl;
    int pid = fork();
        *p = 1;
        cout << "Child 1: " << *p << endl;
        cout<<"Child 1 ----: "<<*p<<endl;
        int pid2 = fork();
            cout << "Child 2: " << *p << endl;
            wait(NULL);
            cout << "Parent: " << *p << endl;
    return 0;
}