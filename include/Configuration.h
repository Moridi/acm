#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include <vector>
#include <iostream>
#include <string>

class Configuration
{
public:
	inline Configuration();

	void parse_configuration(const std::string &line) noexcept;

	inline void reset_validations();
	inline void set_true(int index);
	inline void clear();

	inline bool is_iterable();
	inline bool has_feature(const std::string& name) noexcept;

	inline int get_size() const noexcept;
	inline int get_index(const std::string& name) noexcept;
	inline std::string get_name(int index) const;
	inline bool get_validation(int index) const;

private:
	std::vector<std::string> configuration;
	std::vector<bool> configuration_validation;
};

#include "Configuration-inl.h"
#endif
