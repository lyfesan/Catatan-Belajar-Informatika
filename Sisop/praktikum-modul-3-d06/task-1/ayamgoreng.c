

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//
typedef struct 
{
  
  char name[50];
  char role[50];
  char type[50];
  int year;
  char hp[50];
  char physicalAttack[50];
  char attackSpeed[50];
  char mana[50];
  char manaRegen[50];

} Hero;


void extract(char file[]){
    char cmd[100];
    snprintf(cmd, sizeof(cmd), "unzip %s", file);
    system(cmd);

}


double calculateSkillPoints(Hero hero) {
    
    if (strstr(hero.role, "TANK") != NULL) {
        return atof(hero.hp);
    } else if (strstr(hero.role, "ASSASSIN") != NULL) {
        return atof(hero.physicalAttack);
    } else if (strstr(hero.role, "FIGHTER") != NULL) {
        return atof(hero.hp) + atof(hero.physicalAttack);
    } else if (strstr(hero.role, "MM") != NULL) {
        return atof(hero.physicalAttack) * atof(hero.attackSpeed);
    } else if (strstr(hero.role, "MAGE") != NULL) {
        return atof(hero.mana) / atof(hero.manaRegen);
    } else if (strstr(hero.role, "SUPPORT") != NULL) {
        return atof(hero.manaRegen) + atof(hero.hp);
    } else {
        return -1; // Role tidak valid
    }
}

void findBestHeroes(Hero *heroes, int numHeroes) {
    // Iterasi untuk setiap role
    char roles[6][20] = {"TANK", "ASSASSIN", "FIGHTER", "MM", "MAGE", "SUPPORT"};
    for (int i = 0; i < 6; i++) {
        int maxSkillPoints = 0;
        char bestHero[50];

        // Iterasi untuk setiap hero dengan role tertentu
        for (int j = 0; j < numHeroes; j++) {
            if (strcmp(heroes[j].role, roles[i]) == 0) {
                int skillPoints = calculateSkillPoints(heroes[j]);
                if (skillPoints > maxSkillPoints) {
                    maxSkillPoints = skillPoints;
                    strcpy(bestHero, heroes[j].name);
                }
            }
        }

        // Menampilkan hero terbaik dari setiap role
        printf("Hero terbaik untuk role %s adalah %s dengan skillpoint %d.\n", roles[i], bestHero, maxSkillPoints);
    }
}

int main(int argc, char *argv[])
{
  // file pointer variable for accessing the file
FILE *file;
char header[100];
int numHeroes;

// NUMBER 1A
int dataset = system("kaggle datasets download -d irwansyah10010/mobilelegend");

 if (dataset == -1) {
   printf("Dataset gagal dieksekusi.\n");
   return 1;
 } else if (dataset != 0) {

   printf("Dataset dieksekusi dengan status: %d\n.", dataset);
   return 1;
 }

extract("mobilelegend.zip");
  
  
  file = fopen("identitas.csv", "r"); 
  // if the file failed to open, exit with an error message and status
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }

    int count = 0;
    char buffer[200];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        count++;
    }
    rewind(file);
  
  // array of structs for storing the Hero data from the file
    Hero *heroes = (Hero*)malloc(count * sizeof(Hero));

  
  // read will be used to ensure each line/record is read correctly
  int read = 0;
  
  // records will keep track of the number of Student records read from the file
  int records = 0;
  fgets(header, sizeof(header), file);

  // read all records from the file and store them into the students array
  do 
  {
   
    read = fscanf(file,
                  "%49[^;];%49[^;];%49[^;];%d\n",
                  heroes[records].name, 
                  heroes[records].role,
                  heroes[records].type,
                  &heroes[records].year); 
    
    if (read == 4) records++;
   
    
    
    if (read != 4 && !feof(file))
    {
      printf("File format incorrect.\n");
      return 1;
    }
    

    if (ferror(file))
    {
      printf("Error reading file.\n");
      return 1;
    }

  } while (!feof(file));

  // close the file as we are done working with it
  fclose(file);
  numHeroes = records;
  records = 0;

  file = fopen("atribut-hero.csv", "r");
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }

    int read2 = 0;
  // Lewati baris header
    char header2[500];
    fgets(header2, sizeof(header2), file);

  do 
  {
   
    read2 = fscanf(file,
                  "%*[^;];%49[^;];%*[^;];%49[^;];%*[^;];%49[^;];%*[^;];%49[^;];%49[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^;];%*[^\n]\n",
                  heroes[records].hp,
                  heroes[records].physicalAttack,
                  heroes[records].attackSpeed,
                  heroes[records].mana,
                  heroes[records].manaRegen); 
                   

    if (read2 == 5) records++;
   
    
    
    if (read2 != 5 && !feof(file))
    {
      printf("File2 format incorrect.\n");
      return 1;
    }
    
    // if there was an error reading from the file exit with an error message 
    // and status
    if (ferror(file))
    {
      printf("Error reading file2.\n");
      return 1;
    }

  } while (!feof(file));

  // close the file as we are done working with it
  fclose(file);
  


  if (argc == 1) {
        findBestHeroes(heroes, numHeroes);
    }
    // Jika ada argumen yang diberikan, mencari hero terbaik untuk role tertentu
    else if (argc == 2) {
        char *role = argv[1];
        int found = 0;

        // Iterasi untuk setiap hero dan mencari hero terbaik dari role yang diberikan
        for (int i = 0; i < numHeroes; i++) {
            if (strcmp(heroes[i].role, role) == 0) {
                printf("Hero terbaik untuk role %s adalah %s dengan skillpoints %.2lf.\n", role, heroes[i].name, calculateSkillPoints(heroes[i]));
                found = 1;
                break;
            }
        }

        // Jika tidak ada hero yang ditemukan untuk role yang diberikan
        if (!found) {
            printf("Role %s tidak ditemukan.\n", role);
        }
    }
    // Jika jumlah argumen yang diberikan tidak valid
    else {
        printf("Penggunaan: ./ayamgoreng [role]\n");
        printf("Contoh: ./ayamgoreng Tank\n");
    }

    // Membebaskan memori yang dialokasikan
    free(heroes);

  return 0;
}
