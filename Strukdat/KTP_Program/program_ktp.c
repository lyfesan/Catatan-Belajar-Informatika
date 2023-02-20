#include<stdio.h>
#include<string.h>
#include<stdbool.h>

typedef struct {
    char nik[16];
    char nama[100];
    char tempat_tanggal_lahir[60];
    bool jenis_kelamin;
    int golongan_darah;
} DATA_KTP;

void read_data(char *argv[]);
void input_data(char *argv[]);
void find_data(char *argv[]);
void rm_data(char *argv[]);

int main(int argc, char *argv[]){
    
    int c;

    if(argc!=2){
        printf("usage : KTP_Program [arg1]\n");
        printf("[arg1] : Data source file\n");
        printf("Invalid number of arguments\n");
        return 1;
    }

    while(1){
        printf("Program data KTP\nMenu :\n");
        printf("1. Input data KTP\n2. Tampilkan data KTP\n3. Cari data KTP\n4. Hapus data KTP berdasarkan NIK\n5. Keluar\n");
        printf("Silahkan pilih menu (1/2/3/4/5) : ");
        scanf("%d", &c);
        getchar();
        if(c==1) input_data(argv);
        else if(c==2) read_data(argv);
        else if(c==3) find_data(argv);
        else if(c==4) rm_data(argv);
        else if(c==5){printf("Terima kasih telah menggunakan program ini...\n");return 0;}
        else printf("Menu invalid"); 
    }
}

void input_data(char *argv[]){
    FILE *file = fopen(argv[1],"wb");
    if(file == NULL){printf("Gagal membuka file\n"); return;}
    DATA_KTP data_ktp;
    char y;
    fseek(file,0,SEEK_END);
    do{
        printf("Masukkan NIK : ");
        scanf("%s",data_ktp.nik);
        getchar();
        printf("Masukkan nama : ");
        fgets(data_ktp.nama,100,stdin);

        printf("Masukkan tempat, tanggal lahir (format : [Tempat],[DD-MM-YYYY]) : ");
        fgets(data_ktp.tempat_tanggal_lahir,60,stdin);

        printf("Masukkan jenis kelamin (0 untuk laki-laki, 1 untuk perempuan) : ");
        scanf("%d", &data_ktp.jenis_kelamin);
        getchar();

        printf("Masukkan golongan darah (A,B,AB,O) : ");
        char tmp[4];
        scanf("%s", tmp);
        if(strcmp(tmp,"A")) data_ktp.golongan_darah = 0;
        else if(strcmp(tmp,"B")) data_ktp.golongan_darah = 1;
        else if(strcmp(tmp,"AB")) data_ktp.golongan_darah = 2;
        else if(strcmp(tmp,"O")) data_ktp.golongan_darah = 3;
        getchar();
        fwrite(&data_ktp,sizeof(data_ktp),1,file);
        printf("Input data berhasil.....\nApakah anda mau melakukan input data lagi? (y/n) : ");
        scanf("%c", &y);
    }while(y=='y'); 
    fclose(file);
}

void read_data(char *argv[]){
    FILE *file = fopen(argv[1], "rb");
    DATA_KTP data;
    if (file == NULL){
        printf("Gagal membuka file\n");
        return;
    }
    bool y=false;
    fseek(file,0,SEEK_SET);
    //system("clear");
    printf("\nMenampilkan data KTP...\n\n");
    while(fread(&data,sizeof(data), 1, file)){
        y=true;
        printf("NIK : %s\n",data.nik);
        printf("Nama : %s",data.nama);
        printf("Tempat, tanggal lahir : %s",data.tempat_tanggal_lahir);
        printf("Jenis kelamin : ");data.jenis_kelamin==1 ? printf("Perempuan\n") : printf("Laki-laki\n");
        printf("Golongan darah : ");
        //0 A, 1 B, 2 AB, 3 O
        if(data.golongan_darah == 0) printf("A");
        else if(data.golongan_darah == 1) printf("B");
        else if(data.golongan_darah == 2) printf("AB");
        else if(data.golongan_darah == 3) printf("O");
        printf("\n\n");
    }
    if(y==false) printf("\nTidak ada data yang ditampilkan.....\n\n");
    fclose(file);
}

void find_data(char *argv[]){
    FILE *file = fopen(argv[1],"rb");
    if(file == NULL){printf("Gagal membuka file\n"); return;}
    DATA_KTP data;
    int c,buf;
    char tmp[100];
    fseek(file,0,SEEK_SET);
    printf("\nPencarian Data KTP\n");
    printf("1. Cari berdasarkan NIK\n");
    printf("2. Cari berdasarkan nama\n");
    printf("3. Cari berdasarkan jenis kelamin\n");
    printf("4. Cari berdasarkan golongan darah\n");
    printf("Pilih menu : ");
    scanf("%d",&c);
    if(c==1){
        bool y = false;
        printf("Masukkan NIK yang dicari : ");
        scanf("%s",tmp);
        printf("Menampilkan data yang cocok\n");
        while(fread(&data,sizeof(data),1,file)){
            if(!strcmp(tmp,data.nik)){
                y=true;
                printf("NIK : %s\n",data.nik);
                printf("Nama : %s",data.nama);
                printf("Tempat, tanggal lahir : %s",data.tempat_tanggal_lahir);
                printf("Jenis kelamin : ");data.jenis_kelamin==1 ? printf("Perempuan\n") : printf("Laki-laki\n");
                printf("Golongan darah : ");
                //0 A, 1 B, 2 AB, 3 O
                if(data.golongan_darah == 0) printf("A");
                else if(data.golongan_darah == 1) printf("B");
                else if(data.golongan_darah == 2) printf("AB");
                else if(data.golongan_darah == 3) printf("O");
                printf("\n");
            }
        }
        if(!y){printf("Tidak ditemukan data yang sesuai....");}
        printf("\n");
    }
    else if(c==2){
        bool y = false;
        printf("Masukkan nama yang dicari : ");
        scanf("%s",tmp);
        printf("Menampilkan data yang cocok\n");
        while(fread(&data,sizeof(data),1,file)){
            if(!strcmp(tmp,data.nama)){
                y=true;
                printf("NIK : %s\n",data.nik);
                printf("Nama : %s",data.nama);
                printf("Tempat, tanggal lahir : %s",data.tempat_tanggal_lahir);
                printf("Jenis kelamin : ");data.jenis_kelamin==1 ? printf("Perempuan\n") : printf("Laki-laki\n");
                printf("Golongan darah : ");
                //0 A, 1 B, 2 AB, 3 O
                if(data.golongan_darah == 0) printf("A");
                else if(data.golongan_darah == 1) printf("B");
                else if(data.golongan_darah == 2) printf("AB");
                else if(data.golongan_darah == 3) printf("O");
                printf("\n");
            }
        }
        if(!y){printf("Tidak ditemukan data yang sesuai....");}
        printf("\n");
    }
    else if(c==3){
        bool y = false;
        printf("Masukkan jenis kelamin yang dicari (0 untuk laki-laki, 1 untuk perempuan) : ");
        scanf("%d",&buf);
        printf("Menampilkan data yang cocok\n");
        while(fread(&data,sizeof(data),1,file)){
            if(buf==data.jenis_kelamin){
                y=true;
                printf("NIK : %s\n",data.nik);
                printf("Nama : %s",data.nama);
                printf("Tempat, tanggal lahir : %s",data.tempat_tanggal_lahir);
                printf("Jenis kelamin : ");data.jenis_kelamin==1 ? printf("Perempuan\n") : printf("Laki-laki\n");
                printf("Golongan darah : ");
                //0 A, 1 B, 2 AB, 3 O
                if(data.golongan_darah == 0) printf("A");
                else if(data.golongan_darah == 1) printf("B");
                else if(data.golongan_darah == 2) printf("AB");
                else if(data.golongan_darah == 3) printf("O");
                printf("\n");
            }
        }
        if(!y){printf("Tidak ditemukan data yang sesuai....");}
        printf("\n");
    }
    else if(c==4){
        bool y = false;
        printf("Masukkan golongan darah yang dicari : ");
        scanf("%s",tmp);
        if(strcmp(tmp,"A")) buf = 0;
        else if(strcmp(tmp,"B")) buf = 1;
        else if(strcmp(tmp,"AB")) buf = 2;
        else if(strcmp(tmp,"O")) buf = 3;
        printf("Menampilkan data yang cocok\n\n");
        while(fread(&data,sizeof(data),1,file)){
            if(buf==data.golongan_darah){
                y=true;
                printf("NIK : %s\n",data.nik);
                printf("Nama : %s",data.nama);
                printf("Tempat, tanggal lahir : %s",data.tempat_tanggal_lahir);
                printf("Jenis kelamin : ");data.jenis_kelamin==1 ? printf("Perempuan\n") : printf("Laki-laki\n");
                printf("Golongan darah : ");
                if(data.golongan_darah == 0) printf("A");
                else if(data.golongan_darah == 1) printf("B");
                else if(data.golongan_darah == 2) printf("AB");
                else if(data.golongan_darah == 3) printf("O");
                printf("\n");
            }
        }
        if(!y){printf("Tidak ditemukan data yang sesuai....");}
        printf("\n");
    }
    else printf("Input invalid\n");
}

void rm_data(char *argv[]){
    FILE *fs = fopen(argv[1],"rb"),*ftmp = fopen("ftemp.temmp","wb");
    DATA_KTP data;
    char tmp[100];
    if(fs == NULL && ftmp == NULL){printf("Gagal membuka file\n");return;}
    fseek(fs,0,SEEK_SET);
    fseek(ftmp,0,SEEK_SET);
    printf("Masukkan data NIK yang akan dihapus : ");
    scanf("%s",tmp);
    while(fread(&data,sizeof(data), 1, fs)){
        if(strcmp(tmp,data.nik)){
            fwrite(&data,sizeof(data),1,ftmp);
        }
    }
    fclose(fs);
    fclose(ftmp);
    if(remove(argv[1])==0 && rename("ftemp.temmp",argv[1])==0) printf("Data berhasil dihapus\n");
    else printf("Gagal menghapus data....\n");
       
}