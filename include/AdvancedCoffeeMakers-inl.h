#ifndef ADVANCED_COFFEE_MAKERS_INL_H_
#define ADVANCED_COFFEE_MAKERS_INL_H_

#ifndef ADVANCED_COFFEE_MAKERS_H_
#error "AdvancedCoffeeMakers-inl.h" should be included only in "AdvancedCoffeeMakers.h" file.
#endif

#include <memory>

typedef std::shared_ptr<AdvancedCoffeeMakers> AdvancedCoffeeMakersSharedPointer;

AdvancedCoffeeMakers::AdvancedCoffeeMakers() noexcept
{
}

AdvancedCoffeeMakersSharedPointer AdvancedCoffeeMakers::get_instance() noexcept
{
	if(instance == nullptr)
		instance = std::make_shared<AdvancedCoffeeMakers>(AdvancedCoffeeMakers());
	return instance;
}

bool AdvancedCoffeeMakers::is_valid_configuration() const noexcept
{
	for (size_t index; index < current_configuration.get_size(); ++index)
	{
		std::string feature_name = current_configuration.get_feature_name(index);
	}
}

#endif
