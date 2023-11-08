#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct etudiant etudiant;
struct etudiant {
	char nom[20];
    int age;
	struct etudiant *suivant;
};
void insererfin(etudiant **tete, char nvnom[20],int nvage)
{
	etudiant *nvetd = (etudiant*) malloc(sizeof(etudiant));
	if (nvetd == NULL)
	{
		printf("la memoire est insuffisante\n");
	}
	else
	{
		nvetd->age = nvage;
        strcpy(nvetd->nom,nvnom);
		nvetd->suivant = NULL;
		if ( *tete == NULL)
		{
			*tete = nvetd;
		}
		else
		{
			etudiant *temp = *tete;
			while (temp->suivant != NULL)
			{
				temp = temp->suivant;
			}
			temp->suivant = nvetd;
		}
	}
}
etudiant *dernieretudiant(etudiant *tete)
{
	etudiant *temp = tete;
	while (temp != NULL && temp->suivant != NULL)
	{
		temp = temp->suivant;
	}
	return temp;
}
void afficherliste(etudiant *tete)
{
	if (tete == NULL)
	{
		printf("votre liste est vide.");
		return;
	}
	etudiant *temp = tete;
	printf("\nvotre liste est :");
	while (temp != NULL)
	{
		printf("\nle nom est : %s, l'age est %d",temp->nom,temp->age );
		temp = temp->suivant;
	}
}
void permuter(etudiant *a,etudiant *b){
  if(a == NULL || b == NULL){
    printf("\nle tri ne peut pas etre realiser!!!");
  }
  else{
    char nomtmp[20];
    int agetmp;
    strcpy(nomtmp,a->nom);
    strcpy(a->nom,b->nom);
    strcpy(b->nom,nomtmp);
    agetmp = a->age;
    a->age = b->age;
    b->age = agetmp;
  }
}
etudiant *partition(etudiant *premier, etudiant *dernier)
{
	etudiant *pivot = premier;
	etudiant *front = premier;
	int temp = 0;
	while (front != NULL && front != dernier)
	{
		if (front->age < dernier->age)
		{
			pivot = premier;
			permuter(front,dernier);
            premier = premier->suivant;
		}
		front = front->suivant;
	}
	permuter(premier,dernier);
	return pivot;
}
void tri_rapide(etudiant *premier, etudiant *dernier)
{
	if (premier == dernier)
	{
		return;
	}
    
       etudiant *pivot = partition(premier, dernier);
	   if (pivot != NULL && pivot->suivant != NULL)
	   {
		tri_rapide(pivot->suivant, dernier);
	   }
	   if (pivot != NULL && dernier != pivot)
	   {
		tri_rapide(premier, pivot);
	   } 
	
}
int main()
{
	etudiant *tete = NULL;
	insererfin( &tete,"AYOUB", 19);
	insererfin( &tete,"AMINE", 20);
    insererfin( &tete,"WALID", 9);
    insererfin( &tete,"YOUSSEF", 21);
    insererfin( &tete,"ANAS", 18);
	printf("\n Avant le tri : ");
	afficherliste(tete);
	tri_rapide(tete, dernieretudiant(tete));
	printf("\n Apres le tri : ");
	afficherliste(tete);
	return 0;
}
