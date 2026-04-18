#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include <sstream>

#include "StatesController.hpp"

StatesController::StatesController(const std::string& fileName)
    : mIn(fileName)
{
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
            auto lsc = ::parse(line);
            if (lsc.has_value()){
                
            }
        }
    }
}
