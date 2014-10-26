/**************************************************************************************************/

/*
* File: main.c
* Author: Ray Weaver
* NetID: rayweaver
* Date: October 26, 2014
*
*
*/

/**************************************************************************************************/

//use selection sort for sorting things

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "bool.h"
#include "score.h"
#include "dlist.h"
#include "reader.h"


/**************************************************************************************************/

int main(int argc, char *argv [])
{
	//golfRounds 
	//double scores[10] = { 6.2, 8.3, 9.7, 10.1, 3.8, 7.6, 3.4, 1.2, 0.7, 12.2 };

	//ACTempData acTemps[MinPerDay];

	/*
	* check for the correct number of commandline arguments.  If incorrect
	* provide a simple usage message to the assist the user
	*/

	if (argc != 4) {
		printf("\nUsage: %s revisionScoresFileIn recentScoresFileIn hcpCardFileOut \n\n", argv[0]);
		return -1;
	}

	int insert;

	DList *myScores;
	myScores = (DList*) malloc(sizeof(DList));
	DListInit(myScores);

	DListNode* RanchoMurieta;
	RanchoMurieta = (DListNode*) malloc(sizeof(DListNode));
	DListNode* TorreyPines;
	TorreyPines = (DListNode*) malloc(sizeof(DListNode));
	DListNode* WildHawk;
	WildHawk = (DListNode*) malloc(sizeof(DListNode));
	DListNode* RMS;
	RMS = (DListNode*) malloc(sizeof(DListNode));

	DListInsertAfter(myScores, NULL, RanchoMurieta);
	DListInsertAfter(myScores, NULL, TorreyPines);
	DListInsertAfter(myScores, NULL, WildHawk);
	DListInsertBefore(myScores, RanchoMurieta, RMS);


	if (!ReadInFile(myScores, argv[1])) {
		printf("Could not read from input file %s\n", argv[1]);
		return -1;
	}

	//	fscanf("%d", &insert);


	//calculateHandicap(scores);




	// function calls
	/*
	if (!WriteTempDataToFile(acTemps, argv[2])) {
	printf("Could not write to output file %s\n", argv[2]);
	return -1;
	}
	*/
	return 0;
}

/**************************************************************************************************/
