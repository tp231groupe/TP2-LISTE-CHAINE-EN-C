## **23V2414-Mar'yam-MFOPIT MVU.md**

> Rapport d'avancement individuel (INF231 - TP/TD 2)

### **Rôle dans le Projet**

Mon rôle principal est l'**intégration** et l'**orchestration des tests**. Cela inclut la gestion du dépôt GitHub, la vérification de la compatibilité des fonctions entre elles, et la création du programme principal de démonstration.

---

### **Séance 1 : Dimanche 27/09/2025**

| Section | Détails de la Séance |
| :--- | :--- |
| **Durée Estimée** | 3 heures |
| **Objectif Principal** | Création et configuration du dépôt GitHub. Définition de l'architecture initiale du code. |
| **Avancement** | **Dépôt créé et structure définie.** J'ai créé le compte Organisation et le repository `INF231-TD2-Listes-Chainées`. J'ai également poussé une première version du fichier d'en-tête `linkedList.h` et créé les répertoires `/doc` et `/src`. |
| **Tâches Accomplies** | * Création du dépôt public et communication du lien à l'enseignant. * Rédaction du fichier `readme.md`. * Mise en place de la structure de fichiers : `linkedList.h`, `list_operations.c` (vide), `main.c` (vide). * Début de la coordination avec les autres membres pour les conventions de nommage des fonctions (confirmées via `linkedList.h`). |
| **Difficultés** | Le processus de connexion du repository local au compte Organisation a pris plus de temps que prévu. J'ai aussi dû m'assurer que les chemins d'accès (`#include`) étaient corrects pour les futurs fichiers source. |
| **À Faire (Prochaine Séance)** | Récupérer les premières fonctions des membres de l'équipe (e.g., insertion en tête circulaire) et commencer à les intégrer dans un programme de test unifié. |

---

### **Séance 2 : Lundi 28/09/2025**

| Section | Détails de la Séance |
| :--- | :--- |
| **Durée Estimée** | 4 heures |
| **Objectif Principal** | Intégrer et tester les fonctions d'insertion en tête et en queue pour la liste simplement chaînée circulaire. |
| **Avancement** | **Intégration et validation des premières fonctions.** J'ai reçu les implémentations de `insertHeadCircular()` et `insertTailCircular()` (partiellement). J'ai créé un fichier `test_circular_list.c` pour compiler et exécuter ces fonctions. |
| **Tâches Accomplies** | * Compilation réussie des fichiers source avec `linkedList.h`. * Intégration de la fonction `insertHeadCircular()`. * Écriture d'un programme de démonstration (dans `main.c`) pour tester la séquence d'insertion en tête. * Identification et correction d'une incohérence dans le nom d'un pointeur dans une fonction fournie par un membre. |
| **Difficultés** | La fonction `insertHeadCircular()` ne gérait pas correctement le cas où l'insertion suivait la fonction `createCircularList()`. J'ai dû implémenter un "wrapper" dans le fichier de test pour stabiliser la fonction lors de la compilation avec les autres. |
| **À Faire (Prochaine Séance)** | Intégrer la fonction de suppression d'occurrences (`deleteOccurrences`) et la fonction d'insertion dans une liste triée (simplement chaînée). Mettre à jour `main.c` pour démontrer ces nouvelles fonctionnalités. |

---

### **Séance 3 : Mardi 29/09/2025**

| Section | Détails de la Séance |
| :--- | :--- |
| **Durée Estimée** | 3 heures |
| **Objectif Principal** | Intégrer les fonctions d'insertion triée (liste simple) et de suppression d'occurrences. |
| **Avancement** | **Programme principal mis à jour.** J'ai intégré les fonctions `insertSortedList()` et `deleteOccurrences()`. J'ai créé des scénarios de démonstration pour chaque fonction dans `main.c` afin de montrer leur bon fonctionnement : création d'une liste désordonnée, tri, insertion triée, puis suppression de toutes les occurrences d'une valeur. |
| **Tâches Accomplies** | * Intégration finale de `insertSortedList()` (simplement chaînée). * Intégration finale de `deleteOccurrences()`. * Rédaction des scripts de démonstration dans `main.c` pour ces deux exigences du TD. * Révision du `readme.md` pour documenter les fonctionnalités désormais complètes. |
| **Difficultés** | La fonction `deleteOccurrences()` entraînait une erreur de `free()` si la tête de la liste était la valeur à supprimer. J'ai corrigé le code source en accord avec le développeur pour gérer correctement la réaffectation de la tête. |
| **À Faire (Prochaine Séance)** | Intégrer les fonctions restantes pour les listes doublement chaînées (triée et circulaire) et finaliser le programme principal. Préparer les rapports d'avancement pour la soumission. |