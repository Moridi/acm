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
			check_configuration_validation();
		}
	}
}

void AdvancedCoffeeMakers::check_configuration_validation() noexcept
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
	}
}
