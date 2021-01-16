#include "jshape.h"

jshape::jshape(cell & first_cell,board & bd):shape(first_cell,bd)
{
    color=YELLOW;
    //获取第一个方格在几行几列
    int r=first_cell.get_location().x();
    int c=first_cell.get_location().y();

    //设置后面方格位置，最后得染色得出形状
    cells[SECOND_CELL] = bd.get_a_cell(r, c + RIGHT);
    cells[THIRD_CELL] = bd.get_a_cell(r + UP, c + RIGHT);
    cells[FOUTH_CELL] = bd.get_a_cell(r + UP + UP, c + RIGHT);

    for(int i = 0; i < NUM_OF_CELLS; i++)
    {
        bd.set_cell_color(cells[i], color);
    }
}
void jshape::compute_rotate_position()
{
    shape::compute_rotate_position();

    int r = rotate_positions[FIRST_POSITION][SECOND_CELL].x();
    int c = rotate_positions[FIRST_POSITION][SECOND_CELL].y();

    rotate_positions[FIRST_POSITION][FIRST_CELL] = QPoint(r, c + LEFT);
    rotate_positions[FIRST_POSITION][THIRD_CELL] = QPoint(r + UP, c);
    rotate_positions[FIRST_POSITION][FOUTH_CELL] = QPoint(r + UP + UP, c);

    rotate_positions[SECOND_POSITION][FIRST_CELL] = QPoint(r + UP, c);
    rotate_positions[SECOND_POSITION][THIRD_CELL] = QPoint(r, c + RIGHT);
    rotate_positions[SECOND_POSITION][FOUTH_CELL] = QPoint(r, c + RIGHT + RIGHT);

    rotate_positions[THIRD_POSITION][FIRST_CELL] = QPoint(r, c + RIGHT);
    rotate_positions[THIRD_POSITION][THIRD_CELL] = QPoint(r + DOWN, c);
    rotate_positions[THIRD_POSITION][FOUTH_CELL] = QPoint(r + DOWN + DOWN, c);

    rotate_positions[FOUTH_POSITION][FIRST_CELL] = QPoint(r + DOWN, c);
    rotate_positions[FOUTH_POSITION][THIRD_CELL] = QPoint(r, c + LEFT);
    rotate_positions[FOUTH_POSITION][FOUTH_CELL] = QPoint(r, c + LEFT + LEFT);
}

jshape::~jshape()
{

}
