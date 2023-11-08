#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct personne personne;
struct personne {
  int age;
  char nom[20];
  struct personne *next;
  struct personne *prev;
};
typedef struct liste liste;
struct liste {
  int taille;
  personne *head;
  personne *tail;
};
liste *allouer(){
  liste *newlist = (liste*)malloc(sizeof(liste));
  if (newlist == NULL)
  {
    printf("\nl'allocation n'est pas effectuer!!");
  }
  else{
    newlist->head = NULL;
    newlist->tail = NULL;
    newlist->taille = 0;
  }
  return newlist;
}
void insererDebut(liste *l,char nom1[20],int valeur){
  personne *nv_per = (personne*)malloc(sizeof(personne));
  if(nv_per == NULL){
    printf("\nles donnees du nouveau personne ne peuvent pas etre inserer.");
  }
  else{
    if(l->taille == 0){
        strcpy(nv_per->nom,nom1);
        nv_per->age = valeur;
        nv_per->next = NULL;
        nv_per->prev = NULL;
        l->head = nv_per;
        l->tail = nv_per;
        (l->taille)++;
        printf("\nl'element est bien inserer.");
    }
    else{
        strcpy(nv_per->nom,nom1);
        nv_per->age = valeur;
        nv_per->prev = NULL;
        nv_per->next = l->head;
        l->head->prev = nv_per;
        l->head = nv_per;
        (l->taille)++;
        printf("\nl'element est bien inserer.");
        }
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
void insertion_sort(liste *maliste){
    personne *temp1,*temp2;int currage;
    temp1 = maliste->head;
    for(temp1 = maliste->head->next;temp1 != NULL ;temp1 = temp1 ->next ){
        currage = temp1->age;
        temp2 = temp1 ;
        while( temp2->prev != NULL && temp2->prev->age > currage){
          temp2->age = temp2->prev->age;
        }
        temp2->age = currage;
    }
    afficherliste(maliste);
}
int main(){
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
    insererDebut(maliste,aidenom,aideage);
  }
  printf("\n****^^^^  avant le tri : ^^^^****");
  afficherliste(maliste);
  printf("\n****^^^^  apres le tri : ^^^^****");
  insertion_sort(maliste);
  return 0;
}

