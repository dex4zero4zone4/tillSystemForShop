/**
*Evan Preisler - dex4zero4zone4
*NUI Galway - Till System for a shop
*Twitter @dex4zero4zone4
*2013
*/
#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "items.h"

str1 sFile1 = {0, "", "", "", "", 0, 0, 0.0};
str2 sFile2[1];

void main ()
{	
	startDay(sFile2);
	populateTextfile(sFile1);

	int i;

	do
	{
		printf("----------------------------------------------------\n");
		printf("Push 1 to sell item.\n");
		printf("Push 2 to return item.\n");
		printf("Push 3 to search stock on system.\n");
		printf("Push 4 to update stock.\n");
		printf("Push 5 to print all stock to screen.\n");
		printf("Push 6 to see cash in till for today only.\n");
		printf("Push 7 or higher to quit the program.\n");
		printf("?: ");
		scanf("%d", &i);

		switch (i)
		{
		case 1:
			printf("\n----------------------------------------------------\n");
			sellItem(sFile1, sFile2);
			printf("----------------------------------------------------\n\n");
			break;

		case 2:
			printf("\n----------------------------------------------------\n");
			returnBook (sFile1, sFile2);
			printf("----------------------------------------------------\n\n");
			break;
			
		case 3:
			printf("\n----------------------------------------------------\n");
			stockSwitch();
			printf("----------------------------------------------------\n\n");
			break;
			
		case 4:
			printf("\n----------------------------------------------------\n");
			updateStock();
			printf("----------------------------------------------------\n");
			break;
		
		case 5:
			printf("\n----------------------------------------------------\n");
			printItem(sFile1);
			printf("----------------------------------------------------\n\n");
			break;

		case 6:
			printf("\n----------------------------------------------------\n");
			cash(sFile2);
			printf("----------------------------------------------------\n\n");
			break;

		case 9:
			rofl();
			break;
		}
	}
	while (i<7 && i!=9);
	populateTextfile(sFile1);
	endStatement(sFile2);
}

void stockSwitch ()
{
	int i;

	do
	{
		printf("----------------------------------------------------\n");
		printf("Push 1 to search stock by code.\n");
		printf("Push 2 to search stock by title.\n");
		printf("Push 3 to search stock by author.\n");
		printf("Push 4 to search stock by category.\n");
		printf("Push 5 to search stock by series.\n");
		printf("Push 6 or higher to go back to main.\n");
		printf("?: ");
		scanf("%d", &i);
	
		switch (i)
		{
		case 1:
			printf("\n----------------------------------------------------\n");
			printBycode(sFile1);
			printf("----------------------------------------------------\n\n");
			break;
	
		case 2:
			printf("\n----------------------------------------------------\n");
			printBytitle(sFile1);
			printf("----------------------------------------------------\n\n");
			break;

		case 3:
			printf("\n----------------------------------------------------\n");
			printByauthor(sFile1);
			printf("----------------------------------------------------\n");
			break;

		case 4:
			printf("\n----------------------------------------------------\n");
			printBycategory(sFile1);
			printf("----------------------------------------------------\n\n");
			break;

		case 5:
			printf("\n----------------------------------------------------\n");
			printByseries(sFile1);
			printf("----------------------------------------------------\n");
			break;
		}
	}
	while (i<6);
}

void updateStock()
{
	int i;

	do
	{
		printf("----------------------------------------------------\n");
		printf("Push 1 to add to stock.\n");
		printf("Push 2 to delete from stock.\n");
		printf("Push 3 to update price of stock.\n");
		printf("Push 4 to update quantity.\n");
		printf("Push 5 or higher to go back to main.\n");
		printf("?: ");
		scanf("%d", &i);

		switch(i)
		{
		case 1:
			printf("\n----------------------------------------------------\n");
			addStock(sFile1);
			printf("----------------------------------------------------\n\n");
			break;

		case 2:
			printf("\n----------------------------------------------------\n");
			delStock(sFile1);
			printf("----------------------------------------------------\n\n");
			break;

		case 3:
			printf("\n----------------------------------------------------\n");
			updatePrice(sFile1);
			printf("----------------------------------------------------\n\n");
			break;

		case 4:
			printf("\n----------------------------------------------------\n");
			updateQuantity();
			printf("----------------------------------------------------\n\n");
			break;
		}
	}
	while(i<5);
}

void updateQuantity()
{
	int i;

	do
	{
		printf("----------------------------------------------------\n");
		printf("Push 1 to add stock to book.\n");
		printf("Push 2 to subtract stock from book.\n");
		printf("Push 3 or higher to go back to main.\n");
		printf("?: ");
		scanf("%d", &i);

		switch(i)
		{
		case 1:
			printf("\n----------------------------------------------------\n");
			addQuantity(sFile1);
			printf("----------------------------------------------------\n\n");
			break;

		case 2:
			printf("\n----------------------------------------------------\n");
			subQuantity(sFile1);
			printf("----------------------------------------------------\n\n");
			break;
		}
	}
	while(i<3);
}