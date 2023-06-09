// Joash's revised version of my v7. https://replit.com/@koa2019/CIS7-Final
#include <iostream>
using namespace std;

//Global Variables
//Contains our alphabet of letters.
//Upper is for Capital Letters and Lower is for Lowercase Letters
char UPPER[26] = {'A', 'B', 'C', 'D','E', 'F', 'G', 'H', 'I','J', 'K', 'L', 'M', 'N','O', 'P', 'Q', 'R', 'S','T', 'U', 'V', 'W', 'X','Y', 'Z'};
char LOWER[26] = {'a', 'b', 'c', 'd','e', 'f', 'g', 'h', 'i','j', 'k', 'l', 'm', 'n','o', 'p', 'q', 'r', 's','t', 'u', 'v', 'w', 'x','y', 'z'};

//Function Prototypes
string encrypt (const string, const string);
string decrypt (const string, const string);
void userInp(string &, string &, bool);
void menuCip();

int main() {
  string plnText, textKey, menuInt;
  bool conType;

  cout << "------------------------------------------------" << endl;
  cout << "Welcome to a Vigenere Cipher Encryter & Decryter" << endl;

  do{
    menuCip();
    cin >> menuInt;
    //User Input Validation
    while (menuInt < "1" || menuInt > "3"){
      cout << "\nInvalid User Input. Outside of Menu Range, Retry. " << endl;
      menuCip();
      cin >> menuInt;
    } 
    switch(menuInt[0]){
      case '1':
        conType = true;
        userInp(plnText, textKey, conType);
        cout << "Original Plaintext: " << plnText << endl;
        cout << "Key for Vigenere Encryption: " << textKey << endl;
        cout << "Encrypted Text: " << encrypt(plnText, textKey) << endl;
        break;
      case '2':
        conType = false;
        userInp(plnText, textKey, conType);
        cout << "Original Plaintext: " << plnText << endl;
        cout << "Key for Vigenere Decryption: " << textKey << endl;
        cout << "Decrypted Text: " << decrypt(plnText, textKey) << endl;
        break;
    }
    cout << endl << endl;
  } while (menuInt != "3");
  cout << "------------------------------------------------" << endl;
  cout << "Thank you for using this Vigenere Cipher Program" << endl;
  cout << "------------------------------------------------" << endl << endl << endl << endl << endl;
}

// Function Definitions and Explanation

string encrypt (const string text, const string key){
  string encText = ""; // Creates empty string to store encrypted text
  for (int i = 0; i < text.length(); i++){ // 
    if(text[i] >= 'A' && text[i] <= 'Z') // Start of Compressed Equation
      encText += UPPER[((text[i] - 'A') + ((toupper(key[i%key.length()])) - 'A')) % 26];
    else if (text[i] >= 'a' && text[i] <= 'z') // Start of Compressed Equation
      encText += LOWER[((text[i] - 'a') + ((toupper(key[i%key.length()])) - 'A')) % 26];
    else 
      encText += text[i]; //Returns a non-letter char, special symbols aren't encrypted
  }
  return encText;
}
/*Encryption Function Conversion Explanation
  Simpler Version For Uppercase Encryption (Compressed Equation at Line )
  if(text[i] >= 'A' && text[i] <= 'Z'){
     int encChar, numShft, encShft;
     encChar = text[i] - 'A';
     numShft = (toupper(key[i%key.length()])) - 'A';
     encShft = (encChar + numShft) % 26;
     encText += UPPER[encShft];
  }
     Represents the E = (M + K) % 26 encryption equation

  Simpler Version For Lowercase Encryption (Compressed Equation at Line )
  if(text[i] >= 'a' && text[i] <= 'z'){
      int encChar, numShft, encShft;
      encChar = text[i] - 'a';
      numShft = (toupper(key[i%key.length()])) - 'A';
      encShft = (encChar + numShft) % 26;
      encText += LOWER[encShft];
  }
      Represents the E = (M + K) % 26 encryption equation 
*/

string decrypt (string text, const string key){
  string decText = "";
  int decChar, numShft, decShft, decAbs;
  for (int i = 0; i < text.length(); i++){
    if(text[i] >= 'A' && text[i] <= 'Z') // Start of Compressed Equation
      decText += UPPER[(((text[i] - 'A') - (toupper(key[i%key.length()]) - 'A') + 
        (((text[i] - 'A') - (toupper(key[i%key.length()]) - 'A')) < 0 ? 26:0)) % 26)];
    else if (text[i] >= 'a' && text[i] <= 'z') // Start of Compressed Equation
      decText += LOWER[(((text[i] - 'a') - (toupper(key[i%key.length()]) - 'A') + 
        (((text[i] - 'a') - (toupper(key[i%key.length()]) - 'A')) < 0 ? 26:0)) % 26)];
    else
      decText += text[i]; //Returns a non-letter char, special symbols aren't decrypted
  }
  return decText;
}
/*Decryption Function Conversion Explanation
  Simpler Version For Uppercase Decryption (Compressed Equation at Line)
  if(text[i] >= 'A' && text[i] <= 'Z'){
    int decChar, numShft, decShft, decAbs;
    decChar = text[i] - 'A';
    numShft = toupper(key[i%key.length()]) - 'A';
    decAbs = decChar - numShft;
    if (decAbs < 0)
      decShft = (decAbs + 26)% 26;
    else
      decShft = decAbs % 26;
    decText += UPPER[decShft];
  }
  
    Represents the E = (C - K) % 26 decryption equation
    
  Simpler Version For Lowercase Decryption (Compressed Equation)
  if(text[i] >= 'a' && text[i] <= 'z'){
      int decChar, numShft, decShft, decAbs;
      decChar = text[i] - 'a';
      numShft = toupper(key[i%key.length()]) - 'A';
      decAbs = decChar - numShft;
      if (decAbs < 0)
        decShft = (decAbs + 26)% 26;
      else
        decShft = decAbs % 26;
      decText += LOWER[decShft];
  }
      Represents the E = (C - K) % 26 decryption equation
*/

void userInp(string &textInt, string &keyInt, bool conType){
  cout << "------------------------------------------------" << endl;
  cout << (conType ? "Enter the Plaintext to Encrypt: " : "Enter the Plaintext to Decrypt: ");
  cin >> textInt;
  
  cout << (conType ? "Enter the Key for Encryption: " : "Enter the Key for Decryption: ");
  cin >> keyInt;
  cout << "------------------------------------------------" << endl;
}


void menuCip(){
   //Menu and User Input 
    cout << "------------------------------------------------" << endl;
    cout << "Select an option for Vigenere Cipher." << endl
         << "1. Encrypt" << endl
         << "2. Decrypt" << endl
         << "3. Quit" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "User Input: ";
}