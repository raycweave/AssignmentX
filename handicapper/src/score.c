/**************************************************************************************************/

/*
* File: score.c
* Author: Ray Weaver
* NetID: rayweaver
* Date: October 21, 2014
*
*
*/

/**************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "bool.h"
#include "score.h"

double calculateHandicap(double scores[]) {
	int i = 0;
	double total = 0.0;

	for (i = 0; i < 10; ++i) {
		total = total + scores[i];
	}

	//printf("%.1lf\n", total); // prints the calculated sum
	total = (total / 10);
	printf("%.2lf\n", total); // prints the calculated average
	//total = (total * 0.96); // calculates the average * 0.96

	// FIXME//
	//NEED TO TRUNCATE VALUE AND CHANGE VARIABLE NAME

	printf("%lf\n", total);

	if (total >= 36.4) {
		total = 36.4;
	}

}

void readRevisionScoresFile(char* fileName) {

	FILE* revisionScoresFileIn;
	revisionScoresFileIn = fopen(fileName, "r");

	if (revisionScoresFileIn == NULL) {
		printf("The file does not exist!\n");
	}

	else {
		while (fscanf(revisionScoresFileIn, "%s\t%d/%d %d\t%lf/%d\t%lf"));
	}

}

//////////////////////////////////////////////////////////////////////////////////////////////////
/*						doubly linked list functions											*/
//////////////////////////////////////////////////////////////////////////////////////////////////



/*
This function initializes a list by setting the head and tail to null, and the size of the list to 0
*/

void GolfRoundsInit(GolfRounds* list) {
	if (list == NULL) {
		return;
	}
	else {
		list->head = NULL;
		list->tail = NULL;
		list->size = 0;
	}
} //end DListInit


/*

*/


void GolfRoundsDestroy(GolfRounds* list) {

} // end DListDestroy


bool GolfRoundsInsertAfter(GolfRounds* list, Score* currNode, Score* newNode) {
	if (currNode == NULL) {
		return GolfRoundsInsertBefore(list, list->head, newNode);
	}
	else {
		newNode->next = currNode->next;
		newNode->prev = currNode;
		if (currNode->next) {
			currNode->next->prev = newNode;
		}
		currNode->next = newNode;
		GolfRoundsUpdateHeadTail(list, currNode, newNode);
		list->size++;
	}
} // end DListInsertAfter


bool GolfRoundsInsertBefore(GolfRounds* list, Score* currNode, Score* newNode) {
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
			GolfRoundsUpdateHeadTail(list, currNode, newNode);
			list->size++;
		}
	}
} // end DListInsertBefore

Score* GolfRoundsSearch(GolfRounds* list, char* key) {

} // end DListSearch



bool GolfRoundsRemove(GolfRounds* list, Score* currNode) {
	if (currNode->prev == NULL) {
		list->head = currNode->next;
	}
} // end DListRemove



void GolfRoundsUpdateHeadTail(GolfRounds* list, Score* currNode, Score* newNode) {
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

	result = (Score *)malloc(sizeof(Score));

	if (result != NULL) {
		result->next = NULL;
		result->prev = NULL;
	}

	return result;
}