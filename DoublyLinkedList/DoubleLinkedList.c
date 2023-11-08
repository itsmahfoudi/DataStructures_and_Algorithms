#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//question1
typedef struct etudient etudient;
struct etudient{
   char nom[20];
   float moy;
   struct etudient *prev;
   struct etudient *next;
};
//question2
typedef struct liste liste;
struct liste{
   etudient *first;
   etudient *last;
   int taille;
};
//question3
liste *creerListe(){
   liste *list = (liste*) malloc(sizeof(liste));
   list->first = NULL;
   list->last = NULL;
   list->taille = 0;
   return list;
}
//question4
void insererDebut(liste *l,char nom1[20],float m){
  etudient *nv_etd = (etudient*)malloc(sizeof(etudient));
  if(nv_etd == NULL){
    printf("\nles donnees du nouveau etudient ne peuvent pas etre inserer.");
  }
  else{
    if(l->taille == 0){
        strcpy(nv_etd->nom,nom1);
        nv_etd->moy = m;
        nv_etd->next = NULL;
        nv_etd->prev = NULL;
        l->first = nv_etd;
        l->last = nv_etd;
        (l->taille)++;
        printf("\nl'element est bien inserer.");
    }
    else{
        strcpy(nv_etd->nom,nom1);
        nv_etd->moy = m;
        nv_etd->prev = NULL;
        nv_etd->next = l->first;
        l->first->prev = nv_etd;
        l->first = nv_etd;
        (l->taille)++;
        printf("\nl'element est bien inserer.");
        }
  }

}
//question5
void insererFin(liste *l,char nom1[],float m){
  etudient *nv_etd = (etudient*)malloc(sizeof(etudient));
  if(nv_etd == NULL){
    printf("\nles donnees du nouveau etudient ne peuvent pas etre inserer.");
  }
  else{
    strcpy(nv_etd->nom,nom1);
    nv_etd->moy = m;
	nv_etd->prev = l->last;
    nv_etd->next = NULL;
    l->last->next = nv_etd;
    l->last = nv_etd;
    (l->taille)++;
	printf("\nl'element est bien inserer.");
  }
}
//question6
void afficheDebut(liste *l){
  etudient *temp;
  temp = l->first;
  printf("\nla taille de votre liste est : %d.",l->taille);
  printf("\nvotre liste est :");
  while(temp != NULL){
    printf("\nle nom de l'etudient : %s, sa moyenne : %f",temp->nom,temp->moy);
    temp = temp->next;
  }
}
//question7
void afficheFin(liste *l){
  etudient *temp;
  temp = l->last;
  printf("\nla taille de votre liste est : %d.",l->taille);
  printf("\nvotre liste est :");
  while(temp != NULL){
    printf("\nle nom de l'etudient : %s, sa moyenne : %f",temp->nom,temp->moy);
    temp = temp->prev;
  }
}
//question8
void supprimerTete(liste *l){
  etudient *temp;
  temp = l->first;
  l->first = l->first->next;
  l->first->prev = NULL;
  free(temp);
  (l->taille)--;
  printf("\nl'element est bien eliminer.");
}
//question9
void supprimerQueue(liste *l){
  etudient *temp;
  temp = l->last;
  l->last = l->last->prev;
  l->last->prev->next = NULL;
  free(temp);
  (l->taille)--;
  printf("\nl'element est bien eliminer.");
}
//question10
float moyenne(liste *l){
  int i=0;
  float S=0,M=0;
  etudient *temp;
  temp = l->first;
  while(temp != NULL){
    S+=temp->moy;
    temp = temp->next;
    i++;
  }
  M=(float)S/i;
  return M;
}
int main(){
  float M;
  liste *mylist = (liste*) malloc(sizeof(liste));
  mylist = creerListe();
  insererDebut(mylist,"AYOUB",15.5);
  insererDebut(mylist,"BILAL",18.5);
  insererDebut(mylist,"Abdelkrim",19.5);
  insererFin(mylist,"AMINE",18.75);
  afficheDebut(mylist);
  supprimerTete(mylist);
  supprimerQueue(mylist);
  afficheFin(mylist);
  M = moyenne(mylist);
  printf("\nla moyenne de la classe est : %f .",M);
  return 0;
}
