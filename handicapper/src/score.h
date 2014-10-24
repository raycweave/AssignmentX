/**************************************************************************************************/

/*
* File: score.h
* Author: Ray Weaver
* NetID: rayweaver
* Date: October 21, 2014
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



/* A list to store all the golf rounds*/
typedef struct GolfRounds_struct {
	int size;
	Score *head;
	Score *tail;
} GolfRounds;


double calculateHandicap(double scores []);

void GolfRoundsInit(GolfRounds* list);

void GolfRoundsDestroy(GolfRounds* list);

bool GolfRoundsInsertAfter(GolfRounds* list, Score* currNode, Score* newNode);

bool GolfRoundsInsertBefore(GolfRounds* list, Score* currNode, Score* newNode);

Score* GolfRoundsSearch(GolfRounds* list, char* key);

bool GolfRoundsRemove(GolfRounds* list, Score* currNode);

void GolfRoundsUpdateHeadTail(GolfRounds* list, Score* currNode, Score* newNode);

Score* createGolfRoundData(Score* currRound);

#endif