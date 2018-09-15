#include "Configuration.h"

#include "Commons.h"

using namespace std;

void Configuration::parse_configuration(const string& line) noexcept
{
	clear();
	constexpr char DELIMITER = ',';
	vector<string> tokens;
	try
	{
		const string configuration_string = Commons::remove_extra_brackets(line);
		Commons::tokenize(tokens, configuration_string, DELIMITER);
		configuration = tokens;
	}
	catch (BadDelimiterException)
	{
		cerr << "No valid delimiter found!" << endl;
	}
	catch (BadConfiguraionStyleException)
	{
		cerr << "Invalid configuraion style!" << endl;
	}
}
