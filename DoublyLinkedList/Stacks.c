#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct personne personne;
struct personne{
  char nom[20];
  personne *next;
  };
typedef struct pile pile;
struct pile{
  personne *tete;
  };
pile *initialiser(){
  pile *mapile =(pile *) malloc(sizeof(mapile));
  mapile->tete = NULL;
  return mapile;
}
int vide(pile *f){
  if (f->tete == NULL)
    printf("votre pile est vide !!!\n");
  else
    printf("votre pile n'est pas vide.\n");
  return 0;
}
pile *empiler(pile *mapile, char nvnom[20]){
  personne *nv_per = (personne *)malloc(sizeof(nv_per));
  if(nv_per == NULL || mapile == NULL){
    printf("la liste n'est pas cree.");
  }
  else{
    strcpy(nv_per->nom,nvnom);
    nv_per->next = mapile->tete;
    mapile->tete = nv_per;
  }
}
pile *depiler(pile *mp){
  personne *temp = (personne*)malloc(sizeof(temp));
  temp = mp->tete;
  mp->tete = mp->tete->next;
  free(temp);
  printf("l'element est bien eliminer de la liste.\n");
  return mp;
}
int taille(pile *p){
  int i=0;
  personne *temp = (personne*)malloc(sizeof(temp));
  if (temp == NULL){
  	printf("la memoire n'est pas allouee.");
  }
  else {
    temp = p->tete;
    while(temp != NULL){
     	i++;
    	temp = temp->next;
    }
  }
  return i;
}
void afficher(pile *p){
  personne *temp;
  temp = p->tete;
  if (temp == NULL){
  	printf("la memoire n'est pas allouee.");
  }
  else{
	printf("\nvotre pile est : \n");
  	while(temp != NULL){
     	printf("%s->",temp->nom);
		temp = temp->next;
	}
  }
  printf("NULL");
}

int main(){
  int T;
  pile *mapile =(pile*) initialiser();
  mapile = empiler(mapile,"Ayoub");
  mapile = empiler(mapile,"Amine");
  mapile = empiler(mapile,"Ahmed");
  mapile = empiler(mapile,"Anass");
  mapile = empiler(mapile,"Abderahim");
  vide(mapile);
  mapile = depiler(mapile);
  T=taille(mapile);
  printf("\nla taille de votre liste est %d.",T);
  afficher(mapile);
  return 0;
}
