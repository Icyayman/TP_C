#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct maillon maillon;
struct maillon {
    int valeur;
    maillon *suivant;
};

void push(maillon **tete, int valeur) {
    maillon *nouveau = (maillon *)malloc(sizeof(maillon));
    if(nouveau==NULL){
        printf("erreure d'allocation");
    }
    nouveau->valeur = valeur;
    nouveau->suivant = *tete;
    *tete = nouveau;
}

void pop(maillon **tete) {
    if (*tete == NULL) {
        printf("La liste est vide.\n");
        return;
    }
    maillon *temp = *tete;
    *tete = (*tete)->suivant;
    free(temp);
}

void afficher(maillon *tete) {
    maillon *courant = tete;
    while (courant != NULL) {
        printf("%d ", courant->valeur);
        courant = courant->suivant;
    }
}

int taille(maillon *tete) {
    int taille = 0;
    maillon *courant = tete;
    while (courant != NULL) {
        taille++;
        courant = courant->suivant;
    }
    return taille;
}

void insererM(maillon **tete,int pos, int val){
    maillon *nouveau = (maillon *)malloc(sizeof(maillon));
    if(nouveau==NULL){
        printf("erreure d'allocation");
    }
    nouveau->valeur = val;
    nouveau->suivant = NULL;
    if(pos==0){
        nouveau->suivant=*tete;
        *tete=nouveau;
        return;
    }
    maillon *temp=*tete;
    for(int i=0;i<pos-1;i++){
        temp=temp->suivant;
    }
    nouveau->suivant=temp->suivant;
    temp->suivant=nouveau;
}

void peek(maillon *tete) {
    if (tete == NULL) {
        printf("La liste est vide.\n");
        return;
    }
    printf("La valeur du premier element est: %d\n", tete->valeur);
}

int main() {
    maillon *tete = NULL;
    int choix, valeur;

    do {
        printf("\nMenu:\n");
        printf("1. Ajouter un element\n");
        printf("2. Supprimer un element\n");
        printf("3. Afficher la liste\n");
        printf("4. Quitter\n");
        printf("Choisissez une option: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Entrez la valeur a ajouter: ");
                scanf("%d", &valeur);
                push(&tete, valeur);
                break;
            case 2:
                pop(&tete);
                afficher(tete);
                printf("\n");
                break;
            case 3:
                afficher(tete);
                break;
            case 4:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 4);
    return 0;
}