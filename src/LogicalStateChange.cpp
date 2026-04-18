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

std::optional<LogicStateLog> parseLog(const std::string& log_str)
{

    std::regex re(R"((\d{4}-\d{2}-\d{2}\s\d{2}:\d{2}:\d{2}\.\d{3})\s+\d+\s+([\w\.]+\(\d+\))\s+FSM:\s+([\w_\.]+)\s+id:\s+(\d+);\s+>\s+St:\s+(\d+)\s+(\w+)\s+Pr:\s+(\d+):(\d+)\s+(\w+)\s+\((.*)\))");
    std::smatch matches;
    std::cout << "QQQ 1\n";
    if (std::regex_search(log_str, matches, re)) {
        LogicStateLog lsl;
        std::cout << "QQQ 2\n";

        std::tm tm = {};
        std::istringstream ss(matches[1].str());
        ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
        lsl.time_stamp = std::mktime(&tm);

        lsl.code_line = matches[2].str();
        lsl.logic.name = matches[3].str();
        lsl.logic.id = std::stoull(matches[4].str());

        lsl.state.id = std::stoull(matches[5].str());
        lsl.state.name = matches[6].str();

        lsl.pr.host = std::stoull(matches[7].str());
        lsl.pr.port = std::stoull(matches[8].str());

        lsl.message = matches[9].str();
        
        return lsl;
    }
    return std::nullopt;
}