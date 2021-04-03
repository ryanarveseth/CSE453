#pragma once
/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER01_H
#define CIPHER01_H

#include <string>
#include "cipher.h"
#include <sstream>
#include <vector>

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher01 : public Cipher
{
public:
    virtual std::string getPseudoAuth() { return "Ryan Arveseth"; }
    virtual std::string getCipherName() { return "Rail Fence Cipher"; }
    virtual std::string getEncryptAuth() { return "Logan Holland"; }
    virtual std::string getDecryptAuth() { return "decrypt author"; }

    /***********************************************************
     * GET CIPHER CITATION
     * Returns the citation from which we learned about the cipher
     ***********************************************************/
    virtual std::string getCipherCitation()
    {
        return std::string("101Computing.net, The Rail Fence Cipher. 08 Oct. 2018. [Online] Available: https://www.101computing.net/the-rail-fence-cipher/");
    }

    /****************************
    ******************************
     * GET PSEUDOCODE
     * Returns the pseudocode as a string to be used by the caller.
     **********************************************************/
    virtual std::string getPseudocode()
    {
        std::string str;
        str =
            "START railFenceEncryption(text, key)\n"
            "   DECLARE char rail[key][LENGTH of text]\n"
            "   DECLARE bool down = false\n"
            "   DECLARE row = 0\n"
            "   DECLARE column = 0\n"
            "   FOR INTEGER r = 0; r < key; r++\n"
            "       FOR INTEGER c = 0; c < LENGTH of text; c++\n"
            "           rail[r][c] = '\\0';\n"
            "       ENDFOR\n"
            "   ENDFOR\n"
            "   FOR INTEGER c = 0; c < LENGTH of text; c++\n"
            "       IF row == 0 OR row == key - 1\n"
            "           down = !down\n"
            "       ENDIF\n"
            "       rail[down ? row++ : row--][column++] = text[c]\n"
            "   ENDFOR\n"
            "   DECLARE string ciphertext\n"
            "   FOR INTEGER r = 0; r < key; r++\n"
            "       FOR INTEGER c = 0; c < LENGTH of text; c++\n"
            "           IF rail[r][c] != '\\0'\n"
            "               ciphertext += rail[r][c]\n"
            "           ENDIF\n"
            "       ENDFOR\n"
            "   ENDFOR\n"
            "   RETURN ciphertext\n"
            "END railFenceEncryption\n";


        str += "\n\n\n";

        // The decrypt pseudocode
        str +=
            "START railFenceDecryption(ciphertext, key)\n"
            "    DECLARE char rail[key][LENGTH of ciphertext]\n"
            "    DECLARE bool down = false\n"
            "    DECLARE row = 0\n"
            "    DECLARE column = 0\n"
            "    FOR INTEGER r = 0; r < key; r++\n"
            "       FOR INTEGER c = 0; c < LENGTH of ciphertext; c++\n"
            "           rail[r][c] = '\\0';\n"
            "       ENDFOR\n"
            "    ENDFOR\n"
            "    FOR INTEGER c = 0; c < LENGTH of ciphertext; c++\n"
            "       IF row == 0\n"
            "           down = true\n"
            "       ELSEIF row == key - 1\n"
            "           down = false\n"
            "       ENDIF\n"
            "   \n"
            "       rail[down ? row++ : row--][column++] = '+'\n"
            "    ENDFOR\n"
            "    DECLARE string plaintext\n"
            "    DECLARE int i = 0\n"
            "    FOR INTEGER r = 0; r < key; r++\n"
            "       FOR INTEGER c = 0; c < LENGTH of ciphertext; c++\n"
            "           IF rail[r][c] != '+' AND i < LENGTH of ciphertext\n"
            "               rail[r][c] = ciphertext[i++]\n"
            "           ENDIF\n"
            "       ENDFOR\n"
            "    ENDFOR\n"
            "    SET row = 0\n"
            "    SET column = 0\n"
            "    FOR INTEGER c = 0; c < LENGTH of ciphertext; c++\n"
            "       IF(row == 0)\n"
            "           down = true;\n"
            "       ELSEIF row == key - 1\n"
            "           down = false;\n"
            "       ENDIF\n"
            "\n"
            "       IF rail[row][column] != '+'\n"
            "           text += rail[down ? row++ : row--][column++]\n"
            "       ENDIF\n"
            "    ENDFOR\n"
            "    RETURN plaintext\n"
            "END railFenceDecryption\n";

        return str;
    }

    /**********************************************************
     * ENCRYPT
     * TODO: ADD description
     **********************************************************/
    virtual std::string encrypt(const std::string& plainText,
        const std::string& password)
    {
        int key = stoi(password);

        std::string cipherText = "";
        char** rail = new char* [key];
        for (int i = 0; i < key; i++) {
            rail[i] = new char[plainText.length()];
        }
        bool down = false;
        int row = 0;
        int column = 0;
        for (int r = 0; r < key; r++) {
            for (int c = 0; c < plainText.length(); c++) {
                rail[r][c] = '\0';
            }
        }
        for (int c = 0; c < plainText.length(); c++) {
            if (row == 0 || row == key - 1) {
                down = !down;
            }
            rail[down ? row++ : row--][column++] = plainText[c];
        }
        for (int r = 0; r < key; r++) {
            for (int c = 0; c < plainText.length(); c++) {
                if (rail[r][c] != '\0') {
                    cipherText += rail[r][c];
                }
            }
        }
        return cipherText;
    }

    /**********************************************************
     * DECRYPT
     * TODO: Iterate over our rail, then mark the places where we'll need text, then 
     *       fill the array with our rail. Finally, iterate over object
     *       again and finish 
     **********************************************************/
    virtual std::string decrypt(const std::string cipherText,
        const std::string key)
    {
        std::string plainText = cipherText;
        const int keyInt = std::stoi(key);
        const int pLength = plainText.length();

        vector <vector<int> > rail(keyInt, vector<int>(pLength));
        bool down = false;

        int row = 0;
        int column = 0;

        for (int r = 0; r < keyInt; r++)
            for (int c = 0; c < plainText.length(); c++)
                rail[r][c] = '\0';

        for (int c = 0; c < plainText.length(); c++)
        {
            if (row == 0)
                down = true;
            else if (row == keyInt - 1)
                down = false;

            rail[down ? row++ : row--][column++] = '+';
        }

        std::string decryptedText;
        int i = 0;

        for (int r = 0; r < keyInt; r++)
            for (int c = 0; c < plainText.length(); c++)
                if (rail[r][c] != '+' && i < plainText.length())
                    rail[r][c] = plainText[i++];

        row = 0; 
        column = 0;

        for (int c = 0; c < plainText.length(); c++)
        {
            if (row == 0)
                down = true;
            else if (row == keyInt - 1)
                down = false;

            if (rail[row][column] != '+')
                decryptedText += rail[down ? row++ : row--][column++];
        }

        return decryptedText;
    }
};

#endif // CIPHER01_H