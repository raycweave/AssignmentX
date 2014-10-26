/**************************************************************************************************/

/*
* File: printing.c
* Author: Ray Weaver
* NetID: rayweaver
* Date: October 26, 2014
*/

/**************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "bool.h"
#include "dlist.h"
#include "score.h"
#include "string.h"

void printHandicapCard(DList *list) {

	printf("Name: Ray Weaver\n");
	printf("Club: ECE 275\n");
	printf("Club #: Assignment X   GHIN #: rayweaver\n");
	printf("Scores Posted: %d      USGA HCP Index: %lf");
	printf("Effective Date: mm/dd/yyyy\n");
	printf("       Score history: Most recent first *If Used\n");
	printf("%d%c%s       %d%c%s       %d%c%s       %d%c%s       %d%c%s\n");
	printf("%d%c%s       %d%c%s       %d%c%s       %d%c%s       %d%c%s\n");
	printf("%d%c%s       %d%c%s       %d%c%s       %d%c%s       %d%c%s\n");
	printf("%d%c%s       %d%c%s       %d%c%s       %d%c%s       %d%c%s\n");

}

/*
DList *temp = list;
DListNode *tempNode;
tempNode = temp->head;

while (temp != NULL) {
printf("%lf\n", tempNode->GolfScore.hcpDifferential);
tempNode = tempNode->next;
if (tempNode == NULL) {
break;
}
}

*/