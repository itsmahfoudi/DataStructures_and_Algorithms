#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct arbre arbre;
struct arbre{
    int data;
    arbre *sa_droit;
    arbre *sa_gauche;
    arbre *parent;
};
arbre *intialiserarbre(){
    arbre *newtree = (arbre*)malloc(sizeof(arbre));
    if (newtree == NULL){
        return NULL;
    } 
    else{
        int x;
        printf("\nveuillez entrer la valeur de la racine : ");
        scanf("%d",&x);
        newtree->data = x;
        newtree->parent = NULL;
        newtree->sa_droit = NULL;
        newtree->sa_gauche = NULL;
        return newtree;
    }
}
