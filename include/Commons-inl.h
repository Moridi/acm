#ifndef COMMONS_INL_H_
#define COMMONS_INL_H_

#ifndef COMMONS_H_
#error "Commons-inl.h" should be included only in "Commons.h" file.
#endif

#include <memory>
#include <iostream>
#include <string>
#include <vector>

#include <bits/stdc++.h>

using namespace std;

void Commons::tokenize(vector<string>& tokens, string line, const char delimiter)
		noexcept
{
	stringstream string_stream(line);
	string intermediate;
	while (getline(string_stream, intermediate, delimiter))
		tokens.push_back(intermediate);
}

char Commons::get_delimiter(string line)
{
	constexpr size_t SIZE = 3;
	constexpr std::array<char, SIZE> DELIMITERS = {'+', '|', '^'};

	for (size_t i = 0; i < DELIMITERS.size(); ++i)
		if (line.find(DELIMITERS[i]) != NOT_FOUND)
			return DELIMITERS[i];

	throw BAD_DELIMITER_EXCEPTION();
}

string Commons::remove_question_mark(string name)
{
	constexpr size_t OPTIONAL_SIGN_INDEX = 1;

	if (name.find(static_cast<char>(FeatureType::Optional)) == NOT_FOUND)
		return name;
	return name.substr(OPTIONAL_SIGN_INDEX);

}

Commons::DelimiterType Commons::get_delimiter_type(char delimiter)
{
	switch (delimiter)
	{
		case static_cast<char>(DelimiterType::Mandatory):
			return DelimiterType::Mandatory;

		case static_cast<char>(DelimiterType::Alternative):
			return DelimiterType::Alternative;

		case static_cast<char>(DelimiterType::Or):
			return DelimiterType::Or;

		default:
			throw BAD_DELIMITER_EXCEPTION();
	}
}

Commons::FeatureType Commons::get_feature_type(string name, char delimiter)
{
	switch (delimiter)
	{
		case static_cast<char>(DelimiterType::Mandatory):
			if (name.find(static_cast<char>(FeatureType::Optional)) == NOT_FOUND)
				return FeatureType::Mandatory;
			return FeatureType::Optional;

		case static_cast<char>(DelimiterType::Alternative):
			return FeatureType::Alternative;

		case static_cast<char>(DelimiterType::Or):
			return FeatureType::Or;

		default:
			throw BAD_DELIMITER_EXCEPTION();
	}
}

#endif
