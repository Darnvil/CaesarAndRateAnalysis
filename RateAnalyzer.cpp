#include "RateAnalyzer.h"

#include <algorithm>
#include <map>

using std::map;

void RateAnalyzer::Analyze()
{
	
	fillBigrammsVector(BASE_TEXT_, m_bigramms_std);
	fillBigrammsVector(TEXT_, m_bigramms_encrypted);

	int count = 0;
	for (auto it = begin(TEXT_); it != end(TEXT_); ++it)
	{
		if(ALPHABET.find(*it) != string::npos)
			++count;
	}



	map<string, float> monogrammCount;
	for(auto it = begin(m_monogramms_std); it != end(m_monogramms_std); ++it)
	{
		monogrammCount[it->nGramm] = 0.f;
	}

	for(int i = 0; i < TEXT_.size(); ++i)
	{
		if(ALPHABET.find(TEXT_[i]) != string::npos)
			monogrammCount[TEXT_.substr(i, 1)]++;
	}

	for (auto it = begin(monogrammCount); it != end(monogrammCount); ++it)
	{
		it->second /= count;
	}

	for (auto item : monogrammCount)
	{
		m_monogramms_encrypted.push_back(RateInfo{item.first, item.second});
	}

	std::sort(m_monogramms_encrypted.begin(), m_monogramms_encrypted.end(),
		[](RateInfo a, RateInfo b) -> bool
		{
			return a.rate > b.rate;
		});



	for (auto i = 0; i < TEXT_.size(); ++i)
	{
		if (ALPHABET.find(TEXT_[i]) != string::npos)
		{
			if (ALPHABET.find(TEXT_[i + 1]) != string::npos)
			{
				string bigramm{TEXT_.substr(i, 2)};
				if (findBigramm(bigramm))
				{
					++i;
					continue;
				}
			}
			string monogramm{ TEXT_[i]};
			findMonogramm(monogramm);
		}
		else
		{
			decryptedText.append(string{ TEXT_[i]});
		}
	}

	
}

void RateAnalyzer::fillBigrammsVector(const string& text, vector<RateInfo>& vec)
{
	int count = 0;
	map<string, float>bigrammCount;
	for (int i = 0; i < text.size(); ++i)
	{
		if (ALPHABET.find(text[i]) != string::npos && ALPHABET.find(text[i + 1]) != string::npos)
		{
			string bigramm = text.substr(i, 2);
			if (bigrammCount.find(bigramm) != bigrammCount.end())
			{
				bigrammCount[bigramm]++;
			}
			else
			{
				bigrammCount.insert({ bigramm, 1.f });
			}

			++count;
		}
	}

	for (auto it = begin(bigrammCount); it != end(bigrammCount); ++it)
	{
		it->second /= count;
	}

	vector<RateInfo> bigrammVector;

	for (auto item : bigrammCount)
	{
		bigrammVector.push_back(RateInfo{ item.first, item.second });
	}

	std::sort(bigrammVector.begin(), bigrammVector.end(),
		[](RateInfo a, RateInfo b) -> bool
		{
			return a.rate > b.rate;
		});

	bigrammVector.resize(15);

	vec = bigrammVector;
}


void RateAnalyzer::findMonogramm(string ch)
{
	int foundIndex = -1;

	for (auto i = 0; i < m_monogramms_encrypted.size(); ++i)
	{
		if (m_monogramms_encrypted.at(i).nGramm == ch)
		{
			foundIndex = i;
			break;
		}
	}

	decryptedText.append(m_monogramms_std.at(foundIndex).nGramm);
}

bool RateAnalyzer::findBigramm(string ch)
{
	int foundIndex = -1;

	for (auto i = 0; i < m_bigramms_encrypted.size(); ++i)
	{
		if (m_bigramms_encrypted.at(i).nGramm == ch)
		{
			foundIndex = i;
			break;
		}
	}
	if (foundIndex >= 0)
	{
		decryptedText.append(m_bigramms_std.at(foundIndex).nGramm);
		return true;
	}
	return false;
}


string& RateAnalyzer::Run()
{
	Analyze();
	
	return decryptedText;
}

