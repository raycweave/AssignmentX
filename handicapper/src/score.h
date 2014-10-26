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
} Score;

#endif