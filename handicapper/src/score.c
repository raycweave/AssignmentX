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


double calculateHandicap(double scores[]) {

	int i = 0;
	float total = 0.0;

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


