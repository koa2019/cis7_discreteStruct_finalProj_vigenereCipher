# vigenereCipher_cis7_discreteStruct_finalPrjt

CIS 7 Discrete Structures Final Project Case 3: Vigenere Cipher. 

Published: 06-07-2023

Authors: Joash, Nathalie, Danielle

How To Run Phis Program:

    1. Download cis7_v8_projectVigenereCipher into Netbeans and click "Run".

    2. A menu with three options will appear on the screen. Enter a number between 1 and 3.
        1. Encrypt a plaintext string with a key.
        2. Decrypt an encrypted string with a key.
        3. Exit program.
    
    3. Menu choice 1:
        1. The program will ask a user to input a plain string of letters they want to encrypt. The sentence should be a string without spaces.
        2. The program will ask the user to input a string that represents the Cipher key.
        3. The program will output an encrypted string of letters. The encrypted string will be the same length as their plaintext string.
        4. Returns to the main function and the menu prompt will be printed to the screen again.

    4. Menu choice 2:
        1. The program will ask a user to input their encrypted string of letters. The sentence should be a string without spaces.
        2. The program will ask the user to input the Cipher key.
        3. Program will output the decrypted string of letters. The decrypted string will be the same length as their encrypted string.
        4. Returns to the main function and the menu prompt will be printed to the screen again.

    5. Menu choice 3: 
        1. The program will display a message and terminate the program.


Project Objectives:
    * Apply discrete structure theorem and principles in programming.
    * Implement algorithm to create a working program in C++.
    * Include calculation methodology from course primary concepts in computation.
    * Explore relevant real-world applications of discrete structures.

Vigenere Cipher is a method of encrypting alphabetic text. It uses a simple form of polyalphabetic substitution. A polyalphabetic cipher is any cipher based on substitution, using multiple substitution alphabets .The encryption of the original text is done using the Vigenere square or Vigenere table.

The table consists of the alphabets written out 26 times in different rows, each alphabet shifted cyclically to the left compared to the previous alphabet, corresponding to the 26 possible Caesar Ciphers.

At different points in the encryption process, the cipher uses a different alphabet from one of the rows.
The alphabet used at each point depends on a repeating keyword.

Example:
Input : Plaintext:   GEEKSFORGEEKS
Keyword :            AYUSH
Output : Ciphertext: GCYCZFMLYLEIM

For generating key, the given keyword is repeated in a circular manner until it matches the length of the plain text.
The keyword "AYUSH" generates the key "AYUSHAYUSHAYU"
The plain text is then encrypted using the process explained below.
 
Encryption
The first letter of the plaintext, G is paired with A, the first letter of the key. So use row G and column A of the Vigenère square, namely G. Similarly, for the second letter of the plaintext, the second letter of the key is used, the letter at row E and column Y is C. The rest of the plaintext is enciphered in a similar fashion.

Decryption
Decryption is performed by going to the row in the table corresponding to the key, finding the position of the ciphertext letter in this row, and then using the column's label as the plaintext. For example, in row A (from AYUSH), the ciphertext G appears in column G, which is the first plaintext letter. Next we go to row Y (from AYUSH), locate the ciphertext C which is found in column E, thus E is the second plaintext letter.
An easier implementation could be to visualize Vigenere algebraically by converting [A-Z] into numbers [0-25].

Encryption
The the plaintext(P) and key(K) are added modulo 26.
E = (P + K) mod 26

Decryption
D = (E - K + 26) mod 26

Note: D denotes the offset of the i-th character of the plaintext. Like offset of A is 0 and of B is 1 and so on.
1.	Given the above description of the Vigenere cipher, create a C++ program that encrypt and decrypts a message from the user. 
2.	Test the program to verify that the output is accurate. Assess program limitations. 
3.	Provide documentation that entails programming approach for encryption and decryption.


Programming Approaches:
Procedural Programming.



