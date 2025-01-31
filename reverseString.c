//Jade Tu
//Chpt2 PA
#include <stdio.h>
#include <string.h>

void ReverseString(char* stringToReverse, int startChar, int endChar) {
	if (startChar >= endChar) { //base case 
		return;
	}
	
	char temp = stringToReverse[startChar]; //puts the start char in the temp variable
	stringToReverse[startChar] = stringToReverse[endChar]; //puts the end char in the start char
	stringToReverse[endChar] = temp; //puts the first char (stored in temp) into the end char
	
	ReverseString(stringToReverse, startChar + 1, endChar - 1); //recursive function that goes inwards to switch the char
}
int main(void) {
	char inStr[50];
   
	printf("Enter the string to be reversed: ");
	fgets(inStr, 20, stdin);
	inStr[strcspn(inStr, "\n")] = '\0'; // Remove newline character from input.
	
	int startChar = 0; //the start of the array which is index 0
	int endChar = strlen(inStr) - 1; //the end of the array which is the length - 1
	
	ReverseString(inStr, startChar, endChar); //calls for ReverseString
	
	printf("Reversed: %s\n", inStr);

   return 0;
}