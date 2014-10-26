/**************************************************************************************************/

/*
* File: dlist.h
* Author: Ray Weaver
* NetID: rayweaver
* Date: October 26, 2014
*
*
*/

/**************************************************************************************************/



#ifndef DLIST_H
#define DLIST_H

#include "score.h"
#include "bool.h"

typedef struct DListNode_struct {

	Score GolfScore;
	struct DListNode_struct *next;
	struct DListNode_struct *prev;

} DListNode;

typedef struct DList_struct {

	int size;
	DListNode *head;
	DListNode *tail;

} DList;


void DListInit(DList* list);

void DListDestroy(DList* list);

bool DListInsertAfter(DList* list, DListNode* currNode, DListNode* newNode);

bool DListInsertBefore(DList* list, DListNode* currNode, DListNode* newNode);

DList* DListSearch(DList* list, char* key);

bool DListRemove(DList* list, DListNode* currNode);

void DListUpdateHeadTail(DList* list, DListNode* currNode, DListNode* newNode);

DListNode CreateNewNode(DList* list, char scoreType [], unsigned short month, unsigned int year, unsigned short adjGrossScore, double courseRating, unsigned short slopeRating, double hcpDifferential);

void SelectionSort(DList *list);

#endif