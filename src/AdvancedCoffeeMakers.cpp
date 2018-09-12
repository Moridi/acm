#include <iostream>
#include <string>
#include <vector>

#include <bits/stdc++.h>

#include "AdvancedCoffeeMakers.h"

using namespace std;

AcmSharedPointer AdvancedCoffeeMakers::instance;

void fill_vector(vector<string>& tokens, string line, const char delimiter)
{
	stringstream string_stream(line);
	string intermediate;
	while (getline(string_stream, intermediate, delimiter))
		tokens.push_back(intermediate);
}

void AdvancedCoffeeMakers::tokenize(vector<string>& tokens, string line, const char delimiter)
		const noexcept
{
	constexpr char ASSIGN_DELIMITER = '=';
	constexpr uint8_t RIGHT_VALUE_INDEX = 1;

	fill_vector(tokens, line, ASSIGN_DELIMITER);
	line = tokens[RIGHT_VALUE_INDEX];
	tokens.erase(tokens.begin() + RIGHT_VALUE_INDEX);
	fill_vector(tokens, line, delimiter);

	for (int i = 0; i < tokens.size(); ++i)
		cout << tokens[i] << " ";
	cout << endl;
}

char AdvancedCoffeeMakers::get_delimiter(string line) const
{
	constexpr int SIZE = 3;

	constexpr std::array<char, SIZE> DELIMITERS = {'+', '|', '^'};

	for (size_t i = 0; i < DELIMITERS.size(); ++i)
		if (line.find(DELIMITERS[i]) != -1)
			return DELIMITERS[i];
}

void AdvancedCoffeeMakers::get_input() const noexcept
{
	constexpr char FEATURE_MODEL_END[] = "#";
	string line;
	vector<string> tokens;

	while ((cin >> line) && (line != FEATURE_MODEL_END))
	{
		char delimiter = get_delimiter(line);
		tokenize(tokens, line, delimiter);
		tokens.clear();
	}
}
