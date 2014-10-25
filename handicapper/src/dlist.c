/**************************************************************************************************/

/*
* File: dlist.c
* Author: Ray Weaver
* NetID: rayweaver
* Date: October 26, 2014
*
*
*/

/**************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "bool.h"
#include "dlist.h"
#include "score.h"



//////////////////////////////////////////////////////////////////////////////////////////////////
/*						doubly linked list functions											*/
//////////////////////////////////////////////////////////////////////////////////////////////////



/*
This function initializes a list by setting the head and tail to null, and the size of the list to 0
*/

void DListInit(DList* list) {
	if (list == NULL) {
		return;
	}
	else {
		list->head = NULL;
		list->tail = NULL;
		list->size = 0;
	}
} //end DListInit

void DListDestroy(DList* list) {

} // end DListDestroy


bool DListInsertAfter(DList* list, Score* currNode, Score* newNode) {
	if (currNode == NULL) {
		return DListInsertBefore(list, list->head, newNode);
	}
	else {
		newNode->next = currNode->next;
		newNode->prev = currNode;
		if (currNode->next) {
			currNode->next->prev = newNode;
		}
		currNode->next = newNode;
		DListUpdateHeadTail(list, currNode, newNode);
		list->size++;
	}
} // end DListInsertAfter


bool DListInsertBefore(DList* list, Score* currNode, Score* newNode) {
	if (currNode == NULL) {
		newNode->next = list->head;
		newNode->prev = NULL;
		if (list->head != NULL) {
			list->head->prev = newNode;
		}
		else {
			newNode->prev = currNode->prev;
			newNode->next = currNode;
			if (currNode->prev != NULL) {
				currNode->prev->next = newNode;
			}
			currNode->prev = newNode;
			DListUpdateHeadTail(list, currNode, newNode);
			list->size++;
		}
	}
} // end DListInsertBefore

Score* DListSearch(DList* list, char* key) {

} // end DListSearch



bool DListRemove(DList* list, Score* currNode) {
	if (currNode->prev == NULL) {
		list->head = currNode->next;
	}
} // end DListRemove



void DListUpdateHeadTail(DList* list, Score* currNode, Score* newNode) {
	if (currNode) {
		if (currNode->next == NULL)
		{
			list->tail = currNode;
		}
		if (currNode->prev == NULL) {
			list->head = currNode;
		}
	}

	if (newNode) {
		if (currNode->next == NULL)
		{
			list->tail = newNode;
		}
		if (currNode->prev == NULL) {
			list->head = newNode;
		}
	}
} // end GolfRoundsUpdateHeadTail

Score* createGolfRoundData(Score* currRound) {
	Score *result = NULL;

	result = (Score *) malloc(sizeof(Score));

	if (result != NULL) {
		result->next = NULL;
		result->prev = NULL;
	}

	return result;
}