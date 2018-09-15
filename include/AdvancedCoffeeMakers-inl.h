#ifndef ADVANCED_COFFEE_MAKERS_INL_H_
#define ADVANCED_COFFEE_MAKERS_INL_H_

#ifndef ADVANCED_COFFEE_MAKERS_H_
#error "AdvancedCoffeeMakers-inl.h" should be included only in "AdvancedCoffeeMakers.h" file.
#endif

#include <vector>
#include <iostream>
#include <memory>

typedef std::shared_ptr<AdvancedCoffeeMakers> AdvancedCoffeeMakersSharedPointer;

AdvancedCoffeeMakers::AdvancedCoffeeMakers() noexcept {}

AdvancedCoffeeMakersSharedPointer AdvancedCoffeeMakers::get_instance() noexcept
{
	if (instance == nullptr)
		instance = std::make_shared<AdvancedCoffeeMakers>(AdvancedCoffeeMakers());
	return instance;
}

void AdvancedCoffeeMakers::check_mandatory_relation(
		const std::vector<Feature>& sub_features) noexcept
{
	for (int index = Commons::BEGIN; index < sub_features.size(); ++index)
	{
		Feature feature = sub_features[index];
		if (feature.get_feature_type() == Commons::FeatureType::Mandatory)
			is_valid_configuration =
					current_configuration.has_feature(feature.get_name())
					&& is_valid_configuration;
	}
}

void AdvancedCoffeeMakers::check_alternative_relation(
		const std::vector<Feature>& sub_features) noexcept
{
	bool is_valid_xor = false;

	for (int index = Commons::BEGIN; index < sub_features.size(); ++index)
	{
		Feature feature = sub_features[index];

		if (feature.get_feature_type() == Commons::FeatureType::Alternative)
		{
			if (current_configuration.has_feature(feature.get_name())
					&& !(is_valid_xor))
				is_valid_xor = true;
			else if (current_configuration.has_feature(feature.get_name())
					&& is_valid_xor)
			{
				is_valid_xor = false;
				break;
			}
		}
	}
	is_valid_configuration = is_valid_configuration & is_valid_xor;
}

void AdvancedCoffeeMakers::check_or_relation(
		const std::vector<Feature>& sub_features) noexcept
{
	bool is_valid_or = false;

	for (int index = Commons::BEGIN; index < sub_features.size(); ++index)
	{
		Feature feature = sub_features[index];

		if (feature.get_feature_type() == Commons::FeatureType::Or)
		{
			if (current_configuration.has_feature(feature.get_name()))
				is_valid_or = true;
		}
	}
	is_valid_configuration = is_valid_configuration & is_valid_or;
}

void AdvancedCoffeeMakers::add_to_output_stream() noexcept
{
	constexpr char VALID[] = "Valid\n";
	constexpr char INVALID[] = "Invalid\n";

	if (is_valid_configuration)
		output_stream << VALID;
	else
		output_stream << INVALID;
}

void AdvancedCoffeeMakers::print_result() const noexcept
{
	std::cout << output_stream.str();
}

#endif
