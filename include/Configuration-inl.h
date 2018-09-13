#ifndef CONFIGURATION_INL_H_
#define CONFIGURATION_INL_H_

#ifndef CONFIGURATION_H_
#error "Configuration-inl.h" should be included only in "Configuration.h" file.
#endif

#include "Commons.h"

Configuration::Configuration()
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

#endif
