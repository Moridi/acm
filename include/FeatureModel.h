#ifndef FEATURE_MODEL_H_
#define FEATURE_MODEL_H_

#include <vector>

class Feature;

class FeatureModel
{
public:
	FeatureModel() {}
	inline void operator+(const Feature& feature) const noexcept;
//	inline Feature& operator=(const Feature& feature);
	inline void operator|(const Feature& feature) const noexcept;
	inline void operator^(const Feature& feature) const noexcept;
private:
	std::vector<Feature*> features;
};

#include "FeatureModel-inl.h"
#endif
