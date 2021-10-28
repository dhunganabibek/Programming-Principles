

/*
 AUTHOR: BIBEK DHUNGANA
 DATE: APRIL 3,2021
 FILENAME: Lab8.c
 SPECIFICATION: This program takes character 'e from user to encrypt the file
                and it take character input 'd' to decrypt the file by shifting
                each character of file by 20 character.
 FOR: CS 1412 Programming Principles 2 Section 504
 */

//including all the required libararies
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

//function prototype for Encrypt
int Encrypt(char inputfile[]);

//function prototype for decrypt
int decrypt(char inputFile[]);

int main(int argc, const char * argv[]) {
    
    //char array to store file name
    char inputFile[50] = "original.txt";
    char encryptedFile[50] = "encrypted.txt";
    
    //asking the user for input
    printf("Enter 'e' for encryption and 'd' for decription:");
    char input = getchar();
    
    //if input is e, perform encryption
    if (tolower(input) == 'e'){
        //encript function produce encripted.txt from original file
        int encrytStatus = Encrypt(inputFile);
        if (encrytStatus == 1){
            printf("The file is successfully encripted\n");
        }
    }
    
    //if input is d, perform decryption
    if (tolower(input) == 'd'){
        //decrypt function produce decripted.txt
        int decryptStatus = decrypt(encryptedFile);
        if(decryptStatus ==1){
            printf("\nThe encripted file is sucessfully decripted\n");
        }
    }
    return 0;
}



/*
 NAME: Encrypt
 INPUT: char[]
 RETURN TYPE: int
 SPECIFICATION: This function takes character array as input file name.
                It encrypt the file and produce encrypted.txt file in
                current working directory. It return 1 indicating file is
                encrypted properly.
 */
int Encrypt(char inputFile[]){
    //opening the file in read mode
    FILE* inputFilePointer = fopen(inputFile,"r");
                                   
    //opening the file in write mode. It will create a file automatically
    //It will save the encrypted file under Encryptedfile.txt in current working directory
    FILE* outputFilePointer = fopen("encrypted.txt","w");
    
    //checking file was opened properly
    if (inputFilePointer == NULL){
        printf("There was error reading the file\n");
      }
    else{
    //reading the character of the file until end of file
    while(true){
      char c = fgetc(inputFilePointer);
      if (feof(inputFilePointer) != 0){
        break;
      }
      //write the encrypted text to the file by adding 20 to char
        fputc(c + 20, outputFilePointer);
        
    }
        
    //closing all the file pointer
    fclose(inputFilePointer);
    fclose(outputFilePointer);
        
    
}
return 1;
}

/*
 NAME: decrypt
 INPUT: char[]
 RETURN TYPE: int
 SPECIFICATION: This function takes character array as input file name.
                It decrypt the file and produce decrypted.txt file in
                current working directory. This function return 1 if
                the file is successfully decrypted.
 */
int decrypt(char inputFile[]){
    //opening file in read mode
    FILE* inputFilePointer = fopen(inputFile,"r");
    
    //open file in write mode
    FILE* outputFilePointer = fopen("decrypted.txt","w");
    
    //checking if file is successfully opened.
    if (inputFilePointer == NULL){
        printf("%s","The file can not be opened\n");
    }
    else{
        //reading the character of the file until end of file
        while(true){
          char c = fgetc(inputFilePointer);
          if (feof(inputFilePointer) != 0){
            break;
          }
      //write the encrypted text to the file by adding 20 to char
          char d = c - 20;
          fputc(d, outputFilePointer);
          printf("%c",d);
          }
    }
    return 1;
    
}


