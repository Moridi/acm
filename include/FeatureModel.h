#ifndef FEATURE_MODEL_H_
#define FEATURE_MODEL_H_

#include <vector>
#include <string>
#include <utility>
#include <map>

#include "Configuration.h"
#include "Feature.h"

class FeatureModel
{
public:
	typedef std::map<std::string, std::pair<Commons::DelimiterType, std::vector<Feature>>>
			FeatureModelMap;

	inline FeatureModel();

	void parse_feature_model(const std::string& line) noexcept;
	void fill_feature_model_vector(std::vector<std::string>& tokens,
			const std::string& feature_model_string, const char delimiter) noexcept;
	inline void clear();

	inline std::string get_root_name() const noexcept;
	inline std::string get_adjacent_name(const std::string& parent_name,
			int index);
	inline int get_adjacents_size(const std::string& parent_name) noexcept;
	inline FeatureModelMap get_features() const noexcept;

private:
	std::string root_name;
	FeatureModelMap features;
};

#include "FeatureModel-inl.h"
#endif
