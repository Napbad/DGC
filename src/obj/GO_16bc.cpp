//
// Created by napbad on 10/25/24.
//

#include "../../include/dgc/obj/GO_16bc.h"

void GO_16bc::add_cnt()
{
    ++_cnt;
}

void GO_16bc::des_cnt()
{
    --_cnt;
}

void GO_16bc::destroy()
{
    delete this;
}

int GO_16bc::get_cnt()
{
    return _cnt;
}
