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
	void process() const noexcept;

private:
	inline AdvancedCoffeeMakers() noexcept;
	static AdvancedCoffeeMakersSharedPointer instance;
};

#include "AdvancedCoffeeMakers-inl.h"
#endif
