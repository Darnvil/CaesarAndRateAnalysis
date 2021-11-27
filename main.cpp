#include <iostream>
#include <string>
#include <fstream>
#include <locale>
#include <Windows.h>

#include "CaesarKey.h"
#include "RateAnalyzer.h"



int main()
{
	using namespace std;
	setlocale(LC_ALL, "rus");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//locale loc("rus_rus.866");
	//locale::global(loc);

	
	
	const std::string alphabet_ = "אבגדהו¸זחטיךכלםמןנסעףפץצקרשתûü‎‏ÿ";

	ifstream fin(L"Ãכאגא.txt");

	string text;
	string str;

	char ch;
	
	while (fin.read(&ch, 1))
	{
		text += ch;
	}
	
	fin.close();

	cout << text;
	
	
	string key;
	int offset;
	
	cout << "Text: \n" << text << endl << endl;
	cout << "Enter a key: ";
	cin >> key;
	cout << "Enter a offset: ";
	cin >> offset;
	
	

	CaesarKey caesar(alphabet_);

	string encrypted = caesar.Encrypt(text, key, offset);
	
	cout << "Caesar - " << encrypted << endl;

	fstream f("encrypted.txt");

	f << encrypted;

	f.close();

	RateAnalyzer analyzer(encrypted, caesar.baseTextLower, alphabet_);
	
	auto& decrypted = analyzer.Run();

	cout << endl << "Decrypted - " << decrypted << endl;

	fstream fDecrypted("decrypted.txt");

	fDecrypted << decrypted;
	
	fDecrypted.close();

	system("pause");
}