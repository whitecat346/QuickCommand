#pragma once

#include <exception>
#include <string>
#include <vector>

extern std::string appPath;

void Command(int ac,char** av);
void RunCom(const std::vector<std::string> head, const std::string com);
