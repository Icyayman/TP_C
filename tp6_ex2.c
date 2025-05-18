#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    FILE *fichier = fopen("C:\\Users\\HP\\Desktop\\c.txt", "r");
    if(fichier == NULL){
        printf("Erreur d'ouverture du fichier\n");
        return 1;
    }
    char nom[20];
    int age;
    fscanf(fichier, "Nom: %s\n", &nom);
    fscanf(fichier, "Age: %d\n", &age);
    printf("Nom: %s\n", nom);
    printf("Age: %d\n", age);
    fclose(fichier);
    return 0;
}