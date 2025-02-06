// Jade Tu
// Chpt3 PA
#include <stdio.h>

int PrintArray(int numbers[], int arrayLength, int i) { // Make a function to print both the unsorted array and the sorted array
	for (i = 0; i < arrayLength; i++) { // Prints the array starting from the first index (0) and incrementing by one to get to the last index
	printf("%d ", numbers[i]); // Prints the numbers from the array
	}	
}

int SortArray(int numbers[], int j, int i, int arrayLength) { // Make a function to sort the array from smallest to largest
	int temp; // Create a temp int to place an int into when swapping two numbers
	for (j = 0; j < arrayLength - 2; j++) { // Repeats the process 25 - 2 = 23 times to compare all the numbers in the array
		for (i = 0; i < arrayLength - 1; i++) { //Goes through the entire array starting from index 0
			if (numbers[i] > numbers[i + 1]) { //Swaps the adjacent numbers
			temp = numbers[i];
			numbers[i] = numbers[i + 1];
			numbers[i + 1] = temp;
			}
		}
		// PrintArray(numbers, arrayLength, i); // Prints out the change after each swap
		// printf("\n"); // Prints a newline
	}
}

int main(void) {
//Declare variables and the array
int numbers[] = {121, 668, 843, 757, 759, 272, 209, 795, 584, 226,998, 122, 902, 75, 924, 502, 903, 775, 470, 47, 118, 4, 586, 170, 553}; 
int arrayLength = 25;
int i;
int j;

//Outputs the text and the unsorted array, two newlines
printf("Unsorted Array:\n"); 
PrintArray(numbers, arrayLength, i); //Call a function to print the array
printf("\n\n");

//Call a function to sort the array
SortArray(numbers, j, i, arrayLength);

//Outputs the text and the sorted array 
printf("Sorted Array:\n");
PrintArray(numbers, arrayLength, i);
printf("\n");

return 0;
}