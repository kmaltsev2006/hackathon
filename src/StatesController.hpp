#pragma once

#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include <map>

#include "InputParser.hpp"
#include "LogicStateChange.hpp"

class StatesController{
public:
    explicit StatesController(InputParser& inputParser, const std::string& out_name);
    ~StatesController();
    
    void findStatesInvalidation();

private:
    InputParser& mInputParser;
    std::unordered_map<size_t, std::shared_ptr<LogicStateChange>> mLogicStateChangeMap;
    std::unordered_map<size_t, std::shared_ptr<LogicStateLog>> mLogicStateLogMap;
    std::ifstream mIn;
    std::ofstream mOut;


private:
    void updateState(std::shared_ptr<LogicStateChange>& lsc);

    void updateState(std::shared_ptr<LogicStateLog>& lsl);
    
    void out();
};