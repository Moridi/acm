#ifndef FEATURE_MODEL_H_
#define FEATURE_MODEL_H_

#include <vector>
#include <string>
#include "Configuration.h"
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
		for (std::map<std::string, std::vector<Feature>>::iterator it=features.begin(); it!=features.end(); ++it)
		{
			std::vector<Feature> features = it->second;
			std::cout << "***** " << it->first << " => \n";
			for (int j = 0; j < features.size(); ++j)
			{
				Feature feature = features[j];
				std::cout << feature.value.first << " " << static_cast<char>(feature.value.second) << std::endl;
			}
		}
	}

private:
	std::map<std::string, std::vector<Feature>> features;
};

#include "FeatureModel-inl.h"
#endif
