#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noeud
{
    int valeur;
    struct noeud *next;
    struct noeud *prev;
} noeud;

noeud *cree(int _valeur)
{
    noeud *n = (noeud *)malloc(sizeof(noeud));
    n->valeur = _valeur;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

void affiche(noeud *debut)
{
    noeud *temp = debut;
    while (temp != NULL)
    {
        printf("%d ", temp->valeur);
        temp = temp->next;
    }
}

void afficheIverse(noeud *debut)
{
    noeud *temp = debut;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->valeur);
        temp = temp->prev;
    }
}

void ajouteDebut(noeud **debut, int valeur)
{
    noeud *n = cree(valeur);
    n->next = *debut;
    if (*debut != NULL)
    {
        (*debut)->prev = n;
    }
    *debut = n;
}

void ajouterfin(noeud **debut, int valeur)
{
    noeud *n = cree(valeur);
    noeud *tmp = *debut;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    n->prev = NULL;
    tmp->next = n;
}

int taille(noeud *debut)
{
    noeud *tmp = debut;
    int cont = 0;
    while (tmp != NULL)
    {
        cont++;
        tmp = tmp->next;
    }
    printf("la taille de la liste est %d", cont);
}

noeud *insertion(noeud *debut, int pos, int _valeur)
{
    noeud *n = cree(_valeur);
    noeud *temp = debut;
    if (pos < 1 || pos > taille(debut) + 1)
    {
        printf("position non valide");
    }
    else
    {
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        n->next = temp->next;
        n->prev = temp;
        if (temp->next != NULL)
        {
            temp->next->prev = n;
        }
        temp->next = n;
    }
    return debut;
}

noeud *rechercher(noeud *debut, int _valeur)
{
    noeud *temp = debut;
    while (temp != NULL)
    {
        if (temp->valeur == _valeur)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

noeud *suppressionD(noeud *debut)
{
    noeud *temp = debut;
    if (debut == NULL)
    {
        printf("la liste est vide");
    }
    debut = debut->next;
    if (debut != NULL)
    {
        debut->prev = NULL;
    }
    free(temp);
    return debut;
}

noeud *suppressionF(noeud *debut)
{
    noeud *temp = debut;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = NULL;
    }
    else
    {
        debut = NULL;
    }
    free(temp);
    return debut;
}

noeud *suppressionP(noeud *debut, int pos)
{
    noeud *temp = debut;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        debut = temp->next;
    }
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    else
    {
        temp->prev->next = NULL;
    }
    free(temp);
    return debut;
}

noeud *modiferD(noeud *debut, int _valeur)
{
    noeud *temp = debut;
    temp->valeur = _valeur;
    return debut;
}

noeud *modifierF(noeud *debut, int _valeur)
{
    noeud *temp = debut;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->valeur = _valeur;
    return debut;
}

noeud *modiferP(noeud *debut, int _valeur, int pos)
{
    noeud *temp = debut;
    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;
    }
    temp->valeur = _valeur;
    return debut;
}

noeud *tri(noeud *debut)
{
    noeud *temp = debut;
    noeud *temp2 = NULL;
    int i, j, t;
    int n = taille(debut);
    for (i = 0; i < n - 1; i++)
    {
        temp = debut;
        for (j = 0; j < n - i - 1; j++)
        {
            if (temp->valeur > temp->next->valeur)
            {
                t = temp->valeur;
                temp->valeur = temp->next->valeur;
                temp->next->valeur = t;
            }
            temp = temp->next;
        }
    }
    return debut;
}

int main()
{
    noeud *debut = NULL;
    noeud *A = cree(30);
    noeud *B = cree(10);
    noeud *C = cree(20);

    debut = A;
    A->next = B;
    B->prev = A;
    B->next = C;
    C->prev = B;

    printf("la liste est : ");
    affiche(debut);
    printf("\n");
    printf("la liste inverse est : ");
    afficheIverse(debut);
    printf("\n");
    printf("la taille de la liste est : ");
    taille(debut);
    printf("\n");
    printf("ajouter un element au debut de la liste : ");
    ajouteDebut(&debut, 5);
    affiche(debut);
    printf("\n");
    printf("ajouter un element a la fin de la liste : ");
    ajouterfin(&debut, 15);
    affiche(debut);
    printf("\n");
    printf("ajouter un element a une position donnee : ");
    int pos;
    printf("donner la position : ");
    scanf("%d", &pos);
    int valeur;
    printf("donner la valeur : ");
    scanf("%d", &valeur);
    debut = insertion(debut, pos, valeur);
    affiche(debut);
    printf("\n");
    printf("rechercher un element : ");
    int valeurR;
    printf("donner la valeur : ");
    scanf("%d", &valeurR);
    noeud *resultat = rechercher(debut, valeurR);
    if (resultat != NULL)
    {
        printf("l'element %d est trouve\n", resultat->valeur);
    }
    else
    {
        printf("l'element n'est pas trouve\n");
    }
    printf("supprimer le premier element de la liste : ");
    debut = suppressionD(debut);
    affiche(debut);
    printf("\n");
    printf("supprimer le dernier element de la liste : ");
    debut = suppressionF(debut);
    affiche(debut);
    printf("\n");
    printf("supprimer un element a une position donnee : ");
    int posS;
    printf("donner la position : ");
    scanf("%d", &posS);
    debut = suppressionP(debut, posS);
    affiche(debut);
    printf("\n");
    printf("modifier le premier element de la liste : ");
    int valeurM;
    printf("donner la valeur : ");
    scanf("%d", &valeurM);
    debut = modiferD(debut, valeurM);
    affiche(debut);
    printf("\n");
    printf("modifier le dernier element de la liste : ");
    int valeurM2;
    printf("donner la valeur : ");
    scanf("%d", &valeurM2);
    debut = modifierF(debut, valeurM2);
    affiche(debut);
    printf("\n");
    printf("modifier un element a une position donnee : ");
    int posM;
    printf("donner la position : ");
    scanf("%d", &posM);
    int valeurM3;
    printf("donner la valeur : ");
    scanf("%d", &valeurM3);
    debut = modiferP(debut, valeurM3, posM);
    affiche(debut);
    printf("\n");
    printf("trier la liste : ");
    debut = tri(debut);
    affiche(debut);
    printf("\n");
    printf("la liste inverse est : ");
    afficheIverse(debut);
    printf("\n");
    return 0;
}