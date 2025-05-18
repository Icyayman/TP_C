#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Noeud{
    int valeur;
    struct Noeud *suivant;
} Noeud;

Noeud* front = NULL;
Noeud* rear = NULL;

void enfiler(int valeur){
    Noeud* nv = (Noeud*)malloc(sizeof(Noeud));
    if(nv == NULL){
        printf("Erreur d'allocation\n");
        return;
    }
    nv->valeur = valeur;
    nv->suivant = NULL;
    if(rear == NULL){
        front = rear = nv;
        return;
    }
    rear->suivant = nv;
    rear = nv;
}

void defiler(){
    if(front == NULL){
        printf("La file est vide\n");
        return;
    }
    Noeud* temp = front;
    front = front->suivant;
    if(front == NULL){
        rear = NULL;
    }
    free(temp);
}

void afficher(Noeud * top){
    Noeud* temp = top;
    if(top == NULL){
        printf("La file est vide\n");
        return;
    }
    while(temp != NULL){
        printf("%d ", temp->valeur);
        temp = temp->suivant;
    }
    printf("\n");
}

void viderFile(){
    while(front != NULL){
        defiler();
    }
}
int main(){
    int choix, valeur;
    do{
        printf("1. Enfiler\n2. Defiler\n3. Afficher\n4. Vider la file\n5. Quitter\nChoix: ");
        scanf("%d", &choix);
        printf("\n");
        switch(choix){
            case 1:
                printf("Entrez la valeur a enfiler: ");
                scanf("%d", &valeur);
                enfiler(valeur);
                printf("\n");
                break;
            case 2:
                defiler();
                afficher(front);
                printf("\n");
                break;
            case 3:
                afficher(front);
                printf("\n");
                break;
            case 4:
                viderFile();
                break;
            case 5:
                viderFile();
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide\n");
        }
    }while(choix != 5);
    return 0;
}