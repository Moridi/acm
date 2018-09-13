#include "AdvancedCoffeeMakers.h"

#include <iostream>
#include <string>

using namespace std;

AdvancedCoffeeMakersSharedPointer AdvancedCoffeeMakers::instance;

void AdvancedCoffeeMakers::process() const noexcept
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
			try
			{
				feature_model.is_valid_configuration(configuration);
			}
			catch(VECTOR_OUT_OF_SIZE_EXCEPTION)
			{
				cerr << "Segmentation fault!" << endl;
			}
		}
	}
}
