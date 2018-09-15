#ifndef COMMONS_H_
#define COMMONS_H_

#include <memory>
#include <vector>
#include <string>

class BadDelimiterException{};
class BadConfiguraionStyleException{};
class VectorOutOfSizeException{};
class FeatureNameNotFound{};

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

	static constexpr size_t BEGIN = 0;
	static constexpr int NOT_FOUND = -1;

	inline static char get_delimiter(std::string line);
	inline static void tokenize(std::vector<std::string>& tokens, std::string line,
			const char delimiter) noexcept;
	inline static FeatureType get_feature_type(std::string name, char delimiter);
	inline static DelimiterType get_delimiter_type(char delimiter);
	inline static std::string remove_question_mark(std::string name);
};

#include "Commons-inl.h"
#endif
