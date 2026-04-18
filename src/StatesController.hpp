#pragma once

#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include <unordered_map>
#include <memory>

#include "LogicalStateChange.hpp"

class StatesController{
public:
    StatesController(const std::string& fileName);
    ~StatesController();

    void parse();

private:
    std::unique_ptr<LogicStateChange> mLogicStateChange;
    std::ifstream mIn;
    std::unordered_map<int, Logic> mHistoryStates;
};