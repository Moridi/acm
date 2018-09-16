#ifndef COMMONS_H_
#define COMMONS_H_

#include <memory>
#include <vector>
#include <string>
#include <exception>

class BadDelimiterException : public std::exception {};
class BadConfiguraionStyleException : public std::exception {};
class VectorOutOfSizeException : public std::exception {};
class FeatureNameNotFound : public std::exception {};

class Commons
{
public:
	enum class FeatureType : char
	{
		Mandatory = '+',
		Optional = '?',
		Or = '|',
		Alternative = '^'
	};

	enum class DelimiterType : char
	{
		Mandatory = '+',
		Or = '|',
		Alternative = '^'
	};

	static constexpr uint8_t BEGIN = 0;
	static constexpr int NOT_FOUND = -1;

	enum class Result : bool
	{
		SUCCESSFUL = true,
		UNSUCCESSFUL = false
	};

	inline static char get_delimiter(const std::string& line) noexcept;
	inline static void tokenize(std::vector<std::string>& tokens,
			const std::string& line, const char delimiter) noexcept;
	inline static FeatureType get_feature_type(const std::string& name,
			char delimiter);
	inline static DelimiterType get_delimiter_type(const char delimiter);
	inline static std::string remove_question_mark(const std::string& name)
			noexcept;
	inline static std::string remove_extra_brackets(const std::string& line);
};

#include "Commons-inl.h"
#endif
