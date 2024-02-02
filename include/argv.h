#pragma once

#include <exception>
#include <string>
#include <vector>

void Command(int& ac, char**& av);
void RunCom(const std::vector<std::string> head, const std::string com);
