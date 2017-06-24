#ifndef _FSM_H_
#define _FSM_H_

#include <functional>
#include <vector>
#include <unordered_map>

class fsm_ {
public:
    fsm_() = delete;
    fsm_(int init_state); 

    void reset();

    void add_transition(
        int state,
        const std::string &symbol,
        int next_state,
        std::function <void()> action = []{}
    ); 

    bool try_transit(const std::string &symbol) const;

    bool transit(const std::string &symbol);

    int get_state() const;

protected:
    std::unordered_map<
        int, 
        std::unordered_map<
            std::string, 
            std::pair<
                int, 
                std::function<void()>
            >
        >
    > _t_table;
    int _init_state;
    int _state;

};

#endif // _FSM_H_
