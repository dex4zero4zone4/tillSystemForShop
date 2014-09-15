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

int num=0;	

FILE*fptr; //Binary file with all the info
FILE*fptr1; //startDay text file
FILE*fptr2; //text file of stock

void startDay (str2 sFile2[])
{	
	int day, month, year;

	puts("**Black Books - Book Shop**");
	puts("Hello user, welcome to till system 4.5V.");

	fptr1=fopen("C:\\/**Your address line goes here where you have the project running.**/\\startDay.txt", "a");
	
	if (fptr1==NULL)
	{
		puts("Error, file not found...");
	}

	else 
	{ 
		printf("Please enter the day of the day. Enter DD MM YYYY\n");
		printf( "? " );
		scanf("%d %d %d", &day, &month, &year);
		fprintf(fptr1, "%d %d %d\n", day, month, year);
		fprintf(fptr1, "---------------------------------------------------------------------------------------------------------------------------\n");
		fprintf(fptr1, "%4s\t%30s\t%30s\t%30s\t%30s\t%10s\t%10s\t%10s\n", "Code", "Title", "Author", "Category", "Series", "Year", "Quantity", "Price");
	}
	fclose (fptr1);
	sFile2[0].totalCash=150.00;
}


void sellItem(str1 sFile1, str2 sFile2[])
{
	int code, sold;
	
	printf("Enter code of book for sale(1 - %d): ", num);
	scanf("%d", &code);
	printf("Number of copies sold: ");
	scanf("%d", &sold);
	
	fseek(fptr, (code-1)*sizeof(str1), SEEK_SET);
	fread(&sFile1, sizeof(str1), 1, fptr);
	
	if(strlen(sFile1.author)==0)
	{
		printf("Product not found. Try again\n");
	}

	else
	{	
		sFile1.quantity=sFile1.quantity-sold;
		fseek(fptr, (code-1)*sizeof(str1), SEEK_SET);
		fwrite(&sFile1, sizeof(str1), 1, fptr1);
		sFile2[0].totalCash=sFile2[0].totalCash+(sFile1.price*sold);
	}
	rewind(fptr);		
	printf("Sold %d of %s.\n", sold, sFile1.title);
	fptr1=fopen("C:\\/**Your address line goes here where you have the project running.**/\\startDay.txt", "a");
	fprintf(fptr1, "\nSold book:\n");
	fprintf(fptr1, "%4d\t%30s\t%30s\t%30s\t%30s\t%10d\t%10d\t%10.2f\n", sFile1.code, sFile1.title, sFile1.author, sFile1.category, sFile1.series, sFile1.year, sold, sFile1.price);
	fclose(fptr1);
}

void returnBook (str1 sFile1, str2 sFile2[])
{
	fptr1=fopen("C:\\/**Your address line goes here where you have the project running.**/\\startDay.txt", "a");
    int code, retQuantity;
	
	printf("Enter code of book you want to return(1 - %d): ", num);
	scanf("%d", &code);

	fseek(fptr, (code-1)*sizeof(str1), SEEK_SET);
	fread(&sFile1, sizeof(str1), 1, fptr);

	if (strlen(sFile1.author)==0) 
	{    
		printf("Book code %d does not exist.\n", code);
	} 
	else 
	{
		printf("%4s\t%30s\t%30s\n", "Code", "Title", "Quantity");
		printf("%4d\t%30s\t%30d\n", sFile1.code, sFile1.title, sFile1.quantity);
		printf("\n");
		printf("How much stock would you like to add to the system: ");
		scanf("%d", &retQuantity);
		sFile1.quantity=sFile1.quantity+retQuantity;
		fseek(fptr, (code-1)*sizeof(str1), SEEK_SET);
		fwrite(&sFile1, sizeof(str1), 1, fptr);
		sFile2[0].totalCash=sFile2[0].totalCash-(sFile1.price*retQuantity);
	}
	rewind(fptr);
	fprintf(fptr1, "\nReturned book: \n");
	fprintf(fptr1, "%4d\t%30s\t%30s\t%30s\t%30s\t%10d\t%10d\t%10.2f\n", sFile1.code, sFile1.title, sFile1.author, sFile1.category, sFile1.series, sFile1.year, retQuantity, sFile1.price);
	fclose(fptr1);
	printf("\n");
}

void cash(str2 sFile2[])
{	
	printf("Cash in till: %.2f\n", sFile2[0].totalCash);
}

void printBycode(str1 sFile1)
{
	int i;

	printf("Enter items stock code: ");
	scanf("%d", &i);
	fseek(fptr,(i-1)*sizeof(str1),SEEK_SET);
	fread(&sFile1, sizeof(str1), 1, fptr);
	printf("%4s\t%30s\t%30s\n", "Code", "Title", "Series");
	printf("%4d\t%30s\t%30s\n", sFile1.code, sFile1.title, sFile1.series);
	printf("\n");
	printf("%4s\t%30s\t%30s\n", "Code", "Author", "Category");
	printf("%4d\t%30s\t%30s\n", sFile1.code, sFile1.author, sFile1.category);
	printf("\n");
	printf("%4s\t%15s\t%15s\t%30s\n", "Code", "Year", "Quantity", "Price");
	printf("%4d\t%15d\t%15d\t%30.2f\n", sFile1.code, sFile1.year, sFile1.quantity, sFile1.price);
	printf("\n");
	rewind(fptr);
}

void printBytitle(str1 sFile1)
{
	int i;
	char check[30];
	
	printf("Enter title name: ");
	fflush(stdin);
	gets(check);
	strlwr(check);

	for (i=0; i<num; i++)
		{
			fread(&sFile1, sizeof(str1), 1, fptr);
			if(strcmp(sFile1.title, check)==0)
			{
				printf("%4s\t%30s\t%30s\n", "Code", "Title", "Series");
				printf("%4d\t%30s\t%30s\n", sFile1.code, sFile1.title, sFile1.series);
				printf("\n");
				printf("%4s\t%30s\t%30s\n", "Code", "Author", "Category");
				printf("%4d\t%30s\t%30s\n", sFile1.code, sFile1.author, sFile1.category);
				printf("\n");
				printf("%4s\t%15s\t%15s\t%30s\n", "Code", "Year", "Quantity", "Price");
				printf("%4d\t%15d\t%15d\t%30.2f\n", sFile1.code, sFile1.year, sFile1.quantity, sFile1.price);
				printf("\n");
			}
		}	
		rewind(fptr);
}

void printByauthor(str1 sFile1)
{
	int i;
	char check[30];

	printf("Enter author name: ");
	fflush(stdin);
	gets(check);
	strlwr(check);

	printf("%4s\t%30s\t%30s\n", "Code", "Title", "Series");
	for(i=0; i<num; i++)
	{	
		fread(&sFile1, sizeof(str1), 1, fptr);
		if(strcmp(sFile1.author, check)==0)
		{
			printf("%4d\t%30s\t%30s\n", sFile1.code, sFile1.title, sFile1.series);
		}
	}
	rewind(fptr);
	printf("\n");

	printf("%4s\t%30s\t%30s\n", "Code", "Author", "Category");
	for(i=0; i<num; i++)
	{	
		fread(&sFile1, sizeof(str1), 1, fptr);
		if(strcmp(sFile1.author, check)==0)
		{
			printf("%4d\t%30s\t%30s\n", sFile1.code, sFile1.author, sFile1.category);
		}
	}
	rewind(fptr);
	printf("\n");

	printf("%4s\t%15s\t%15s\t%30s\n", "Code", "Year", "Quantity", "Price");
	for(i=0; i<num; i++)
	{
		fread(&sFile1, sizeof(str1), 1, fptr);
		if(strcmp(sFile1.author, check)==0)
		{
			printf("%4d\t%15d\t%15d\t%30.2f\n", sFile1.code, sFile1.year, sFile1.quantity, sFile1.price);
		}
	}
	rewind(fptr);
	printf("\n");
}

void printBycategory(str1 sFile1)
{
	int i;
	char check[30];

	printf("Enter category type: ");
	fflush(stdin);
	gets(check);
	strlwr(check);

	printf("%4s\t%30s\t%30s\n", "Code", "Title", "Series");
	for(i=0; i<num; i++)
	{	
		fread(&sFile1, sizeof(str1), 1, fptr);
		if(strcmp(sFile1.category, check)==0)
		{
			printf("%4d\t%30s\t%30s\n", sFile1.code, sFile1.title, sFile1.series);
		}
	}
	rewind(fptr);
	printf("\n");

	printf("%4s\t%30s\t%30s\n", "Code", "Author", "Category");
	for(i=0; i<num; i++)
	{	
		fread(&sFile1, sizeof(str1), 1, fptr);
		if(strcmp(sFile1.category, check)==0)
		{
			printf("%4d\t%30s\t%30s\n", sFile1.code, sFile1.author, sFile1.category);
		}
	}
	rewind(fptr);
	printf("\n");

	printf("%4s\t%15s\t%15s\t%30s\n", "Code", "Year", "Quantity", "Price");
	for(i=0; i<num; i++)
	{
		fread(&sFile1, sizeof(str1), 1, fptr);
		if(strcmp(sFile1.category, check)==0)
		{
			printf("%4d\t%15d\t%15d\t%30.2f\n", sFile1.code, sFile1.year, sFile1.quantity, sFile1.price);
		}
	}
	rewind(fptr);
	printf("\n");
}

void printByseries(str1 sFile1)
{
	int i;
	char check[30];

	printf("Enter series name: ");
	fflush(stdin);
	gets(check);
	strlwr(check);

	printf("%4s\t%30s\t%30s\n", "Code", "Title", "Series");
	for(i=0; i<num; i++)
	{	
		fread(&sFile1, sizeof(str1), 1, fptr);
		if(strcmp(sFile1.series, check)==0)
		{
			printf("%4d\t%30s\t%30s\n", sFile1.code, sFile1.title, sFile1.series);
		}
	}
	rewind(fptr);
	printf("\n");

	printf("%4s\t%30s\t%30s\n", "Code", "Author", "Category");
	for(i=0; i<num; i++)
	{	
		fread(&sFile1, sizeof(str1), 1, fptr);
		if(strcmp(sFile1.series, check)==0)
		{
			printf("%4d\t%30s\t%30s\n", sFile1.code, sFile1.author, sFile1.category);
		}
	}
	rewind(fptr);
	printf("\n");

	printf("%4s\t%15s\t%15s\t%30s\n", "Code", "Year", "Quantity", "Price");
	for(i=0; i<num; i++)
	{
		fread(&sFile1, sizeof(str1), 1, fptr);
		if(strcmp(sFile1.series, check)==0)
		{
			printf("%4d\t%15d\t%15d\t%30.2f\n", sFile1.code, sFile1.year, sFile1.quantity, sFile1.price);
		}
	}
	rewind(fptr);
	printf("\n");
}

void addStock(str1 sFile1)
{
	int code;

	printf("Enter in book code number that is not being used (1 - %d)\nOr enter the next available book code number: ", num);
	scanf("%d", &code);

	fseek(fptr, (code-1)*sizeof(str1), SEEK_SET);
	fread(&sFile1, sizeof(str1), 1, fptr);

	if (strlen(sFile1.author)!=0)
	{
		printf("The book code for %d is already used.\n", sFile1.code);
	}

	else
	{
		sFile1.code=code;

		printf("Enter title: ");
		fflush(stdin);
		gets(sFile1.title);

		printf("Enter author: ");
		fflush(stdin);
		gets(sFile1.author);

		printf("Enter category: ");
		fflush(stdin);
		gets(sFile1.category);

		printf("Enter series: ");
		fflush(stdin);
		gets(sFile1.series);

		printf("Enter year: ");
		fflush(stdin);
		scanf("%d", &sFile1.year);

		printf("Enter quantity: ");
		fflush(stdin);
		scanf("%d", &sFile1.quantity);

		printf("Enter price: ");
		fflush(stdin);
		scanf("%f", &sFile1.price);

		fseek(fptr, (code-1)*sizeof(str1), SEEK_SET);
		fwrite(&sFile1, sizeof(str1), 1, fptr);
	}
	rewind(fptr);
	num++;
}

void delStock(str1 sFile1)
{
	str1 blankBook = {0, "", "", "", "", 0, 0, 0.0};

	int code; 

	printf("Enter book code to delete (1 - %d): ", num);
	scanf("%d", &code);

	fseek(fptr, (code-1)*sizeof(str1), SEEK_SET);
	fread(&sFile1, sizeof(str1), 1, fptr);

	if ( strlen(sFile1.author) == 0 ) 
	{    
		printf("Book code %d does not exist.\n", code);
	} 
	else 
	{ 
		fseek(fptr, (code-1)*sizeof(str1), SEEK_SET);
		fwrite(&blankBook, sizeof(str1), 1, fptr);
	}
	rewind(fptr);
}

void updatePrice(str1 sFile1)
{
	int code;
	float price;
	
	printf("Enter price on book code(1 - %d): ", num);
	scanf("%d", &code);

	fseek(fptr, (code-1)*sizeof(str1), SEEK_SET);
	fread(&sFile1, sizeof(str1), 1, fptr);

	if ( strlen(sFile1.author) == 0 ) 
	{    
		printf("Book code %d does not exist.\n", code);
	} 
	else 
	{
		printf("%4s\t%30s\t%30s\n", "Code", "Title", "Price");
		printf("%4d\t%30s\t%30.2f\n", sFile1.code, sFile1.title, sFile1.price);
		printf("\n");
		printf("Enter new price: ");
		scanf("%f", &price);
		sFile1.price=price;
		fseek(fptr, (code-1)*sizeof(str1), SEEK_SET);
		fwrite(&sFile1, sizeof(str1), 1, fptr);
	}
	rewind(fptr);
	printf("\n");
}

void addQuantity(str1 sFile1)
{
	int code, quantity;
	
	printf("Enter price on book code(1 - %d): ", num);
	scanf("%d", &code);

	fseek(fptr, (code-1)*sizeof(str1), SEEK_SET);
	fread(&sFile1, sizeof(str1), 1, fptr);

	if ( strlen(sFile1.author) == 0 ) 
	{    
		printf("Book code %d does not exist.\n", code);
	} 
	else 
	{
		printf("%4s\t%30s\t%30s\n", "Code", "Title", "Quantity");
		printf("%4d\t%30s\t%30d\n", sFile1.code, sFile1.title, sFile1.quantity);
		printf("\n");
		printf("How much stock would you like to add to system: ");
		scanf("%d", &quantity);
		sFile1.quantity=sFile1.quantity+quantity;
		fseek(fptr, (code-1)*sizeof(str1), SEEK_SET);
		fwrite(&sFile1, sizeof(str1), 1, fptr);
	}
	rewind(fptr);
	printf("\n");
}

void subQuantity(str1 sFile1)
{
	int code, quantity;
	
	printf("Enter price on book code(1 - %d): ", num);
	scanf("%d", &code);

	fseek(fptr, (code-1)*sizeof(str1), SEEK_SET);
	fread(&sFile1, sizeof(str1), 1, fptr);

	if ( strlen(sFile1.author) == 0 ) 
	{    
		printf("Book code %d does not exist.\n", code);
	} 
	else 
	{
		printf("%4s\t%30s\t%30s\n", "Code", "Title", "Quantity");
		printf("%4d\t%30s\t%30d\n", sFile1.code, sFile1.title, sFile1.quantity);
		printf("\n");
		printf("How much stock would you like to subtract from system: ");
		scanf("%d", &quantity);
		sFile1.quantity=sFile1.quantity-quantity;
		fseek(fptr, (code-1)*sizeof(str1), SEEK_SET);
		fwrite(&sFile1, sizeof(str1), 1, fptr);
	}
	rewind(fptr);
	printf("\n");
}

void printItem(str1 sFile1)
{
	int i;

	printf("%4s\t%30s\t%30s\n", "Code", "Title", "Series");
	for(i=0; i<num; i++)
	{	
		fread(&sFile1, sizeof(str1), 1, fptr);
		printf("%4d\t%30s\t%30s\n", sFile1.code, sFile1.title, sFile1.series);
	}
	rewind(fptr);
	printf("\n");

	printf("%4s\t%30s\t%30s\n", "Code", "Author", "Category");
	for(i=0; i<num; i++)
	{	
		fread(&sFile1, sizeof(str1), 1, fptr);
		printf("%4d\t%30s\t%30s\n", sFile1.code, sFile1.author, sFile1.category);
	}
	rewind(fptr);
	printf("\n");

	printf("%4s\t%15s\t%15s\t%30s\n", "Code", "Year", "Quantity", "Price");
	for(i=0; i<num; i++)
	{
		fread(&sFile1, sizeof(str1), 1, fptr);
		printf("%4d\t%15d\t%15d\t%30.2f\n", sFile1.code, sFile1.year, sFile1.quantity, sFile1.price);
	}
	rewind(fptr);
	printf("\n");

}

void rofl ()
{
	printf("\n ROFL:ROFL:LOL:ROFL:ROFL \n");
	printf("      ______||_____       \n");
	printf(" L   /        [ ]  |     \n");
	printf(" O===          [ ]  |_     \n");
	printf(" L   |________________]    \n");
	printf("         I       I       \n");
	printf("       -------------/    \n");
}

void populateTextfile (str1 sFile1)
{
	fptr=fopen("C:\\/**Your address line goes here where you have the project running.**/\\items.dat", "rb+");
	if(fptr==NULL)
	{
		puts("File not found.");
	}

	fptr2=fopen("C:\\/**Your address line goes here where you have the project running.**/\\items.txt", "w");
	
	if(fptr2==NULL)
	{
		puts("File not found.");
	}

	else
	{
		fprintf(fptr2, "%4s\t%30s\t%30s\t%30s\t%30s\t%10s\t%10s\t%10s\n", "Code", "Title", "Author", "Category", "Series", "Year", "Quantity", "Price");

		while(!feof(fptr))
		{
			fread(&sFile1, sizeof(str1), 1, fptr);

			if (strlen(sFile1.author)>0)
			{
				fprintf(fptr2, "%4d\t%30s\t%30s\t%30s\t%30s\t%10d\t%10d\t%10.2f\n", sFile1.code, sFile1.title, sFile1.author, sFile1.category, sFile1.series, sFile1.year, sFile1.quantity, sFile1.price);
				num++;
			}
		}
		fclose(fptr2);
		rewind(fptr);
	}
}

void endStatement(str2 sFile2[])
{
	fptr1=fopen("C:\\/**Your address line goes here where you have the project running.**/\\startDay.txt", "a");
	fprintf(fptr1, "Cash total: %.2f\n", sFile2[0].totalCash);
	fclose(fptr1);
	printf("\nHave a nice day ^_^ \n");
}