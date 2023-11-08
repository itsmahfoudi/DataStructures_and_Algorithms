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
void permuter(personne *a,personne *b){
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
void selection_sort(liste *maliste){
  personne *temp1,*temp2,*temp3;
  for(temp1 = maliste->head ; temp1->next->next != NULL;temp1 = temp1->next){
    temp3 = temp1;
    for(temp2 = temp1->next ; temp2 != NULL;temp2 = temp2->next ){
      if(temp2->age < temp3->age){
        temp3 = temp2;
      }
    }
    permuter(temp1,temp3);
  }
  afficherliste(maliste);
}
void main(){
  liste *maliste = allouer();
  int n,i,aideage;
  char aidenom[20];
  printf("\nveuillez entrer le nombre des personnes que vous voulez inserer : ");
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    printf("\nveuillez entrer le nom du personne numero %d :",i );
    scanf("%s",aidenom);
    printf("veuillez entrer l'age du personne numero %d :",i);
    scanf("%d",&aideage);
    ajouteraudebut(maliste,aidenom,aideage);
  }
  printf("\n****^^^^  avant le tri : ^^^^****");
  afficherliste(maliste);
  printf("\n****^^^^  apres le tri : ^^^^****");
  selection_sort(maliste);
}