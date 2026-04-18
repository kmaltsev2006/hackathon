#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include <unordered_map>
#include <memory>

#include "logicstatechange.h"

struct Logic{
    struct State{
        int id;
        std::string name;
        std::string date;
        std::string time;
    };
    struct Log{
        int id;
        std::string name;
        std::string message;
    };

    State lastState;
    Log lastLog;
};

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