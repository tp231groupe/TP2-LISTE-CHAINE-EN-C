#include <stdio.h>
#include <stdlib.h>
#include "../lib/linkedList.h"
#include "../lib/utils.h"



void printList(list l){
    for(node* cur = l; cur!= NULL ; cur = cur->next){
        printf("[%d]->",cur->val);
    }
    printf("NULL");
}


void printDoubleList(list l){
    for(node* cur = l; cur!= NULL ; cur = cur->next){
        printf("[%d]<->",cur->val);
    }
}

int main() {
    list l = NULL;    
    doubleList dl = NULL;

    int choix, val, pos, order;

    do {
        printf("\n===== MENU LISTES =====\n");
        printf("1. Insérer en tête (simple)\n");
        printf("2. Insérer en queue (simple)\n");
        printf("3. Insérer à une position (simple)\n");
        printf("4. Trier la liste simple\n");
        printf("5. Supprimer toutes occurrences (simple)\n");
        printf("6. Afficher la longueur de la liste simple\n");
        printf("7. Créer liste double circulaire\n");
        printf("8. Insérer tête double circulaire\n");
        printf("9. Insérer queue double circulaire\n");
        printf("10. Trier liste double circulaire\n");
        printf("11. Afficher longueur liste double circulaire\n");
        printf("12. Afficher la liste (simple)\n");
        printf("13. Afficher la liste (double)\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Valeur à insérer : ");
                scanf("%d", &val);
                l = insertHead(l, val);
                break;

            case 2:
                printf("Valeur à insérer : ");
                scanf("%d", &val);
                l = insertTail(l, val);
                break;

            case 3:
                printf("Valeur à insérer : ");
                scanf("%d", &val);
                printf("Position : ");
                scanf("%d", &pos);
                l = insertPos(l, val, pos);
                break;

            case 4:
                printf("Ordre (1 = croissant, 0 = décroissant) : ");
                scanf("%d", &order);
                l = sortList(l, order);
                break;

            case 5:
                printf("Valeur à supprimer : ");
                scanf("%d", &val);
                l = deleteOccurrences(l, val);
                break;

            case 6:
                printf("Longueur de la liste simple : %d\n", listLength(l));
                break;

            case 7:
                printf("Valeur initiale : ");
                scanf("%d", &val);
                dl = createDoubleCircularList(val);
                break;

            case 8:
                printf("Valeur à insérer : ");
                scanf("%d", &val);
                dl = insertHeadDoubleCircular(dl, val);
                break;

            case 9:
                printf("Valeur à insérer : ");
                scanf("%d", &val);
                dl = insertTailDoubleCircular(dl, val);
                break;

            case 10:
                printf("Ordre (1 = croissant, 0 = décroissant) : ");
                scanf("%d", &order);
                dl = sortDoubleList(dl, order);
                break;

            case 11:
                printf("Longueur de la liste double circulaire : %d\n", doubleListLength(dl));
                break;
            
            case 12:
                printList(l);
                break;

            case 13:
                printDoubleList(dl);

            case 0:
                printf("Fin du programme.\n");
                break;

            default:
                printf("Choix invalide !\n");
        }

    } while (choix != 0);

    deleteList(l);  

    return 0;
}
