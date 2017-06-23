#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "game.h"
#include "table.h"
#include "constants.h"

using namespace std;

int exec() {
    game_ game;
    string command;
    do {
        cin >> command;
    } while (game.input(command));
    

    return 0;
}

int main() {
    srand((unsigned)time(0));
    return exec();
}
