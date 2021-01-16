#ifndef PUBLIC1_H
#define PUBLIC1_H
#include <QApplication>
#include <QMainWindow>
#include <QPainter>
#include <QPoint>
#include <QPointF>
#include <QColor>
#include <QtGlobal>
#include <QTime>
#include <QTimer>
#include <QKeyEvent>
#include <Qt>

#define HALF 2

#define HRZ_CENTER 0//水平居中
#define HRZ_START 1//水平最左边
#define VRTX_CENTER 0//垂直居中
#define VRTX_START 1//垂直最左边

#define BIAS 1

#define S_O_Z_T_VRTX_START_LOCATION 1
#define I_VRTX_START_LOCATION 3
#define J_L_VRTX_START_LOCATION 2
#define ALL_HRZ_START_LOCATION 0

#define TIME_SCALAR 100000
#define MINS_TO_SECS 60
#define SLOW_TIME_INTERVAL 400
#define FAST_TIME_INTERVAL 100

#define NUM_OF_BOARDS 2
#define MAIN_BOARD 0
#define NEXT_BOARD 1

//主棋盘的宽和高
#define MAIN_BOARD_WIDTH 16
#define MAIN_BOARD_HEIGHT 34

//副棋盘的宽高
#define NEXT_BOARD_WIDTH 6
#define NEXT_BOARD_HEIGHT 7

#define CELL_LENGTH 20
#define NUM_OF_CELLS 4//最多有四个方格
#define FIRST_CELL 0
#define SECOND_CELL 1
#define THIRD_CELL 2
#define FOUTH_CELL 3

//上下左右移动
#define UP -1
#define DOWN 1
#define LEFT -1
#define RIGHT 1
#define NO_MOVE 0

#define MOVE_DOWN 0
#define MOVE_LEFT 1
#define MOVE_RIGHT 2

//颜色
#define NO_COLOR 0
#define RED 1
#define YELLOW 2
#define BLUE 3
#define GRAY 4
#define BLACK 5
#define PURPLE 6
#define ORANGE 7

#define NUM_OF_SHAPES 7//有多少个形状
#define O_SHAPE 0
#define S_SHAPE 1
#define Z_SHAPE 2
#define T_SHAPE 3
#define I_SHAPE 4
#define J_SHAPE 5
#define L_SHAPE 6

#define NUMBER_OF_ROTATE_POSITIONS 4//旋转位置4种
#define FIRST_POSITION 0
#define SECOND_POSITION 1
#define THIRD_POSITION 2
#define FOUTH_POSITION 3
class public1
{
public:
    public1();
};

#endif // PUBLIC1_H
