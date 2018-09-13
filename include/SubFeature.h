#ifndef SUB_FEATURE_H_
#define SUB_FEATURE_H_

#include <vector>
#include <string>

#include "Commons.h"

class SubFeature
{
public:
	inline SubFeature(std::string name, Commons::FeatureType feature_type);

public:
	std::pair<std::string, Commons::FeatureType> value;
};

#include "SubFeature-inl.h"
#endif
