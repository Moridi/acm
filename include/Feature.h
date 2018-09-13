#ifndef FEATURE_H_
#define FEATURE_H_

#include <vector>
#include <string>

#include "SubFeature.h"

class Feature
{
public:
	inline Feature(std::string name_);
	inline void add_sub_feature(std::string sub_feature_name,
			Tools::FeatureType sub_feature_type);

	void print_feature()
	{
		std::cout << name << std::endl;
		for (int i = 0; i < sub_features.size(); ++i)
		{
			std::cout << sub_features[i].value.first << " " << static_cast<char>(sub_features[i].value.second) << std::endl;
		}
	}

private:
	std::string name;
	std::vector<SubFeature> sub_features;
};

#include "Feature-inl.h"
#endif
