#pragma once

#include <chrono>
#include <string>

inline void GetSystemTime(tm& tmd);
inline tm GetSystemTime();

class Logger
{
public:
	Logger() {};
	Logger(std::string name) : loggerName(name) {};
	Logger(char name[]) : loggerName(name) {};
	~Logger() {};

	void Error(std::string msg);
	void Info(std::string msg);
	void Warn(std::string msg);
	void Fata(std::string msg);

	void Error(char msg[]);
	void Info(char msg[]);
	void Warn(char msg[]);
	void Fata(char msg[]);

	void operator<< (std::string msg);
	void operator<< (char msg[]);

	

private:
	std::string loggerName;
};

// ESC
#define DEFAULT "\x1b[0m"
#define BOLD "\x1b[1m"
#define NO_BOLD "\x1b[22m"
#define UNDERLINE "\x1b[4m"
#define NO_UNDERLINE "\x1b[24m"
#define SWAP "\x1b[7m"
#define SWAP_BACK "\x1b[27m"

#define P_BLACK "\x1b[30m"
#define P_RED "\x1b[31m"
#define P_GREEN "\x1b[32m"
#define P_YELLOW "\x1b[33m"
#define P_BLUE "\x1b[34m"
#define P_MAGENTA "\x1b[35m"
#define P_CHARTREUSE "\x1b[36m"
#define P_WHITE "\x1b[37m"
#define P_DEFAULT "\x1b[39m"

#define B_BLACK "\x1b[40m"
#define B_RED "\x1b[41m"
#define B_GREEN "\x1b[42m"
#define B_YELLOW "\x1b[43m"
#define B_BLUE "\x1b[44m"
#define B_MAGENTA "\x1b[45m"
#define B_CHARTREUSE "\x1b[46m"
#define B_WHITE "\x1b[47m"
#define B_DEFAULT "\x1b[48m"

#define P_LIGHT_BLACK "\x1b[90m"
#define P_LIGHT_RED "\x1b[91m"
#define P_LIGHT_GREEN "\x1b[92m"
#define P_LIGHT_YELLOW "\x1b[93m"
#define P_LIGHT_BLUE "\x1b[94m"
#define P_LIGHT_MAGENTA "\x1b[95m"
#define P_LIGHT_CHARTREUSE "\x1b[96m"
#define P_LIGHT_WHITE "\x1b[97m"

#define B_LIGHT_BLACK "\x1b[100m"
#define B_LIGHT_RED "\x1b[101m"
#define B_LIGHT_GREEN "\x1b[102m"
#define B_LIGHT_YELLOW "\x1b[103m"
#define B_LIGHT_BLUE "\x1b[104m"
#define B_LIGHT_MAGENTA "\x1b[105m"
#define B_LIGHT_CHARTREUSE "\x1b[106m"
#define B_LIGHT_WHITE "\x1b[107m"

void SetCmdColor(std::string color);

std::string CoutTime();
