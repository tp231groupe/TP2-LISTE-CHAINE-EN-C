# Opérations Matricielles

> Informations personnelles

* Noms & Prénoms : Ngamize Ineza Kwizera Philbert

* Matricule : 22T2944

* Rôle dans le projet : Responsable de la partie operation Matricielle

## Contexte

Pour ce projet, j’étais responsable de la partie **matrices**.
L’idée était de manipuler des matrices en C, de mettre en pratique les opérations classiques et de vérifier la compatibilité des dimensions avant toute opération.
C’était un bon exercice pour combiner **mathématiques** et **programmation dynamique en C**.

---

## Somme de deux matrices

### Comment ça marche

Avant d’additionner deux matrices, il faut s’assurer qu’elles ont **la même taille**. Ensuite, on additionne les éléments **un par un** pour construire une nouvelle matrice résultat.

### Pseudo-code

```
fonction somme_matrices(A, B)
    si dimensions(A) ≠ dimensions(B)
        afficher "Erreur"
        arrêter
    C ← matrice de même taille que A
    pour chaque ligne i
        pour chaque colonne j
            C[i][j] ← A[i][j] + B[i][j]
    retourner C
```

### Exemple

```
A = 1 2
    3 4

B = 5 6
    7 8

C = A + B
Résultat :
C = 6  8
    10 12
```

> Ici, chaque élément de `C` est juste la somme des éléments correspondants de `A` et `B`.

---

## Produit de deux matrices

### Comment ça marche

Le produit n’est pas un simple élément par élément.
Il faut que le **nombre de colonnes de la première matrice soit égal au nombre de lignes de la deuxième**.
Chaque élément du résultat est obtenu en multipliant les éléments d’une ligne par ceux d’une colonne, puis en les additionnant.

### Pseudo-code

```
fonction produit_matrices(A, B)
    si cols(A) ≠ rows(B)
        afficher "Erreur"
        arrêter
    C ← matrice de taille rows(A) × cols(B)
    pour i de chaque ligne de A
        pour j de chaque colonne de B
            C[i][j] ← 0
            pour k de 0 à cols(A)-1
                C[i][j] += A[i][k] * B[k][j]
    retourner C
```

### Exemple

```
A = 1 2
    3 4

B = 5 6
    7 8

C[0][0] = 1*5 + 2*7 = 19
C[0][1] = 1*6 + 2*8 = 22
C[1][0] = 3*5 + 4*7 = 43
C[1][1] = 3*6 + 4*8 = 50

Résultat :
C = 19 22
    43 50
```

> Ici, on voit que chaque élément de `C` résulte d’une combinaison de ligne et colonne. C’est un peu comme un mélange coordonné des valeurs.

---

## Multiplication par un scalaire

### Comment ça marche

Cette opération est plus simple : **on multiplie chaque élément de la matrice par un nombre entier**.

### Pseudo-code

```
fonction multiplication_scalaire(A, m)
    C ← matrice de même taille que A
    pour chaque ligne i
        pour chaque colonne j
            C[i][j] = A[i][j] * m
    retourner C
```

### Exemple

```
A = 1 2
    3 4

m = 3

Résultat :
C = 3 6
    9 12
```

> Ici, chaque valeur est juste multipliée par 3. Très direct et visuel !

---

## Produit positif

### Comment ça marche

C’est une variante du produit matriciel.
On calcule d’abord le **produit normal**, puis on transforme chaque élément en `1` si le résultat est **positif**, ou `0` sinon.

### Pseudo-code

```
fonction produit_positif(A, B)
    P ← produit_matrices(A, B)
    C ← matrice de même taille que P
    pour chaque ligne i
        pour chaque colonne j
            si P[i][j] > 0
                C[i][j] ← 1
            sinon
                C[i][j] ← 0
    retourner C
```

### Exemple

```
A = 1 -2
    3  4

B = 5 6
    7 8

Produit normal P = -9 -10
                   43  50

Produit positif C = 0 0
                   1 1
```

> On transforme le produit en une sorte de **matrice “oui/non”** selon le signe des valeurs. C’est très pratique pour certaines applications logiques.

