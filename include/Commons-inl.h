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

void Commons::tokenize(std::vector<std::string>& tokens,
		const std::string& line, const char delimiter) noexcept
{
	std::stringstream string_stream(line);
	std::string intermediate;
	while (getline(string_stream, intermediate, delimiter))
		tokens.push_back(intermediate);
}

char Commons::get_delimiter(const std::string& line) noexcept
{
	constexpr uint8_t SIZE = 3;
	constexpr uint8_t MANDATORY_INDEX = 0;
	constexpr char DELIMITERS[SIZE] = {'+', '|', '^'};

	for (int index = Commons::BEGIN; index < SIZE; ++index)
		if (line.find(DELIMITERS[index]) != NOT_FOUND)
			return DELIMITERS[index];

	return DELIMITERS[MANDATORY_INDEX];
}

std::string Commons::remove_question_mark(const std::string& name) noexcept
{
	constexpr uint8_t OPTIONAL_SIGN_INDEX = 1;

	if (name.find(static_cast<char>(FeatureType::Optional)) == NOT_FOUND)
		return name;
	return name.substr(OPTIONAL_SIGN_INDEX);
}

std::string Commons::remove_extra_brackets(const std::string& line) noexcept
{
	constexpr uint8_t USELESS_OPEN_BRACKET_INDEX = 1;
	constexpr uint8_t MINIMUM_SIZE = 2;

	if (line.size() < MINIMUM_SIZE)
		throw BadConfiguraionStyleException();

	const int useless_close_bracket_index = line.size() - MINIMUM_SIZE;
	return line.substr(USELESS_OPEN_BRACKET_INDEX, useless_close_bracket_index);
}

Commons::DelimiterType Commons::get_delimiter_type(const char delimiter)
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
			throw BadDelimiterException();
	}
}

Commons::FeatureType Commons::get_feature_type(const std::string& name,
		char delimiter)
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
			throw BadDelimiterException();
	}
}

#endif
