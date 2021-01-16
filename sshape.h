#ifndef SSHAPE_H
#define SSHAPE_H
#include "public1.h"
#include "shape.h"
#include "board.h"

// __
//  __形状
class sshape:public shape
{
public:
    sshape(cell &,board &);
    ~sshape();

private:
    virtual void compute_rotate_position() override;
};

#endif // SSHAPE_H
