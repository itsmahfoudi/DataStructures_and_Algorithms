#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct personne personne;
struct personne{
  char nom[20];
  int age;
  personne *suivant;
};
typedef struct file file;
struct file{
  personne *tete;
};
file *initialiser(){
  file *mafile = (file*)malloc(sizeof(file));
  mafile->tete == NULL;
  return mafile;
}
int vide(file *f){
  if(f->tete == NULL)
    printf("votre file est vide!!!");
  else
    printf("votre liste n'est pas vide.");
  return 0;
}
