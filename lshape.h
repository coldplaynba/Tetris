#ifndef LSHAPE_H
#define LSHAPE_H
#include "public1.h"
#include "shape.h"
#include "board.h"

//  __
//  |
//  | 形状
class lshape:public shape
{
public:
    lshape(cell &,board &);
    ~lshape();

private:
    virtual void compute_rotate_position() override;
};

#endif // LSHAPE_H
