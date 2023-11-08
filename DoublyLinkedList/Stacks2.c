#include <stdio.h>
#include <stdlib.h>

typedef struct element element;
struct element{
  int r;
  element *next;
  };
typedef struct pile pile;
struct pile{
  element *tete;
  };
pile *initialiser(){
  pile *mapile =(pile *) malloc(sizeof(mapile));
  mapile->tete = NULL;
  return mapile;}
pile *empiler(pile *mapile, int nombre){
  element *nv_ele = (element *)malloc(sizeof(nv_ele));
  if(nv_ele == NULL || mapile == NULL){
    printf("la liste n'est pas cree.");
  }
  else{
    nv_ele->r = nombre;
    nv_ele->next = mapile->tete;
    mapile->tete = nv_ele;
  }
}
void afficher(pile *p){
  element *temp ;
  temp = p->tete;
  if (temp == NULL){
  	printf("la memoire n'est pas allouee.");
  }
  else{

  	while(temp != NULL){
     	printf("%d",temp->r);
		temp = temp->next;
	}
  }
}
int main(){
  int X,R,Q,A,i=0;
  pile *mapile =(pile*) initialiser();
  do {
  printf("veuillez entrer le nombre a convertir : ");
  scanf("%d",&X);}while(X<0);
    A = X;
    do {
      R = X % 2;
      Q = X / 2;
      empiler(mapile,R);
      X = Q;
  }while (X>0);
  printf("le nombre %d convertit en decimal est : ",A);
  afficher(mapile);
  return 0;
}

