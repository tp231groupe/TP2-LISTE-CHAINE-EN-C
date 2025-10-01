## **23H2300-Caleb-KEMMOEBUGIN.md**

> Rapport d'avancement individuel (INF231 - TP/TD 2)

### **Tâche Principale**

Implémentation de la fonction `doubleList insertTailDoubleCircular(doubleList l, int val)` (Insertion en queue dans une liste doublement chaînée circulaire).

---

### **Séance 1 : Dimanche 27/09/2025**

| Section | Détails de la Séance |
| :--- | :--- |
| **Durée Estimée** | 3 heures |
| **Objectif Principal** | Comprendre la structure `Node` (avec `prev`) et implémenter le cas limite de la **liste vide** pour `insertTailDoubleCircular()`. |
| **Avancement** | **Gestion du cas "Liste Vide" finalisée.** J'ai révisé les structures `Node` et `doubleList` de `linkedList.h`. Dans le cas où la liste est `NULL` : le nouveau nœud se pointe sur lui-même à la fois pour `next` et `prev`, car il devient l'unique élément. |
| **Tâches Accomplies** | * Rédaction de la fonction d'allocation et d'initialisation d'un `Node`. * Définition des conditions de sortie et de retour pour le cas `l == NULL`. * Test manuel de l'initialisation et des pointeurs `next` et `prev` pour le premier élément. |
| **Difficultés** | La vérification des deux pointeurs (`next` et `prev`) pointant vers le nouveau nœud lui-même nécessite une double vérification par rapport à la liste simplement chaînée, mais le concept reste simple pour le cas vide. |
| **À Faire (Prochaine Séance)** | Implémenter le cas général de `insertTailDoubleCircular()` (liste non vide). |

---

### **Séance 2 : Lundi 28/09/2025**

| Section | Détails de la Séance |
| :--- | :--- |
| **Durée Estimée** | 4 heures |
| **Objectif Principal** | Finaliser et tester la fonction `insertTailDoubleCircular()` pour le cas "Liste Non Vide". |
| **Avancement** | **Fonction `insertTailDoubleCircular()` implémentée avec succès.** La logique a été complétée : j'ai trouvé le dernier nœud (`tail`) en cherchant le nœud dont le pointeur `next` est la tête. Quatre pointeurs doivent être mis à jour, ce qui rend cette étape la plus délicate. |
| **Tâches Accomplies** | * Implémentation de la boucle pour trouver le dernier nœud (`tail`). * Mise à jour des pointeurs du **nouveau nœud** (`new_node`): * `new_node->prev = tail` * `new_node->next = head` * Mise à jour des pointeurs existants : * `tail->next = new_node` * `head->prev = new_node` |
| **Difficultés** | La principale difficulté était de ne pas oublier l'étape `head->prev = new_node`. Un oubli entraînait une rupture de la circularité "arrière" (via `prev`), bien que l'insertion en `next` semblait correcte. J'ai dû débugger en affichant les pointeurs `prev` et `next` de chaque nœud. |
| **À Faire (Prochaine Séance)** | Rédiger les tests unitaires pour `insertTailDoubleCircular()` et commencer l'implémentation de l'insertion en tête (`insertHeadDoubleCircular()`) pour cette même structure. |

---

### **Séance 3 : Mardi 29/09/2025**

| Section | Détails de la Séance |
| :--- | :--- |
| **Durée Estimée** | 3 heures |
| **Objectif Principal** | Compléter la validation de l'insertion en queue et entamer l'implémentation de l'insertion en tête. |
| **Avancement** | **Tests de `insertTailDoubleCircular` achevés et validés.** La fonction est stable pour tous les cas (y compris l'insertion dans une liste de 1 élément). J'ai ensuite pu implémenter rapidement le cas "Liste Non Vide" pour la fonction **`insertHeadDoubleCircular()`**. |
| **Tâches Accomplies** | * Création de scénarios de tests robustes pour valider la double circularité après l'insertion en queue. * Implémentation du cas "Liste Non Vide" pour `insertHeadDoubleCircular()`, en réutilisant la logique pour trouver le dernier nœud. * Préparation du code pour retourner la nouvelle tête (`new_node`) dans `insertHeadDoubleCircular()`. |
| **Difficultés** | Aucune difficulté majeure. La logique pour `insertHeadDoubleCircular` est un miroir de celle en queue, mais il faut être très attentif à retourner le nouveau nœud comme tête. |
| **À Faire (Prochaine Séance)** | Finaliser le cas "Liste Vide" de `insertHeadDoubleCircular()` et intégrer le code complet avec le reste de l'équipe pour les tests d'intégration. |