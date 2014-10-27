/**************************************************************************************************/

/*
* File: dlist.c
* Author: Ray Weaver
* NetID: rayweaver
* Date: October 26, 2014
*/

/**************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "bool.h"
#include "dlist.h"
#include "score.h"
#include "string.h"


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


void DListDestroy(DList* list) { //FIXME

} // end DListDestroy


bool DListInsertAfter(DList* list, DListNode* currNode, DListNode* newNode){

	if (list != NULL){
		if (currNode == NULL) {
			return DListInsertBefore(list, list->head, newNode);							 
		}

		else																				
		{
			newNode->next = currNode->next;
			newNode->prev = currNode;
			if (currNode->next != NULL) {													
				currNode->next->prev = newNode;
			}
			currNode->next = newNode;
		}
		DListUpdateHeadTail(list, currNode, newNode);
		list->size++;

		return true;
	}
	return false;
}


bool DListInsertBefore(DList* list, DListNode* currNode, DListNode* newNode){

	if (list != NULL) {
		if (currNode == NULL) {																	//list->head was passed in from insertafter as currNode, so if this executes list is empty
			newNode->next = list->head;															//if list is empty then next will just point to null because list->head = null
			newNode->prev = NULL;																//if head then prev is ALWAYS null
																									//DListUpdateHeadTail(list, currNode, newNode);
			if (list->head != NULL) {															//if head was actually already point to an element..
				list->head->prev = newNode;														//first elements prev is not pointing to newnode
			}
	
		}

		else {																					//insert before in the middle of list
																								//    newNode->prev = currNode->prev zx
																								//    newNode->next = currNode;
				newNode->prev = currNode->prev;
				newNode->next = currNode;
				if (currNode->prev != NULL){
					currNode->prev->next = newNode;
				}
				currNode->prev = newNode;
		}

		DListUpdateHeadTail(list, currNode, newNode);
		list->size++; //update above as well

		return true;
	}
	return false;

}

DList* DListSearch(DList* list, char* key) { // FIXME



} // end DListSearch



bool DListRemove(DList* list, DListNode* currNode) { //FIXME
	if (currNode->prev == NULL) {
		list->head = currNode->next;
	}
	else {
		currNode->prev->next = currNode->next;
	}
	if (currNode->next == NULL) {
		list->tail = currNode->prev;
	}
	else {
		currNode->next->prev = currNode->prev;
	}
	free(currNode);
} // end DListRemove



void DListUpdateHeadTail(DList* list, DListNode* currNode, DListNode* newNode) {
	if (currNode != NULL) {
		if (currNode->next == NULL)
		{
			list->tail = currNode;
		}
		if (currNode->prev == NULL) {
			list->head = currNode;
		}
	}

	if (newNode != NULL) {
		if (newNode->next == NULL)
		{
			list->tail = newNode;
		}
		if (newNode->prev == NULL) {
			list->head = newNode;
		}
	}
} 

DListNode CreateNewNode(DList* list, char scoreType [], unsigned short month, unsigned int year, unsigned short adjGrossScore, double courseRating, unsigned short slopeRating, double hcpDifferential) {
	DListNode* newNode;
	newNode = (DListNode*) malloc(sizeof(DListNode));

	newNode->GolfScore.counted = true;
	strcpy(newNode->GolfScore.scoreType, scoreType); 
	newNode->GolfScore.month = month;
	newNode->GolfScore.year = year;
	newNode->GolfScore.adjGrossScore = adjGrossScore;
	newNode->GolfScore.courseRating = courseRating;
	newNode->GolfScore.slopeRating = slopeRating;
	newNode->GolfScore.hcpDifferential = hcpDifferential;

	DListInsertAfter(list, list->tail, newNode);

	return *newNode;

}

void SelectionSort(DList *list) {

	DListNode *i = NULL;
	DListNode *j = NULL;
	DListNode *indexSmallest = NULL;																//need to find where to dereference and swap
	DListNode *temp = NULL;

	for (i = list->head; (i != NULL); i = i->next) {
		// Find index of largest remaining element
		indexSmallest = i;
		for (j = i->next; (j != NULL); j = j->next)
		{
			if (j->GolfScore.hcpDifferential < indexSmallest->GolfScore.hcpDifferential)
			{
				*indexSmallest = *j;
			}
		}
		*temp = *i;
		*i = *indexSmallest;
		*indexSmallest = *temp;
	}

}

	