#include "AdvancedCoffeeMakers.h"

#include <iostream>
#include <string>

#include "FeatureModel.h"
#include "Configuration.h"

using namespace std;

AcmSharedPointer AdvancedCoffeeMakers::instance;

void AdvancedCoffeeMakers::get_input() const noexcept
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
			feature_model.make_feature_model(line);
		feature_model.print_feature_model();

		while ((cin >> line) && (line != TEST_CASE_END))
		{
			Configuration configuration;
			configuration.make_configuration(line);
		}
	}
}
