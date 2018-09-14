#ifndef ADVANCED_COFFEE_MAKERS_INL_H_
#define ADVANCED_COFFEE_MAKERS_INL_H_

#ifndef ADVANCED_COFFEE_MAKERS_H_
#error "AdvancedCoffeeMakers-inl.h" should be included only in "AdvancedCoffeeMakers.h" file.
#endif

#include <iostream>
#include <memory>

typedef std::shared_ptr<AdvancedCoffeeMakers> AdvancedCoffeeMakersSharedPointer;

AdvancedCoffeeMakers::AdvancedCoffeeMakers() noexcept
{
}

AdvancedCoffeeMakersSharedPointer AdvancedCoffeeMakers::get_instance() noexcept
{
	if(instance == nullptr)
		instance = std::make_shared<AdvancedCoffeeMakers>(AdvancedCoffeeMakers());
	return instance;
}

void AdvancedCoffeeMakers::dfs_utility(int dfs_index)
{
	current_configuration.set_true(dfs_index);

	std::string name = current_configuration.get_name(dfs_index);

	for (size_t index = Commons::BEGIN;
			index < current_feature_model.get_adjacents_size(name); ++index)
	{
		try
		{
			int configuration_index = current_configuration.get_index(
					current_feature_model.get_adjacent_name(name, index));

			if (!current_configuration.get_validation(configuration_index))
				dfs_utility(configuration_index);
		}
		catch(FEATURE_NAME_NOT_FOUND)
		{
			continue;
		}
	}
}

void AdvancedCoffeeMakers::dfs(int root_index)
{
	current_configuration.reset_validations();
	dfs_utility(root_index);
}

void AdvancedCoffeeMakers::mandatory_check(const std::vector<Feature>& sub_features)
{
	for (int j = 0; j < sub_features.size(); ++j)
	{
		Feature feature = sub_features[j];
		if(feature.get_feature_type() == Commons::FeatureType::Mandatory)
			is_valid_configuration = (current_configuration.has_feature(feature.get_name()))
					&& is_valid_configuration;
	}
}

void AdvancedCoffeeMakers::alternative_check(const std::vector<Feature>& sub_features)
{
	bool is_valid_xor = false;

	for (int j = 0; j < sub_features.size(); ++j)
	{
		Feature feature = sub_features[j];

		if(feature.get_feature_type() == Commons::FeatureType::Alternative)
		{
			if (current_configuration.has_feature(feature.get_name()) && !(is_valid_xor))
				is_valid_xor = true;
			if (current_configuration.has_feature(feature.get_name()) && is_valid_xor)
			{
				is_valid_xor = false;
				break;
			}
		}
	}
	is_valid_configuration = is_valid_configuration & is_valid_xor;
}

void AdvancedCoffeeMakers::add_to_output_stream()
{
	if (is_valid_configuration)
		output_stream << "Valid\n";
	else
		output_stream << "Invalid\n";
}

void AdvancedCoffeeMakers::print_result()
{
	std::cout << output_stream.str();
}

#endif
