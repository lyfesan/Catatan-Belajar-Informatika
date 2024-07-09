#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<pthread.h>
#include<linux/limits.h>

const char HORSE_DIR[] = "horses";

void HorseFetcher(){
    char current_dir[PATH_MAX];
    getcwd(current_dir,sizeof(current_dir));
    strcat(current_dir,"/horses.zip");
    system("wget -O horses.zip https://drive.usercontent.google.com/download?id=1gJkoTbiHZcJ1M36vqZPTrj3qTQkRMElQ&export=download&authuser=0&confirm=t&uuid=c59270d1-66fa-44e9-a424-faef8c48d9b3&at=APZUnTVccyI5pT70VPS_NfJJStDT:1714024470709");
    char extract_command[PATH_MAX+20] = "unzip -o -d horses ";
    strcat(extract_command, current_dir); 
    system(extract_command);
    printf("%s\n", current_dir);
}

void HorseRaceHooray(char *horsesListDir){
    FILE *fp;
    fp = fopen(horsesListDir, "r");
    if(fp==NULL){
        printf("Opening file %s failed, returning to main program", horsesListDir);
        return;
    }

}

int main(){
    HorseFetcher();
}