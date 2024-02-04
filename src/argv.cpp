#include "../include/argv.h"
#include "../include/runtime.h"
#include "../include/cmd_log.h"
#include "../include/erro.h"
#include <exception>
#include <string>

extern std::string appPath;	// QuickCommand running path. equal main.cpp

void RunCom(const std::vector<std::string> head, const std::string com)
{
	std::string filePath(appPath);	// create command file (string)

	for (auto it : head)
		filePath.append("\\" + it);	// append file path
	filePath.append("\\" + com);

	if (!com.find(".qc") && !com.at(com.size() - 3) == '.')	// .qc or not
		filePath.append(".qc");

	loadFile(filePath);	// call loadFile (*void)
}

void Command(const int& ac, const char**& av)
{
	Logger t("Command");	// create logger named command

	try
	{
		if (ac == 1)	// no command
			throw erro::no_future_infoamtion();

		if (std::string(av[ac]).at(0) != '-')	// the began of the end of command not with -
			throw erro::command_end_erro();
	}
	catch (erro::no_future_infoamtion nfi)
	{
		t.Error(nfi.what("The value of (int)argc should not 1"));
		exit(1);
	}
	catch (erro::command_end_erro cee)	// the end of command is error
	{
		t.Error(cee.what());
		exit(1);
	}

	t << "Loading...";	// if all was pass, print loading

	std::vector<std::string> command, headCommand;	// create two vector: command used for av; headCommand used for file path
	for (int i = 0; i < ac; i++)
		command.push_back(av[i]);

	for (int i = 0; i < command.size(); i++)
	{
		if (command.at(i)[0] != '-')	// push back file path
			headCommand.push_back(command.at(i));
		else
		{
			try
			{
				if (command.at(++i)[0] == '-')
					throw erro::head_command_erro();
			}
			catch (erro::head_command_erro hce)	// double file command
			{
				t.Error(hce.what("Head Command should begin with \'-\' , but it is not!"));
				exit(1);
			}

			RunCom(headCommand, command.at(i));	// if all was pass, call RunCom (*void)

			headCommand.clear();	// clear headCommand (vector) used for next
		}
	}
}
