#include <iostream>
#include "constants.h"
#include "game.h"

game_::game_() : _fsm(GameState::MENU), _table() {
    system("clear");
    std::cout << Messages::ENTRY_MESSAGE;
    _fsm.add_transition(GameState::MENU, "start", GameState::GAME, [this](){ to_game(); });
    _fsm.add_transition(GameState::MENU, "exit",  GameState::EXIT);
    _fsm.add_transition(GameState::GAME, "exit",  GameState::MENU, [this](){ to_menu(); });
    _fsm.add_transition(GameState::GAME, "up",    GameState::GAME, [this](){ up_move(); });
    _fsm.add_transition(GameState::GAME, "down",  GameState::GAME, [this](){ down_move(); });
    _fsm.add_transition(GameState::GAME, "left",  GameState::GAME, [this](){ left_move(); });
    _fsm.add_transition(GameState::GAME, "right", GameState::GAME, [this](){ right_move(); });
}

bool game_::input(const std::string &command) {
    _fsm.transit(command);
    if (_fsm.get_state() == GameState::EXIT) {
        std::cout << Messages::EXIT_MESSAGE;
        return false;
    }
    return true;
}

void game_::to_game() {
    system("clear");
    _table.draw();
    std::cout << Messages::START_MESSAGE;
}

void game_::to_menu() {
    redraw();
    std::cout << Messages::ENTRY_MESSAGE;
}

void game_::up_move() {
    _table.up_move();
    redraw();
    std::cout << "UP\n";
}

void game_::down_move() {
    _table.down_move();
    redraw();
    std::cout << "DOWN\n";
}

void game_::left_move() {
    _table.left_move();
    redraw();
    std::cout << "LEFT\n";
}

void game_::right_move() {
    _table.right_move();
    redraw();
    std::cout << "RIGHT\n";
}

void game_::redraw() {
    system("clear");
    _table.draw();
}
