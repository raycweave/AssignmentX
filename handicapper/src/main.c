/**************************************************************************************************/

/*
* File: main.c
* Author: Ray Weaver
* NetID: rayweaver
* Date: October 26, 2014
*/

/**************************************************************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "bool.h"
#include "score.h"
#include "dlist.h"
#include "reader.h"
#include "printing.h"

/**************************************************************************************************/

int main(int argc, char *argv [])
{
	
	/*
	* check for the correct number of commandline arguments.  If incorrect
	* provide a simple usage message to the assist the user
	*/

	if (argc != 4) {
		printf("\nUsage: %s revisionScoresFileIn recentScoresFileIn hcpCardFileOut \n\n", argv[0]);
		return false;
	}

	DList *myScores;
	myScores = (DList*) malloc(sizeof(DList));
	DListInit(myScores);

	/*
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
	*/


	if (!ReadInFile(myScores, argv[1])) {
		printf("Could not read from input file %s\n", argv[1]);
		return -1;
	}

	if (!ReadInFile(myScores, argv[2])) {
		printf("Could not read from input file %s\n", argv[1]);
		return -1;
	}

	SelectionSort(myScores);

	//SelectionSort()

	//	fscanf("%d", &insert);


	//calculateHandicap(scores);


	printHandicapCard(myScores);

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
