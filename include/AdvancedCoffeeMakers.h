#ifndef ADVANCED_COFFEE_MAKERS_H_
#define ADVANCED_COFFEE_MAKERS_H_

#include <memory>
#include <vector>
#include <string>

#include "FeatureModel.h"
#include "Configuration.h"

class AdvancedCoffeeMakers
{
public:
	typedef std::shared_ptr<AdvancedCoffeeMakers> AdvancedCoffeeMakersSharedPointer;

	inline static AdvancedCoffeeMakersSharedPointer get_instance() noexcept;
	void process() noexcept;

	void check_configuration_validity() noexcept;
	inline void mandatory_check(const std::vector<Feature>& sub_features);
	inline void alternative_check(const std::vector<Feature>& sub_features);
	inline void or_check(const std::vector<Feature>& sub_features);
	inline void check_relations(FeatureModelMap::iterator& iterator);

	inline void dfs(int root_index);
	void dfs_utility(int dfs_index);

	inline void add_to_output_stream();
	inline void print_result();

private:
	inline AdvancedCoffeeMakers() noexcept;
	static AdvancedCoffeeMakersSharedPointer instance;
	Configuration current_configuration;
	FeatureModel current_feature_model;
	bool is_valid_configuration;
	std::stringstream output_stream;
};

#include "AdvancedCoffeeMakers-inl.h"
#endif
