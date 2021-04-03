#pragma once
/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER05_H
#define CIPHER05_H

#include <string>
#include "cipher.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <ctype.h>
#include <sstream>
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher05 : public Cipher
{
public:
    virtual std::string getPseudoAuth() { return "Tyler DeFreitas"; }
    virtual std::string getCipherName() { return "Polybius Square Cipher"; }
    virtual std::string getEncryptAuth() { return "Scott Malin"; }
    virtual std::string getDecryptAuth() { return "Noah Cook"; }

    /***********************************************************
     * GET CIPHER CITATION
     * Returns the citation from which we learned about the cipher
     ***********************************************************/
    virtual std::string getCipherCitation()
    {
        return std::string("https://crypto.interactive-maths.com/polybius-square.html#:~:text=The%20Polybius%20Square%20is%20an,have%20one%20too%20many%20letters.");
    }

    /**********************************************************
     * GET PSEUDOCODE
     * Returns the pseudocode as a string to be used by the caller.
     **********************************************************/
    virtual std::string getPseudocode()
    {
        std::string str;

        // TODO: please format your pseudocode
        // The encrypt pseudocode
        str = "START polybiusSquareEncrypt(plainText, key)\n"
	            "DECLARE Character grid[5][5]\n"
	            "DECLARE row = 0\n"
	            "DECLARE column = 0\n"
	
	            "For loop to put key into grid followed by alphabet (skip j and repeated letters)\n"
	
	            "DECLARE String cipherText\n"
	
	            "For loop walk through plain text and find matching letter in grid\n"
		        "cipherText += row\n"
		        "cipherText += column\n"
	            "RETURN cipherText\n"
                "END polybiusSquareEncrypt\n";

        // The decrypt pseudocode
        str += "START polybiusSquareDecrypt(ciperText, key)\n"
	            "DECLARE Character grid[5][5]\n"
	            "DECLARE row = 0\n"
	            "DECLARE column = 0\n"
	
	            "For loop to put key into grid followed by alphabet (skip j)\n"
	
	            "DECLARE String plainText\n"
	
	            "For loop to walk through cipherText\n"
		        "plainText += grid[ciphertext[i]] [ciphertext[i+1]]\n"
	            "RETURN plainText\n"
                "END polybiusSquareDecrypt\n";

        return str;
    }

    /**********************************************************
     * ENCRYPT
     * TODO: ADD description
     **********************************************************/
    virtual std::string encrypt(const std::string& plainText,
        const std::string& password)
    {
        std::string cipherText = plainText;
    char alphabet[] = "abcdefghiklmnopqrstuvwxyz";
    int n = sizeof(alphabet) / sizeof(alphabet[0]);
 
    vector<char> vect(alphabet, alphabet + n);
    char table[5][5];
    int w = 0;
    transform(password.begin(), password.end(), password.begin(), ::tolower);
    for (int i = 0; i < 5; i++)
    {
      for (int j = 0; password[j] ; j++)
      {
        table[i][j] = password[w];
        if (password[w])
          w++;
      }
    }
    int k = 0;
    vector<char>::iterator it;
    while (k < 5)
      {
        it = find(vect.begin(), vect.end(), password[k]);
        vect.erase(it);
        k++;
      }
    int row = (w % 5) + 1;
    int column = (w / 5);

    w = 0;
    for (int i = row; i < 5; i++)
    {
      for (int j = 0; j < 5; j++)
      {
        table[i][j] = vect[w];
        w++;
      }
    }
    
   transform(plainText.begin(), plainText.end(), plainText.begin(), ::tolower);
   for (int i = 0; plainText[i]; i++)
   {
   	if (plainText[i] == 'j');
       		plainText[i] = 'i';
     for (int r = 0; r < 5; r++)
     {
       for (int c = 0; c < 5; c++)
       {
         if (plainText[i] == table[r][c])
         {
           cipherText += to_string(r+1);
           cipherText += to_string(c+1);
         }
       }
     }
    
    }
        return cipherText;
    }

    /**********************************************************
     * DECRYPT
     * TODO: ADD description
     **********************************************************/
    virtual std::string decrypt(const std::string& cipherText,
        const std::string& password)
    {
        std::string plainText = cipherText;
	 char alphabet[] = "abcdefghiklmnopqrstuvwxyz";
    int n = sizeof(alphabet) / sizeof(alphabet[0]);
 
    vector<char> vect(alphabet, alphabet + n);
    char table[5][5];
    int w = 0;
    transform(password.begin(), password.end(), password.begin(), ::tolower);
    for (int i = 0; i < 5; i++)
    {
      for (int j = 0; password[j] ; j++)
      {
        table[i][j] = password[w];
        if (password[w])
          w++;
      }
    }
    int k = 0;
    vector<char>::iterator it;
    while (k < 5)
      {
        it = find(vect.begin(), vect.end(), password[k]);
        vect.erase(it);
        k++;
      }
    int row = (w % 5) + 1;
    int column = (w / 5);

    w = 0;
    for (int i = row; i < 5; i++)
    {
      for (int j = 0; j < 5; j++)
      {
        table[i][j] = vect[w];
        w++;
      }
    }
	
    for (int i = 0; cipherText[i]; i += 2)
    {
    	int r = cipherText [i] - 49;
    	int c = cipherText [i+1] - 49;
    	plainText += table[r][c];
    }
        return plainText;
    }
};

#endif // CIPHER05_H
