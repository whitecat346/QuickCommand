#include "../include/argv.h"
#include "../include/cmd_log.h"
#include <exception>
#include <string>

// Exception
namespace erro
{
	class no_future_infoamtion : public std::exception
	{
	public:
		char const* what(const char* info) const throw()
		{
			return "No Future Information: " + *info;
		}
	};

	class file_command_error : public std::exception
	{
	public:
		char const* what() const throw()
		{
			return "File Command Error: The file command should begin with \'-\'";
		}
	};
}

void Command(int ac, char** av)
{
	Logger t("Command");

	try
	{
		if (ac == 1)
			throw erro::no_future_infoamtion();

		if (std::string(av[ac]).at(0) != '-')
			throw erro::file_command_error();
	}
	catch (erro::no_future_infoamtion nfi)
	{
		t.Error(nfi.what("The value of (int)argc should not 1"));
		exit(1);
	}
	catch (erro::file_command_error fce)
	{
		t.Error(fce.what());
		exit(1);
	}
	
	// Command: qc git -gitignone
	t << "Loading...";

	for ( int i = 0; i < ac; i += 2 )
		RunCom(av[i], av[(i + 1)]);
}

void RunCom(std::string head, std::string com)
{
	try
	{
		
	}
	catch (erro::no_future_infoamtion)
	{
	}
}

