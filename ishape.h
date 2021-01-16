#ifndef ISHAPE_H
#define ISHAPE_H
#include "public1.h"
#include "shape.h"
#include "board.h"

//直线形状
class ishape:public shape
{
public:
    ishape(cell &,board &);
    ~ishape();

private:
    //重写compute_rotate_position()函数，计算对应形状的旋转位置
    virtual void compute_rotate_position() override;
};

#endif // ISHAPE_H
