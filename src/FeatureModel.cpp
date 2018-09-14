#include "FeatureModel.h"

#include "Commons.h"

using namespace std;

void FeatureModel::parse_feature_model(string line) noexcept
{
	constexpr size_t PARENT_FEATURE_INDEX = 0;
	vector<string> features_name;

	try
	{
		char delimiter = Commons::get_delimiter(line);
		fill_feature_model_vector(features_name, line, delimiter);

		for (size_t index = PARENT_FEATURE_INDEX + 1; index < features_name.size(); ++index)
		{
			string name = Commons::remove_question_mark(features_name[index]);

			features[features_name[PARENT_FEATURE_INDEX]].first =
					Commons::get_delimiter_type(delimiter);
			features[features_name[PARENT_FEATURE_INDEX]].second.push_back(
					Feature(name, Commons::get_feature_type(features_name[index], delimiter)));
		}
	}
	catch (BAD_DELIMITER_EXCEPTION)
	{
		cerr << "No valid delimiter found!" << endl;
	}
}
