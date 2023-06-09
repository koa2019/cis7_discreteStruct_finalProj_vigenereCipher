// Joash's revised version of my v6. https://replit.com/@koa2019/CIS7finalcipher
#include <iostream>
#include <fstream>
using namespace std;

string encrypt (const string text, const string key){
  string enc = "";
  char temp;
  int holder;
  int c;
  for(int i = 0; i < text.length(); i++){
    holder = (text[i] + (toupper(key[i%key.length()])) - 65);
    c = toupper(key[i%key.length()]) - 65;
    if(holder > 'z'){
      temp = holder - 'z' + 'a' - 1;
            cout << "Hit If" << endl;
      cout << text[i] << " " << c << " "<< holder << " " << temp << endl;
    }
    else if (holder > 'Z'){
      temp = holder - 'Z' + 'A' - 1;
      cout << "Hit Else" << endl;
      cout << text[i] << " " << c << " "<< holder << " " << temp << endl;
    }
    enc += temp;
  }
  return enc;
}

string decrypt (const string text, const string key){
  string dec = "";
  int temp;
  for(int i = 0; i < text.length(); i++){
    temp = (text[i] - ((toupper(key[i%key.length()])) - 65));
    if(temp > 'Z')temp = temp - 'Z' + 'A' - 1;
    else if(temp > 'z')temp = temp - 'z' + 'a' - 1;
  }
  return dec;
}
int main() {
  ofstream output;
  int c = 0;
  output.open("Output.txt");
  string text, key;
  while(true){
  cout << "Enter Plaintext then Key" << endl;
  cin >> text;
  cin >> key;
  output << encrypt(text,key);
  cout << encrypt(text,key) << endl;
  }
  output.close();
  //cout << decrypt(text, key);
}

