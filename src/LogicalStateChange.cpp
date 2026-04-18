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

<<<<<<< Updated upstream
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
=======
std::string format_time(time_t time_stamp) {
    std::tm* tm = std::localtime(&time_stamp);
    std::stringstream ss;
    ss << std::setfill('0')
       << std::setw(2) << tm->tm_mday << "."
       << std::setw(2) << (tm->tm_mon + 1) << "."
       << std::setw(4) << (tm->tm_year + 1900) << " "
       << tm->tm_hour << ":"
       << std::setw(2) << tm->tm_min << ":"
       << std::setw(2) << tm->tm_sec;
    
    return ss.str();
}

std::ostream& operator<<(std::ostream& stream, LogicStateChange logic){
    stream << (logic.time_stamp) << "," 
        << logic.logic.name << "," 
        << logic.logic.id << "," 
        << "logic.logic.next" << "," 
        << "logic.last_message" << "," 
        << "delta time from block";
        
    return stream;
>>>>>>> Stashed changes
}