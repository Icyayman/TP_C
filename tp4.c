#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Etudiant
{
    int id;
    char nom[50];
    float moyenne;
    struct Etudiant *suivant;
    struct Etudiant *precedent;
} Etudiant;

Etudiant *creer_etudiant()
{
    Etudiant *p = (Etudiant *)malloc(sizeof(Etudiant));
    printf("ID: ");
    scanf("%d", p->id);
    printf("Nom: ");
    scanf("%s", p->nom);
    printf("Moyenne: ");
    scanf("%f", &p->moyenne);

    p->suivant = NULL;
    p->precedent = NULL;
    return p;
}

int longueur(Etudiant *tete)
{
    int s = 0;
    if (tete != NULL)
    {
        while (tete != NULL)
        {
            s++;
            tete = tete->suivant;
        }
    }
    return s;
}

Etudiant *ajouter_position(Etudiant *tete, Etudiant *nouveau, int position)
{
    if (position == 0 || tete == NULL)
    {
        nouveau->suivant = tete;
        if (tete)
        {
            tete->precedent = nouveau;
        }
        return nouveau;
    }

    Etudiant *tmp = tete;
    int s = 0;
    while (tmp != NULL && s < position - 1)
    {
        tmp = tmp->suivant;
        s++;
    }

    if (tmp != NULL)
    {
        nouveau->suivant = tmp->suivant;
        if (tmp->suivant)
        {
            tmp->suivant->precedent = nouveau;
        }

        tmp->suivant = nouveau;
        nouveau->precedent = tmp;
    }
    return tete;
}

void afficher_liste(Etudiant *tete)
{
    Etudiant *tmp = tete;
    while (tmp != NULL)
    {
        printf("ID: %d, Nom: %s, Moyenne: %.2f\n", tmp->id, tmp->nom, tmp->moyenne);
        tmp = tmp->suivant;
    }
}
Etudiant *modifier_moyenne(Etudiant *tete, int position, float nouvelle_moyenne)
{
    Etudiant *tmp = tete;
    int s = 0;
    while (tmp != NULL && s < position)
    {
        tmp = tmp->suivant;
        s++;
    }
    if (tmp != NULL)
        tmp->moyenne = nouvelle_moyenne;

    return tete;
}
Etudiant *supprimer_position(Etudiant *tete, int position)
{
    Etudiant *tmp = tete;
    int s = 0;

    while (tmp != NULL && s < position)
    {
        tmp = tmp->suivant;
        s++;
    }

    if (tmp != NULL)
    {
        if (tmp->precedent != NULL)
        {
            tmp->precedent->suivant = tmp->suivant;
        }
        else
        {
            tete = tmp->suivant;
        }
        if (tmp->suivant != NULL)
        {
            tmp->suivant->precedent = tmp->precedent;
        }

        free(tmp);
        return tete;
    }
}
Etudiant *derniere_cellule(Etudiant *tete)
{
    Etudiant *tmp = tete;
    if (tete != NULL)
    {
        while (tmp->suivant != NULL)
        {
            tmp = tmp->suivant;
        }
    }
    return tmp;
}
void afficher_liste_inverse(Etudiant *dernier)
{
    Etudiant *tmp = dernier;

    if (dernier != NULL)
    {
        while (tmp->suivant != NULL)
        {
            tmp = tmp->suivant;
        }
        while (tmp != NULL)
        {
            printf("ID: %d, Nom: %s, Moyenne: %.2f\n", tmp->id, tmp->nom, tmp->moyenne);
            tmp = tmp->precedent;
        }
    }
}
int chercher_etudiant(Etudiant *tete, int id)
{
    Etudiant *tmp = tete;
    while (tmp != NULL)
    {
        if (tmp->id == id)
        {
            return 1;
        }
        tmp = tmp->suivant;
    }
    return 0;
}
Etudiant *tri(Etudiant *tete)
{
    if (tete)
    {

        int p;
        Etudiant *tmp;
        Etudiant *f = NULL;

        do
        {
            p = 0;
            tmp = tete;

            while (tmp->suivant != f)
            {
                if (tmp->moyenne > tmp->suivant->moyenne)
                {

                    int id_tmp = tmp->id;
                    char nom_tmp[50];
                    strcpy(nom_tmp, tmp->nom);
                    float moy_tmp = tmp->moyenne;

                    tmp->id = tmp->suivant->id;
                    strcpy(tmp->nom, tmp->suivant->nom);
                    tmp->moyenne = tmp->suivant->moyenne;

                    tmp->suivant->id = id_tmp;
                    strcpy(tmp->suivant->nom, nom_tmp);
                    tmp->suivant->moyenne = moy_tmp;

                    p = 1;
                }
                tmp = tmp->suivant;
            }
            f = tmp;
        } while (p);

        return tete;
    }
}
int main()
{
    Etudiant *tete = NULL;

    printf("Creation de 3 etudiants :\n");
    Etudiant *e1 = creer_etudiant();
    Etudiant *e2 = creer_etudiant();
    Etudiant *e3 = creer_etudiant();
    printf("ajout de chaque etudiant dans sa position:\n");
    tete = ajouter_position(tete, e1, 0);
    tete = ajouter_position(tete, e2, 1);
    tete = ajouter_position(tete, e3, 1);
    printf("\nListe des étudiants :\n");
    afficher_liste(tete);
    int len = longueur(tete);
    printf("\nLongueur de la liste : %d\n", len);
    int id_recherche;
    printf("\nEntrer l'ID à rechercher : ");
    scanf("%d", &id_recherche);
    int trouve = chercher_etudiant(tete, id_recherche);
    if (trouve == 1)
    {
        printf("Résultat de recherche : Trouve\n");
    }
    else
    {
        {
            printf("Résultat de recherche :Non trouve\n");
        }
    }

    int pos_suppr;
    printf("\nEntrer la position à supprimer : ");
    scanf("%d", &pos_suppr);
    tete = supprimer_position(tete, pos_suppr);
    printf("\nListe apres suppression :\n");
    afficher_liste(tete);

    int pos_modif;
    float nouvelle_moyenne;
    printf("\nEntrer la position à modifier : ");
    scanf("%d", &pos_modif);
    printf("Entrer la nouvelle moyenne : ");
    scanf("%f", &nouvelle_moyenne);
    tete = modifier_moyenne(tete, pos_modif, nouvelle_moyenne);

    printf("\nListe apres modification de moyenne :\n");
    afficher_liste(tete);

    tete = tri(tete);
    printf("\nListe triee par moyenne :\n");
    afficher_liste(tete);

    printf("\nAffichage en sens inverse :\n");
    Etudiant *fin = derniere_cellule(tete);
    afficher_liste_inverse(fin);

    return 0;
}