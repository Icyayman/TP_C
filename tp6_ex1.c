#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char nom[20];
    int age;

    FILE *fichier = fopen("C:\\Users\\HP\\Desktop\\c.txt", "w");

    if(fichier == NULL){
        printf("Erreur d'ouverture du fichier\n");
        return 1;
    }
    printf("Entrez votre nom: ");
    scanf("%s", &nom);
    printf("Entrez votre age: ");
    scanf("%d", &age);

    fprintf(fichier, "Nom: %s\n", nom);
    fprintf(fichier, "Age: %d\n", age);
    fclose(fichier);

return 0;
}