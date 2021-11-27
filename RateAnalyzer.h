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
		{"�", 0.1097f},
		{"�", 0.0845f},
		{"�", 0.0801f},
		{"�", 0.0735f},
		{"�", 0.067f},
		{"�", 0.0626f},
		{"�", 0.0547f},
		{"�", 0.0473f},
		{"�", 0.0454f},
		{"�", 0.044f},
		{"�", 0.0349f},
		{"�", 0.0321f},
		{"�", 0.0298f},
		{"�", 0.0281f},
		{"�", 0.0262f},
		{"�", 0.0201f},
		{"�", 0.019f},
		{"�", 0.0174f},
		{"�", 0.017f},
		{"�", 0.0165f},
		{"�", 0.0159f},
		{"�", 0.0144f},
		{"�", 0.0121f},
		{"�", 0.0097f},
		{"�", 0.0094f},
		{"�", 0.0073f},
		{"�", 0.0064f},
		{"�", 0.0048f},
		{"�", 0.0036f},
		{"�", 0.0032f},
		{"�", 0.0026f},
		{"�", 0.0004f},
		{"�", 0.0004f},
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
