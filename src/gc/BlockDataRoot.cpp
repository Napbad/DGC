//
// Created by napbad on 10/25/24.
//

#include "../../include/dgc/gc/BlockDataRoot.h"

void BlockDataRoot::add_data(GCable* data)
{
    _data.push_back(data);
}

void BlockDataRoot::gc()
{
    for (auto& data : _data)
    {
        data->gc();

        if (data->get_cnt() == 0)
        {
            data->destroy();
        }
    }
}

void BlockDataRoot::exit_block()
{
    for (auto& data : _data)
    {
        data->des_cnt();
        data->gc();
        if (data->get_cnt() == 0)
            data->destroy();
    }
}

void BlockDataRoot::destroy()
{
    for (const auto& data : _data)
    {
        data->destroy();
    }
}

BlockDataRoot* BlockDataRoot::init()
{
        return new BlockDataRoot();
}

int BlockDataRoot::get_cnt()
{
    return _cnt;
}

void BlockDataRoot::des_cnt()
{
    _cnt--;
}
