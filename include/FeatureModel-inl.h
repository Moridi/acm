#ifndef FEATURE_MODEL_INL_H_
#define FEATURE_MODEL_INL_H_

#ifndef FEATURE_MODEL_H_
#error "FeatureModel-inl.h" should be included only in "FeatureModel.h" file.
#endif

#include <vector>
#include <string>
#include <utility>
#include <map>

typedef std::map<std::string, std::pair<Commons::DelimiterType, std::vector<Feature>>>
		FeatureModelMap;

FeatureModel::FeatureModel() {}

void FeatureModel::clear()
{
	root_name.clear();
	features.clear();
}

std::string FeatureModel::get_root_name() const noexcept
{
	return root_name;
}

std::string FeatureModel::get_adjacent_name(const std::string& parent_name,
		int index)
{
	if (index > features[parent_name].second.size())
		throw VectorOutOfSizeException();

	return features[parent_name].second[index].get_name();
}

int FeatureModel::get_adjacents_size(const std::string& parent_name) noexcept
{
	return features[parent_name].second.size();
}

FeatureModelMap FeatureModel::get_features() const noexcept
{
	return features;
}

#endif
