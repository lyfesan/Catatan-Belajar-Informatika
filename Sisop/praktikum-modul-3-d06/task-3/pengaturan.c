#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc, char *argv[]){
    pid_t child;
    char dockerImages[] = "dockermessage";
    if(argc==2 && strcmp(argv[1],"list")==0){
        execlp("docker","docker","ps", NULL);
    }
    else {
        if(argc==3){
            if(strcmp(argv[1],"create")==0){
                execlp("docker", "docker", "run","-dt","--name", argv[2], dockerImages, NULL);
            }
            else if(strcmp(argv[1],"delete")==0){    
                child = fork();
                if(child==0) execlp("docker","docker","stop",argv[2],NULL);
                else {
                    wait(NULL);
                    execlp("docker","docker","rm","-f",argv[2],NULL);
                }    
            }
            else if(strcmp(argv[1],"login")==0){
                //child=fork();
                //if(child==0) execlp("docker","docker","start",argv[2],NULL);
                //else {
                //wait(NULL);
                execlp("docker","docker","exec","-it",argv[2],"/bin/sh",NULL);
                //}
            }
        }   
        else printf("Unmatched number of argument!\n");
    }
}