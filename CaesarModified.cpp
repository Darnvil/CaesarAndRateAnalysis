#include "CaesarModified.h"

string CaesarModified::Encrypt(const string& message, string key)
{
	string res;

	for (int i = 0; i < message.length(); ++i)
	{
		int z = (ALPHABET.find(message[i]) + ALPHABET.find(key[i % key.length()]) + 1) % 26;
		
		res += ALPHABET[z];
	}

	return res;
}
