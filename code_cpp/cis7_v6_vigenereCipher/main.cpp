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
 * Encrypt formula:  Encrypt = (plaintext + shift) mod 26
 * Decrypt formula:  Decrypt = (plaintext - shift + 26) mod 26
 * Shift formula  :  Shift   = (plaintext - Decrypt + 26) mod 26
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
void setAZ(char []); // Set arrays with the alphabet [A,Z]==[0,25]
void printAZ(char []);


void setStr2IntArr(char[], string, int[]); // Convert each letter in string to its alphabet values. Save to int array
void setKey(char[], int[], int[], int[], string &, string, string, int); // Find the shift for each letter of the encrypted string 
void getKey(char[], int[]);
void encrypt(char[]);
void decrypt(char[]);
int  getShift(char[], string, string key);


void prntIntArr(int [], int size = NUM_LTTRS);
void prntStrAndVal(string, string, int []); // Print converted strings alphabet values
void prnt3Strs(string, string, string, string, string, string);
void prnt3Arr(int[], int[], int[], int size = 2);


//Code Begins Execution Here with function main

int main(int argc, char** argv) {


    // Declare variables here
    char azChar[NUM_LTTRS] = {};

    setAZ(azChar); // Set arrays with the alphabet [A,Z]==[0,25]
    //printAZ(azChar); // Prints the alphabet char arrays

    int ans = 0;
    do {
        cout<< "Menu\n"
            << "1. Encrypt\n"
            << "2. Decrypt\n"
            << "3. Exit\n";
        cin >> ans;
    

    switch(ans){
        case 1: { 
            encrypt(azChar);
            break;
        }
        case 2: { 
            decrypt(azChar);
            break;            
        }
        //default: { exit();}
    }
 
    } while ((ans == 1 || ans == 2));
    return 0;
}


//______________________________FUNCTION DEFINITIONS____________________________

//******************************************************************************
//                      Decrypt an encrypted string with key                    
//******************************************************************************

void decrypt(char azChar[]) {

    
    string cipher = "";
    string key = "";
    
    //  Get User inputs
    cout << "\n---------------------------------------------\n"
         << "\t\tDECRYPT\n\n"
         << "Enter encrypted:  ";
    
    //cin >> cipher;
    cipher = "GCYCZFMLYLEIM";
    cout << cipher << endl;
    
    
    cout << "Enter key:        ";
    //cin >> key;  
    key = "AYUSH";
    cout << key << endl;
    
    char plaintext[cipher.length()]={};
    int keySize = key.length();   
    
    for(int i=0; i < cipher.length(); i++){
        
        if(cipher[i]>=65 && cipher[i]<=97){
            
            //cout << "key[(i%keySize)] = " << toupper((key[(i%keySize)]-65))<< endl;
            plaintext[i] = ( cipher[i] - toupper((key[(i%keySize)]-65)));
        
            // Conditionals handles symbols
            //if(plaintext[i] < 'a') {plaintext[i] = cipher[i] +'z' - 'a' + 1;}
            //if(plaintext[i] < 'A') {plaintext[i] = cipher[i] +'Z' - 'A' + 1;}
            //cout<<plaintext[i]<<endl;
            
        }
    }
    
    cout << endl << "Plaintext: " << plaintext << endl;  
    cout << endl << "---------------------------------------------\n\n\n";
}


//******************************************************************************
//                      Encrypt plaintext string                      
//******************************************************************************

void encrypt(char azChar[]) {

    string plaintext = "";   
    string key = "";
    
    
    // Get User inputs
    cout << endl << "---------------------------------------------\n";
    cout << "\t\tENCRYPT\n\n";
    cout << "Enter Plaintext:  ";  
    //cin >> plaintext;
    plaintext = "GEEKSFORGEEKS"; //"geeksforgeeks"; //"GeEksForGEeks;    
    cout << plaintext << endl;   
    
    
    cout << "Enter key:        ";
    //cin >> key;
    key = "AYUSH";
    cout << key << endl;    
    
    char cipher[plaintext.length()]={};
    int keySize = key.length();   
    
    for(int i=0; i < plaintext.length(); i++){
        
        if(plaintext[i]>=65 && plaintext[i]<=97){
            
            //cout << "key[(i%keySize)] = " << toupper((key[(i%keySize)]-65))<< endl;
            cipher[i] = ( plaintext[i] + toupper((key[(i%keySize)]-65)));
        
            // Conditionals handles symbols
            if(cipher[i] > 'z') {cipher[i] = cipher[i] -'z' + 'a' - 1;}
            if(cipher[i] > 'Z') {cipher[i] = cipher[i] -'Z' + 'A' - 1;}
            //cout<<cipher[i]<<endl;
            
        }
    }
    
    cout << endl << "Ciper: " << cipher << endl;  
    cout << endl << "---------------------------------------------\n\n\n";
}



// Set alphabet array. 'A' ASCII value is 65. 'Z' = 90. 'a'=97. 'z'=122.
void setAZ(char azChar[]) {   
    char ch = 65;
    for (int i = 0; i < NUM_LTTRS; i++) {
        azChar[i] = ch; // Set array with every letter in alphabet
        ch++;
    }
}


// Print all letters in alphabet
void printAZ(char charArr[]) {
    for (int i = 0; i < NUM_LTTRS; i++) {
        cout << setw(3) << charArr[i];
    }
    cout << endl;
}