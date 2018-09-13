#ifndef COMMONS_H_
#define COMMONS_H_

#include <memory>
#include <vector>
#include <string>

class BAD_DELIMITER_EXCEPTION{};
class BAD_CONFIGURAION_STYLE_EXCEPTION{};
class VECTOR_OUT_OF_SIZE_EXCEPTION{};

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

	inline static char get_delimiter(std::string line);
	inline static void tokenize(std::vector<std::string>& tokens, std::string line,
			const char delimiter) noexcept;
	inline static FeatureType get_feature_type(std::string name, char delimiter);
	inline static std::string remove_question_mark(std::string name);

private:
	static constexpr int DELIMITER_NOT_FOUND = -1;
};

#include "Commons-inl.h"
#endif
