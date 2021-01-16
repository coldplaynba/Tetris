#include "shape.h"

//将第一个方格初始化为first_cell
shape::shape(cell & first_cell, board & bd):m_bd(bd)//初始化列表获取棋盘
{
    color=NO_COLOR;
    for(int i=0;i<NUM_OF_CELLS;i++)
    {
        cells[i]=cell();//初始化每个方格
    }
    cells[FIRST_CELL]=first_cell;//初始化第一个方格
    which_position=0;
}

//旋转函数
void shape::rotate()
{
    //计算旋转位置
    compute_rotate_position();

    //记录按了多少下旋转键（上键旋转）
    which_position++;
    //取余看是该第几个旋转位置（二维数组第几行）
    which_position=which_position % NUMBER_OF_ROTATE_POSITIONS;

    //看旋转之后位置什么情况
    //如果可以旋转
    if(is_vaild_position(which_position))
    {
        for(int i=0;i<NUM_OF_CELLS;i++)
        {
            //取出该地址的x,y坐标
            int r=rotate_positions[which_position][i].x();
            int c=rotate_positions[which_position][i].y();
            //将坐标放进对应方格
            cells[i]=m_bd.get_a_cell(r,c);
        }
    }
    //没有形状which_position加一
    else
    {
        which_position--;
    }
}
//判断是否能够旋转
bool shape::is_vaild_position(int which)
{
    bool is_vaild = false;

    for(int i = 0; i < NUM_OF_CELLS; i++)
    {
        //取出旋转后的方格位置
        QPoint tmp = rotate_positions[which][i];
        //取出是第几行，第几列
        int x = tmp.x();
        int y = tmp.y();
        //旋转后的方格不能触底，不能靠到两边，且旋转后该位置不能有颜色
        if(x >= 0 && y >= 0 && x < MAIN_BOARD_HEIGHT && y < MAIN_BOARD_WIDTH && m_bd.get_a_cell(x, y).get_color() == NO_COLOR)
            is_vaild = true;
        else
        {
            is_vaild = false;
            break;
        }
    }

    return is_vaild;
}
//判断旋转位置
void shape::compute_rotate_position()
{
    //先将第二列的方格固定死作为圆心
    for(int i = 0; i < NUMBER_OF_ROTATE_POSITIONS; i++)
    {
        //获取第二个方格的在几行几列，返回类型为qpoint，rotate_positions也为qpoint类型
        rotate_positions[i][SECOND_CELL] = cells[SECOND_CELL].get_location();
    }
}
shape::~shape()
{

}
