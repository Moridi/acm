#include "AdvancedCoffeeMakers.h"

#include <iostream>
#include <string>

using namespace std;

AdvancedCoffeeMakersSharedPointer AdvancedCoffeeMakers::instance;

void AdvancedCoffeeMakers::process() noexcept
{
	static constexpr char FEATURE_MODEL_END[] = "#";
	static constexpr char TEST_CASE_END[] = "##";
	int number_of_test_cases;
	string line;

	cout << "Please enter number of test cases : " << endl;
	cin >> number_of_test_cases;

	for (int index = Commons::BEGIN; index < number_of_test_cases; ++index)
	{
		current_feature_model.clear();
		while ((cin >> line) && (line != FEATURE_MODEL_END))
			current_feature_model.parse_feature_model(line);

		while ((cin >> line) && (line != TEST_CASE_END))
		{
			current_configuration.parse_configuration(line);
			check_configuration_validity();
			add_to_output_stream();
		}
		output_stream << TEST_CASE_END << endl;
	}
}

void AdvancedCoffeeMakers::check_relations(
		const FeatureModelMap::iterator& iterator) noexcept
{
	vector<Feature> sub_features = iterator->second.second;
	Commons::DelimiterType delimiter_type = iterator->second.first;
	string feature_name = iterator->first;

	if (current_configuration.has_feature(feature_name))
		switch (delimiter_type)
		{
			case Commons::DelimiterType::Mandatory:
				check_mandatory_relation(sub_features);
				break;

			case Commons::DelimiterType::Or:
				check_or_relation(sub_features);
				break;

			case Commons::DelimiterType::Alternative:
				check_alternative_relation(sub_features);
				break;
			default:
				break;
		}
}

void AdvancedCoffeeMakers::check_configuration_validity() noexcept
{
	is_valid_configuration = false;
	if (dfs() == Commons::Result::UNSUCCESSFUL)
		return;

	if (current_configuration.is_iterable())
	{
		is_valid_configuration = true;
		FeatureModelMap features = current_feature_model.get_features();

		for (FeatureModelMap::iterator iterator = features.begin();
			 iterator != features.end(); ++iterator)
			check_relations(iterator);
	}
}


Commons::Result AdvancedCoffeeMakers::dfs() noexcept
{
	try
	{
		int root_index = current_configuration.get_index(
					current_feature_model.get_root_name());
		if (root_index == Commons::NOT_FOUND)
			return Commons::Result::UNSUCCESSFUL;

		current_configuration.reset_validations();
		dfs_utility(root_index);
	}
	catch (VectorOutOfSizeException)
	{
		std::cerr << "Segmentation fault!" << std::endl;
		return Commons::Result::UNSUCCESSFUL;
	}
	return Commons::Result::SUCCESSFUL;
}

void AdvancedCoffeeMakers::dfs_utility(int dfs_index) noexcept
{
	current_configuration.set_true(dfs_index);

	std::string name = current_configuration.get_name(dfs_index);

	for (int index = Commons::BEGIN;
			index < current_feature_model.get_adjacents_size(name); ++index)
	{
		int configuration_index = current_configuration.get_index(
				current_feature_model.get_adjacent_name(name, index));

		if ((configuration_index != Commons::NOT_FOUND)
				&& (!current_configuration.get_validation(configuration_index)))
			dfs_utility(configuration_index);
	}
}
