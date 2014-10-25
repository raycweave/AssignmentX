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


void DListInit(DList* list);

void DListDestroy(DList* list);

bool DListInsertAfter(DList* list, Score* currNode, Score* newNode);

bool DListInsertBefore(DList* list, Score* currNode, Score* newNode);

Score* DListSearch(DList* list, char* key);

bool DListRemove(DList* list, Score* currNode);

void DListUpdateHeadTail(DList* list, Score* currNode, Score* newNode);

#endif