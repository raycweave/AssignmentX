/**************************************************************************************************/

/*
* File: score.h
* Author: Ray Weaver
* NetID: rayweaver
* Date: October 26, 2014
*
*
*/

/**************************************************************************************************/


#ifndef SCORE_H
#define SCORE_H



typedef struct Score_struct {
	bool counted;
	char scoreType[3];
	unsigned short month;
	unsigned int year;
	unsigned short adjGrossScore;
	double courseRating;
	unsigned short slopeRating;
	double hcpDifferential;
	struct Score_struct *next;
	struct Score_struct *prev;
} Score;

typedef struct DList_struct {
	int size;
	Score *head;
	Score *tail;
} DList;

double calculateHandicap(double scores []);

Score* createGolfRoundData(Score* currRound);

void DListInit(DList* list);

void DListDestroy(DList* list);

bool DListInsertAfter(DList* list, Score* currNode, Score* newNode);

bool DListInsertBefore(DList* list, Score* currNode, Score* newNode);

Score* DListSearch(DList* list, char* key);

bool DListRemove(DList* list, Score* currNode);

void DListUpdateHeadTail(DList* list, Score* currNode, Score* newNode);

#endif