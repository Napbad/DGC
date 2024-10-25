//
// Created by napbadsen on 24-10-17.
//

#include <string>

#include "../../include/dgc/gc/DataRoot.h"

#include <chrono>
#include <thread>

class FunDataRoot;
class GCable;
class DataRoot;
DataRoot* GLOBAL_DATA_ROOT = new DataRoot("root");

DataRoot::DataRoot(const std::string& name)
{
    _name = name;
    _data = {};
    _fun_data = {};
}

void DataRoot::add_data(GCable* data)
{
    _data.push_back(data);
}

void DataRoot::add_fun_data_root(FunDataRoot* data)
{
    _fun_data.push_back(data);
}

void DataRoot::destroy()
{
#ifdef DEBUG_MODE
    char buffer[50];
    sprintf(buffer, "Destroy DataRoot: %p \n\0", this);
    dbg_util::dbg_print(std::cout, buffer);
#endif

    for (const auto data : _data)
    {
        data->destroy();
    }
    for (const auto data : _fun_data)
    {
        data->destroy();
    }
}

void DataRoot::gc()
{
    for (const auto& data : _fun_data)
    {
        data->gc();
    }
    for (const auto& data : _data)
    {
        data->gc();
    }
}

void DataRoot::start_gc()
{
#ifdef DEBUG_MODE
    char buffer[50];
    sprintf(buffer, "Start GC: %p \n\0", GLOBAL_DATA_ROOT);
    dbg_util::dbg_print(std::cout, buffer);
#endif

    std::thread gc_thread = std::thread([]
    {
        GLOBAL_DATA_ROOT->auto_pick_time_gc();
    });

    if (gc_thread.joinable()) {
        gc_thread.join();
    }

    delete GLOBAL_DATA_ROOT;
}

[[noreturn]] void DataRoot::schedule_gc(const long nano_sec)
{
    while (true)
    {
#ifdef DEBUG_MODE
        char buffer[50];
        sprintf(buffer, "Scheduled-GC: %p \n\0", this);
        dbg_util::dbg_print(std::cout, buffer);
#endif
        std::this_thread::sleep_for(std::chrono::nanoseconds(nano_sec));
        this->gc();
    }
}

[[noreturn]] void DataRoot::auto_pick_time_gc()
{
    long cost_time = 0;

    while (true)
    {
#ifdef DEBUG_MODE
        char buffer[50];
        sprintf(buffer, "Auto pick time-GC: %p \n\0", this);
        dbg_util::dbg_print(std::cout, buffer);
#endif
        std::this_thread::sleep_for(std::chrono::nanoseconds(cost_time));
        std::chrono::nanoseconds start = std::chrono::system_clock::now().time_since_epoch();
        this->gc();
        std::chrono::nanoseconds end = std::chrono::system_clock::now().time_since_epoch();
        cost_time = (end - start).count() / 2;
    }
}
