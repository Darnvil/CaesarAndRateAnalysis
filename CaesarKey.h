#pragma once

#include <string>

using std::string;

class CaesarKey
{
private:
	string GetOffset(const std::string & alphabet, const std::string & key, const int offset);
	string MakeLowerCase(const string& text);

public:
	CaesarKey(const string& alphabet) : ALPHABET(alphabet) {}
	string Encrypt(const string & message, string key, int offset = 3);
	const string& GetAlphabet() const
	{
		return ALPHABET;
	}

private:
	const string ALPHABET;
public:
	string encryptedMessage;
	string baseTextLower;
};
