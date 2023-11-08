#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employe employe;
struct employe{
    int matricule;
    char nom[20];
    int anciennete;
};
typedef struct liste liste;
struct liste{
    employe emp;
    liste *suivant;
};

employe saisir(){
    employe nv_emp;
    printf("\nveuillez entrer la matricule de l'employe : ");
    scanf("%d",nv_emp.matricule);
    printf("\nveuillez entrer le nom de l'employe : \n");
    scanf("%s",nv_emp.nom);
    printf("\nveuillez entrer l'nciennete de l'employe : ");
    scanf("%d",nv_emp.anciennete);
    return nv_emp;
}

liste* ajouterEnFin(liste *maliste, employe e){
    liste *nv_emp = (liste *)malloc(sizeof(liste));
    nv_emp->emp = e;
    nv_emp->suivant = NULL;
    if(maliste == NULL || nv_emp == NULL){
        return nv_emp;
    }
    else{
        nv_emp->emp = e;
        liste *temp;
        temp = maliste;
        while(temp->suivant != NULL){
            temp = temp->suivant;
        }
        temp->suivant = nv_emp;
        return maliste;
    }
}
void afficher(liste *maliste){
    liste *temp;
    temp = maliste;
    while(temp != NULL){
        printf("\tle matricule de l'employe : %d, le nom est : %s, l'anciennete : %d \n",temp->emp.matricule,temp->emp.nom,temp->emp.anciennete);
        temp = temp->suivant;
    }
    printf("NULL\n");
}
liste* supprimerEnTete(liste* maliste){
    if(maliste == NULL){
        return NULL;
    }
    else{
        liste *ptr;
        ptr = maliste;
        maliste = ptr->suivant;
        free(ptr);
        return maliste;
    }
}
int main(){
    liste *maliste = (liste *)malloc(sizeof(liste));
    int n,i;
    printf("veuillez entrer le nombre des employes : ");
    scanf("%d",&n);
    employe nvemp;
    for(i=0;i<n;i++){
        nvemp = saisir();
        ajouterEnFin(maliste,nvemp);
    }
    afficher(maliste);
    supprimerEnTete(maliste);
    afficher(maliste);
    return 0;
}
