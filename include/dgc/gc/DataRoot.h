//
// Created by napbadsen on 24-10-17.
//


#ifndef DATAROOT_H
#define DATAROOT_H
#include <string>
#include <vector>

#include "DataNode.h"
#include "FunDataRoot.h"
#define GLOBAL_DATA_ROOT global_data_root
#include "../reserve/d_define.h"


class DataRoot final : public GCable
{
    std::string _name;
    std::vector<GCable*> _data;
    std::vector<FunDataRoot*> _fun_data;

public:
    explicit DataRoot(const std::string& name);
    void add_data(GCable* data);
    void add_fun_data_root(FunDataRoot* data);

    void destroy() override;
    void gc() override;

    static void start_gc();
    [[noreturn]] void schedule_gc(long nano_sec);
    [[noreturn]] void auto_pick_time_gc();
};

extern DataRoot*GLOBAL_DATA_ROOT;

#endif //DATAROOT_H
