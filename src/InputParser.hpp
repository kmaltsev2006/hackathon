#pragma once

#include <string>
#include <fstream>
#include <functional>

#include "LogicStateChange.hpp"

class InputParser{
public:
    explicit InputParser(const std::string& fileName);
    ~InputParser();

    // Non-copiable
    InputParser(const InputParser&) = delete;
    InputParser& operator=(const InputParser&) = delete;

    // Non-moveable
    InputParser(InputParser&&) = delete;
    InputParser& operator=(InputParser&&) = delete;

    void parse(const std::function<void(std::shared_ptr<LogicStateChange>&)>& actionStateChange,
               const std::function<void(std::shared_ptr<LogicStateLog>&)>& actionStateLog);

private:
    std::ifstream mIn;
};