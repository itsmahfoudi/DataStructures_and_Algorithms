#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define LONGUEUR_NOM 256
#define  TAILLE_TABLE 10

typedef struct
{
    char nom[LONGUEUR_NOM];
    int age;
} etudiant;

etudiant *table_hachage[TAILLE_TABLE];

/*-------------------*/

int my_strlen(char str[])
{
    int i;
    i=0;
    while(str[i]!='\0')
        ++i;
    return i;
}
/*-------------------*/

unsigned int hash(char *nom)
{
    int length=my_strlen(nom);
    unsigned int hash_valeur=0;
    for(int i=0; i<length; i++)
    {
        hash_valeur+=nom[i];
        hash_valeur=(hash_valeur*nom[i])%TAILLE_TABLE;
    }
    return hash_valeur;
}
void init_hash_table()
{
    for(int i=0; i<TAILLE_TABLE; i++)
    {
        table_hachage[i]=NULL;
    }

}
void imprimer_table()
{
    printf("Debut\n");
    for(int i=0; i<TAILLE_TABLE; i++)
    {
        if(table_hachage[i]==NULL)
        {
            printf("\t%i\t---\n",i);
        }
        else
        {
            printf("\t%i\t%s---\n",i,table_hachage[i]->nom);
        }
    }
    printf("Fin\n");
}
bool table_hachage_insertion(etudiant *p)
{
    if(p==NULL)
        return false;
    int index=hash(p->nom);
    for(int i=0; i<LONGUEUR_NOM; i++)
    {
        int choix=(i+index)%LONGUEUR_NOM;
        if(table_hachage[choix]==NULL)
        {
            table_hachage[choix]=p;
            return true;
        }
    }
    return false;
}
// rechercher un etudiant dans la table
etudiant *table_Hachage_Recherche(char *nom)
{
    int index=hash(nom);
    for(int i=0; i<LONGUEUR_NOM; i++)
    {
        int choix=(i+index)%LONGUEUR_NOM;
        if(table_hachage[choix]!=NULL)
            if(strncmp(table_hachage[index]->nom,nom,LONGUEUR_NOM)==0)
        {
            return table_hachage[index];
        }

    }
      return NULL;

}
int main()
{
    init_hash_table();
    imprimer_table();
    etudiant Ahmed= {.nom="Ahmed",.age=24};
    etudiant Ali= {.nom="Ali",.age=26};
    etudiant Sara= {.nom="Sara",.age=12};
    etudiant Said= {.nom="Said",.age=17};
    etudiant Hatim= {.nom="Hatim",.age=16};
    etudiant Mounir= {.nom="Mounir",.age=19};
    etudiant Moustapha= {.nom="Moustapha",.age=18};
    etudiant Ayman= {.nom="Ayman",.age=14};
    etudiant Mohammed= {.nom="Mohammed",.age=29};
    etudiant Jaouad= {.nom="Jaouad",.age=34};

    table_hachage_insertion(&Ahmed);
    table_hachage_insertion(&Ali);
    table_hachage_insertion(&Sara);
    table_hachage_insertion(&Said);
    table_hachage_insertion(&Hatim);
    table_hachage_insertion(&Mounir);
    table_hachage_insertion(&Moustapha);
    table_hachage_insertion(&Ayman);
    table_hachage_insertion(&Mohammed);
    table_hachage_insertion(&Jaouad);

    imprimer_table();
    etudiant *temp= table_Hachage_Recherche("Rachid");
    if(temp==NULL)
    {
        printf("%s est non trouve:\n",temp->nom);
    }
    else
    {
        printf("%s est Trouve:\n",temp->nom);
    }
    temp= table_Hachage_Recherche("Hatim");
    if(temp==NULL)
    {
        printf("%s est non trouve:\n",temp->nom);
    }
    else
    {
        printf("%s est Trouve :\n",temp->nom);
    }
    return 0;
}
