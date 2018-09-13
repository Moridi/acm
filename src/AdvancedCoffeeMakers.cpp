#include "AdvancedCoffeeMakers.h"

#include <iostream>
#include <string>
#include <vector>

#include <bits/stdc++.h>

#include "Tools.h"

using namespace std;

AcmSharedPointer AdvancedCoffeeMakers::instance;

void AdvancedCoffeeMakers::make_feature_model(string line) const noexcept
{
	try
	{
		vector<string> tokens;
		char delimiter = Tools::get_delimiter(line);
		Tools::fill_feature_model_vector(tokens, line, delimiter);
		tokens.clear();
	}
	catch (BAD_DELIMITER_EXCEPTION)
	{
		cerr << "No valid delimiter found!" << endl;
	}
}

void AdvancedCoffeeMakers::make_configuration(string line) const noexcept
{
	constexpr char DELIMITER = ',';

	try
	{
		line = Tools::make_compatible_string_for_configuration(line);
		vector<string> tokens;
		Tools::tokenize(tokens, line, DELIMITER);
		tokens.clear();
	}
	catch (BAD_DELIMITER_EXCEPTION)
	{
		cerr << "No valid delimiter found!" << endl;
	}
	catch (BAD_CONFIGURAION_STYLE)
	{
		cerr << "Invalid configuraion style!" << endl;
	}
}

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
		while ((cin >> line) && (line != FEATURE_MODEL_END))
			make_feature_model(line);
		while ((cin >> line) && (line != TEST_CASE_END))
			make_configuration(line);

	}
}
