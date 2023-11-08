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
personne *gettail(liste *maliste){
    personne *temp = maliste->head;
    while(temp != NULL){
        temp = temp->next;
    }
    return temp; 
}
personne *partition(){

}