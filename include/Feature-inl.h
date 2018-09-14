#ifndef FEATURE_INL_H_
#define FEATURE_INL_H_

#ifndef FEATURE_H_
#error "Feature-inl.h" should be included only in "Feature.h" file.
#endif

Feature::Feature(std::string name, Commons::FeatureType feature_type)
{
	value = std::pair<std::string, Commons::FeatureType> (name, feature_type);
}

std::string Feature::get_name()
{
	return value.first;
}

#endif
