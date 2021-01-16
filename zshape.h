#ifndef ZSHAPE_H
#define ZSHAPE_H
#include "public1.h"
#include "shape.h"
#include "board.h"

// __
//__形状
class zshape:public shape
{
public:
    zshape(cell &,board &);
    ~zshape();

private:
    virtual void compute_rotate_position() override;
};

#endif // ZSHAPE_H
