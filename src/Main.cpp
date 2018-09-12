#include "AdvancedCoffeeMakers.h"

int main()
{
	AcmSharedPointer instance = AdvancedCoffeeMakers::get_instance();
	instance->get_input();
}
