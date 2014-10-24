/**************************************************************************************************/

/*
* File: main.c
* Author: Ray Weaver
* NetID: rayweaver
* Date: October 21, 2014
*
*
*/
//adding this hello here
/**************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "bool.h"
#include "score.h"


/**************************************************************************************************/

int main(int argc, char *argv[])
{
	//golfRounds 
	//double scores[10] = { 6.2, 8.3, 9.7, 10.1, 3.8, 7.6, 3.4, 1.2, 0.7, 12.2 };
	
	//ACTempData acTemps[MinPerDay];

	/*
	* check for the correct number of commandline arguments.  If incorrect
	* provide a simple usage message to the assist the user
	*
	*/
	if (argc != 4) {
		printf("\nUsage: %s revisionScoresFileIn recentScoresFileIn hcpCardFileOut \n\n", argv[0]);
		return -1;
	}

	GolfRounds myScores;
	GolfRoundsInit(&myScores);

	Score *torreyPines = NULL;
	Score *RanchoMurieta = NULL;
	Score *head = NULL;

	GolfRoundsInsertAfter(&myScores, 0, torreyPines);

	//createGolfRoundData(torreyPines);
	//createGolfRoundData(RanchoMurieta);
	

	//GolfRoundsInsertAfter(&myScores, 0, torreyPines);



	//calculateHandicap(scores);

	/*	if (!ReadTempDataFromFile(acTemps, argv[1])) {
	printf("Could not read from input file %s\n", argv[1]);
	return -1;
	}

	// function calls

	if (!WriteTempDataToFile(acTemps, argv[2])) {
	printf("Could not write to output file %s\n", argv[2]);
	return -1;
	}
	*/
	return 0;
}

/**************************************************************************************************/
