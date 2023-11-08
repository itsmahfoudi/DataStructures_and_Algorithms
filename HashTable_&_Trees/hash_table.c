#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define LONGUEUR_NOM 60
#define MAX_TABLE 10

typedef struct {
    char nom[LONGUEUR_NOM];
    int age;
}etudient;

etudient *hash_table[MAX_TABLE];
unsigned int hash(char *nom){
    int longueur = strnlen(nom,MAX_TABLE);
    unsigned int hash_value = 0;
    for (int i=0 ; i<longueur ;i++){
        hash_value += nom[i];
        hash_value = (hash_value * nom[i]) % MAX_TABLE; 
    }
    return hash_value;
}
void init_hash_table(){
    for(int i= 0; i< MAX_TABLE ;i++){
        hash_table[i] = NULL;
    }
}
void afficher(){
    for(int i=0 ; i<MAX_TABLE ; i++){
        if(hash_table[i] == NULL){
            printf("\n\t%d\t---",i);
        }
        else{
            printf("\n\t%d\t%s",i,hash_table[i]->nom);
        }
    }
}
bool hash_table_insert(etudient *nv_etd){
    if(nv_etd == NULL) return false;
    int index = hash(nv_etd->nom);
    for(int i=0; i<LONGUEUR_NOM ; i++){
        int choice = (i+index)%LONGUEUR_NOM;
        if (hash_table[choice] == NULL){
            hash_table[choice] = nv_etd;
            return true;
        }
    }
    return false;
}
etudient *hash_table_search(char *nom){
    int indice = hash(nom);
    if(hash_table[indice] != NULL && strncmp(hash_table[indice]->nom,nom,MAX_TABLE) == 0){
        return hash_table[indice];
    }
    else{
        return NULL;
    }
}
etudient *hash_table_delete(char *nom){
    int index = hash(nom);
    if(hash_table[index] != NULL && strncmp(hash_table[index]->nom,nom,MAX_TABLE) == 0){
        etudient *tmp = hash_table[index];
        hash_table [index] = NULL;
        return tmp;
    }
    else{
        return NULL;
    }
}
int main(){
    init_hash_table();
    //afficher();
    etudient Ahmed= {.nom="Ahmed",.age=24};
    etudient Ali= {.nom="Ali",.age=26};
    etudient Sara= {.nom="Sara",.age=12};
    etudient Said= {.nom="Said",.age=17};
    etudient Hatim= {.nom="Hatim",.age=16};
    
    hash_table_insert(&Ahmed);
    hash_table_insert(&Ali);
    hash_table_insert(&Sara);
    hash_table_insert(&Said);
    hash_table_insert(&Hatim);
    afficher();
    etudient *tmp1 = hash_table_search("Sara");
    if(tmp1 == NULL){
        printf("\nl'element n'existe pas!!!");
    }
    else{
        printf("\nl'element existe");
    }
    hash_table_delete("Sara");
    etudient *tmp2 = hash_table_search("Sara");
    if(tmp2 == NULL){
        printf("\nl'element n'existe pas!!!");
    }
    else{
        printf("\nl'element existe");
    }
    afficher();
    return 0;
}
