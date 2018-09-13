#include "FeatureModel.h"

#include "Commons.h"

using namespace std;

void FeatureModel::make_feature_model(string line) noexcept
{
	constexpr size_t PARENT_FEATURE_INDEX = 0;
	vector<string> tokens;
	try
	{
		char delimiter = Commons::get_delimiter(line);
		fill_feature_model_vector(tokens, line, delimiter);
		std::vector<Feature> sub_features;

		for (size_t index = PARENT_FEATURE_INDEX + 1; index < tokens.size(); ++index)
		{
			string name = Commons::remove_question_mark(tokens[index]);
			sub_features.push_back(Feature(name, Commons::get_feature_type(
					tokens[index], delimiter)));
		}
		features[tokens[PARENT_FEATURE_INDEX]] = sub_features;
	}
	catch (BAD_DELIMITER_EXCEPTION)
	{
		cerr << "No valid delimiter found!" << endl;
	}
}
