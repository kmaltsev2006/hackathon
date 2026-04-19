#include "StatesController.hpp"

StatesController::StatesController(InputParser& inputParser, const std::string& out_name)
    : mInputParser(inputParser)
    , mOut(out_name)
{}

StatesController::~StatesController() {
    mOut.close();
}

void StatesController::findStatesInvalidation() {
    mInputParser.parse(
        [this](std::shared_ptr<LogicStateChange>& lsc){ updateState(lsc); },
        [this](std::shared_ptr<LogicStateLog>& lsl){ updateState(lsl); }
    );

    out();
}

void StatesController::out() {
    std::cout << "here\n";
    for (const auto& [id, lsc_ptr] : mLogicStateChangeMap) {
        if (lsc_ptr->state.name != "NUL") {
            mOut << to_string(*lsc_ptr, *mLogicStateLogMap[id]);
        }
    }
}

void StatesController::updateState(std::shared_ptr<LogicStateChange>& lsc) {
    mLogicStateChangeMap[lsc->logic.id] = lsc;
}

void StatesController::updateState(std::shared_ptr<LogicStateLog>& lsl) {
    mLogicStateLogMap[lsl->logic.id] = lsl;
}