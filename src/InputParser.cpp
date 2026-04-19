#include "InputParser.hpp"

InputParser::InputParser(const std::string& fileName)
    : mIn(fileName)
{}

InputParser::~InputParser() {
    mIn.close();
}

void InputParser::parse(const std::function<void(std::shared_ptr<LogicStateChange>&)>& actionStateChange,
                        const std::function<void(std::shared_ptr<LogicStateLog>&)>& actionStateLog)
{
    std::string line;
 
    if (mIn.is_open()) {
        while (std::getline(mIn, line)) {
            auto lsc = ::parseStateChange(line);
            if (lsc.has_value())
                actionStateChange(lsc.value());

            auto lsl = ::parseStateLog(line);
            if (lsl.has_value())
                actionStateLog(lsl.value());
        }
    }
}
