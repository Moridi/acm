#ifndef SUB_FEATURE_H_
#define SUB_FEATURE_H_

#include <vector>
#include <string>

#include "Tools.h"

class SubFeature
{
public:
	inline SubFeature(std::string name, Tools::FeatureType feature_type);

public:
	std::pair<std::string, Tools::FeatureType> value;
};

#include "SubFeature-inl.h"
#endif
