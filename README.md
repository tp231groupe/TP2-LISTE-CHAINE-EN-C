# 📝 Rapport Final du Projet INF231 - Listes Chaînées en C

**Université de Yaoundé I / Département d'Informatique INF L2 / Année académique 2025-2026**

## Introduction

> « La structure des données est au cœur de l'efficacité algorithmique. La bonne organisation de l'information peut transformer un traitement lent en une opération quasi-instantanée. »

Ce projet s'inscrit dans le cadre du cours **INF231 : Technique de Conception d'Algorithmes et Structures de Données**. L'objectif est de maîtriser l'implémentation en langage **C** des opérations fondamentales sur diverses structures de listes chaînées.

### 🔎 Objectifs du Projet

L'objectif principal était d'implémenter de manière complète et robuste les opérations suivantes :

1.  **Suppression d'Occurrences** : Supprimer **toutes les occurrences** d'un élément dans une liste simplement chaînée.
2.  **Insertion Triée** : Insertion d'un élément dans une **liste triée** (simplement et doublement chaînée).
3.  **Gestion de la Circularité** : **Insertion en tête et en queue** pour les listes simplement et doublement chaînées **circulaires**.

-----

## 📂 1. Architecture Modulaire du Code

Le code est structuré de manière modulaire en C, séparant l'interface, l'implémentation et le programme de test.

### 🔹 Organisation du Dépôt

```
projet-listes/
├── src/                 # Fichiers source contenant le code implémenté (.c)
│   ├── test2.c          # Programme principal de démonstration (Menu interactif)
│   ├── linkedList.c     # Implémentation des fonctions de gestion des listes
│   └── utils.c          # Implémentation des fonctions utilitaires (affichage, etc.)
│
├── lib/                 # Fichiers d'en-tête (headers) qui définissent les interfaces
│   ├── linkedList.h     # Prototypes et définitions des structures (node, list, doubleList)
│   └── utils.h          # Prototypes des fonctions utilitaires
│
├── doc/                 # Documentation individuelle et rapports de suivi
│   └── Matricule_Prenom-NOM.md # Cahier de suivi de chaque membre
│
└── README.md            # Descriptif du projet
```

-----

## 🛠️ 2. Structures de Données Implémentées

Le fichier `lib/linkedList.h` a défini les structures de base pour les nœuds simples, doubles et leurs variantes circulaires :

| Structure | Type C | Caractéristiques |
| :--- | :--- | :--- |
| **Liste Simple** | `typedef node* list` | Pointeur `next` uniquement. |
| **Liste Double** | `typedef Node* doubleList` | Pointeur `next` et `prev`. |
| **Listes Circulaires** | (Utilisent `list` ou `doubleList`) | La fin pointe vers le début (Tête). |

-----

## 🧪 3. Logique des Fonctionnalités Clés

Cette section détaille l'approche algorithmique adoptée dans `linkedList.c` pour les fonctionnalités les plus complexes.

### 3.1. Insertion en Tête (Liste Doublement Chaînée Circulaire)

La fonction **`insertHeadDoubleCircular(dl, val)`** ajoute un nouvel élément en tête tout en maintenant la double circularité.

| Aspect | Détails |
| :--- | :--- |
| **Description** | Le nouvel élément devient la nouvelle tête. Mise à jour de **quatre pointeurs** pour lier le nouveau nœud à l'ancienne tête et à la queue. |
| **Exemple** | **Input :** `[5]<->[10]<->(5)`, **Nouvelle valeur :** 1. **Output :** `[1]<->[5]<->[10]<->(1)` |

**Pseudo-code**

```
Function insertHeadDoubleCircular(L, V):
    Si L est vide: 
        Retourner createDoubleCircularList(V)
    
    Créer Nœud N, N.val ← V
    N.next ← L
    N.prev ← L.prev
    
    L.prev.next ← N (Queue pointe vers N)
    L.prev ← N (Ancienne tête pointe vers N)
    
    Retourner N
```

### 3.2. Insertion en Queue (Liste Doublement Chaînée Circulaire)

La fonction **`insertTailDoubleCircular(dl, val)`** utilise une logique similaire à l'insertion en tête, mais conserve l'ancienne tête comme point de départ de la liste.

| Aspect | Détails |
| :--- | :--- |
| **Description** | Le nouvel élément devient la queue. Les quatre pointeurs de circularité sont mis à jour sans changer la valeur de retour (l'ancienne tête). |
| **Exemple** | **Input :** `[5]<->[10]<->(5)`, **Nouvelle valeur :** 20. **Output :** `[5]<->[10]<->[20]<->(5)` |

**Pseudo-code**

```
Function insertTailDoubleCircular(L, V):
    Si L est vide: 
        Retourner createDoubleCircularList(V)
    
    Créer Nœud N, N.val ← V
    
    N.next ← L
    N.prev ← L.prev
    
    L.prev.next ← N (Queue pointe vers N)
    L.prev ← N (Ancienne tête pointe vers N)
    
    Retourner L
```

### 3.3. Tri de Liste (Liste Simplement Chaînée)

La fonction **`sortList(l, order)`** trie la liste en permutant les valeurs entre les nœuds.

| Aspect | Détails |
| :--- | :--- |
| **Description** | Implémentation d'un tri simple par sélection (ou bulle) qui **échange uniquement les valeurs** (`val`) des nœuds, sans manipuler les pointeurs, garantissant ainsi la structure de la liste. |
| **Exemple** | **Input :** `[5]->[1]->[10]`, **Order :** 1 (Croissant). **Output :** `[1]->[5]->[10]` |

**Pseudo-code**

```
Function sortList(L, Order):
    Pour NI de L à la fin:
        Pour NJ de NI à la fin:
            Si (comparaison(NI.val, NJ.val) ≠ Order):
                Échanger NI.val et NJ.val
    Retourner L
```

### 3.4. Suppression de Toutes les Occurrences

La fonction **`deleteOccurrences(l, val)`** supprime tous les nœuds correspondant à `val` en assurant la gestion de la mémoire.

| Aspect | Détails |
| :--- | :--- |
| **Description** | Un pointeur **précédent** (`prev`) est maintenu. Si un nœud est supprimé, le nœud `prev` est lié au nœud suivant, et le nœud courant est libéré (`free`). Gère correctement la suppression en tête. |
| **Exemple** | **Input :** `[1]->[5]->[1]->[10]`, **Valeur :** 1. **Output :** `[5]->[10]` |

**Pseudo-code**

```
Function deleteOccurrences(L, V):
    Précédent ← NULL
    Courant ← L
    
    Tant que Courant non-NULL:
        Si Courant.val == V:
            Si Précédent est NULL (Suppression à la tête):
                L ← Courant.next
            Sinon:
                Précédent.next ← Courant.next
            
            Temp ← Courant 
            Courant ← Courant.next
            Libérer Temp (free)
        Sinon:
            Précédent ← Courant
            Courant ← Courant.next
            
    Retourner L (la nouvelle tête)
```

-----

## 💻 4. Guide de Compilation et d'Exécution

### 4.1. Compilation

Depuis la racine du projet (`projet-listes/`), compilez en incluant le chemin vers les fichiers d'en-tête :

```bash
gcc -I lib src/test2.c src/linkedList.c src/utils.c -o run
```

### 4.2. Exécution

Exécutez le programme pour accéder au menu interactif :

```bash
./run
```

### 4.3. Exemple d'Exécution du Menu

``` bash
$ ./run

===== MENU LISTES =====
...
7. Créer liste double circulaire
...
Votre choix : 7
Valeur initiale : 10

===== MENU LISTES =====
...
13. Afficher la liste (double)
...
Votre choix : 13
[10]<->

===== MENU LISTES =====
...
8. Insérer tête double circulaire
...
Votre choix : 8
Valeur à insérer : 5

===== MENU LISTES =====
...
13. Afficher la liste (double)
...
Votre choix : 13
[5]<->[10]<->

===== MENU LISTES =====
...
9. Insérer queue double circulaire
...
Votre choix : 9
Valeur à insérer : 20

===== MENU LISTES =====
...
13. Afficher la liste (double)
...
Votre choix : 13
[5]<->[10]<->[20]<->

===== MENU LISTES =====
...
11. Afficher longueur liste double circulaire
...
Votre choix : 11
Longueur de la liste double circulaire : 3
```
-----

## 👥 5. Auteurs et Contribution

Ce projet a été développé par le groupe de TD/TP, sous la supervision du Pr Melatagia.

| Nom et Prénom | Matricule | Rôle Principal | Compte GitHub |
| :--- | :--- | :--- | :--- |
| **Mar'yam MFOPIT** | 23V2414 | Lead (intégration et test) | [https://github.com/maryam2379](https://github.com/maryam2379) |
| **Philbert NGAMIZE** | 22T2944 | Membre (Insertion en tête et queue de liste chaînée circulaire) | [https://github.com/nik-p12](https://github.com/nik-p12) |
| **Caleb KEMMOE** | 24H2300 | Membre (Insertion en queue de liste doublement chaînée circulaire) | [https://github.com/kemmoebugincaleb-cell](https://github.com/kemmoebugincaleb-cell) |
