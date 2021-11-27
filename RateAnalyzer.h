#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

struct RateInfo
{
	string nGramm;
	float rate;
};

class RateAnalyzer
{
private:	
	vector<RateInfo> m_monogramms_std = {
		{"î", 0.1097f},
		{"å", 0.0845f},
		{"à", 0.0801f},
		{"è", 0.0735f},
		{"í", 0.067f},
		{"ò", 0.0626f},
		{"ñ", 0.0547f},
		{"ð", 0.0473f},
		{"â", 0.0454f},
		{"ë", 0.044f},
		{"ê", 0.0349f},
		{"ì", 0.0321f},
		{"ä", 0.0298f},
		{"ï", 0.0281f},
		{"ó", 0.0262f},
		{"ÿ", 0.0201f},
		{"û", 0.019f},
		{"ü", 0.0174f},
		{"ã", 0.017f},
		{"ç", 0.0165f},
		{"á", 0.0159f},
		{"÷", 0.0144f},
		{"é", 0.0121f},
		{"õ", 0.0097f},
		{"æ", 0.0094f},
		{"ø", 0.0073f},
		{"þ", 0.0064f},
		{"ö", 0.0048f},
		{"ù", 0.0036f},
		{"ý", 0.0032f},
		{"ô", 0.0026f},
		{"¸", 0.0004f},
		{"ú", 0.0004f},
	};
	vector<RateInfo> m_bigramms_std;
	vector<RateInfo> m_monogramms_encrypted;
	vector<RateInfo> m_bigramms_encrypted;

	const string BASE_TEXT_;
	const string TEXT_;
	const string ALPHABET;
	string decryptedText;
	

private:
	void Analyze();

	void findMonogramm(string ch);
	bool findBigramm(string ch);

	void fillBigrammsVector(const string& text, vector<RateInfo>& vec);

public:
	RateAnalyzer(const string& text, const string& base_text, const string& alph) : TEXT_(text), BASE_TEXT_(base_text), ALPHABET(alph) {}
	
	string& Run();
};
