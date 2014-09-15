/**
*Evan Preisler - dex4zero4zone4
*NUI Galway - Till System for a shop
*Twitter @dex4zero4zone4
*2013
*/
typedef struct{
	int code;
	char title [30];
	char author [30];
	char category [30];
	char series [30];
	int year;
	int quantity;
	float price;
}str1;

typedef struct{
	float totalCash;
}str2;

//(inside main.
void startDay(str2 sFile2[]);
void populateTextfile(str1 sFile1);
void sellItem(str1 sFile1, str2 sFile2[]);
void returnBook(str1 sFile1, str2 sFile2[]);
//stockSwitch
//updateStock
void cash(str2 sFile2[]);
void printItem(str1 sFile1);
void rofl();
void endStatement(str2 sFile2[]);
//)

void stockSwitch();
//(function belonging to stockSwitch.
void printBycode(str1 sFile1);
void printBytitle(str1 sFile1);
void printByauthor(str1 sFile1);
void printBycategory(str1 sFile1);
void printByseries(str1 sFile1);
//)

void updateStock();
//(function belonging to updateStock.
void addStock(str1 sFile1);
void delStock(str1 sFile1);
void updatePrice(str1 sFile1);
//updateQuantity
//)

void updateQuantity();
//(function belonging to updateQuantuty.
void addQuantity(str1 sFile1);
void subQuantity(str1 sFile1);
//)