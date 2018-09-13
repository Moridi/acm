#ifndef ADVANCED_COFFEE_MAKERS_H_
#define ADVANCED_COFFEE_MAKERS_H_

#include <memory>
#include <vector>
#include <string>

#include "FeatureModel.h"

class AdvancedCoffeeMakers
{
public:
	typedef std::shared_ptr<AdvancedCoffeeMakers> AcmSharedPointer;

	inline ~AdvancedCoffeeMakers() = default;
	inline static AcmSharedPointer get_instance() noexcept;
	void get_input() const noexcept;

private:
	inline AdvancedCoffeeMakers() noexcept;
	static AcmSharedPointer instance;
};

#include "AdvancedCoffeeMakers-inl.h"
#endif
