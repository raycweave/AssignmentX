/**************************************************************************************************/

/*
* File: score.c
* Author: Ray Weaver
* NetID: rayweaver
* Date: October 26, 2014
*
*
*/

/**************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "bool.h"
#include "score.h"
#include "dlist.h"


float calculateHandicap(DList *list) {

	DListNode *i = NULL;
	float total = 0.0;
	float avgDifferential = 0.0;
	int roundedAvg;

	for (i = list->head; (i != NULL); i = i->next) {
		total = i->GolfScore.hcpDifferential + total;
	}

	avgDifferential = total / 10;

	avgDifferential = avgDifferential * 0.96;

	roundedAvg = (int) avgDifferential;

	if (roundedAvg >= 36.4) {
		roundedAvg = 36.4;
	}

	return roundedAvg;

}


