#ifndef FEATURE_MODEL_H_
#define FEATURE_MODEL_H_

#include <vector>
#include <string>
#include "Feature.h"

class FeatureModel
{
public:
	inline FeatureModel();
	void make_feature_model(std::string line) noexcept;
	inline void fill_feature_model_vector(std::vector<std::string>& tokens,
			std::string line, const char delimiter) noexcept;

	void print_feature_model()
	{
		for (int i = 0; i < features.size(); ++i)
		{
			Feature feature = features[i];
			std::cout << "***** " << feature.name << std::endl;
			for (int j = 0; j < feature.sub_features.size(); ++j)
			{
				SubFeature sub_feature = feature.sub_features[j];
				std::cout << sub_feature.value.first << " " << static_cast<char>(sub_feature.value.second) << std::endl;
			}
		}
	}

private:
	std::vector<Feature> features;
};

#include "FeatureModel-inl.h"
#endif
