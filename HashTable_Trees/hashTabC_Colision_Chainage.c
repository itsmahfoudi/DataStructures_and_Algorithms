#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define size 11
#define LONGUEUR_NOM 256

// 1)-La structure Eleve:

typedef struct Eleve Eleve;
struct Eleve
{
    char nom[LONGUEUR_NOM];
    Eleve *suivant;
};

// La declaration du table d'hachage:
Eleve *TH[size];

// 2)- La fonction d'hachage:

int Hash(char *nom)
{
    int i,H=0;
    for(i=0; i<strlen(nom); i++)//La strlen() : fonction en C  utilis�e pour calculer la longueur d'une cha�ne
    //la fonction renvoie la longueur de la cha�ne qui lui est pass�e.
    {
        H+=nom[i];
    }
    return H%size;
}

// 3)-Initialisation de la Table d'hachage:
void initialiser()
{
    int i;
    for(i=0; i<size; i++)
    {
        TH[i]=NULL;
    }
}

// 4)-Remplissage de la Table d'hachage:
// Methode 1:
void Insertion(int key,const char* p)
{
    /* Pour g�rer les collisions on va utiliser la m�thode
    du chainnage,s'il y a deux noms qui ont le m�me indice
    renvoy� par la fonction de hachage on va les stocker dans
    une liste chain�e. */
    Eleve* E= (Eleve*)malloc(sizeof(Eleve));
    if (E== NULL)
    {
        return;
    }

    strcpy(E->nom, p);//La strcpy()fonction renvoie �galement la cha�ne copi�e.
    E->suivant = NULL;
    if (TH[key] == NULL)
    {
        TH[key] = E;
    }
    //v�rifier l'insertion � la queue
    else
    {
        Eleve* predptr = TH[key];
        while (1)
        {
             if (predptr->suivant == NULL)
            {
                predptr-> suivant = E;
                break;
            }
            predptr = predptr-> suivant;
        }
    }

}
// Methode 2:
bool Ajout(Eleve *E)
{
    /*On peut �galement utiliser la m�thode d'adressage ouvert,
    on va parcourir le tableau et s'il y a une case vide on va
    la remplir par l'�l�ment en question.*/
    if(E==NULL)
        return false;
    int i,j=0,ix=Hash(E->nom);
    for(i=0; i<size; i++)
    {
        j=(i+ix)%size;
        if(TH[j]==NULL)
        {
            TH[j]=E;
            return true;
        }
    }
    return false;
}

// 5)- Affichage de la Table d'hachage:

void Afficher()
{
    int i;
    printf("\n \t Indice\t|\tEleves \t \n \n");
    for(i=0; i<size; i++)
    {
        if(TH[i]==NULL)
        {
            printf("\t %d \t|\t----\n",i);
        }
        else
        {
            printf("\t %d \t|",Hash(TH[i]->nom));
            Eleve *tmp=TH[i];
            while(tmp!=NULL)
            {
                printf("\t%s- ",tmp->nom);
                tmp=tmp->suivant;
            }
            printf("\n");
        }
    }
}
// La recherche d'un �l�ment

Eleve *Rechercher(char *nom)
{
    int index=Hash(nom);
    for(int i=0; i<size; i++)
    {
        int tr=(index+i)%size;
        if(TH[tr]!=NULL)
        { if((strncmp(TH[tr]->nom,nom,size)==0))
            return TH[tr];
        }
    }
    return NULL;
}

/*----Fonction Main------*/
int main()
{
    int i,n, hashedValue;
    char* name;
    name=(char*)malloc(30);
    printf("le nombre des etudiants ? \n");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("donnez un nom : \n");
        scanf("%s",name);
        hashedValue = Hash(name);
        Insertion(hashedValue, name);
    }
    Afficher();

    Eleve * temp=Rechercher("anass");
    if(temp==NULL)
    {
        printf("non trouve:\n");
    }
    else
    {
        printf("%s est Trouve :\n",temp->nom);
    }
}
