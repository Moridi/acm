#ifndef FEATURE_MODEL_INL_H_
#define FEATURE_MODEL_INL_H_

#ifndef FEATURE_MODEL_H_
#error "FeatureModel-inl.h" should be included only in "FeatureModel.h" file.
#endif

FeatureModel::FeatureModel()
{
}

void FeatureModel::fill_feature_model_vector(std::vector<std::string>& tokens,
		std::string line, const char delimiter) noexcept
{
	constexpr char ASSIGN_DELIMITER = '=';
	constexpr uint8_t RIGHT_VALUE_INDEX = 1;

	Commons::tokenize(tokens, line, ASSIGN_DELIMITER);
	line = tokens[RIGHT_VALUE_INDEX];
	tokens.erase(tokens.begin() + RIGHT_VALUE_INDEX);
	Commons::tokenize(tokens, line, delimiter);
}

#endif
