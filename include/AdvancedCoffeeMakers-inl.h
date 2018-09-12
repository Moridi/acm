#ifndef ADVANCED_COFFEE_MAKERS_INL_H_
#define ADVANCED_COFFEE_MAKERS_INL_H_

#ifndef ADVANCED_COFFEE_MAKERS_H_
#error "AdvancedCoffeeMakers-inl.h" should be included only in "AdvancedCoffeeMakers.h" file
#endif

#include <memory>

typedef std::shared_ptr<AdvancedCoffeeMakers> AcmSharedPointer;

AdvancedCoffeeMakers::AdvancedCoffeeMakers() noexcept
{
}

AcmSharedPointer AdvancedCoffeeMakers::get_instance() noexcept
{
	if(instance == nullptr)
		instance = std::make_shared<AdvancedCoffeeMakers>(*(new AdvancedCoffeeMakers));
	return instance;
}

#endif
