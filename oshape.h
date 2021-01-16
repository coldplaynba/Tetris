#ifndef OSHAPE_H
#define OSHAPE_H
#include "public1.h"
#include "shape.h"
#include "board.h"

//正方体形状
class oshape:public shape
{
public:
    oshape(cell &,board &);
    ~oshape();
    virtual void rotate() override;

private:
    virtual void compute_rotate_position() override;
};

#endif // OSHAPE_H
