#include <stdio.h>
#include <stdlib.h>

void permuter(int a, int b){
    int temp;
    temp = a;
    a=b;
    b=temp;
}
int partition(int *tab ,int premier, int dernier){
    int pivot = tab[dernier];
    int indice_de_partition = premier;
    for(int i=premier ;i<dernier;i++){
        if(tab[i] <= pivot){
            permuter(tab[i],tab[indice_de_partition]);
            indice_de_partition ++;
        }
    }
    permuter(tab[indice_de_partition],tab[dernier]);
    return indice_de_partition;
}
void tri_rapide(int *tab,int premier, int dernier){
    if(premier < dernier){
        int indice_de_partition = partition(tab , premier ,dernier);
        tri_rapide(tab, premier,indice_de_partition-1);
        tri_rapide(tab,indice_de_partition +1,dernier);
    }
}
void main(){
  int liste[20],taille,i;

  printf("Entrer la taille de votre liste: ");
  scanf("%d",&taille);

  
  for(i = 0; i < taille; i++)
    {printf("Entreer la valeur numero %d : ",i+1);
     scanf("%d",&liste[i]);}
  
  printf("votre liste avant le tri: ");
  for(i = 0; i < taille; i++)
    printf(" %d",liste[i]);

  tri_rapide(liste,0,taille-1);

  printf("votre liste apres le tri: ");
  for(i = 0; i < taille; i++)
    printf(" %d",liste[i]);

}

