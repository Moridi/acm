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
	void check_configuration_validation() noexcept;
	inline void dfs(int root_index);
	inline void dfs_utility(int dfs_index);

private:
	inline AdvancedCoffeeMakers() noexcept;
	static AdvancedCoffeeMakersSharedPointer instance;
	Configuration current_configuration;
	FeatureModel current_feature_model;
	bool is_valid_configuration;
};

#include "AdvancedCoffeeMakers-inl.h"
#endif
