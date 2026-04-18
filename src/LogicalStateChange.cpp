#include "LogicalStateChange.hpp"
#include <iostream> // TODO: remove

std::optional<LogicStateChange> parse(const std::string& log_str) {
    std::regex re(R"((\d{4}-\d{2}-\d{2}\s\d{2}:\d{2}:\d{2}\.\d{3})\s+\d+\s+([\w\.]+\(\d+\))\s+FSM:\s+([\w_\.]+)\s+id:\s+(\d+);\s+<\s+St:\s+(\d+)\s+(.*))");

    std::smatch matches;
    
    if (std::regex_search(log_str, matches, re)) {
        LogicStateChange lsc;
        std::cout << "QQQ 2\n";

        std::tm tm = {};
        std::istringstream ss(matches[1].str());
        ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
        lsc.time_stamp = std::mktime(&tm);

        lsc.code_line = matches[2].str();
        lsc.logic.name = matches[3].str();
        lsc.logic.id = std::stoull(matches[4].str());

        lsc.state.id = std::stoull(matches[5].str());
        lsc.state.name = matches[6].str();
        
        return lsc;
    }
    return std::nullopt;
}