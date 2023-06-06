/* File:    main.cpp
 * Author:  Danielle F
 * Created: 05-20-23 @ 3 AM
 * Purpose:  CIS 7 Final project Case 3: Vigenere Cipher v4_decrypt
  
Takes an encrypted string and finds each letters corresponding value in the 
alphabet [0,25] and sets the corresponding letter's array index to a new array.

Takes a given key string and finds each letters corresponding value in the 
alphabet [0,25] and sets the corresponding letter's array index to a new array.
The key is 5 letters long, and it is repeated to match the length of the encrypted.

Loops through the encrypted string length, and applies the Decrypt formula 
by subtracting each decrypted value from a shift value, add 26, 
then modulus 26 to calculates the alphabet value of the decrypted letter. 
Decrypted value is then converted back into a letter that it represents 
and saves it to the decrypted string.

 
To do:
 * parse key to keySize.
 * Add user inputs for getKey(), encrypt(), getPT().

 
  
 Formulas
 * NUM_LTTRS = 26;
 * Encrypt formula:  Encrypt = (ptString + shift) mod 26
 * Decrypt formula:  Decrypt = (ptString - shift + 26) mod 26
 * Shift formula  :  Shift   = (ptString - Decrypt + 26) mod 26
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
void setAZArrays(char [], char[], int []); // Set arrays with the alphabet [A,Z]==[0,25]
void prntAZ(char[],char[],int[]);
void encrypt(char[],char[]);
void decrypt(char[],char[]);
void setString2IntArr(char[],char[], string, int[]); // Convert each letter in string to its alphabet values. Save to int array


void setKey(char[], int[], int[], int[], string &, string, string, int); // Find the shift for each letter of the encrypted string 
void getKey(char[], int[]);



void prntStrAndVal(string, string, int []); // Print converted strings alphabet values
void prnt3Strs(string, string, string, string, string, string);
void prnt3Arr(int[], int[], int[], int size = 2);


//Code Begins Execution Here with function main

int main(int argc, char** argv) {


    // Declare variables here
    char azUC[NUM_LTTRS] = {};
    char azLC[NUM_LTTRS] = {};
    int azVal[NUM_LTTRS] = {};
    setAZArrays(azUC,azLC, azVal); // Set arrays with the alphabet [A,Z]==[0,25]
    prntAZ(azUC, azLC, azVal);

    int ans = 0;
    do {
        cout << "Menu\n"
                << "1. Encrypt\n"
                << "2. Decrypt\n"
                << "3. Exit\n";
        cin >> ans;

        switch (ans) {
            case 1:
            {
                encrypt(azUC, azLC);
                break;
            }
            case 2:
            {
                decrypt(azUC, azLC);
                break;
            }
                //default: { exit();}
        }
    } while ((ans == 1 || ans == 2));
    return 0;
}


//______________________________FUNCTION DEFINITIONS____________________________

//******************************************************************************
//      BUG! key string needs to be parsed.
//                      Decrypt an encrypted string with key                    
//******************************************************************************

void decrypt(char azUC[], char azLC[]) {

    string cipher = "";
    string key = "";
    
    //  Get User inputs
    cout << "\t\tDECRYPT\n\n" << "Enter encrypted:  ";
    //cin >> cipher;
    cipher = "GCYCZFMLYLEIM";
    cout << cipher << endl;
    cout << "Enter key:        ";
    //cin >> key;  
    key = "ayush";//"AYUSH"; //"aYuSh";//
    cout << key << endl;
    
    
    int ciphSize = cipher.length();
    int ptArr[ciphSize] = {};
    int ciphArr[ciphSize] = {};
    int keySize = key.length();
    int shiftArr[ciphSize] = {}; //key: AYUSH = {0, 24, 20, 18, 7};
    string plaintext = "";

    // Convert each letter in encrypted string to its alphabet values. Save to int array
    setString2IntArr(azUC, azLC, cipher, ciphArr);
    //prntStrAndVal("Encrypted", cipher, ciphArr);

    // Convert each letter in key string to its alphabet values. Save to int array
    setString2IntArr(azUC, azLC, key, shiftArr);
    //prntStrAndVal("Key", key, shiftArr);


    /**********Decrypt string **********/
    int shift = 0, 
            ptCharVal = 0, 
            ciphCharVal = 0, 
            count = 0;

    // Loop through each letter in cipher string
    for (int i = 0; i < ciphSize; i++) {

        // Key repeats to match length of plaintext/cipher
        if (i % keySize == 0) { count = 0; }
        else { count++; }
        shift = shiftArr[count];
        ciphCharVal = ciphArr[i]; // encrypt letter value range [0,25]

        // Decrypt formula:  Decrypt = (ptString - shift + 26) mod 26
        ptCharVal = ((ciphCharVal - shift + NUM_LTTRS) % NUM_LTTRS);

        // Set array with decrypted values that represent letters
        ptArr[i] = ptCharVal;

        // Concatenate decrypted string
        plaintext += azUC[ptCharVal];
        key += azUC[shift];

        cout<< cipher[i] << " = " << setw(2) << ptCharVal << " + "
            << setw(2) << shift << " shift = " << setw(2) << ptArr[i]
            << " == " << setw(2) << azUC[ptCharVal] << endl;

    }
    cout << endl << "plaintext:  " << plaintext << endl;
    cout << endl << "-------------------------------------------------------\n\n";
}


//******************************************************************************
//                      Encrypt plaintext string                      
//******************************************************************************

void encrypt(char azUC[], char azLC[]) {

    // Get User inputs
    string ptString = ""; // plaintext
    string key = "";      // key for encrypting
    
    cout << "\t\tENCRYPT\n\n" << "Enter Plaintext:  ";
    //cin >> plaintext;
    ptString = "GeEksForGEeks"; //"geeksforgeeks"; //"GEEKSFORGEEKS"; // 
    cout << ptString << endl;
    cout << "Enter key:        ";
    //cin >> key;
    key = "aYuSh";//"ayush";//AYUSH";
    cout << key << endl;


    int ptSize = ptString.length(); // length of plaintext  
    int ptArr[ptSize] = {}; // int array to hold each ptString[i] numeric value in between [0,25]
    int ciphArr[ptSize] = {}; // int array to hold each ciper[i] numeric value in between [0,25]
    int keySize = key.length(); // length of key
    int shiftArr[ptSize] = {}; //Key: AYUSH = {0, 24, 20, 18, 7};
    string cipher = "";


    // Convert each letter in string to its alphabet value [0,25]. Save to int array
    setString2IntArr(azUC, azLC, ptString, ptArr);
    setString2IntArr(azUC, azLC, key, shiftArr);
    //prntStrAndVal("Plaintext", ptString, ptArr);
    //prntStrAndVal("key-shift", key, shiftArr); 

    /********** Encrypt the plaintext string **********/

    int shift = 0, // will hold current shift amount 
            cipCharVal = 0, // converted encrypted value [0,25]
            pTCharVal = 0,  //plaintext[i]'s numeric value [0,25]
            count = 0;     // count because key repeats itself to match the length of plaintext

    // Loop through each letter in ptString string
    cout<<endl;
    for (int i = 0; i < ptSize; i++) {

        // Key repeats to match the length of plaintext
        if (i % keySize == 0) {count = 0; }
        else { count++; }
        shift = shiftArr[count]; // current shift amount 
        pTCharVal = ptArr[i]; // plaintext's letter value [0,25]

        // Encrypt formula:  E = (Plaintext + shift) mod 26.       
        cipCharVal = ((pTCharVal + shift + NUM_LTTRS)) % NUM_LTTRS; // cipCharVal  = ((ptArr[i] + shiftArr[count] + NUM_LTTRS)) % NUM_LTTRS;       
        ciphArr[i] = cipCharVal;  // Set array with encrypted values that represent letters       
        cipher += azUC[cipCharVal]; // Concatenation cipher string
        
        cout<< ptString[i] << " = " << setw(2) << pTCharVal << " + "
            << setw(2) << shift << " shift " << setw(2) << "%26 = " << setw(2) 
            << ciphArr[i] << " == " << setw(2) << azUC[cipCharVal] << endl;
    }
    cout << endl << "Cipher:  " << cipher << endl;
    cout << endl << "-------------------------------------------------------\n\n\n";
}


// Convert each letter in string to its alphabet values. Save to int array
void setString2IntArr(char azUC[], char azLC[], string str, int strIntArr[]) {

    int count = 0;

    // Loop through each letter in ptString string
    for (int j = 0; j < str.length(); j++) {

        // Loop through each letter in alphabet
        for (int i = 0; i < NUM_LTTRS; i++) {

            if(str[j]>=65 && str[j]<=90){ // Uppercase letters
                // Compare one letter in ptString string to every letter in alphabet
                // If the letters match, then set pText element with value of i.
                if (str[j] == azUC[i]) {
                    strIntArr[count] = i;
                    count++;
                }
            } else { // lowercase letter
                if (str[j] == azLC[i]) {
                    strIntArr[count] = i;
                    count++;
                }
            }
        }
    }
}


// Set alphabet array and alphabet's value array
void setAZArrays(char azUC[], char azLC[], int azVal[]) {
    
    // Set array with every letter in alphabet
    char A = 65, a=97;  // 'A' ASCII value is 65. 'Z' = 90
    for (int i = 0; i < NUM_LTTRS; i++) {
        azUC[i] = A;
        azLC[i] = a;
        azVal[i] = i;
        A++;
        a++;
    }
}


// Prints the alphabet array and each letters value [0,25]
void prntAZ(char azUC[],char azLC[], int azVal[]) {
    
    cout << "azUC [] = {";
    for (int i = 0; i < NUM_LTTRS; i++) {
        cout << setw(3) << azUC[i];
    }
    cout << " }\n" << "azLC [] = {";
    for (int i = 0; i < NUM_LTTRS; i++) {
        cout << setw(3) << azLC[i];
    }
    cout << " }\n" << "azLC [] = {";
    for (int i = 0; i < NUM_LTTRS; i++) {
        cout << setw(3) << azVal[i];
    }
    cout << " }\n";
    cout<<"-------------------------------------------------------------------------------------------\n\n";
}