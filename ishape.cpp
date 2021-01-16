#include "ishape.h"

ishape::ishape(cell & first_cell,board &bd):shape(first_cell,bd)
{
    color= RED;
    //获得第一个方格在几行几列
    int r = first_cell.get_location().x();
    int c = first_cell.get_location().y();

    //设置后面方格位置，最后得染色得出形状
    cells[SECOND_CELL]=bd.get_a_cell(r+UP,c);
    cells[THIRD_CELL]=bd.get_a_cell(r+UP+UP,c);
    cells[FOUTH_CELL]=bd.get_a_cell(r+UP+UP+UP,c);

    for(int i=0;i<NUM_OF_CELLS;i++)
    {
        //对方格分别进行染色
        bd.set_cell_color(cells[i],color);
    }
}
void ishape::compute_rotate_position()
{
    //将第二个方格固定死作为圆心
    shape::compute_rotate_position();

    //计算旋转后的坐标
    int r=rotate_positions[FIRST_POSITION][SECOND_CELL].x();
    int c=rotate_positions[FIRST_POSITION][SECOND_CELL].y();

    //未旋转时
    rotate_positions[FIRST_POSITION][FIRST_CELL] = QPoint(r + DOWN, c);
    rotate_positions[FIRST_POSITION][THIRD_CELL] = QPoint(r + UP, c);
    rotate_positions[FIRST_POSITION][FOUTH_CELL] = QPoint(r + UP + UP, c);

    //第一次旋转
    rotate_positions[SECOND_POSITION][FIRST_CELL] = QPoint(r, c + LEFT);
    rotate_positions[SECOND_POSITION][THIRD_CELL] = QPoint(r, c + RIGHT);
    rotate_positions[SECOND_POSITION][FOUTH_CELL] = QPoint(r, c + RIGHT + RIGHT);
    //第二次旋转
    rotate_positions[THIRD_POSITION][FIRST_CELL] = QPoint(r + UP, c);
    rotate_positions[THIRD_POSITION][THIRD_CELL] = QPoint(r + DOWN, c);
    rotate_positions[THIRD_POSITION][FOUTH_CELL] = QPoint(r + DOWN + DOWN, c);
    //第三次旋转
    rotate_positions[FOUTH_POSITION][FIRST_CELL] = QPoint(r, c + RIGHT);
    rotate_positions[FOUTH_POSITION][THIRD_CELL] = QPoint(r, c + LEFT);
    rotate_positions[FOUTH_POSITION][FOUTH_CELL] = QPoint(r, c + LEFT + LEFT);

}
ishape::~ishape()
{

}
