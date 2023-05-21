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
* Add user inputs for getKey(), getEncrypt(), getPT().

 
  
 Formulas
 * NUM_LTTRS = 26;
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
void setKey(char[], int[], int[], int[], string &,string,string, int); // Find the shift for each letter of the encrypted string 
void getKey(char[], int[]);
void getEncrypt(char[]);
void getDecrypt(char[]);

void prntAZ(char [], int []);
void prntCharArr(char []);
void prntIntArr(int [], int size = NUM_LTTRS);
void prntStrAndVal(string, string, int []); // Print converted strings alphabet values
void prnt3Strs(string, string, string,string,string,string);
void prnt3Arr(int[], int[], int[], int size=2);


//Code Begins Execution Here with function main
int main(int argc, char** argv) {

    //Set random number seed once here
    //srand(static_cast<unsigned int> (time(0)));
    //rand()%90+10;//2 digit numbers


    // Declare variables here
    char azChar[NUM_LTTRS] = {};
    int azVal[NUM_LTTRS] = {};
    
    setAZArrays(azChar, azVal); // Set arrays with the alphabet [A,Z]==[0,25]
    //prntAZ(azChar, azVal);
    getKey(azChar, azVal); // Find key  
    getEncrypt(azChar);
    getDecrypt(azChar);
    
    return 0;
}


//______________________________FUNCTION DEFINITIONS____________________________

//******************************************************************************
//      BUG! key string needs to be parsed.
//                      Decrypt an encrypted string with key                    
//******************************************************************************
void getDecrypt(char azChar[]){
    
    cout<<endl<<"-------------------------------------------------------\n\n";
    cout << " Decrypt string with key Section \n"; 
    string decryptStr = "";
    string encryptStr = "";
    string key = "";

    // UNCOMMENT LATER
    //cout << "Enter encrypted string\n";
    //cin >> encryptStr;
    //cout << "Enter key\n";
    //cin >> key;    
    
    encryptStr = "GCYCZFMLYLEIM";
    key = "AYUSH";
    int encryptSize = encryptStr.length();
    int decryptArr[encryptSize] = {};
    int encryptArr[encryptSize] = {};
    int keySize = key.length();
    int keyShiftArr[encryptSize] = {};//{0, 24, 20, 18, 7};


    // Convert each letter in encrypted string to its alphabet values. Save to int array
    setStr2IntArr(azChar, encryptStr, encryptArr);
    //prntStrAndVal("Encrypted", encryptStr, encryptArr);

    // Convert each letter in key string to its alphabet values. Save to int array
    setStr2IntArr(azChar, key, keyShiftArr);
    //prntStrAndVal("Key", key, keyShiftArr);
    
    
    /**********Decrypt string **********/
    cout << endl << "\nEncrypted string successfully decrypted:\n";
    int shift = 0, decryptVal = 0, encCharVal = 0, count = 0;
    
    // Loop through each letter in encryptStr string
    for (int i = 0; i < encryptSize; i++) {

        // Key repeats every keySize times
        if (i%keySize==0) {
            count = 0;
        } else {
            count++;
        }
        
        shift = keyShiftArr[count];
        
        // encrypt letter value range [0,25]
        encCharVal = encryptArr[i];

        // Decrypt formula:  Decrypt = (pTextStr - shift + 26) mod 26
        decryptVal = ((encCharVal - shift + NUM_LTTRS) % NUM_LTTRS);

        // Set array with decrypted values that represent letters
        decryptArr[i] = decryptVal;

        // Concatenate decrypted string
        decryptStr += azChar[decryptVal];
        key += azChar[shift];
        
        cout << encryptStr[i] << " = " << setw(2) << decryptVal << " + "
                << setw(2) << shift << " shift = " << setw(2) << decryptArr[i]
                << " == " << setw(2) << azChar[decryptVal] << endl;

    }
    cout << endl << "\nEncrypted string successfully decrypted:";
    prnt3Strs(encryptStr, key, decryptStr,"Cipher", "decrypted", "Decrypted");
     cout<<endl<<"-------------------------------------------------------\n\n";
}


//******************************************************************************
//                      Encrypt plaintext string                      
//******************************************************************************
void getEncrypt(char azChar[]){
    
    cout<<endl<<"-------------------------------------------------------\n\n";
    cout << "   Get Encrypted String with Custom Key Section\n"; 
    
    
    string pTextStr = "";
    string encryptStr = "";
    string key = "";

    // Get User inputs
    // UNCOMMENT LATER
    //cin >> pTextStr;
    //cin >> keySize;
    //for(int i=0; i<keySize; i++){
        //cin >> keyShiftArr[i]; }
    
    pTextStr = "GEEKSFORGEEKS"; //"geeksforgeeks";    
    int pTextSize = pTextStr.length();
    int pTextArr[pTextSize] = {};
    int encryptArr[pTextSize] = {};
    int keySize = 5;
    int keyShiftArr[pTextSize] = {0, 24, 20, 18, 7};
    int pTSize = pTextStr.length();


    // Convert each letter in string to its alphabet values. Save to int array
    setStr2IntArr(azChar, pTextStr, pTextArr);
    //prntStrAndVal("Plaintext", pTextStr, pTextArr);


    /********** Encrypt the plaintext string **********/
    cout << "\n   Key Size: " << keySize << "\n   keyShift[0, 24, 20, 18, 7]\n";
    cout << endl << "\nPlaintext successfully encrypted with custom key:\n";
    
    int num = 0, shift = 0, encryptVal = 0, pTCharVal = 0, count = 0;

    // Loop through each letter in pTextStr string
    for (int i = 0; i < pTSize; i++) {

        // Key repeats every keySize times
        if (i%keySize==0) {
            count = 0;
        } else {
            count++;
        }
        shift = keyShiftArr[count];
        
        // plaintext's letter value [0,25]
        pTCharVal = pTextArr[i];

        // Encrypt formula:  E = (Plaintext + shift) mod 26.
        num  = ((pTCharVal + shift + NUM_LTTRS));

        encryptVal = num % NUM_LTTRS;
        
        // Set array with encrypted values that represent letters
        encryptArr[i] = encryptVal;

        // Concate encrypted string
        encryptStr += azChar[encryptVal];
        key += azChar[shift];
        cout << pTextStr[i] << " = " << setw(2) << pTCharVal << " + "
             << setw(2) << shift << " shift = " << setw(2) << num 
             <<" %26 = " << setw(2) << encryptArr[i]
             << " == " << setw(2) << azChar[encryptVal] << endl;
    }
    
    prnt3Strs(pTextStr, key, encryptStr,"Plaintext", "enrypted","Cipher");
    //prnt3Arr(pText,keyShift,encrypt,pTextSize); 
    cout<<endl<<"-------------------------------------------------------\n\n\n";    
}


//******************************************************************************
//               Find key values with plaintext and encrypted strings            
//******************************************************************************
void getKey(char azChar[], int azVal[]) {

    cout<<endl<<"-------------------------------------------------------\n\n";  
    cout << "\t\t Get key with a \nPlaintext string and an Encrypted string Section \n\n"; 
    string pTextStr = "";
    string encryptStr = "";
    string key = "";
    pTextStr = "GEEKSFORGEEKS"; //"geeksforgeeks";
    encryptStr = "GCYCZFMLYLEIM";
    int pTextSize = pTextStr.length();
    int pText[pTextSize] = {};
    int encrypt[pTextSize] = {};
    int keyShift[pTextSize] = {};


    // Convert each letter in string to its alphabet values. Save to int array
    setStr2IntArr(azChar, pTextStr, pText);
    //prntStrAndVal("Plaintext", pTextStr, pText);

    // Find the value of each letter in encrypted string and save azChar's index to an array
    setStr2IntArr(azChar, encryptStr, encrypt);
    //prntStrAndVal("Ciphertext", encryptStr, encrypt);


    // Find the shift for each letter of the encrypted string 
    // Calculate key by using a given plaintext string and a given encrypted string   
    setKey(azChar, pText, encrypt, keyShift, key, pTextStr, encryptStr, pTextSize);    
    
    prnt3Strs(pTextStr, key, encryptStr,"Plaintext", "decrypted","Cipher"); // Prints all three strings 
    //prnt3Arr(pText,keyShift,encrypt,pTextSize);  
    cout<<endl<<"-------------------------------------------------------\n\n\n"; 
}


//******************************************************************************
//            Find the shift for each letter of the encrypted string 
// Calculate key by using a given plaintext string and a given encrypted string
//******************************************************************************

void setKey(char azChar[], int pText[], int encrypt[], int keyShift[], string &key, string pTextStr, string encryptStr, int pTextSize) {

    cout << endl << "Plaintext encrypted with key\n";
    
    int shift = 0, num = 0, encryptChar = 0, pTChar = 0; 

    for (int i = 0; i < pTextSize; i++) {

        encryptChar = encrypt[i];
        pTChar = pText[i];

        num = (encryptChar - pTChar + NUM_LTTRS)+NUM_LTTRS;

        // Shift formula:  Shift = (pTextStr - Decrypt + 26) mod 26
        shift = (num - ((num / NUM_LTTRS) * NUM_LTTRS));
        keyShift[i] = shift;
        key += azChar[shift];

        cout << setw(2) << pTChar  << " = " << pTextStr[i] << "->"
        << setw(2) << encryptStr[i] << " = " << setw(2) << pTChar  << " "
        << " num = "       << setw(2) << num 
        << " %shift = "     << setw(2) << keyShift[i] 
        << " == "          << setw(2) << azChar[shift] << endl;
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

void prnt3Strs(string given, string key, string result, string str1, string str2, string str3) {

    cout << endl << str1 << " " << str2 << " with key\n----------------------------\n"
            << setw(13) << str1 << ": " << given << endl
            << setw(15) << "Key: " << key << endl
            << setw(13) << str3 << ": " << result << endl;
}

void prnt3Arr(int pText[], int keyShift[], int encrypt[], int pTextSize){
    cout<<endl;
    prntIntArr(pText, pTextSize);   // Prints the plaintext's int values arrays [0,25]
    prntIntArr(keyShift, pTextSize);// Prints the keyShift's int values arrays [0,25]
    prntIntArr(encrypt, pTextSize); // Prints the encrypted's int values arrays [0,25]
}