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
		output_stream << "##\n";
	}
}

void AdvancedCoffeeMakers::check_configuration_validity() noexcept
{
	try
	{
		int root_index = current_configuration.get_index(
				current_feature_model.get_root_name());
		dfs(root_index);
	}
	catch(FEATURE_NAME_NOT_FOUND)
	{
		is_valid_configuration = false;
		return;
	}

	if(current_configuration.is_iterable())
	{
		is_valid_configuration = true;

		FeatureModelMap features = current_feature_model.get_features();

		for (FeatureModelMap::iterator iterator = features.begin();
				iterator != features.end(); ++iterator)
		{
			std::vector<Feature> sub_features = iterator->second;
			std::string feature_name = iterator->first;

			if (current_configuration.has_feature(feature_name))
			{
				mandatory_check(sub_features);
//				alternative_check(sub_features);
			}
			else
				continue;
		}
	}
}
