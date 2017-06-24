#include <string>
#include <iostream>
#include <unordered_map>
#include "table.h"

const int START_CAGE_COUNT = 3;

const std::unordered_map <int, std::string> NUM_TO_CAGE_MAPPER{
    { 0, "    " },
    { 1, "  2 " },
    { 2, "  4 " },
    { 3, "  8 " },
    { 4, " 16 " },
    { 5, " 32 " },
    { 6, " 64 " },
    { 7, " 128" },
    { 8, " 256" },
    { 9, " 512" },
    { 10, "1024" },
    { 11, "2048" },
    { 12, "4096" }
};

table_::table_() {
    clear();
    for (int i = 0; i < DIM; ++i) {
        int x = rand() % DIM;
        int y = rand() % DIM;
        int value = rand() % 2 + 1;
        _matrix[x][y] = value;
    }
}

void table_::draw() const {
    for (int x = 0; x < DIM; ++x) {
        for (int y = 0; y < DIM; ++y)
            std::cout << NUM_TO_CAGE_MAPPER.find(_matrix[x][y])->second << "|";
        std::cout << "\n----|----|----|----|\n";
    }
}

// -x
void table_::up_move() {
    bool was_shift = false;
    for (int y = 0; y < DIM; ++y)
        for (int x = 0; x < DIM; ++x) {
            if (_matrix[x][y] == 0) {
                for (int xx = x + 1; xx < DIM; ++xx)
                    if (_matrix[xx][y] != 0) {
                        _matrix[x][y] = _matrix[xx][y];
                        _matrix[xx][y] = 0;
                        was_shift = true;
                        break;
                    }
            }
            if (_matrix[x][y] != 0) {
                for (int xx = x + 1; xx < DIM; ++xx)
                    if (_matrix[xx][y] == _matrix[x][y]) {
                        ++_matrix[x][y];
                        _matrix[xx][y] = 0;
                        was_shift = true;
                        break;
                    }
            }
        }
    if (was_shift) cage_gen();
}

// +x
void table_::down_move() {
    for (int y = 0; y < DIM; ++y)
        for (int x = DIM - 1; x >= 0; --x) {
            if (_matrix[x][y] == 0) {
                for (int xx = x - 1; xx >= 0; --xx)
                    if (_matrix[xx][y] != 0) {
                        _matrix[x][y] = _matrix[xx][y];
                        _matrix[xx][y] = 0;
                        was_shift = true;
                        break;
                    }
            }
            if (_matrix[x][y] != 0) {
                for (int xx = x - 1; xx >= 0; --xx)
                    if (_matrix[xx][y] == _matrix[x][y]) {
                        ++_matrix[x][y];
                        _matrix[xx][y] = 0;
                        was_shift = true;
                        break;
                    }
            }
        }
    if (was_shift) cage_gen();
}

// -y
void table_::left_move() {
    for (int x = 0; x < DIM; ++x)
        for (int y = 0; y < DIM; ++y) {
            if (_matrix[x][y] == 0) {
                for (int yy = y + 1; yy < DIM; ++yy)
                    if (_matrix[x][yy] != 0) {
                        _matrix[x][y] = _matrix[x][yy];
                        _matrix[x][yy] = 0;
                        was_shift = true;
                        break;
                    }
            }
            if (_matrix[x][y] != 0) {
                for (int yy = y + 1; yy < DIM; ++yy)
                    if (_matrix[x][yy] == _matrix[x][y]) {
                        ++_matrix[x][y];
                        _matrix[x][yy] = 0;
                        was_shift = true;
                        break;
                    }
            }
        }
    if (was_shift) cage_gen();
}

// +y
void table_::right_move() {
    for (int x = 0; x < DIM; ++x)
        for (int y = DIM - 1; y >= 0; --y) {
            if (_matrix[x][y] == 0) {
                for (int yy = y - 1; yy >= 0; --yy)
                    if (_matrix[x][yy] != 0) {
                        _matrix[x][y] = _matrix[x][yy];
                        _matrix[x][yy] = 0;
                        was_shift = true;
                        break;
                    }
            }
            if (_matrix[x][y] != 0) {
                for (int yy = y - 1; yy >= 0; --yy)
                    if (_matrix[x][yy] == _matrix[x][y]) {
                        ++_matrix[x][y];
                        _matrix[x][yy] = 0;
                        was_shift = true;
                        break;
                    }
            }
        }
    if (was_shift) cage_gen();
}

void table_::clear() {
    for (int x = 0; x < DIM; ++x)
        for (int y = 0; y < DIM; ++y)
            _matrix[x][y] = 0;
}

void table_::cage_gen() {
    int x, y;
    do {
        x = rand() % DIM;
        y = rand() % DIM;
    } while (_matrix[x][y] != 0);
    _matrix[x][y] = rand() % 2 + 1;
}
