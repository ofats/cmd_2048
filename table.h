#ifndef _TABLE_H_
#define _TABLE_H_

#include <array>

class table_ {
public:
    static const int DIM = 4;

    table_();
    void draw() const;
    void up_move();
    void down_move();
    void left_move();
    void right_move();

private:
    std::array <std::array <int, DIM>, DIM> _matrix;

    void clear();
    void cage_gen();

};

#endif // _TABLE_H_
