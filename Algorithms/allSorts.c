#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//definition des structures
typedef struct Element Element;
typedef struct Pile Pile;
typedef struct Liste Liste;
//les fonctions
Liste* Allouer();
void Empiler(Pile *, int );
void AfficherP(Pile *);
void AjouDebut(Liste*, int );
void AfficherL(Liste*);
void Permuter(Element *, Element *);
void SuppVal(Liste *, int );
void SuppDebut(Liste *);
Element *Precedent(Element*, Liste*);
void Tri_Selection(Liste* );
void Tri_Bulles(Liste* );
void Tri_Insertion(Liste *);
//structure element
struct Element
{
    int valeur;
    Element *suivant;
};

struct Pile
{
    Element *premier;
};

struct Liste
{
    int longueur;
    Element *Tete;
};

Liste* Allouer()
{
    Liste* New=(Liste*)malloc(sizeof(Liste));

    New->longueur=0;
    New->Tete=NULL;
    return New;
}

void Empiler(Pile *pile, int valeur)
{
    Element *New=(Element*)malloc(sizeof(Element));
    New->valeur=valeur;
    New->suivant=pile->premier;
    pile->premier=New;
}

void AjouDebut(Liste* liste, int valeur)
{
    Element *New=(Element*)malloc(sizeof(Element));
    New->valeur=valeur;
    New->suivant=liste->Tete;
    liste->Tete=New;
    liste->longueur++;
}

void AfficherL(Liste* liste)
{
    Element* tmp=liste->Tete;
    printf("\n ");
    while(tmp!=NULL)
    {
        printf(" %d -> ", tmp->valeur);
        tmp=tmp->suivant;
    }
    printf(" NULL \n ");
}

void AfficherP(Pile *pile)
{
    Element* tmp=pile->premier;
    while(tmp!=NULL)
    {
        printf("\t\t%d\n", tmp->valeur);
        tmp=tmp->suivant;
    }
    printf("\t\tNULL\n\n");

}

void Permuter(Element *a, Element *b)
{
    int t;
    t=a->valeur;
    a->valeur=b->valeur;
    b->valeur=t;
}

void SuppVal(Liste *liste, int Valeur)
{
    Element* tmp=liste->Tete;
    while(tmp!=NULL)
    {
        if(tmp->valeur==Valeur)
            Precedent(tmp,liste)->suivant = tmp->suivant;
        tmp=tmp->suivant;
    }
    liste->longueur--;
}

void SuppDebut(Liste* liste)
{
    Element* tmp=liste->Tete;
    liste->Tete=tmp->suivant;
    free(tmp);
}

Element *Precedent(Element* E, Liste *L)
{
    Element *R;
    if(E==(L->Tete))
        return NULL;
    else
        for(R=L->Tete; R->suivant!=E; R=R->suivant);
    return R;
}
// Le tri par selection :

void Tri_Selection(Liste* liste)
{
    Pile* pile=(Pile*)malloc(sizeof(Pile));
    pile->premier=NULL;
    Element*tmp=liste->Tete;
    int min;
    while(liste->longueur >= 0 )
    {
        tmp=liste->Tete;
        min=tmp->valeur;
        while(tmp!=NULL)
        {
            if(min>tmp->valeur)
                min=tmp->valeur;
            tmp=tmp->suivant;
        }
        Empiler(pile, min);
        AfficherP(pile);
        if(min==liste->Tete->valeur)
            SuppDebut(liste);
        else
            SuppVal(liste,min);
    }
}

// Le tri a bulle:

void Tri_Bulles(Liste* liste)
{

    Element *tmp,*cmp;
    for(tmp=liste->Tete; tmp->suivant!=NULL; tmp=tmp->suivant)
    {
        for(cmp=tmp; cmp!=NULL; cmp=cmp->suivant)
        {
            if(tmp->valeur > cmp->valeur)
                Permuter(tmp,cmp);

        }
    }
    AfficherL(liste);
}

// Tri par insertion:

void Tri_Insertion(Liste *liste)
{

    Liste *Nliste=Allouer();
    Element* tmp;
    int max;
    while(liste->longueur >= 0)
    {
        tmp=liste->Tete;
        max=tmp->valeur;
        while(tmp!=NULL)
        {
            if(max < tmp->valeur)
                max=tmp->valeur;
            tmp=tmp->suivant;
        }
        AjouDebut(Nliste, max);
        AfficherL(Nliste);
        if(max==liste->Tete->valeur)
            SuppDebut(liste);
        else
            SuppVal(liste, max);
    }
}

int main()
{

    Liste *liste=Allouer();
    int i,n,ele,choix;
    printf("Combien d'elements vous voulez inserer dans votre liste: ");
    scanf("%d", &n);
    printf("Entrez vos elements: \n");
    for(i=1; i<=n; i++)
    {
        scanf("%d",&ele);
        AjouDebut(liste, ele);
    }

    printf("\n Avant le tri: 	\n    ");
    AfficherL(liste);
    printf("\n 1. Le tri par selection: \n ");
    printf("\n 2. Le tri a bulles: \n ");
    printf("\n 3. Le tri par insertion: \n ");

    printf("\n \n Entrez votre choix: ");
    scanf("%d",&choix);

    switch(choix)
    {

    case 1 :
        printf("\n Apres le tri:\n ");
        Tri_Selection(liste);
        break;

    case 2 :
        printf("\n Apres le tri:\n ");
        Tri_Bulles(liste);
        break;

    case 3 :
        printf("\n Apres le tri:\n ");
        Tri_Insertion(liste);
        break;
    }

    return 0;
}
