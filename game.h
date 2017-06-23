#ifndef _GAME_H_
#define _GAME_H_

#include "fsm.h"
#include "table.h"

namespace GameState {
    enum {
        MENU,
        GAME,
        EXIT
    };
}; // GameState

class game_ {
public:
    game_();
    bool input(const std::string &command);
    void to_game();
    void to_menu();

    void up_move();
    void down_move();
    void left_move();
    void right_move();

private:
    fsm_ _fsm;
    table_ _table;

    void redraw();

};

#endif // _GAME_H_
