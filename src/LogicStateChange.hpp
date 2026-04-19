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

std::optional<std::shared_ptr<LogicStateChange>> parseStateChange(const std::string& log_str);

std::optional<std::shared_ptr<LogicStateLog>> parseStateLog(const std::string& log_str);

std::string to_string(const LogicStateChange& logicChange, const LogicStateLog& logicLog);

std::string format_time(time_t time_stamp);