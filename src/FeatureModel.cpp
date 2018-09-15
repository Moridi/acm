#include "FeatureModel.h"

#include "Commons.h"

using namespace std;

void FeatureModel::parse_feature_model(const string& feature_model_string)
		noexcept
{
	constexpr uint8_t PARENT_FEATURE_INDEX = 0;
	vector<string> features_name;

	char delimiter = Commons::get_delimiter(feature_model_string);
	fill_feature_model_vector(features_name, feature_model_string, delimiter);

	for (int index = PARENT_FEATURE_INDEX + 1; index < features_name.size(); ++index)
	{
		string name = Commons::remove_question_mark(features_name[index]);

		features[features_name[PARENT_FEATURE_INDEX]].first =
				Commons::get_delimiter_type(delimiter);

		features[features_name[PARENT_FEATURE_INDEX]].second.push_back(
				Feature(name, Commons::get_feature_type(
						features_name[index], delimiter)));
	}
}

void FeatureModel::fill_feature_model_vector(std::vector<std::string>& tokens,
		const std::string& feature_model_string, const char delimiter) noexcept
{
	constexpr char ASSIGN_DELIMITER = '=';
	constexpr uint8_t LEFT_VALUE_INDEX = 0;
	constexpr uint8_t RIGHT_VALUE_INDEX = 1;

	Commons::tokenize(tokens, feature_model_string, ASSIGN_DELIMITER);
	const string right_value_string = tokens[RIGHT_VALUE_INDEX];
	tokens.erase(tokens.begin() + RIGHT_VALUE_INDEX);
	Commons::tokenize(tokens, right_value_string, delimiter);

	if (features.empty())
		root_name = tokens[LEFT_VALUE_INDEX];
}

