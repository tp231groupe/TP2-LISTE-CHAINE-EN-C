# Projet de Structures de Données : Listes Chaînées en C

## 📖 Contexte du projet

Ce projet a été réalisé dans le cadre de l’apprentissage des **structures de données** en langage **C**.
Il a pour objectif de mettre en œuvre différentes variantes de **listes chaînées** et leurs principales opérations (insertion, suppression, tri, affichage, etc.), en respectant une organisation modulaire du code source.

---

## 🎯 Objectifs pédagogiques

* Comprendre la représentation en mémoire des **listes simplement chaînées** et **doublement chaînées**.
* Manipuler les opérations fondamentales sur les listes (création, insertion, suppression, parcours, tri).
* Appliquer les principes de **modularité** en C avec les fichiers `.h` (headers) et `.c` (implémentations).
* Approfondir la gestion dynamique de la mémoire via `malloc` et `free`.

---

## 📂 Organisation du projet

```
projet-listes/
│── src/
│   ├── test2.c          # Programme principal (menu interactif)
│   ├── linkedList.c     # Implémentation des fonctions de gestion des listes
│   ├── utils.c          # Fonctions utilitaires (affichage, etc.)
│
│── lib/
│   ├── linkedList.h     # Prototypes et définitions des structures de listes
│   ├── utils.h          # Prototypes des fonctions utilitaires
│
│── README.md            # Documentation du projet
```

---

## 🛠️ Fonctionnalités implémentées

### 🔹 Listes simplement chaînées

* Création de liste
* Insertion en tête, en queue, ou à une position donnée
* Insertion triée
* Tri de la liste (ordre croissant ou décroissant)
* Suppression des occurrences d’une valeur
* Suppression complète de la liste
* Affichage de la longueur et du contenu

### 🔹 Listes simplement chaînées circulaires

* Création d’une liste circulaire
* Insertion en tête et en queue

### 🔹 Listes doublement chaînées

* Création et insertion
* Insertion triée
* Tri de la liste
* Calcul de la longueur

### 🔹 Listes doublement chaînées circulaires

* Création de liste
* Insertion en tête et en queue
* Calcul de la longueur

---

## 💻 Compilation et exécution

### 1. Compilation

Depuis le dossier `src/` :

```bash
gcc test2.c linkedList.c utils.c -o run
```

### 2. Exécution

```bash
./run
```

---

## 📋 Menu du programme

Lors de l’exécution, un **menu interactif** s’affiche :

```
===== MENU LISTES =====
1. Insérer en tête (simple)
2. Insérer en queue (simple)
3. Insérer à une position (simple)
4. Trier la liste simple
5. Supprimer toutes occurrences (simple)
6. Afficher la longueur de la liste simple
7. Créer liste double circulaire
8. Insérer tête double circulaire
9. Insérer queue double circulaire
10. Trier liste double circulaire
11. Afficher longueur liste double circulaire
0. Quitter
```
---

Université Yaounde 1 – Année académique 2025/2026
