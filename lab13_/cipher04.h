/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER04_H
#define CIPHER04_H
#include <string>
#include "cipher.h"

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher04 : public Cipher
{
public:
    virtual std::string getPseudoAuth() { return "Noah Cook"; }
    virtual std::string getCipherName() { return "Noah's pig latin"; }
    virtual std::string getEncryptAuth() { return "Noah Cook"; }
    virtual std::string getDecryptAuth() { return "Logan Holland"; }

    /***********************************************************
     * GET CIPHER CITATION
     * Returns the citation from which we learned about the cipher
     ***********************************************************/
    virtual std::string getCipherCitation()
    {
        return std::string("https://www.wattpad.com/432553860-codes-and-ciphers-pig-latin");
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
        str = "If word starts with consonant and last letter put consonant to the end and add ay?\nelse add way! to the end\n";

        // The decrypt pseudocode
        str += "if encryption ends in ? remove last three and move the fourth from the end to the front\nelse remove last 4\n";

        return str;
    }

    /**********************************************************
     * ENCRYPT
     * TODO: Encrypts the plainText into Noah's version of 
     * piglatin. password is ignored
     **********************************************************/
    virtual std::string encrypt(const std::string& plainText,
        const std::string& password)
    {
        std::string cipherText = plainText;
        char c = cipherText[0];
        
        if (c == 'A' || c == 'E' || c == 'I' || 
            c == 'O' || c == 'U' || c == 'a' || 
            c == 'e' || c == 'i' || c == 'o' ||
            c == 'u') {
            cipherText = cipherText + "way!";
            return cipherText;
            }
        cipherText = cipherText.substr(1, cipherText.size()) + cipherText[0] + "ay?";
        return cipherText;
    }

    /**********************************************************
     * DECRYPT
     * TODO: Decrypts from Noah's piglatin into plainText.
     * password is still ignored.
     **********************************************************/
    virtual std::string decrypt(const std::string& cipherText,
        const std::string& password)
    {
        std::string plainText = cipherText;
        if (plainText[plainText.size() - 1] == '!') {
            return plainText.substr(0, plainText.size() - 4);
        }
        return plainText[plainText.size() - 4] + plainText.substr(0, plainText.size() - 4);
    }
};

#endif // CIPHER04_H
