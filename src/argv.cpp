#include "../include/argv.h"
#include "../include/cmd_log.h"
#include <exception>
#include <string>

extern const std::string appPath;

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

	class command_end_erro : public std::exception
	{
	public:
		char const* what() const throw()
		{
			return "The end of command should begin with \'-\' !";
		}
	};

	class head_command_erro : public std::exception
	{
	public:
		char const* what(const char* info) const throw()
		{
			return info;
		}
	};
}

void Command(const int ac, const char** av)
{
	Logger t("Command");

	try
	{
		if (ac == 1)
			throw erro::no_future_infoamtion();

		if (std::string(av[ac]).at(0) != '-')
			throw erro::command_end_erro();
	}
	catch (erro::no_future_infoamtion nfi)
	{
		t.Error(nfi.what("The value of (int)argc should not 1"));
		exit(1);
	}
	catch (erro::command_end_erro cee)
	{
		t.Error(cee.what());
		exit(1);
	}

	t << "Loading...";

	std::vector<std::string> command, headCommand;
	for ( int i = 0; i < ac; i ++ )
		command.push_back(av[i]);

	for ( int i = 0; i < command.size(); i ++ )
	{
		if (command.at(i)[0] != '-')
			headCommand.push_back(command.at(i));
		else
		{
			try
			{
				if (command.at(++i)[0] == '-')
					throw erro::head_command_erro();
			}
			catch (erro::head_command_erro hce)
			{
				t.Error(hce.what("Head Command should begin with \'-\' , but it is not!"));
				exit(1);
			}

			RunCom(headCommand, command.at(i));

			headCommand.clear();
		}
	}

	t << "Finish!";
}

void RunCom(const std::vector<std::string> head, const std::string com)
{
	Logger rc("RunTime");
	std::string filePath(appPath);

	
}

