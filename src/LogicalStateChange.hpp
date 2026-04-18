#pragma once

#include <optional>
#include <ctime>
#include <iomanip>
#include <regex>

struct State {
    size_t id;
    std::string name;
};

struct Logic {
    size_t id;
    std::string name;
};

struct LogicStateChange {
    std::time_t time_stamp;
    std::string code_line;
    Logic logic;
    State state;    
};

std::optional<LogicStateChange> parse(const std::string& log_str);