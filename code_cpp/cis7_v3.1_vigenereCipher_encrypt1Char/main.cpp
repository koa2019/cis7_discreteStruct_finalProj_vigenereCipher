/* 
 * File:    main.cpp
 * Author:  Danielle F
 * Created: 05-20-23 @ 5:36 PM
 * Purpose:  CIS 7 Final project Case 3: Vigenere Cipher v3.1_encrypt1Char
 * 
v3.1_createKey_encrypt:
 * Put all the code to find the key by deconstructing the plaintext and 
   encrypted strings into getKey();
 * Takes a plaintext string and finds each letters corresponding
   value in the alphabet [0,25] and sets the corresponding letter's array index to a new array.
  
 * Takes each letter of the plaintext string and applies the Encrypt formula by 
   adding each plaintext value with a shift value, then modulus 26 to 
   calculates the alphabet value of the encrypted letter. Encrypted value is
   then converted back into a letter that it represents and saves it to the key string.
   The key is 5 letters long, and it is repeated to match the length of the plaintext.
 * 
 * 
 * numAlpha = 26;
 * Encrypt formula:  Encrypt = (pTextStr + shift) mod 26
 * Decrypt formula:  Decrypt = (pTextStr - shift + 26) mod 26
 * Shift formula  :  Shift   = (pTextStr - Decrypt + 26) mod 26
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
//void menu();
void setAZArrays(char [], int []); // Set arrays with the alphabet [A,Z]==[0,25]
void setStr2IntArr(char[], string, int[]); // Convert each letter in string to its alphabet values. Save to int array
void setKey(char[], int[], int[], int[], string &, int); // Find the shift for each letter of the ciphered string 
void getKey(char[], int[]);

void prntAZ(char [], int []);
void prntCharArr(char []);
void prntIntArr(int [], int size = NUM_LTTRS);
void prntStrAndVal(string, string, int []); // Print converted strings alphabet values
void prnt3Strs(string, string, string);

//Code Begins Execution Here with function main

int main(int argc, char** argv) {

    //Set random number seed once here
    //srand(static_cast<unsigned int> (time(0)));
    //rand()%90+10;//2 digit numbers


    // Declare variables here
    char azChar[NUM_LTTRS] = {};
    int azVal[NUM_LTTRS] = {};
    string pTextStr = "";
    string encryptStr = "";
    string key = "";


   
    setAZArrays(azChar, azVal);  // Set arrays with the alphabet [A,Z]==[0,25]
    //prntAZ(azChar, azVal);
    getKey(azChar, azVal);// Find key  
    
    cout << endl << endl << "\tENCRYPT\n";
    
   


    pTextStr = "GEEKSFORGEEKS"; //"geeksforgeeks";    
    int pTextSize = pTextStr.length();
    int pTextArr[pTextSize] = {};
    int encryptArr[pTextSize] = {};
    int keyShiftArr[pTextSize] = {0,24,20,18,7, 0,24,20,18,7,0,24,20};
    int pTSize = pTextStr.length();
   
    
    // Convert each letter in string to its alphabet values. Save to int array
    setStr2IntArr(azChar, pTextStr, pTextArr);
    //prntStrAndVal("Plaintext", pTextStr, pTextArr);

    
    /**********Find the shift for each letter of the encrypted string **********/
    int shift = 0, encryptVal = 0, pTCharVal = 0;

    // Encrypt formula:  E = (P + K) mod 26.
    shift = keyShiftArr[2];
    pTCharVal = pTextArr[2];

    
    encryptVal = ((pTCharVal + shift + NUM_LTTRS) % NUM_LTTRS);
    encryptArr[2] = encryptVal;
    encryptStr += azChar[encryptVal];

        cout << pTextStr[2] << " =" << setw(2) << pTCharVal << "+("
             << setw(2) << shift << " shift) = " << setw(2) << encryptArr[2] 
             << " == "  << setw(2) << azChar[encryptVal] << endl;
    cout << "encryptStr: " << encryptStr << endl;







    return 0;
}


//******************************************************************************
//                          FUNCTION DEFINITIONS 
//******************************************************************************



//******************************************************************************
//                          
//******************************************************************************

void getKey(char azChar[], int azVal[]) {

    string pTextStr = "";
    string cipherStr = "";
    string key = "";
    pTextStr = "GEEKSFORGEEKS"; //"geeksforgeeks";
    cipherStr = "GCYCZFMLYLEIM";
    int pTextSize = pTextStr.length();
    int pText[pTextSize] = {};
    int cipher[pTextSize] = {};
    int keyShift[pTextSize] = {};


    // Convert each letter in string to its alphabet values. Save to int array
    setStr2IntArr(azChar, pTextStr, pText);
    //prntStrAndVal("Plaintext", pTextStr, pText);

    // Find the value of each letter in ciphered string and save azChar's index to an array
    setStr2IntArr(azChar, cipherStr, cipher);
    //prntStrAndVal("Ciphertext", cipherStr, cipher);


    // Find the shift for each letter of the ciphered string 
    // Calculate key by using a given plaintext string and a given encrypted string
    setKey(azChar, pText, cipher, keyShift, key, pTextSize);

    //cout << endl << "\nKey successfully created:";
    //prntStrAndVal("Key", key, keyShift);
    prnt3Strs(pTextStr, key, cipherStr);
    prntIntArr(pText, pTextSize); // Prints the alphabet's int values arrays [0,25]
    prntIntArr(keyShift, pTextSize);
    prntIntArr(cipher, pTextSize);

}


//******************************************************************************
//            Find the shift for each letter of the ciphered string 
// Calculate key by using a given plaintext string and a given encrypted string
//******************************************************************************

void setKey(char azChar[], int pText[], int cipher[], int keyShift[], string &key, int pTextSize) {

    int shift = 0,
            mod = 26,
            num = 0,
            cipherChar = 0, //
            decryptdChar = 0; // plaintext[i]

    for (int i = 0; i < pTextSize; i++) {

        cipherChar = cipher[i];
        decryptdChar = pText[i];

        num = (cipherChar - decryptdChar + mod);

        // Shift formula:  Shift = (pTextStr - Decrypt + 26) mod 26
        shift = (num - ((num / mod) * mod));
        keyShift[i] = shift;
        key += azChar[shift];

        //cout << setw(2) << decryptdChar  << " = " << pTextStr[i] << "->"
        //<< cipherStr[i] << " = " << setw(2) << cipherChar   << " "
        //<< " num = "       << setw(2) << num 
        //<< " shift = "     << setw(2) << keyShift[i] 
        //<< " == "          << setw(2) << azChar[shift] << endl;
    }
}

// Convert each letter in string to its alphabet values. Save to int array

void setStr2IntArr(char azChar[], string str, int intArr[]) {

    int count = 0;

    // Loop through each letter in pTextStr string
    for (int j = 0; j < str.length(); j++) {

        // Loop through each letter in alphabet
        for (int i = 0; i < NUM_LTTRS; i++) {

            // Compare one letter in pTextStr string to every letter in alphabet
            // If the letters match, then set pText element with value of i.
            if (str[j] == azChar[i]) {
                intArr[count] = i;
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

void prntStrAndVal(string str1, string str, int strVal[]) {

    cout << endl << "\t" << str1 << "'s string and its alphabet value\n"
            << "-----------------------------------------------------------";
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


// Prints the alphabet array and each letters value [0,25]

void prntAZ(char azChar[], int azVal[]) {
    prntCharArr(azChar); // Prints the alphabet char arrays
    prntIntArr(azVal); // Prints the alphabet's int values arrays [0,25]
}

// Print each letter in alphabets value

void prntIntArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(3) << arr[i];
    }
    cout << endl;
}

// Print all letters in alphabet

void prntCharArr(char charArr[]) {
    for (int i = 0; i < NUM_LTTRS; i++) {
        cout << setw(3) << charArr[i];
    }
    cout << endl;
}

void prnt3Strs(string pText, string key, string cipher) {

    cout << endl << "Plaintext encrypted with key\n----------------------------\n"
            << "Plaintext: " << pText << endl
            << setw(11) << "key: " << key << endl
            << setw(11) << "Cipher: " << cipher << endl;
}