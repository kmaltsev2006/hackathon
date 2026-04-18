#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include <sstream>

#include "statescontroller.h"

StatesController::StatesController(const std::string& fileName)
    : mIn(fileName)
{
    mLogicStateChange = std::make_unique<LogicStateChange>();
}

StatesController::~StatesController()
{
    mIn.close();
}

void StatesController::parse()
{
    std::string line;
 
    std::stringstream out;
    if (mIn.is_open())
    {
        while (std::getline(mIn, line))
        {
            std::cout << line << std::endl;
            const auto resultParse = mLogicStateChange.parse(line);
            if (mLogicStateChange.parse(line)){
                
            }
        }
    }
    mIn.close();
}

int main()
{
    StatesController states("in.txt");
    states.parse();
    return 0;
}