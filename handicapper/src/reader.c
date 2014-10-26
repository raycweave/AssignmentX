/**************************************************************************************************/

/*
* File: reader.c
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

bool ReadInFile(DList *list, char *fileName) {

	FILE* inputFile;
	char string[100];

	bool counted;
	char star[2] = "";
	char scoreType[3] = "";
	unsigned short month = 0; //hu
	unsigned int year = 0; // u
	unsigned short adjGrossScore = 0; // hu
	double courseRating = 0; //lf
	unsigned short slopeRating = 0;
	double hcpDifferential = 0;

	inputFile = fopen(fileName, "r");

	if (inputFile == NULL) {
		printf("The file %s does not exist!\n", fileName);
		return false;
	}

	else {
		while (!feof(inputFile)) {
			fgets(string, 100, inputFile);
			if (string[0] == '*') {
				sscanf(string, "%c %s %hu/%u %hu %lf/%hu %lf", star, scoreType, &month, &year, &adjGrossScore, &courseRating, &slopeRating, &hcpDifferential);
				CreateNewNode(list, scoreType, month, year, adjGrossScore, courseRating, slopeRating, hcpDifferential);
			}
			
			else {
				sscanf(string, "%s %hu/%u %hu %lf/%hu %lf", scoreType, &month, &year, &adjGrossScore, &courseRating, &slopeRating, &hcpDifferential);
				CreateNewNode(list, scoreType, month, year, adjGrossScore, courseRating, slopeRating, hcpDifferential);
			}
		}
	}
	return true;
}