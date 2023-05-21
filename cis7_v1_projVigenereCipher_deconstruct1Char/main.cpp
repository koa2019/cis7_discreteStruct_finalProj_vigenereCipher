/* 
 * File:    main.cpp
 * Author:  Danielle F
 * Created: 05-20-23 @ 5:36 PM
 * Purpose:  CIS 7 Final project Case 3: Vigenere Cipher v1_deconstruct1Char
 * 
 * v1_deconstruct1Char:
 * Creates an alphabet array with range [0,25].
  
 * Takes a plaintext string and finds each letters corresponding
   value in the alphabet [0,25] and sets the corresponding letter's array index to a new array.
  
 * Takes an encrypted string and finds each letters corresponding
   value in the alphabet [0,25] and sets the corresponding letter's array index to a new array.
 
 * Uses third letter from plaintext and third letter from cipher and applies 
   the Shift formula using the alphabet values of each corresponding letter and 
   finds the number of places the plaintext letter was shift. The shift value is
   then converted back to a letter it represents in the key string.
 
 * 
 * numAlpha = 26;
 * Encrypt formula:  Encrypt = (pTextString + shift) mod 26
 * Decrypt formula:  Decrypt = (pTextString - shift + 26) mod 26
 * Shift formula  :  Shift   = (pTextString - Decrypt + 26) mod 26
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>  //setw()
#include <cstdlib> // rand()
#include <ctime>   // time()
#include <string> //string
#include <cstring> //c-strings
#include <cctype> // tolower()
#include <array> 
using namespace std; //STD Name-space where Library is compiled

//05-20-23 @4:42 pm

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions
const int NUM_LTTRS = 26;

//Function Prototypes
void setAZArrays(char [], int []);
void setStrArr(char[], string, int[]);
void prntCharArr(char []);
void prntIntArr(int [], int);
void prntStrArray(string, string, int []);

//Code Begins Execution Here with function main

int main(int argc, char** argv) {

    //Set random number seed once here
    //srand(static_cast<unsigned int> (time(0)));
    //rand()%90+10;//2 digit numbers

    
    /**********Declare variables here**********/
    char azChar[NUM_LTTRS] = {};
    int azVal[NUM_LTTRS] = {};
    string pTextString = "";
    string encryptdString = "";
    string key = "";
    pTextString = "GEEKSFORGEEKS"; //"geeksforgeeks";
    encryptdString = "GCYCZFMLYLEIM";
    int pTextSize = pTextString.length();
    int pText[pTextSize] = {};
    int encrypt[pTextSize] = {};
    int keyShiftArr[pTextSize] = {};

    
    /**********Initialize variables here**********/

    // Set arrays with the alphabet [A,Z]==[0,25]
    setAZArrays(azChar, azVal);
    //prntCharArr(azChar);
    //prntIntArr(azVal, NUM_LTTRS);


    // Find the value of each letter in pTextString string and save azChar's index to an array
    setStrArr(azChar, pTextString, pText);
    //prntStrArray("Plaintext", pTextString, pText);

    // Find the value of each letter in encrypted string and save azChar's index to an array
    setStrArr(azChar, encryptdString, encrypt);
    //prntStrArray("Ciphertext", encryptdString, encrypt);


    /**********Find the shift for each letter of the encrypted string **********/
    int shift = 0, mod = 26, num = 0, encryptdChar = 0, decryptdChar = 0;

    encryptdChar = encrypt[2];
    decryptdChar = pText[2];

    num = (encryptdChar - decryptdChar + mod);

    // Shift formula:  Shift = (pTextString - Decrypt + 26) mod 26
    shift = (num - ((num / mod) * mod));
    keyShiftArr[pTextSize] = shift;
    key += azChar[shift];

    cout << "num = " << num << "  shift = " << shift << " == " << azChar[shift] << endl;
    cout << "key: " << key << endl;


    return 0;
}

/**********  Function Definitions  **************/
void setStrArr(char azChar[], string pTextString, int pText[]) {

    int count = 0;

    // Loop through each letter in pTextString string
    for (int j = 0; j < pTextString.length(); j++) {

        // Loop through each letter in alphabet
        for (int i = 0; i < NUM_LTTRS; i++) {

            // Compare one letter in pTextString string to every letter in alphabet
            // If the letters match, then set pText element with value of i.
            if (pTextString[j] == azChar[i]) {
                pText[count] = i;
                count++;
            }
        }
    }
}


// Set alphabet array and alphabet's value array

void setAZArrays(char azChar[], int azVal[]) {

    // 'A' ASCII value is 65. 'Z' = 90
    char ch = 65;

    // Set array with every letter in alphabet
    for (int i = 0; i < NUM_LTTRS; i++) {
        azChar[i] = ch;
        ch++;
    }

    // Set each letter in alphabets with corresponding value
    for (int i = 0; i < NUM_LTTRS; i++) {
        azVal[i] = i;
    }
}


// Print converted strings alphabet values

void prntStrArray(string str1, string str, int strVal[]) {

    for (int i = 0; i < str.length(); i++) {

        if (i == 0) {
            cout << endl << setw(10) << str1 << ":  " << str[i];
        } else {
            cout << setw(3) << str[i];
        }
        //cout << str[i] << " == " << strVal[i] << " \n";
    }

    for (int i = 0; i < str.length(); i++) {

        if (i == 0) {
            cout << endl << setw(10) << "char value" << ":  " << strVal[i];
        } else {
            cout << setw(3) << strVal[i];
        }
    }
    cout << endl;
}

// Print each letter in alphabets value

void prntIntArr(int arr[], int pTextSize) {
    for (int i = 0; i < pTextSize; i++) {
        cout << setw(3) << arr[i];
    }
    cout << endl;
}

// Print all letters in alphabet

void prntCharArr(char azChar[]) {
    for (int i = 0; i < NUM_LTTRS; i++) {
        cout << setw(3) << azChar[i];
    }
    cout << endl;
}