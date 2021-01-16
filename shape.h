#ifndef SHAPE_H
#define SHAPE_H
#include "public1.h"
#include "cell.h"
#include "board.h"

class shape
{
public:
    //获得初始方格和棋盘
    shape(cell &,board & bd);
    virtual ~shape()=0;
    //旋转，在旋转后方格位置不变的形状中重写
    virtual void rotate();
    int get_color(){return color;}
    cell & get_a_cell(int n){return cells[n];}
    void set_a_cell(int n,cell& _cell){cells[n]=_cell;}

protected:
    //计算旋转位置，定义为虚函数，在派生形状类中重写
    virtual void compute_rotate_position();
    bool is_vaild_position(int);//判断旋转之后位置是否合适
    int color;
    cell cells[NUM_OF_CELLS];//方格数组（4个方格）
    //旋转相关，记录原来方格旋转后的坐标
    QPoint rotate_positions[NUMBER_OF_ROTATE_POSITIONS][NUM_OF_CELLS];
    int which_position;
    board m_bd;//获取棋盘信息
};

#endif // SHAPE_H
