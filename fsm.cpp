#include "fsm.h"

fsm_::fsm_(int init_state) : _init_state(init_state) {
    reset();
}

void fsm_::reset() {
    _state = _init_state;
}

void fsm_::add_transition(
    int state,
    const std::string &symbol,
    int next_state,
    std::function <void()> action
) {
    _t_table[state][symbol] = { next_state, action };
}

bool fsm_::try_transit(const std::string &symbol) const {
    if (_t_table.count(_state) && _t_table.find(_state)->second.count(symbol))
        return true;
    return false;
}

bool fsm_::transit(const std::string &symbol) {
    if (!try_transit(symbol))
        return false;
    auto &tmp_result = _t_table[_state][symbol];
    _state = tmp_result.first;
    tmp_result.second();
    return true;
}

int fsm_::get_state() const {
    return _state;
}
