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

void AdvancedCoffeeMakers::dfs_utility(int dfs_index)
{
	current_configuration.set_true(dfs_index);

	std::string name = current_configuration.get_name(dfs_index);

	for (size_t index = Commons::BEGIN;
			index < current_feature_model.get_adjacents_size(name); ++index)
	{
		try
		{
			int configuration_index = current_configuration.get_index(
					current_feature_model.get_adjacent_name(name, index));

			if (!current_configuration.get_validation(configuration_index))
				dfs_utility(configuration_index);
		}
		catch(FEATURE_NAME_NOT_FOUND)
		{
			continue;
		}
	}
}

void AdvancedCoffeeMakers::dfs(int root_index)
{
	current_configuration.reset_validations();
	dfs_utility(root_index);
}

#endif
