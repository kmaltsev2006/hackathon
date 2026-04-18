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

struct Pr {
    size_t host;
    size_t port;
};

struct LogicStateChange {
    std::time_t time_stamp;
    std::string code_line;
    Logic logic;
    State state;    
};

struct LogicStateLog {
    std::time_t time_stamp;
    std::string code_line;
    Logic logic;
    State state;
    std::string message;
    Pr pr; 
};

std::optional<LogicStateChange> parse(const std::string& log_str);

std::optional<LogicStateLog> parseLog(const std::string& log_str);