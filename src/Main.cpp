#include "AdvancedCoffeeMakers.h"

int main()
{
	AdvancedCoffeeMakersSharedPointer instance =
			AdvancedCoffeeMakers::get_instance();
	instance->process();
}
