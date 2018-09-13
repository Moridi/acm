#ifndef TOOLS_INL_H_
#define TOOLS_INL_H_

#ifndef TOOLS_H_
#error "Tools-inl.h" should be included only in "Tools.h" file.
#endif

#include <memory>
#include <iostream>
#include <string>
#include <vector>

#include <bits/stdc++.h>

using namespace std;

void Tools::tokenize(vector<string>& tokens, string line, const char delimiter)
		noexcept
{
	stringstream string_stream(line);
	string intermediate;
	while (getline(string_stream, intermediate, delimiter))
		tokens.push_back(intermediate);
}

void Tools::fill_feature_model_vector(vector<string>& tokens, string line,
		const char delimiter) noexcept
{
	constexpr char ASSIGN_DELIMITER = '=';
	constexpr uint8_t RIGHT_VALUE_INDEX = 1;

	tokenize(tokens, line, ASSIGN_DELIMITER);
	line = tokens[RIGHT_VALUE_INDEX];
	tokens.erase(tokens.begin() + RIGHT_VALUE_INDEX);
	tokenize(tokens, line, delimiter);
}

char Tools::get_delimiter(string line)
{
	constexpr size_t SIZE = 3;
	constexpr int DELIMITER_NOT_FOUND = -1;
	constexpr std::array<char, SIZE> DELIMITERS = {'+', '|', '^'};

	for (size_t i = 0; i < DELIMITERS.size(); ++i)
		if (line.find(DELIMITERS[i]) != DELIMITER_NOT_FOUND)
			return DELIMITERS[i];

	throw BAD_DELIMITER_EXCEPTION();
}

string Tools::make_compatible_string_for_configuration(string line)
{
	constexpr size_t USELESS_OPEN_BRACKET_INDEX = 1;
	constexpr size_t MINIMUM_SIZE = 2;

	if (line.size() < MINIMUM_SIZE)
		throw BAD_CONFIGURAION_STYLE();

	size_t useless_close_bracket_index = line.size() - MINIMUM_SIZE;

	return line.substr(USELESS_OPEN_BRACKET_INDEX, useless_close_bracket_index);
}

#endif
