#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include <vector>
#include <string>

class Configuration
{
public:
	inline Configuration();

	static inline std::string make_compatible_string_for_configuration(std::string& line);
	static void make_configuration(std::string line) noexcept;
};

#include "Configuration-inl.h"
#endif
