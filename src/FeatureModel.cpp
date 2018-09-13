#include "FeatureModel.h"

#include "Commons.h"
#include "Feature.h"

using namespace std;

void FeatureModel::make_feature_model(string line) noexcept
{
	constexpr size_t PARENT_FEATURE_INDEX = 0;
	vector<string> tokens;
	try
	{
		char delimiter = Commons::get_delimiter(line);
		fill_feature_model_vector(tokens, line, delimiter);
		Feature parent_feature(tokens[PARENT_FEATURE_INDEX]);

		for (size_t sub_index = PARENT_FEATURE_INDEX + 1; sub_index < tokens.size(); ++sub_index)
		{
			string name = Commons::remove_question_mark(tokens[sub_index]);
			parent_feature.add_sub_feature(name, Commons::get_feature_type(
					tokens[sub_index], delimiter));
		}
		features.push_back(parent_feature);
	}
	catch (BAD_DELIMITER_EXCEPTION)
	{
		cerr << "No valid delimiter found!" << endl;
	}
}

