#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>

pthread_mutex_t mutex;

struct writeBatchData{
    int threadNum;
    char *wordToWrite;
    FILE *pointerFile;
};

void readFile(int argc, char *argv[]){
    char *fpath = argv[argc-1];
    FILE *fp = fopen(fpath,"r");
    char buff[1024];
    if(fp==NULL) {
        perror("Error opening file: file not exists or permission denied!");
        return;
    }
    printf("Pesan yang ditulis:\n");
    while(fgets(buff,128,fp)!=NULL){
        if(ferror(fp)) {
            perror("Error while reading file");
            fclose(fp);
            return;
        }
        else printf("%s",buff);
    };
    printf("\n");
    fclose(fp);
}

void *writeBatch(void *arg) {
    
    pthread_mutex_lock(&mutex);
    struct writeBatchData *dataParam;
    dataParam = (struct writeBatchData *) arg;
    
    fputs(dataParam->wordToWrite,dataParam->pointerFile);
    fputs(" ",dataParam->pointerFile);
    printf("thread %d mengolah kata %s\n",dataParam->threadNum,dataParam->wordToWrite);
    pthread_mutex_unlock(&mutex);
}

void writeFile(int argc, char *argv[]){

    struct writeBatchData dataParamArr[argc-3];
    pthread_t thread[argc-3];
    
    char *fpath = argv[argc-1];
    FILE *fp =fopen(fpath,"a");
    if(fp==NULL) {
        perror("Error opening file: file not exists or permission denied!");
        return;
    }
    
    for(int i=0;i<(argc-3);i++){
        dataParamArr[i].threadNum=i+1;
        dataParamArr[i].wordToWrite=argv[i+2];
        dataParamArr[i].pointerFile=fp;
        pthread_create(&thread[i], NULL, writeBatch, &dataParamArr[i]);
        sleep(0.0000001);
    }
    for(int i=0;i<(argc-3);i++){
        pthread_join(thread[i],NULL);
    }
    fclose(fp);
    printf("Pesan berhasil ditulis ke dalam file \'%s\'.\n",fpath);
}

int main(int argc, char *argv[]){
    
    pthread_mutex_init(&mutex,NULL);
    if(argc<3){
        printf("More argument required!\n");
        return 1;
    }
    else{
        if(strcmp(argv[1],"read")==0) {
            readFile(argc, argv);
        }
        else if(strcmp(argv[1],"write")==0) {
            writeFile(argc, argv);
        }
        else printf("No command specified!\n");
    }   
}