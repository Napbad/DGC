//
// Created by napbadsen on 24-10-17.
//

#include "../../include/dgc/gc/FunDataRoot.h"

#include "../../include/dgc/gc/DataRoot.h"
#include "../../include/dgc/reserve/d_define.h"
#include "../../include/dgc/util//debug_util.h"

class GCable;

void FunDataRoot::add_data(GCable* data)
{
    _data.push_back(data);
}

void FunDataRoot::gc()
{
    for (auto it = _data.begin(); it != _data.end();)
    {
        if ((*it)->get_cnt() == 0)
        {
            it = _data.erase(it);
        }
        else
        {
            (*it)->gc();
            ++it;
        }
    }
}

void FunDataRoot::exit_fun()
{
#ifdef DEBUG_MODE
    char buffer[50];
    sprintf(buffer, "Exit FunDataRoot: %p \n\0", this);
    dbg_util::dbg_print(std::cout, buffer);
#endif

    for (auto data : _data)
    {
        data->des_cnt();
    }

    this->gc();
}

void FunDataRoot::destroy()
{
#ifdef DEBUG_MODE
    char buffer[50];
    sprintf(buffer, "Destroy FunDataRoot: %p \n\0", this);
    dbg_util::dbg_print(std::cout, buffer);
#endif
    for (const auto data : _data)
        data->destroy();
}

FunDataRoot* FunDataRoot::init()
{
    FunDataRoot* fdr = new FunDataRoot();

#ifdef DEBUG_MODE
    char buffer[50];
    sprintf(buffer, "Init FunDataRoot: %p \n\0", fdr);
    dbg_util::dbg_print(std::cout, buffer);
#endif
    GLOBAL_DATA_ROOT->add_fun_data_root(fdr);
    return fdr;
}

int FunDataRoot::get_cnt()
{
    return _cnt;
}

void FunDataRoot::des_cnt()
{
#ifdef DEBUG_MODE
    char buffer[50];
    sprintf(buffer, "FunDataRoot count decreasing: %p, now: %d \n\0", this, _cnt - 1);
    dbg_util::dbg_print(std::cout, buffer);
#endif
    _cnt--;
}
