#ifndef CONFIGURATION_INL_H_
#define CONFIGURATION_INL_H_

#ifndef CONFIGURATION_H_
#error "Configuration-inl.h" should be included only in "Configuration.h" file.
#endif

#include "Commons.h"

Configuration::Configuration()
: is_valid_configuraion(false)
{
}

std::string Configuration::make_compatible_string_for_configuration(std::string& line)
{
	constexpr size_t USELESS_OPEN_BRACKET_INDEX = 1;
	constexpr size_t MINIMUM_SIZE = 2;

	if (line.size() < MINIMUM_SIZE)
		throw BAD_CONFIGURAION_STYLE_EXCEPTION();

	size_t useless_close_bracket_index = line.size() - MINIMUM_SIZE;
	return line.substr(USELESS_OPEN_BRACKET_INDEX, useless_close_bracket_index);
}

string Configuration::get_feature_name(size_t index) const
{
	if (index > configuration.size())
		throw VECTOR_OUT_OF_SIZE_EXCEPTION();
	return configuration[index];
}

size_t Configuration::get_size() const noexcept
{
	return configuration.size();
}

void Configuration::reset_validations()
{
	for (size_t i = 0; i < configuration.size(); ++i)
		configuration_validation.push_back(false);
}

int Configuration::get_index(std::string name)
{
	std::vector<std::string>::iterator iterator;

	iterator = find(configuration.begin(), configuration.end(), name);
	if (iterator != configuration.end())
		return iterator - configuration.begin();
	throw FEATURE_NAME_NOT_FOUND();
}

bool Configuration::has_feature(std::string name) noexcept
{
	std::vector<std::string>::iterator iterator;

	iterator = find(configuration.begin(), configuration.end(), name);
	if (iterator != configuration.end())
		return true;
	return false;
}

inline void Configuration::set_true(size_t index)
{
	configuration_validation[index] = true;
}

std::string Configuration::get_name(size_t index)
{
	return configuration[index];
}

bool Configuration::get_validation(size_t index)
{
	return configuration_validation[index];
}

inline bool Configuration::is_iterable()
{
	bool is_iterable = true;
	for (size_t index; index < configuration_validation.size(); ++index)
		is_iterable = configuration_validation[index] & is_iterable;
	return is_iterable;
}

#endif
