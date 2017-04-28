#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <fcntl.h>  
#include <limits.h>  
#include <systemd/sd-daemon.h>
#include <string>
using namespace std; 
int main(int argc, char *argv[]) {  /*
    char strCurPath[PATH_MAX];  
  
    if(daemon(1, 0) < 0)  
    {  
        perror("error daemon.../n");  
        exit(1);  
    }  
    sleep(10);  
  
    if(getcwd(strCurPath, PATH_MAX) == NULL)  
    {  
        perror("error getcwd");  
        exit(1);  
    }
*/  
    while(1) {
        int error = 0;
        string status = "hello world";
        static int pid = getpid();
         if (0 != error) {
            (void)::sd_notifyf(0, "STATUS=%s\n"
                "ERRNO=%d"
                "MAINPID=%d", status.c_str(), error, pid);
        } else {
            (void)::sd_notifyf(0, "READY=1\n"
                "STATUS=%s\n"
                "MAINPID=%d",  status.c_str(), pid);
        }
        sleep(2);
    } 
    return 0;  
} 

