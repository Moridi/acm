#ifndef FEATURE_MODEL_H_
#define FEATURE_MODEL_H_

#include <vector>
#include <string>
#include "Configuration.h"
#include "Feature.h"

class FeatureModel
{
public:
	inline FeatureModel();
	void parse_feature_model(std::string line) noexcept;
	inline void fill_feature_model_vector(std::vector<std::string>& tokens,
			std::string line, const char delimiter) noexcept;
	inline std::string get_root_name();
	inline std::string get_adjacent_name(std::string parent_name, size_t index);
	inline size_t get_adjacents_size(std::string parent_name);

private:
	std::string root_name;
	std::map<std::string, std::vector<Feature>> features;
};

#include "FeatureModel-inl.h"
#endif
