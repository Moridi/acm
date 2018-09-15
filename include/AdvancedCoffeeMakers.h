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
	inline void check_mandatory_relation(const std::vector<Feature>& sub_features)
			noexcept;
	inline void check_alternative_relation(const std::vector<Feature>& sub_features)
			noexcept;
	inline void check_or_relation(const std::vector<Feature>& sub_features)
			noexcept;
	inline void check_relations(const FeatureModelMap::iterator& iterator) noexcept;

	Commons::Result dfs() noexcept;
	void dfs_utility(int dfs_index) noexcept;

	inline void add_to_output_stream() noexcept;
	inline void print_result() const noexcept;

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
