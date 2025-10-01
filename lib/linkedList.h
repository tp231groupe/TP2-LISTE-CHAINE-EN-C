#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node{
    int val;
    struct node* next;
}node;

typedef node* list;

typedef struct Node{
    int val;
    struct Node* next;
    struct Node* prev;
}Node;

typedef Node* doubleList;

/******************************
 * LISTE SIMPLEMENT CHAÎNÉE
 ******************************/
int isListEmpty(list l);
int listLength(list l);

list insertHead(list l, int val);
list insertTail(list l, int val);
list insertPos(list l, int val, int pos);

list sortList(list l, int order);
list insertSortedList(list l, int order, int val);

void deleteList(list l);
list deleteOccurrences(list l, int val);


/***************************************
 * LISTE SIMPLEMENT CHAÎNÉE CIRCULAIRE
 ***************************************/
list createCircularList(int val);
list insertHeadCircular(list l, int val);
list insertTailCircular(list l, int val);


/*************************************
 * LISTE DOUBLEMENT CHAÎNÉE
 *************************************/
int isDoubleListEmpty(doubleList l);
int doubleListLength(doubleList l);
doubleList sortDoubleList(doubleList l, int order);
doubleList insertSortedDoubleList(doubleList l, int order, int val);


/*****************************************
 * LISTE DOUBLEMENT CHAÎNÉE CIRCULAIRE
 *****************************************/
doubleList createDoubleCircularList(int val);
doubleList insertHeadDoubleCircular(doubleList l, int val);
doubleList insertTailDoubleCircular(doubleList l, int val);

#endif