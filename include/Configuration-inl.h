#ifndef CONFIGURATION_INL_H_
#define CONFIGURATION_INL_H_

#ifndef CONFIGURATION_H_
#error "Configuration-inl.h" should be included only in "Configuration.h" file.
#endif

#include <vector>
#include <string>

#include "Commons.h"

Configuration::Configuration() {}

void Configuration::clear()
{
	configuration.clear();
	configuration_validation.clear();
}

int Configuration::get_size() const noexcept
{
	return configuration.size();
}

void Configuration::reset_validations()
{
	for (int index = Commons::BEGIN; index < configuration.size(); ++index)
		configuration_validation.push_back(false);
}

int Configuration::get_index(const std::string& name) noexcept
{
	std::vector<std::string>::iterator iterator;

	iterator = find(configuration.begin(), configuration.end(), name);
	if (iterator != configuration.end())
		return iterator - configuration.begin();
	return Commons::NOT_FOUND;
}

bool Configuration::has_feature(const std::string& name) noexcept
{
	std::vector<std::string>::iterator iterator;

	iterator = find(configuration.begin(), configuration.end(), name);
	if (iterator != configuration.end())
		return true;
	return false;
}

void Configuration::set_true(int index)
{
	if (index > configuration_validation.size())
		throw VectorOutOfSizeException();

	configuration_validation[index] = true;
}

std::string Configuration::get_name(int index) const
{
	if (index > configuration_validation.size())
		throw VectorOutOfSizeException();

	return configuration[index];
}

bool Configuration::get_validation(int index) const
{
	if (index > configuration_validation.size())
		throw VectorOutOfSizeException();

	return configuration_validation[index];
}

bool Configuration::is_iterable()
{
	bool is_iterable = true;
	for (int index = Commons::BEGIN;
			index < configuration_validation.size(); ++index)
		is_iterable &= configuration_validation[index];

	return is_iterable;
}

#endif
