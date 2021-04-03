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

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher05 : public Cipher
{
public:
    virtual std::string getPseudoAuth() { return "Tyler DeFreitas"; }
    virtual std::string getCipherName() { return "Polybius Square"; }
    virtual std::string getEncryptAuth() { return "encrypt author"; }
    virtual std::string getDecryptAuth() { return "decrypt author"; }

    /***********************************************************
     * GET CIPHER CITATION
     * Returns the citation from which we learned about the cipher
     ***********************************************************/
    virtual std::string getCipherCitation()
    {
        return std::string("citation");
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
	
	            "For loop to put key into grid followed by alphabet (skip j)\n"
	
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
        // TODO - Add your code here
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
        // TODO - Add your code here
        return plainText;
    }
};

#endif // CIPHER05_H