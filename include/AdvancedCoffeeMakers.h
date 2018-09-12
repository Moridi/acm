#ifndef ADVANCED_COFFEE_MAKERS_H_
#define ADVANCED_COFFEE_MAKERS_H_

#include <memory>
#include <vector>
#include <string>

class AdvancedCoffeeMakers
{
public:
	typedef std::shared_ptr<AdvancedCoffeeMakers> AcmSharedPointer;

	~AdvancedCoffeeMakers() = default;
	inline static AcmSharedPointer get_instance() noexcept;
	void get_input() const noexcept;
	char get_delimiter(std::string line) const;
	void tokenize(std::vector<std::string>& tokens, std::string line, const char delimiter)
			const noexcept;

private:
	inline AdvancedCoffeeMakers() noexcept;
	static AcmSharedPointer instance;
};

#include "AdvancedCoffeeMakers-inl.h"
#endif
