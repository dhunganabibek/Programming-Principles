/*including all the required libraries*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*defining maximum size for the array*/
#define SIZE 100

/*function prototype for alphabetCount*/
int alphabetCount(char myString[]);

/*function prototype for digitCount*/
int digitCount(char myString[]);

/*function prototype for lowerAlphabetCount*/
int lowerAlphabetCount(char myString[]);

/*function prototype for upperAlphabetCount*/
int upperAlphabetCount(char myString[]);

/*function prototype for vowelAndConsonantCount*/
void vowelAndConsonantCount(char myString[], int* vowelCount, int* consonantCount);

int main(void) {
	/*initializing all the required variables*/
	char myString[SIZE];
	int totalAlphabetCount;
	int totalDigitCount;
	int totalLowerAlphabetCount;
	int totalUpperAlphabetCount;
	int vowelCount = 0;
	int consonantCount = 0;

	/*input string from the user*/
	printf("Input the string:");
	fgets(myString, SIZE, stdin);

	/*calling alphabetcount function*/
	totalAlphabetCount = alphabetCount(myString);

	/*calling the function digitCount function*/
	totalDigitCount = digitCount(myString);

	/*calling the function lowerAlphabetCount*/
	totalLowerAlphabetCount = lowerAlphabetCount(myString);

	/*calling the function upperAlphabetCount*/
	totalUpperAlphabetCount = upperAlphabetCount(myString);

	/*calling vowelAndConsonatCount function*/
	vowelAndConsonantCount(myString, &vowelCount, &consonantCount);
	
	/*printing the result*/
	printf("The total number of alphabets:%d\n", totalAlphabetCount);
	printf("The total number of digits:%d\n", totalDigitCount);
	printf("The total number of lower case alphabets:%d\n", totalLowerAlphabetCount);
	printf("The total number of upper case alphabets:%d\n", totalUpperAlphabetCount);
	printf("The total number of vowels:%d\n", vowelCount);
	printf("The total number of consonants:%d\n", consonantCount);
	
	return 0;
}

/*defining function to calculate number of alphabets*/
int alphabetCount(char myString[]) {
	int i = 0;
	int count = 0;
	while (myString[i] != '\0') {
		if (isalpha(myString[i])) {
			count++;
		}
		i++;
	}

	return count;
}

/*function to calculate number of digits*/
int digitCount(char myString[]) {
	int count = 0;
	
	for (int i = 0; myString[i] != '\0'; i++) {
		if (isdigit(myString[i])) {
			count++;
		}
		
	}
	return count;
}

/*function to calculate the number of lower case alphabet*/
int lowerAlphabetCount(char myString[]) {
	int i = 0;
	int count = 0;
	while (myString[i] != '\0') {
		if (isalpha(myString[i])) {
			if ((myString[i] >= 'a' && myString[i] <= 'z')) {
				count++;
			}

		}
		i++;
	}
	return count;
}

/*function to calculate the number of uppercasealphabet*/
int upperAlphabetCount(char myString[]){
	int i = 0;
	int count = 0;
	while (myString[i] != '\0') {
		if (isalpha(myString[i])) {
			if ((myString[i] >= 'A' && myString[i] <= 'Z')) {
				count++;
			}

		}
		i++;
	}
	return count;;
}

/*function to count number of vowels*/
void vowelAndConsonantCount(char myString[], int* vowelsCount, int* consonantsCount) {
	
	for (int i = 0; myString[i] != '\0'; i++) {
		char a = myString[i];
		if (isalpha(a)) {
			if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') {
				(*vowelsCount) = (*vowelsCount) + 1;
			}
			else {
				(*consonantsCount) = (*consonantsCount) + 1;
			}

		}
	}
}