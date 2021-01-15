#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
  
// Let us create a global variable to change it in threads 
int g = 0; 
  
// The function to be executed by all threads 
void *myThreadFun(void *vargp) 
{ 
    // Store the value argument passed to this thread 
    int *myid = (int *)vargp; 
  
    // Let us create a static variable to observe its changes 
    static int s = 0; 
  
    // Change static and global variables 
    ++s; ++g; 
  
    // Print the argument, static and global variables 
    printf("Thread ID: %d, Static: %d, Global: %d\n", *myid, ++s, ++g); 
} 
  
int main() 
{ 
    int i; 
    pthread_t tid; 
  
    // Let us create three threads 
    for (i = 0; i < 3; i++) 
        pthread_create(&tid, NULL, myThreadFun, (void *)&tid); 
  
    pthread_exit(NULL); 
    return 0; 
} 
//gfg@ubuntu:~/$ gcc multithread.c -lpthread
//gfg@ubuntu:~/$ ./a.out
//Thread ID: 3, Static: 2, Global: 2
//Thread ID: 3, Static: 4, Global: 4
//Thread ID: 3, Static: 6, Global: 6
//gfg@ubuntu:~/$ 
