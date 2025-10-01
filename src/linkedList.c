#include "../lib/linkedList.h"
#include "../lib/utils.h"

int isListEmpty(list l){
    return l == NULL;
}

int listLength(list l){

    int length = 0;

    for(node* current = l; current !=NULL; current= current->next){
        length++;
    }
    return length;
}

list createCircularList(int val){
    list l = malloc(sizeof(node));

    if(l == NULL){
        printf("Erreur: Echec de creation de la liste");
        return NULL;
    }

    l->val = val;
    l->next = l;
    return l;
}

doubleList insertHeadDoubleCircular(doubleList l, int val){
    if(isDoubleListEmpty(l))
        return createDoubleCircularList(val);
    
    doubleList new = malloc(sizeof(Node));

    if(new == NULL){
        printf("Erruer: Echec de creation de la liste");
        return NULL;
    }

    new->val = val;
    new->next = l;
    new->prev = l->prev;
    l->prev->next = new;
    l->prev = new;
    return new;
}

doubleList insertTailDoubleCircular(doubleList l, int val){
    if(isDoubleListEmpty(l))
        return createDoubleCircularList(val);
    
    doubleList new = malloc(sizeof(Node));

    if(new == NULL){
        printf("Erruer: Echec de creation de la liste");
        return NULL;
    }

    new->val = val;
    new->next = l;
    new->prev = l->prev;
    l->prev->next = new;
    l->prev = new;
    return l;
}

int isDoubleListEmpty(doubleList l){
    return l == NULL;
}

int doubleListLength(doubleList l){

    if(isDoubleListEmpty(l))
        return 0;

    int length = 1;

    for(Node* current = l->next; current !=l ; current= current->next){
        length++;
    }
    return length;
}

doubleList createDoubleCircularList(int val){
    doubleList l = malloc(sizeof(Node));

    if(l == NULL){
        printf("Erreur: echec de creation de la liste");
        return NULL;
    }

    l->val = val;
    l->next = l;
    l->prev = l;
    
    return l;

}

list insertHead(list l, int val){

    node* n = malloc(sizeof(node));

    if(n==NULL){
        printf("Erreur lors de la creation de la liste");
        return NULL;
    }
    
    n->val = val;
    n->next = l;

    return n;
}

list insertTail(list l, int val){
    node* n = malloc(sizeof(node));
    if(n== NULL){
        printf("Erreur: Echec lors de la creation de la liste");
        return NULL;
    } 

    n->val = val;
    n->next = NULL;

    if(isListEmpty(l)){
        return n;
    }
    else{
       list cur = l;
       while(cur->next!=NULL){
        cur= cur->next; 
       }
       cur->next = n;
    }    
     
    return l;
}

list insertPos(list l, int val, int pos){

    node* n = malloc(sizeof(node));

    if(n==NULL){
        printf("Erreur: Echec lors de la creation de la liste");
    }
    
    n->val = val;
    node* current = l;
    int i = 0;

    while(current->next!=NULL && i != pos-1){
        current = current->next;
        i++;
    }

    n->next = current->next;
    current->next = n;
    return l;

}

list sortList(list l, int order){
    list new = l;

    for(node* ni = new; ni != NULL; ni = ni->next){
        for(node* nj = ni; nj != NULL; nj = nj->next){
            if((ni->val < nj->val) == order){
                int temp = ni->val;
                ni->val = nj->val; 
                nj->val = temp;
            }
        }
    }

    return new;

}

doubleList sortDoubleList(doubleList l, int order){
    doubleList new = l;

    for(Node* ni = new; ni != NULL; ni = ni->next){
        for(Node* nj = ni; nj != NULL; nj = nj->next){
            if((ni->val < nj->val) == order){
                int temp = ni->val;
                ni->val = nj->val; 
                nj->val = temp;
            }
        }
    }

    return new; 
}

list insertSortedList(list l, int order,int val){
 
    list new = insertHead(l, val);
    new = sortList(new, order);
    return new;

}

doubleList insertSortedDoubleList(doubleList l, int order, int val){
    doubleList new = insertHeadDoubleCircular(l, val);
    new = sortDoubleList(new, order);
    return new;
}

void deleteList (list l){
    node* n= l;

   while(n!=NULL){
    node* temp = n;
    n = n->next;
    free(temp);
   }
}

list deleteOccurrences(list l, int val){ 
    node* n= l;
    node* prev = NULL;

    while(n!=NULL){
        if(n->val == val){   
            if(prev ==  NULL)
                l = n->next;
            else
                prev->next = n->next;
            n = n->next;
            free(n);
        }else{
            prev = n;
            n = n->next;
        }
    }
    
    return n;

}