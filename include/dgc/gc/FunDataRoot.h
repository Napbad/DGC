//
// Created by napbadsen on 24-10-17.
//

#ifndef FUNDATAROOT_H
#define FUNDATAROOT_H
#include <string>
#include <vector>

#include "GCable.h"

#include "../reserve/d_define.h"

class FunDataRoot final : public GCable {

    std::string _name;
    std::vector<GCable*> _data;
    short _cnt = 1;

public:
    void add_data(GCable* data);

    void gc() override;

    void exit_fun();

    void destroy() override;

    static FunDataRoot* init();

    int get_cnt() override;

    void des_cnt() override;
};

#endif //FUNDATAROOT_H
