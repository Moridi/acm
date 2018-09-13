#ifndef TOOLS_H_
#define TOOLS_H_

#include <memory>
#include <vector>
#include <string>

class BAD_DELIMITER_EXCEPTION{};
class BAD_CONFIGURAION_STYLE{};

class Tools
{
public:
	inline static char get_delimiter(std::string line);
	inline static void fill_feature_model_vector(std::vector<std::string>& tokens,
			std::string line, const char delimiter) noexcept;
	inline static void tokenize(std::vector<std::string>& tokens, std::string line,
			const char delimiter) noexcept;
	inline static std::string make_compatible_string_for_configuration(std::string line);
};

#include "Tools-inl.h"
#endif
