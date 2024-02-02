// Name: Quick Command
// Create DateL 2024/1/31
// Author: WhiteCAT346

// Head File
#include <iostream>

#include "include/argv.h"
#include "include/cmd_log.h"

// Software Path
std::string appPath;

int main(int argc, char** argv)
{
	Logger qc("QuickCommand");
	appPath = argv[0];

	try
	{
		if (argc == 1)
			throw 1;

		Command(argc, argv);
	}
	catch (int)
	{
		qc.Fata("Should have command, but it is not!");
		return 1;
	}

	return 0;
}
