#include "AdvancedCoffeeMakers.h"

#include <iostream>
#include <string>

using namespace std;

AdvancedCoffeeMakersSharedPointer AdvancedCoffeeMakers::instance;

void AdvancedCoffeeMakers::process() noexcept
{
	constexpr char FEATURE_MODEL_END[] = "#";
	constexpr char TEST_CASE_END[] = "##";
	int number_of_test_cases;
	string line;

	cout << "Please enter number of test cases : " << endl;
	cin >> number_of_test_cases;

	for (size_t i = 0; i < number_of_test_cases; ++i)
	{
		FeatureModel feature_model;

		while ((cin >> line) && (line != FEATURE_MODEL_END))
			feature_model.parse_feature_model(line);

		current_feature_model = feature_model;

		while ((cin >> line) && (line != TEST_CASE_END))
		{
			Configuration configuration;
			configuration.parse_configuration(line);
			current_configuration = configuration;
			check_configuration_validity();
			add_to_output_stream();
		}
		output_stream << TEST_CASE_END << "\n";
	}
}

void AdvancedCoffeeMakers::check_relations(FeatureModelMap::iterator& iterator)
{
	vector<Feature> sub_features = iterator->second.second;
	Commons::DelimiterType delimiter_type = iterator->second.first;

	switch (delimiter_type)
	{
		case Commons::DelimiterType::Mandatory:
			mandatory_check(sub_features);
			break;

		case Commons::DelimiterType::Or:
			or_check(sub_features);
			break;

		case Commons::DelimiterType::Alternative:
			alternative_check(sub_features);
			break;
		default:
				break;
	}
}

void AdvancedCoffeeMakers::check_configuration_validity() noexcept
{
	is_valid_configuration = false;
	try
	{
		int root_index = current_configuration.get_index(
				current_feature_model.get_root_name());
		dfs(root_index);
	}
	catch (FeatureNameNotFound)
	{
		return;
	}

	if (current_configuration.is_iterable())
	{
		is_valid_configuration = true;

		FeatureModelMap features = current_feature_model.get_features();

		for (FeatureModelMap::iterator iterator = features.begin();
				iterator != features.end(); ++iterator)
		{
			string feature_name = iterator->first;

			if (current_configuration.has_feature(feature_name))
				check_relations(iterator);
		}
	}
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
		catch (FeatureNameNotFound)
		{
			continue;
		}
	}
}
