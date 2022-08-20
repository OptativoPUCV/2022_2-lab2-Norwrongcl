#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
	List *list= (List*) calloc(1,sizeof(list));
  return list;
}

void * firstList(List * list) {
	if (list-> current && list->head){
		list-> current= list-> head;
		return list-> head-> data;
	}
    return NULL;
}

void * nextList(List * list) {
	if (list-> current && list->current ->next){
		list-> current= list-> current-> next;
		return list-> current-> data;
	}
    return NULL;
}

void * lastList(List * list) {
	if (list-> tail && list->tail ->data){
		list-> current= list-> tail;
		return list-> tail-> data;
	}
    return NULL;
}

void * prevList(List * list) {
	if (list-> current && list->current ->prev){
		list-> current= list-> current-> prev;
		return list-> current-> data;
	}
    return NULL;
}

void pushFront(List * list, void * data) {
	Node * node= createNode(data);
  node-> next= list-> head;
  list-> head= node;
  list-> tail= node;
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
	Node* node= createNode(data);
	node-> prev= list-> current;
	list-> current-> next= node;
	list-> tail= node;
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
	int deleted= list-> current;
	list-> current= list-> current-> prev;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}
