//
// Created by napbadsen on 24-10-17.
//

#ifndef DATANODE_H
#define DATANODE_H

#include "FunDataRoot.h"
#include "GCable.h"
#include "../util/debug_util.h"
#include "../common/d_define.h"
#include <sstream>

template <typename T>
class DataNode final : public GCable
{
    friend class FunDataRoot;
    T* _data; /// T must be a pointer
    short _data_cnt_size = 1;

    explicit DataNode(T* data) : _data(data)
    {
    }

public:
    ~DataNode() override;

    void gc() override;
    void destroy() override;

    void add_ref();
    void remove_ref();

    T get();

    int get_cnt() override;

    void des_cnt() override;

    static DataNode* create(T* data);

    static void link(T* data, FunDataRoot* fun_data_root);
};


template <typename T>
DataNode<T>::~DataNode()
{
    delete _data;
}

template <typename T>
void DataNode<T>::gc()
{
    if (_data_cnt_size != 0)
        delete _data;
}

template <typename T>
void DataNode<T>::destroy()
{
#ifdef DEBUG_MODE
    std::stringstream ss;
    ss << "Destroy DataNode: " << _data << " \n";
    dbg_util::dbg_print(std::cout, ss.str());
#endif
    if (_data_cnt_size != 0)
    {
        delete _data;
        _data_cnt_size = 0;
    }
}

template <typename T>
void DataNode<T>::add_ref()
{
    _data_cnt_size++;
}

template <typename T>
void DataNode<T>::remove_ref()
{
    _data_cnt_size--;
}

template <typename T>
T DataNode<T>::get()
{
    return _data;
}

template <typename T>
int DataNode<T>::get_cnt()
{
    return _data_cnt_size;
}

template <typename T>
void DataNode<T>::des_cnt()
{
#ifdef DEBUG_MODE
    std::stringstream ss;
    ss << "Decrementing DataNode: " << _data << " , now: " << (_data_cnt_size - 1) << "\n";
    dbg_util::dbg_print(std::cout, ss.str());
#endif
    _data_cnt_size--;
}

template <typename T>
DataNode<T>* DataNode<T>::create(T* data)
{
#ifdef DEBUG_MODE
    std::stringstream ss;
    ss << "Creating DataNode: " << data << " \n";
    dbg_util::dbg_print(std::cout, ss.str());
#endif
    return new DataNode(data);
}


template <typename T>
void DataNode<T>::link(T* data, FunDataRoot* fun_data_root)
{
#ifdef DEBUG_MODE
    std::stringstream ss;
    ss << "Linking DataNode: " << data << " \n";
    dbg_util::dbg_print(std::cout, ss.str());
#endif
    fun_data_root->add_data(DataNode::create(data));
}


#endif //DATANODE_H
