#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include <vector>
#include <string>

class Configuration
{
public:
	inline Configuration();

	inline std::string make_compatible_string_for_configuration(std::string& line);
	void make_configuration(std::string line) noexcept;
	inline std::string get_feature_name(size_t index) const;
	inline size_t get_size() const noexcept;

private:
	std::vector<std::string> configuration;
};

#include "Configuration-inl.h"
#endif
