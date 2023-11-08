#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define max_table 10
#define noun_length 30 

typedef struct eleve eleve;
struct eleve{
    char nom[noun_length];
    eleve *next;
};

eleve *hashtable[max_table];

unsigned int hash(char *nom){
    unsigned int i,H=0;
    for (i=0;i<strlen(nom);i++){
        H += nom[i];
    }
    return H%max_table;
}
void init_hash_table(){
    for( int i=0 ; i<max_table ; i++){
        hashtable[i] = NULL;
    }
}
// insertion au cas de collision avec chainage
void inserer_ch(int key, char *nom){
    eleve *nv_eleve = (eleve*)malloc(sizeof(eleve));
    if (nv_eleve == NULL ){
        return;
    }
    strcpy(nv_eleve->nom,nom);
    nv_eleve->next = NULL;
    if(hashtable[key] == NULL){
        hashtable[key] = nv_eleve;
    }
    else{
        eleve *temp = hashtable[key];
        while(1){
            if(temp->next == NULL){
                temp->next = nv_eleve;
                break;
            }
            temp = temp->next;
        }
    }
}
// insertion au cas de collision avec adressage ouvert 
bool inserer_AO (eleve *nv_eleve) {
    if (nv_eleve == NULL){
        return false;
    }
    int i,j,index = hash(nv_eleve->nom);
    for(i=0 ; i< max_table ;i++){
        j=(i+index)%max_table;
        if(hashtable[j] == NULL){
            hashtable[j] = nv_eleve;
            return true;
        }
    }
    return false;
}
void afficher(){
    printf("\n Indice \t Nom de l'eleve : ");
    for (int i=0 ; i<max_table ;i++){
        if(hashtable[i] == NULL){
            printf("\n   %d \t\t  ---------",i);
        }
        else{
            printf("\n   %d \t\t ",hash(hashtable[i]->nom));
            eleve *temp = hashtable[i];
            while(temp != NULL){
                printf(" %s -> ",temp->nom);
                temp = temp->next;
            }
            printf("NULL");
        } 
    }
}
eleve *Rechercher(char *nom)
{
    int index=hash(nom);
    for(int i=0; i<max_table; i++)
    {
        int tr=(index+i)%max_table;
        if(hashtable[tr]!=NULL)
        { if((strncmp(hashtable[tr]->nom,nom,max_table)==0))
            return hashtable[tr];
        }
    }
    return NULL;
}
int main(){
    int i,n;
    unsigned int hash_value;
    init_hash_table();
    char *nom1;
    nom1 = (char *)malloc(20*sizeof(char));
    char *nom2;
    nom2 = (char *)malloc(20*sizeof(char));
    printf("\nveuillez entrer le nombre des etudients : ");
    scanf("%d",&n);
    for( i=0 ; i<n ; i++){
        printf("\nveuillez entrer un nom : ");
        scanf("%s",nom1);
        hash_value = hash(nom1);
        inserer_ch(hash_value, nom1);
    }
    afficher();
    printf("\nveuillez entrer le nom de l'etudient que vous cherchez : ");
    scanf("%s",nom2);
    eleve *temp = Rechercher(nom2);
    if(temp == NULL){
        printf("\n%s n'existe pas !!!",nom2);
    }
    else{
        printf("\n%s existe.",nom2);
    }
    return 0;
}