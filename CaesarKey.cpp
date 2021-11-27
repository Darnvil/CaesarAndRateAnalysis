#include "CaesarKey.h"

string CaesarKey::GetOffset(const std::string & alphabet, const std::string & key, const int offset)
{
	string newAlph;
	string offseted;

	for (auto ch : alphabet)
	{
		if (key.find(ch) == string::npos)
			newAlph += ch;
	}

	for (int i = 0; i < offset; ++i)
	{
		offseted += newAlph[newAlph.length() - offset + i];
	}

	offseted += key + newAlph.substr(0, newAlph.length() - offset);

	return offseted;
}

string CaesarKey::MakeLowerCase(const string& text)
{
	string tmp;
	for (auto it = begin(text); it != end(text); ++it)
	{
		if (((int)(*it)<0 && (int)(*it) > -65) || ((int)(*it)>64 && (int)(*it) < 91) || ((int)(*it)>96 && (int)(*it) < 123))         
        {
			tmp += tolower(*it);
		}
		else
		{
			tmp += *it;
		}
	}
	baseTextLower = tmp;
	return tmp;
}

string CaesarKey::Encrypt(const string & message, string key, int offset)
{
	string offseted = GetOffset(ALPHABET, key, offset);

	string res = "";

	string _messageToLower = MakeLowerCase(message);
	
	for (auto it = _messageToLower.begin(); it != _messageToLower.end(); ++it)
	{
		/*if (*it == ' ')
			res += ' ';
		else
			res += offseted[ALPHABET.find(*it)];*/
		if (ALPHABET.find(*it) != string::npos)
			res += offseted[ALPHABET.find(*it)];
		else
			res += *it;
	}

	return res;
}