# Insertion dans une liste doublement chainee triee

*Informations Personnelles*

Nom: `MFOPIT MVU`
Prenom : `MAR'YAM`
Matricule: `23V2414`

## Objectif
Inserer un nouvel element dans une liste doublement chainee **tout en maintenant l'ordre croissant** des elements.

## Structure de la liste

typedef struct Node{
int data;  // valeur stockee dans le noeud
struct Node* prec;  // pointeur vers le noeud precedent
struct Node* suiv;  // pointeur vers le noeud suivant
} Node;

  chaque noeud contient 
  - une donnee(`data`)
  - un lien vers le noeud precedent(`prec`)
  - un lien vers le noeud suivant(`suiv`)

* Logique de l'insertion triee *

1. Creer un nouveau noeud avec la valeir a inserer
2. Si la liste est vide, le nouveau noeud devient la tete
3. sinon, parcourir la liste jusqu'a trouver le bonemplacement:
   - si la valeur est inferieur a la tete ->insertion en tete
   - si la valeur est superieure a tous les elements ->insertion en queue
   - sinon->insertion entre deux noeuds.

* Fonction complete *
  Node* inserer_trie_double(Node* tete, int donnee){
    Node*nouveau=malloc(sizeof(Node));
    if(!nouveau)return tete;
    nouveau->donnee=donnee;
    nouveau->prec=NULL;
    nouveau->suiv=NULL;
    //cas ou la liste est vide 
    if(!tete) return nouveau;
    //cas ou l'element doit etre insere en tete
    if(donnee<tete->donnee){
        nouveau->suiv=tete;
        tete->prec=nouveau;
        return nouveau;
    }
    Node*courent =tete;
    while(courent->suiv&& courent->suiv->donnee<donnee){
        courent=courent->suiv;
    }
    //insertion apres courant 
    nouveau->suiv=courent->suiv;
    nouveau->prec=courent;
    if(courent->suiv){
        courent->suiv->prec=nouveau;
    }
    courent->suiv=nouveau;
    return tete;

};

* Explication detaillee du code *

  - `malloc(sizeof(Node))`: alloue dynamiquement de la memoire pour le nouveau noeud.
  - `tete==NULL` :verifie si la tete est vide
  - `while(courent != NULL && courent->data<valeur)`:avance dans la liste tant que les valeurs sont inferieures a celle qu'on veut inserer
  - `courent== *tete`:signifie que la valeur a inserer est plus petite que la premiere ->insertion en tete
  - `courent== NULL`:on est arrive a la fin ->insertion en queue.
  - -`else`: insertion entre deux noeuds, on met a jour les pointeurs des voisins
