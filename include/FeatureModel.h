#ifndef FEATURE_MODEL_H_
#define FEATURE_MODEL_H_

#include <vector>

class Feature;

class FeatureModel
{
public:
	FeatureModel() {}
private:
	std::vector<Feature*> features;
};

#include "FeatureModel-inl.h"
#endif
