//
// Created by napbadsen on 24-10-8.
//

#ifndef GCABLE_H
#define GCABLE_H

#include "../reserve/d_define.h"

class GCable
{

    u_int8_t _cnt = 1;


public:
    virtual ~GCable() = default;

    virtual void gc()
    {
    };

    virtual void destroy()
    {
    };

    virtual int get_cnt() { return 0; };

    virtual void des_cnt()
    {
    };
};


#endif //GCABLE_H
