#ifndef BOARD_H
#define BOARD_H
#include "public1.h"
#include "cell.h"

class board
{
public:
    board() {}
    board(int,int,int,int);
    board(const board & bd){copy(bd);}
    //获取方格坐标返回类型为cell的引用
    cell & get_a_cell(int,int)const;
    void clear_board();

    void set_cell_color(cell &,int);
    void update_rows();
    int get_cell_color(cell &);
    bool is_full(int);
    bool is_empty(int);
    bool is_something(int);
    void clear_row(int);
    void row_cut_paste(int,int);
    //获取形状的初始位置
    const QPoint get_start_location(int,int,int);
    board & operator=(const board& bd){return copy(bd);}
    ~board();
private:
    board & copy(const board&);
    cell * cells;//一维函数
    int board_h;//高
    int board_w;//宽
};

#endif // BOARD_H
