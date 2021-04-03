#pragma once
/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER02_H
#define CIPHER02_H

#include <string>
#include "cipher.h"

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher02 : public Cipher
{
public:
    virtual std::string getPseudoAuth() { return "Logan Holland"; }
    virtual std::string getCipherName() { return "autokey cipher"; }
    virtual std::string getEncryptAuth() { return "Ryan Arveseth"; }
    virtual std::string getDecryptAuth() { return "Scott Malin"; }

    /***********************************************************
     * GET CIPHER CITATION
     * Returns the citation from which we learned about the cipher
     ***********************************************************/
    virtual std::string getCipherCitation()
    {
        std::string s;
		s += "geeksforgeeks.com (2020), ";
		s += "\"Autokey Cipher | Symmetric Ciphers\', \n   retrieved: ";
		s += "https://www.geeksforgeeks.org/autokey-cipher-symmetric-ciphers/";
        return s;
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
        str =
            "START autokeyEncrypt(plaintext, key)\n"
            "    DECLARE STRING stream = key + plaintext\n"
            "    DECLARE String ciphertext = \"\"\n"
            "    FOR INTEGER i = 0; i < Length of plaintext; i += 1\n"
            "        DECLARE CHARACTER temp = (CHARACTER)(plaintext[i].TOUPPER() + stream[i].TOUPPER() - 'A')\n"
            "\n"
            "        IF temp > 'Z'\n"
            "            temp -= 26\n"
            "        ENDIF\n"
            "        ciphertext += temp\n"
            "    ENDFOR\n"
            "    RETURN ciphertext\n"
            "END autokeyEncrypt\n"
            "    \n"
            "    \n";


        // The decrypt pseudocode
        str += 
        "START autokeyDecrypt(ciphertext, key)\n"
        "    DECLARE String plaintext = ""\n"
        "\n"
        "    FOR Integer i = 0; i < Length of key; i += 1\n"
        "        DECLARE CHARACTER temp = (CHARACTER)(ciphertext[i].TOUPPER() - key[i].TOUPPER() + 'A')\n"
        "\n"
        "        IF temp < 'A'\n"
        "            temp += 26\n"
        "        ENDIF\n"
        "        plaintext += temp\n"
        "    ENDFOR\n"
        "    FOR INTEGER i = Length of key; i < Length of ciphertext; i += 1\n"
        "        DECLARE CHARACTER temp = (CHARACTER)(ciphertext[i].TOUPPER() - plaintext[i - (Length of key)].TOUPPER() + 'A')\n"
        "\n"
        "        IF temp < 'A'\n"
        "            temp += 26\n"
        "        ENDIF\n"
        "        plaintext += temp\n"
        "    ENDFOR\n"
        "    RETURN plaintext\n"
        "End autokeyDecrypt\n";

        return str;
    }

    /**********************************************************
     * ENCRYPT
     *       Take the plainText and key and incorporate the plaintext 
     *       into the key. To decrypt, one must use the agreed 
     *       upon keyword for  both encryption and decryption.
     **********************************************************/
    virtual std::string encrypt(const std::string& plainText,
        const std::string& key)
    {
        std::string ciphertext = plainText;
        std::string stream = key + plainText;
        std::string cipher = "";

        for (int i = 0; i < plainText.length(); i++)
        {
            char temp = (char)(toupper(ciphertext[i]) + toupper(stream[i]) - 'A');

            if (temp > 'Z')
                temp -= 26;

            if (temp != -1)
                cipher += temp;
        }

        return cipher;
    }

    /**********************************************************
     * DECRYPT
     * Takes the cipher text and the password and then recreates 
     * the original string by using the first letter of the auto key
     * and calculating what the original letters were based on the 
     * subkeys.
     **********************************************************/
    virtual std::string decrypt(const std::string& cipherText,
        const std::string& password)
    {
        std::string plainText = "";
        for (int i = 0; i < password.length(); i++) 
        {
            char temp = (char)(std::toupper(cipherText[i]) - std::toupper(password[i]) + 'A');

            if (temp < 'A') 
            {
                temp += 26;
            }
            plainText += temp;
        }

        for (int i = password.length(); i < cipherText.length(); i++)
         {
            char temp = (char)(std::toupper(cipherText[i]) - std::toupper(plainText[i - password.length()]) + 'A');
            if (temp < 'A') 
            {
                temp += 26;
            }
            plainText += temp;
        }
        return plainText;
    }
};

#endif // CIPHER02_H