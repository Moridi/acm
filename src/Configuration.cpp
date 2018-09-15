#include "Configuration.h"

#include "Commons.h"

using namespace std;

void Configuration::parse_configuration(string line) noexcept
{
	constexpr char DELIMITER = ',';
	vector<string> tokens;

	try
	{
		line = make_compatible_string_for_configuration(line);
		Commons::tokenize(tokens, line, DELIMITER);
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
