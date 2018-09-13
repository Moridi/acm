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
	inline bool is_valid_configuration() const noexcept;

private:
	inline AdvancedCoffeeMakers() noexcept;
	static AdvancedCoffeeMakersSharedPointer instance;
	Configuration current_configuration;
	FeatureModel feature_model;
};

#include "AdvancedCoffeeMakers-inl.h"
#endif
