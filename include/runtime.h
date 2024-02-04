#pragma once

#include <fstream>
#include <map>

void loadFile(const std::string& filePath);
void runCommand(std::string& command);

namespace fileCommand
{
	void Print(std::string command, std::string head, std::string info);
	void Creat(std::string command, std::string head, std::string info);
	void Write(std::string command, std::string head, std::string info);
	void Read(std::string command, std::string head, std::string info);


	typedef void(*fun) (std::string command, std::string head, std::string info);	// Function pointer
	static std::map<std::string, fun> functionIndex = { {"print", fileCommand::Print},{ "creat", fileCommand::Creat },
		{ "read", fileCommand::Read}, {"write", fileCommand::Write} };
}
