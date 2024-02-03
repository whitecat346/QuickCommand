#include "../include/runtime.h"
#include <exception>
#include <fstream>
#include <map>

#include "../include/erro.h"
#include "../include/cmd_log.h"

typedef void(*fun) (std::string head, std::string info);	// Function pointer
namespace fileCommand	// command
{
	void Print(std::string head, std::string info);
	void Creat(std::string head, std::string info);
	void Write(std::string head, std::string info);
	void Read(std::string head, std::string info);

	static std::map<std::string, fun> functionIndex = { {"print", fileCommand::Print},{ "creat", fileCommand::Creat },
		{ "read", fileCommand::Read}, {"write", fileCommand::Write} };
}

Logger rt("RunTime");	// create logger named RunTime
void loadFile(const std::string& filePath)
{
	std::ifstream comFile(filePath);	// create ifstream for load command file

	try
	{
		if (!comFile.is_open())
			throw erro::no_load_file();
	}
	catch (erro::no_load_file nlf)	// can not open the command file
	{
		std::string file(filePath, filePath.rfind('\\'));	// file name
		rt.Error(nlf.what(file.c_str(), "Can not open the file!"));
	}
	// load file info
	/*std::vector<std::string> fileInfomation;*/	// have every line of command file
	std::string fileInfo, com;
	while (std::getline(comFile, fileInfo))
		com.append(fileInfo);
	fileInfo.clear();
	comFile.close();

	runCommand(com);
}

#define COMMAND 91
#define HEAD 40
#define INFO 123
#define END_COMMAND 93
#define END_HEAD 41
#define END_INFO 125

unsigned int lineInCommandFile = 0;

void runCommand(const std::string& command)	// read file to run command
{
	std::string comm, head, info;
	bool inIndex = false;	// in command
	unsigned short type = NULL;	// info type

	for ( auto it : command )
	{
		try
		{
			if (inIndex == true)	// put it into comm || head || info
			{
				if (type == COMMAND)
					comm += it;
				else if (type == HEAD)
					head += it;
				else if (type == INFO)
					info += it;
				else
					throw erro::no_future_infoamtion();

				continue;
			}

			if (it == COMMAND || it == HEAD || it == INFO)	// command head
			{
				type = (int)it;
				inIndex = true;
				continue;
			}
			else if (it == END_COMMAND || it == END_HEAD || it == END_INFO)
			{
				type == NULL;
				inIndex == false;
				continue;
			}



			// next line
			if (it == '\n')
				lineInCommandFile++;
		}
		catch (erro::no_future_infoamtion nfi)
		{
			rt.Error(nfi.what("Got an error message! Position: runCommand (*void) Reason: The value of (short) type is error."));
			exit(1);
		}

	}
}
