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

constexpr short COMMAND = 91;
constexpr short HEAD = 40;
constexpr short INFO = 123;
constexpr short END_COMMAND = 93;
constexpr short END_HEAD = 41;
constexpr short END_INFO = 125;

unsigned int lineInCommandFile = 1;

void runCommand(const std::string& command)	// read file to run command
{
	std::string comm, head, info;
	bool inIndex = false, commandEnd = false;	// in command & end
	unsigned short type = NULL, endType = NULL;	// info type

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
			else if (commandEnd == true)	// if command error throw file command error
			{
				if (endType == END_INFO)	// { }
					endType == NULL;
				else if (endType == END_HEAD && (it != '\n' || it != INFO))	// ( )
					throw erro::file_command_error();
				else if (endType == END_COMMAND && it != HEAD)	// [ ]
					throw erro::file_command_error();

				commandEnd = false;
				continue;
			}

			if (it == COMMAND || it == HEAD || it == INFO)	// command head
			{
				type = (int)it;
				inIndex = true;
				continue;
			}
			else if (it == END_COMMAND || it == END_HEAD || it == END_INFO)	// the end of command
			{
				type == NULL;
				endType = it;
				inIndex == false;
				continue;
			}



			// next line
			if (it == '\n')
			{
				lineInCommandFile++;
				if (inIndex == false)
				{
					auto getFunctionIndex = [&](const std::string& temp)->std::string
						{
							if (temp.find(' '))
								return std::string(temp, temp.find(' '));
							else if (temp.find('>'))
								return std::string(temp, temp.find('>'));
							else return temp;
						};
					std::string functionIndexTemp = getFunctionIndex(comm);
					if (fileCommand::functionIndex.find(functionIndexTemp) != fileCommand::functionIndex.end())
						fileCommand::functionIndex.at(functionIndexTemp);
					else throw erro::file_command_not_found();
				}
			}
		}
		catch (erro::no_future_infoamtion nfi)
		{
			rt.Error(nfi.what("Got an error message! Position: runCommand (*void) Reason: The value of (short) type is error."));
			exit(1);
		}
		catch (erro::file_command_error fce)
		{
			rt.Error(fce.what("No future information. In line " + lineInCommandFile));
			exit(1);
		}
		catch (erro::file_command_not_found fcnf)
		{
			rt.Error(fcnf.what("Not Found Command in line " + lineInCommandFile));
			exit(1);
		}
	}
}

