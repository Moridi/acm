#ifndef SUB_FEATURE_INL_H_
#define SUB_FEATURE_INL_H_

#ifndef SUB_FEATURE_H_
#error "SubFeature-inl.h" should be included only in "SubFeature.h" file.
#endif

SubFeature::SubFeature(std::string name, Commons::FeatureType feature_type)
{
	value = std::pair<std::string, Commons::FeatureType> (name, feature_type);
}

#endif
