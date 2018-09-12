#ifndef FEATURE_H_
#define FEATURE_H_

#include <vector>

class Feature
{
public:
	Feature() {}
private:
	std::vector<Feature*> sub_features;
};

#include "Feature-inl.h"
#endif
