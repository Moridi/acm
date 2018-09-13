#include "AdvancedCoffeeMakers.h"

#include <iostream>
#include <string>
#include <vector>

#include <bits/stdc++.h>

#include "Tools.h"
#include "SubFeature.h"
#include "Feature.h"

using namespace std;

AcmSharedPointer AdvancedCoffeeMakers::instance;

void AdvancedCoffeeMakers::make_feature_model(string line) const noexcept
{
	constexpr size_t PARENT_FEATURE_INDEX = 0;

	vector<string> tokens;
	try
	{
		char delimiter = Tools::get_delimiter(line);
		Tools::fill_feature_model_vector(tokens, line, delimiter);
		Feature parent_feature(tokens[PARENT_FEATURE_INDEX]);
		for (size_t sub_index = PARENT_FEATURE_INDEX + 1; sub_index < tokens.size(); ++sub_index)
		{
			string name = Tools::remove_question_mark(tokens[sub_index]);
			parent_feature.add_sub_feature(name, Tools::get_feature_type(
					tokens[sub_index], delimiter));
		}
		parent_feature.print_feature();
	}
	catch (BAD_DELIMITER_EXCEPTION)
	{
		cerr << "No valid delimiter found!" << endl;
	}
}

void AdvancedCoffeeMakers::make_configuration(string line) const noexcept
{
	constexpr char DELIMITER = ',';
	vector<string> tokens;

	try
	{
		line = Tools::make_compatible_string_for_configuration(line);
		Tools::tokenize(tokens, line, DELIMITER);
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
