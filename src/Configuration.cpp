#include "Configuration.h"

#include "Commons.h"

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
	catch (BAD_DELIMITER_EXCEPTION)
	{
		cerr << "No valid delimiter found!" << endl;
	}
	catch (BAD_CONFIGURAION_STYLE_EXCEPTION)
	{
		cerr << "Invalid configuraion style!" << endl;
	}
}
