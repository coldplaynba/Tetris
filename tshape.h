#ifndef TSHAPE_H
#define TSHAPE_H
#include "public1.h"
#include "shape.h"
#include "board.h"

// |
//___形状
class tshape:public shape
{
public:
    tshape(cell &,board &);
    ~tshape();

private:
    virtual void compute_rotate_position() override;
};

#endif // TSHAPE_H
