#ifndef FEATURE_H_
#define FEATURE_H_

#include <vector>
#include <string>

#include "Commons.h"

class Feature
{
public:
	inline Feature(std::string name, Commons::FeatureType feature_type);

public:
	std::pair<std::string, Commons::FeatureType> value;
};

#include "Feature-inl.h"
#endif
