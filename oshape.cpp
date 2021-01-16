#include "oshape.h"

//设置第二三四个方格在哪，设置颜色
oshape::oshape(cell & first_cell,board &bd):shape(first_cell,bd)
{
    color=ORANGE;
    //获得第一个方格在几行几列
    int r = first_cell.get_location().x();
    int c = first_cell.get_location().y();

    //设置后面方格位置，最后得染色得出形状
    cells[SECOND_CELL]=bd.get_a_cell(r,c+RIGHT);
    cells[THIRD_CELL]=bd.get_a_cell(r+UP,c);
    cells[FOUTH_CELL]=bd.get_a_cell(r+UP,c+RIGHT);

    for(int i=0;i<NUM_OF_CELLS;i++)
    {
        //对方格分别进行染色
        bd.set_cell_color(cells[i],color);
    }
}
void oshape::rotate()
{

}

void oshape::compute_rotate_position()
{

}

oshape::~oshape()
{

}
