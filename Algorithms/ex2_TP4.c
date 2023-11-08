#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct personne personne;
struct personne {
  int age;
  char nom[20];
  struct personne *next;
};
typedef struct liste liste;
struct liste {
  int taille;
  personne *head;
};
liste *allouer(){
  liste *newlist = (liste*)malloc(sizeof(liste));
  if (newlist == NULL)
  {
    printf("\nl'allocation n'est pas effectuer!!");
  }
  else{
    newlist->head = NULL;
    newlist->taille = 0;
  }

}
void ajouteraudebut(liste *l,char nvnom[],int nvage){
  personne *nvper = (personne*) malloc(sizeof(personne));
  if(nvper == NULL){
    printf("\nles donnees ne peuvent pas etre inserer!!!");
  }
  else{
    nvper->age = nvage;
    strcpy(nvper->nom,nvnom);
    nvper->next = l->head;
    l->head = nvper;
    (l->taille)++;
  }
}
void afficherliste(liste *l){
  personne *temp;
  temp = l->head;
  printf("\nvotre liste est : \n");
  while(temp != NULL){
    printf("l'age de %s est %d.\n",temp->nom,temp->age);
    temp = temp->next;
  }
}
int maximumoftable(tab){
  
}
