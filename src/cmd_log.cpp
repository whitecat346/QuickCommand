// CMD LOG Head File

#include "../include/cmd_log.h"

#include <chrono>
#include <iostream>

void GetSystemTime(tm& tmd)
{
	time_t tt = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	localtime_s(&tmd, &tt);
}

tm GetSystemTime()
{
	time_t tt = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	tm temp;
	localtime_s(&temp, &tt);
	return temp;
}

std::string CoutTime()
{
	tm tmm = GetSystemTime();
	std::cout << tmm.tm_year + 1900 << "/" << tmm.tm_mon << "/" << tmm.tm_mday
	<< " " << tmm.tm_hour << ":" << tmm.tm_min << ":" << tmm.tm_sec;
}


void SetCmdColor(std::string color)
{
	std::cout << color;
}

void Logger::Info(std::string msg)
{
	if (fileName.size() != 0)
		std::cout << "[" << CoutTime << "] [" << fileName << "] " << P_GREEN "[INFO]" DEFAULT << msg << std::endl;
	else
		std::cout << "[" << CoutTime << "] " << P_GREEN "[INFO]" DEFAULT << msg << std::endl;
}

void Logger::Warn(std::string msg)
{
	if (fileName.size() != 0)
		std::cout << "[" << CoutTime << "] [" << fileName << "] " << P_YELLOW "[WARN]" DEFAULT << msg << std::endl;
	else
		std::cout << "[" << CoutTime << "] " << P_YELLOW "[WARN]" DEFAULT << msg << std::endl;
}

void Logger::Error(std::string msg)
{
	if (fileName.size() != 0)
		std::cout << "[" << CoutTime << "] [" << fileName << "] " << P_MAGENTA "[ERROR]" DEFAULT << msg << std::endl;
	else
		std::cout << "[" << CoutTime << "] " << P_MAGENTA "[ERROR]" DEFAULT << msg << std::endl;
}

void Logger::Fata(std::string msg)
{
	if (fileName.size() != 0)
		std::cout << "[" << CoutTime << "] [" << fileName << "] " << P_RED "[FATA]" DEFAULT << msg << std::endl;
	else
		std::cout << "[" << CoutTime << "] " << P_RED "[FATA]" DEFAULT << msg << std::endl;
}

void Logger::Info(char msg[])
{
	if (fileName.size() != 0)
		std::cout << "[" << CoutTime << "] [" << fileName << "] " << P_GREEN "[INFO]" DEFAULT << msg << std::endl;
	else
		std::cout << "[" << CoutTime << "] " << P_GREEN "[INFO]" DEFAULT << msg << std::endl;
}

void Logger::Warn(char msg[])
{
	if (fileName.size() != 0)
		std::cout << "[" << CoutTime << "] [" << fileName << "] " << P_YELLOW "[WARN]" DEFAULT << msg << std::endl;
	else
		std::cout << "[" << CoutTime << "] " << P_YELLOW "[WARN]" DEFAULT << msg << std::endl;
}

void Logger::Error(char msg[])
{
	if (fileName.size() != 0)
		std::cout << "[" << CoutTime << "] [" << fileName << "] " << P_MAGENTA "[ERROR]" DEFAULT << msg << std::endl;
	else
		std::cout << "[" << CoutTime << "] " << P_MAGENTA "[ERROR]" DEFAULT << msg << std::endl;
}

void Logger::Fata(char msg[])
{
	if (fileName.size() != 0)
		std::cout << "[" << CoutTime << "] [" << fileName << "] " << P_RED "[FATA]" DEFAULT << msg << std::endl;
	else
		std::cout << "[" << CoutTime << "] " << P_RED "[FATA]" DEFAULT << msg << std::endl;
}

void Logger::operator<<(std::string msg)
{
	if (fileName.size() != 0)
		std::cout << "[" << CoutTime << "] [" << fileName << "] " << P_GREEN "[INFO]" DEFAULT << msg << std::endl;
	else
		std::cout << "[" << CoutTime << "] " << P_GREEN "[INFO]" DEFAULT << msg << std::endl;
}

void Logger::operator<<(char msg[])
{
	if (fileName.size() != 0)
		std::cout << "[" << CoutTime << "] [" << fileName << "] " << P_GREEN "[INFO]" DEFAULT << msg << std::endl;
	else
		std::cout << "[" << CoutTime << "] " << P_GREEN "[INFO]" DEFAULT << msg << std::endl;
}

