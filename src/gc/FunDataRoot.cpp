//
// Created by napbadsen on 24-10-17.
//

#include "../../include/dgc/gc/FunDataRoot.h"
#include "../../include/dgc/gc/DataRoot.h"
#include "../../include/dgc/common/d_define.h"
#include "../../include/dgc/util/debug_util.h"
#include <sstream>

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
    std::stringstream ss;
    ss << "Exit FunDataRoot: " << this << " \n";
    dbg_util::dbg_print(std::cout, ss.str());
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
    std::stringstream ss;
    ss << "Destroy FunDataRoot: " << this << " \n";
    dbg_util::dbg_print(std::cout, ss.str());
#endif
    for (const auto data : _data)
        data->destroy();
}

FunDataRoot* FunDataRoot::init()
{
    FunDataRoot* fdr = new FunDataRoot();

#ifdef DEBUG_MODE
    std::stringstream ss;
    ss << "Init FunDataRoot: " << fdr << " \n";
    dbg_util::dbg_print(std::cout, ss.str());
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
    std::stringstream ss;
    ss << "FunDataRoot count decreasing: " << this << ", now: " << (_cnt - 1) << " \n";
    dbg_util::dbg_print(std::cout, ss.str());
#endif
    _cnt--;
}
