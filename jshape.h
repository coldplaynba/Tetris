#ifndef JSHAPE_H
#define JSHAPE_H
#include "public1.h"
#include "shape.h"
#include "board.h"
// __
//  |
//  | 形状
class jshape:public shape
{
public:
    jshape(cell &,board &);
    ~jshape();

private:
    virtual void compute_rotate_position() override;
};

#endif // JSHAPE_H
