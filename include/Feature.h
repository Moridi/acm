#ifndef FEATURE_H_
#define FEATURE_H_

#include <vector>
#include <string>
#include <utility>

#include "Commons.h"

class Feature
{
public:
	inline Feature(std::string name, Commons::FeatureType feature_type);

	inline std::string get_name() const noexcept;
	inline Commons::FeatureType get_feature_type() const noexcept;

private:
	std::pair<std::string, Commons::FeatureType> value;
};

#include "Feature-inl.h"
#endif
