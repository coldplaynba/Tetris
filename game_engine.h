#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "public1.h"
#include "board.h"
#include "cell.h"
#include "shape.h"
#include "oshape.h"
#include "sshape.h"
#include "tshape.h"
#include "zshape.h"
#include "ishape.h"
#include "jshape.h"
#include "lshape.h"
class game_engine
{
public:
    game_engine(int, int, int, int);
    board& get_main_bd() { return main_bd; }
    board& get_next_bd() { return next_bd; }
    bool get_move_down_ok() { return move_down_ok; }
    //把形状放在下一个棋盘上，具体怎么放在place_shape中实现
    void next_place_shape();
    //把形状放在主棋盘上，具体怎么放在place_shape中实现
    void main_place_shape();
    void move_down();//向下移动
    void move_left();//左移
    void move_right();//右移
    void rotate();//旋转
    //消除行
    void clear_rows();
    //记录已满的行号
    int num_rows_cld();
    //消除行后，将上面的行下移
    void rows_move_down();
    //记录得分
    int compute_score();
    ~game_engine();
private:
    void traverse_rows(int* cld_rows = NULL);
    //把形状放在棋盘上,封装为一个函数
    shape * place_shape(board &,int,int,int);
    //主棋盘
    board main_bd;
    //下一个棋盘
    board next_bd;
    //记录下一个棋盘中所要产生的形状
    int m_ishape;
    //判断是否还能移动
    bool is_moveable(int, int, bool);
    //移动函数，具体实现怎么移动
    void move(int, int);
    //记录当前形状
    shape* tracked_shape;
    //判断能否上下移动
    bool move_down_ok;
    //设置形状颜色
    int set_shape_color(int);
};

#endif // GAME_ENGINE_H
