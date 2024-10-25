//
// Created by napbad on 10/25/24.
//

#ifndef BLOCKDATAROOT_H
#define BLOCKDATAROOT_H
#include <string>
#include <vector>

#include "GCable.h"

class BlockDataRoot final : public GCable
{
    std::string _name;
    std::vector<GCable*> _data;
    short _cnt = 1;

public:
    void add_data(GCable* data);

    void gc() override;

    void exit_block();

    void destroy() override;

    static BlockDataRoot* init();

    int get_cnt() override;

    void des_cnt() override;
};

#endif //BLOCKDATAROOT_H
