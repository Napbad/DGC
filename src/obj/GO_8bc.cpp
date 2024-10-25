//
// Created by napbad on 10/25/24.
//

#include "../../include/dgc/obj/GO_8bc.h"

void GO_8bc::add_cnt()
{
    ++_cnt;
}

void GO_8bc::des_cnt()
{
    --_cnt;
}

void GO_8bc::destroy()
{
    delete this;
}

int GO_8bc::get_cnt()
{
    return _cnt;
}
