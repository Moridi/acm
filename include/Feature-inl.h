#ifndef FEATURE_INL_H_
#define FEATURE_INL_H_

#ifndef FEATURE_H_
#error "Feature-inl.h" should be included only in "Feature.h" file.
#endif

Feature::Feature(std::string name_)
: name(name_)
{
}

void Feature::add_sub_feature(std::string sub_feature_name,
		Tools::FeatureType sub_feature_type)
{
	sub_features.push_back(SubFeature(sub_feature_name, sub_feature_type));
}

#endif
