#pragma once

#include <string>
#include <map>

class FunctionExecutor
{
public:
    FunctionExecutor();
    ~FunctionExecutor();

    std::map<long double, long double> ExecuteOneParametered(std::string body);
    std::map<std::pair<long double, long double>, long double> ExectureTwoParametered(std::string body);
};