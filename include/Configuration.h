#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include <vector>
#include <iostream>
#include <string>

class Configuration
{
public:
	inline Configuration();

	inline std::string make_compatible_string_for_configuration(std::string& line);
	void parse_configuration(std::string line) noexcept;
	inline std::string get_feature_name(size_t index) const;
	inline size_t get_size() const noexcept;
	inline void reset_validations();
	inline int get_index(std::string name);
	inline void set_true(size_t index);
	inline std::string get_name(size_t index);
	inline bool get_validation(size_t index);

private:
	std::vector<std::string> configuration;
	std::vector<bool> configuration_validation;
	bool is_valid_configuraion;
};

#include "Configuration-inl.h"
#endif
