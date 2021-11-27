#pragma once

#include <string>

using std::string;

class CaesarModified
{
public:
	CaesarModified(const std::string& alphabet) : ALPHABET(alphabet) {}
	string Encrypt(const string & message, string key);
	
	const string& GetAlphabet() const
	{
		return ALPHABET;
	}

private:
	const string ALPHABET;
public:
	string encryptedMessage;
};
