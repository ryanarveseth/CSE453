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

    /**********************************************************
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
            "           rail[r][c] = '\\n';\n"
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
            "           IF rail[r][c] != '\\n'\n"
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
            "           rail[r][c] = '\\n';\n"
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
            "       IF rail[row][col] != '+'\n"
            "           text += rail[down ? row++ : row--][col++]\n"
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

#endif // CIPHER01_H