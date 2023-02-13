#include<stdio.h>
#include<stdlib.h>

#define BUFF_LIM 8000000 //Set limit ukuran buffer/bytes yang dibaca agar tidak terjadi segmentation fault

int main(int argc, char *argv[]){
    FILE *fs, *ft;
    if(argc != 4){
        printf("usage : copy_binary [arg1] [arg2] [arg3]\n");
        printf("[arg1] : Source file to  copy\n");
        printf("[arg2] : Destination of copied file\n");
        printf("[arg3] : Buffer size / Bytes size to read per operations\n");
        printf("Invalid number of arguments\n");
        return 1;
    }
    fs=fopen(argv[1],"rb");
    if(fs==NULL){
        printf("Can't locate the source file.\n");
        return 1;
    }
    ft=fopen(argv[2],"wb");
    if(ft==NULL){
        printf("Can't open the target file.\n");
        fclose(fs);
        return 1;
    }

    long long BUFF_SIZE = atoi(argv[3]); //Convert string pada argument menjadi integer
    
    if(BUFF_SIZE <= 0 || BUFF_SIZE > BUFF_LIM){ //Cek nilai buffer pada argument agar tidak terjadi segmentation fault
        printf("Invalid buffer size. Using default value (8192)\n"); //Gunakan ukuran default buffer yaitu 8192 
        BUFF_SIZE = 8192;
    }

    fseek(fs,0,SEEK_END); //Fungsi untuk memindahkan indikator posisi stream pada bagian terakhir file 
    long long sz = ftell(fs); //Fungsi untuk mengetahui posisi stream pada file. Digunakan untuk mengetahui ukuran file
    rewind(fs); //Fungsi untuk mengembalikan indikator posisi stream ke bagian awal file 
    unsigned char buffer[BUFF_SIZE];
    
    //Block program copy file
    while(fread(buffer,sizeof(buffer),1,fs) > 0 && sz >= sizeof(buffer)){
        fwrite(buffer,sizeof(buffer),1,ft);
        sz-=sizeof(buffer);
    }
    //Copy bytes yang tersisa pada bagian akhir file
    if(sz>0){
        fread(buffer,sz,1,fs);
        fwrite(buffer,sz,1,ft);
    }

    printf("Content from %s copied to %s\n", argv[1], argv[2]);
    fclose(fs);
    fclose(ft);
    return 0;
}