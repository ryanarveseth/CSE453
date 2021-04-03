/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER03_H
#define CIPHER03_H
#define SIZE 256
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher03 : public Cipher
{
public:
	virtual std::string getPseudoAuth() { return "Scott Malin"; }
	virtual std::string getCipherName() { return "RC4 Cipher"; }
	virtual std::string getEncryptAuth() { return "Scott Malin"; }
	virtual std::string getDecryptAuth() { return "Scott Malin"; }

	/***********************************************************
	 * GET CIPHER CITATION
	 * Returns the citation from which we learned about the cipher
	 ***********************************************************/
	virtual std::string getCipherCitation()
	{
		std::string s;
		s += "geeksforgeeks.com (2019), ";
		s += "\"RC4 Encryption Algorithm\', \n   retrieved: ";
		s += "https://www.geeksforgeeks.org/rc4-encryption-algorithm/";
		return s;
	}

	/**********************************************************
	 * GET PSEUDOCODE
	 * Returns the pseudocode as a string to be used by the caller.
	 **********************************************************/
	virtual std::string getPseudocode()
	{
		std::string strEncrypt;
		std::string strDecrypt;
		std::string str;

		// The encrypt pseudocode
		strEncrypt = "encrypt(plainText, password)\n";
		strEncrypt += "   //Initialize:\n";
		strEncrypt += "   DECLARE UNSIGNED INT i , j =0 \n";
		strEncrypt += "   DECLARE UNSIGNED CHAR S[256]\n";
		strEncrypt += "   DECLARE INT length = passwordlength:\n";
		strEncrypt += "   DECLARE STRING codes\n";
		strEncrypt += "   FOR i = 0 to 255 \n";
		strEncrypt += "      S[i] = i\n";
		strEncrypt += "   ENDFOR\n";
		strEncrypt += "   //Key-Scheduling Algorithm:\n";
		strEncrypt += "   FOR i = 0 to 255 \n";
		strEncrypt += "      j = (j + S[i] + key[i mod passwordlength]) mod 256;\n";
		strEncrypt += "      swap S[i] and S[j]\n";
		strEncrypt += "   ENDFOR\n";
		strEncrypt += "   //Pseudo-random generation algorithm (PRGA):\n";
		strEncrypt += "   FOR iPRGA = 0 to 255 \n";
		strEncrypt += "      i = (i + 1) mod 256;\n";
		strEncrypt += "      j = (j + S[i]) mod 256;\n";
		strEncrypt += "      swap S[i] and S[j]\n";
		strEncrypt += "      codes pushback (S[(S[i] + S[j]) mod 256 ]);\n";
		strEncrypt += "   ENDFOR\n";
		strEncrypt += "   //CIPHER TEXT:\n";
		strEncrypt += "   DECLARE STRING cipherText\n";
		strEncrypt += "   FOR i = 0 to plaintextlength \n";
		strEncrypt += "      i = (i + 1) mod 256;\n";
		strEncrypt += "      j = (j + S[i]) mod 256;\n";
		strEncrypt += "      cipherText pushback (codes[i] XOR plaintext[i]);\n";
		strEncrypt += "   ENDFOR\n";
		strEncrypt += "   RETURN cipherText\n\n";

		
		// The decrypt pseudocode
		strDecrypt = "The decrypt pseudocode\n";
		strDecrypt += "decrypt(cipherText, password)\n";
		strDecrypt += "   // Initialize:\n";
		strDecrypt += "   DECLARE STRING plainText = encrypt(cipherText, password):\n";
		strDecrypt += "   RETURN plainText\n\n";

		str = strEncrypt + strDecrypt;

		return str;
	}

	/**********************************************************
	 * ENCRYPT
	 * Takes a user created password and text which is used to 
	 * create a secret key that is then used to XOR the characters
	 * in the keystream with the plaintext characters. It is also
	 * used to decrypt the same text and password by XOR the ciphertext
	 * with the plaintext.
	 **********************************************************/
	virtual std::string encrypt(const std::string& plainText,
		const std::string& password)
	{
		// Initialize
		// #define SIZE 256 at top of file
		unsigned int i, j = 0;
		unsigned char S[SIZE];
		const int lengthText = plainText.length();
		std::string codes;
		// initialize the SBox
		for (i = 0; i < SIZE; i++) 
		{
			S[i] = i;
		}
		//Key-Scheduling Algorithm:
		for (i = 0; i < SIZE; i++) 
		{
			j = (j + S[i] + password[i % password.length()]) % SIZE;
			std::swap(S[i], S[j]);
		}
		//Pseudo-random generation algorithm (PRGA):
		i, j = 0;
		for (int iPRGA = 0; iPRGA < plainText.size(); iPRGA++) 
		{
			i = (i + 1) % SIZE;
			j = (j + S[i]) % SIZE;
			std::swap(S[i], S[j]);
			codes.push_back(S[(S[i] + S[j]) % SIZE]);
		}
		//CIPHER TEXT:
		std::string cipherText;
		for (i = 0; i < plainText.size(); i++) 
		{
			cipherText.push_back(codes[i] ^ plainText[i]); // XOR Keystream with the plainText / CipherText
		}
		return cipherText;
	}

	/**********************************************************
	 * DECRYPT
	 * This function simply calles the encrypt function but passes 
	 * the cipher text as the first parameter rather than the plaintext.
	 **********************************************************/
	virtual std::string decrypt(const std::string& cipherText,
		const std::string& password)
	{
		// initialize plaintext string and call encrypt
		std::string plainText = encrypt(cipherText, password);
		return plainText;
	}
};

#endif // CIPHER03_H