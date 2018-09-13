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
			Commons::FeatureType sub_feature_type);

public:
	std::string name;
	std::vector<SubFeature> sub_features;
};

#include "Feature-inl.h"
#endif
