## **22T2944-Philbert-NGAMIZE.md**

> Rapport d'avancement individuel (INF231 - TP/TD 2)

### **Séance 1 : Dimanche 27/09/2025**

| Section | Détails de la Séance |
| :--- | :--- |
| **Durée Estimée** | 3 heures |
| **Objectif Principal** | Définir la structure de la liste simple circulaire (`list`) et commencer l'implémentation de la fonction d'**insertion en tête : `insertHeadCircular()`**. |
| **Avancement** | **Implémentation du cas "Liste Vide" finalisée.** J'ai utilisé la structure `node` et le type `list`. J'ai écrit la logique pour allouer un nouveau nœud et gérer le cas où la liste est initialement vide : le nouveau nœud se pointe sur lui-même (`next = new_node`). |
| **Tâches Accomplies** | * Définition des types (`node`, `list`) selon `linkedList.h`. * Écriture de la fonction d'allocation de nœud. * Implémentation complète et vérification du cas *Liste Vide*. |
| **Difficultés** | Aucune difficulté majeure. Le reste de la séance a été consacré à planifier l'algorithme pour le cas *Liste Non Vide*, qui nécessite de trouver le dernier élément. |
| **À Faire (Prochaine Séance)** | Implémenter le cas général de `insertHeadCircular()` (liste non vide). |

---

### **Séance 2 : Lundi 28/09/2025**

| Section | Détails de la Séance |
| :--- | :--- |
| **Durée Estimée** | 4 heures |
| **Objectif Principal** | Finaliser et tester la fonction `insertHeadCircular()` pour le cas "Liste Non Vide". |
| **Avancement** | **Fonction `insertHeadCircular()` finalisée et opérationnelle.** La logique est implémentée en deux étapes clés : 1. Parcourir la liste pour localiser le **dernier nœud** (celui qui pointe actuellement vers la tête). 2. Mettre à jour les pointeurs : le `next` du nouveau nœud pointe vers l'ancienne tête, puis le `next` du dernier nœud pointe vers le nouveau nœud. |
| **Tâches Accomplies** | * Implémentation de la boucle de parcours itérative pour trouver le **dernier nœud** (`tail`). * Mise à jour correcte des deux pointeurs essentiels. * Écriture d'une fonction d'affichage temporaire pour valider le comportement circulaire. |
| **Difficultés** | J'ai eu une **erreur de segmentation** due à une mauvaise condition d'arrêt dans la recherche du dernier nœud, initialement. J'ai corrigé en m'assurant de référencer l'ancienne tête correctement avant de la remplacer par le nouveau nœud. |
| **À Faire (Prochaine Séance)** | Rédiger une série de tests unitaires pour `insertHeadCircular()` et commencer l'implémentation de la fonction d'insertion en queue. |

---

### **Séance 3 : Mardi 29/09/2025**

| Section | Détails de la Séance |
| :--- | :--- |
| **Durée Estimée** | 3 heures |
| **Objectif Principal** | Compléter les tests pour l'insertion en tête et implémenter la fonction d'**insertion en queue : `insertTailCircular()`**. |
| **Avancement** | **Tests de `insertHeadCircular` validés. `insertTailCircular` implémentée.** J'ai réutilisé la logique de parcours du dernier nœud (développée lundi) pour l'insertion en queue. La fonction est terminée pour les cas liste vide et non vide. |
| **Tâches Accomplies** | * Création de scénarios de tests dans `test_list.c` pour valider l'insertion en tête. * Implémentation complète de `insertTailCircular()` : le nouveau nœud se connecte à l'ancienne tête, et le dernier nœud (`tail`) se connecte au nouveau nœud. |
| **Difficultés** | Aucune difficulté majeure. Le travail précédent a simplifié l'approche pour l'insertion en queue. |
| **À Faire (Prochaine Séance)** | Tester `insertTailCircular()` et passer à la prochaine exigence de l'exercice : l'**insertion dans une liste triée** (`insertSortedList`) ou la **suppression d'occurrences** (`deleteOccurrences`). |