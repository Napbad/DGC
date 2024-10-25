# 0 "/home/napbad/Projects/dgc/gc/DataNode.cpp"
# 1 "/home/napbad/Projects/dgc/cmake-build-debug//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "/home/napbad/Projects/dgc/gc/DataNode.cpp"




# 1 "/home/napbad/Projects/dgc/gc/DataNode.h" 1







# 1 "/home/napbad/Projects/dgc/gc/GCable.h" 1
# 9 "/home/napbad/Projects/dgc/gc/GCable.h"
class GCable
{
public:
    virtual ~GCable() = default;

    virtual void gc() {};

    virtual void destroy() {};
};
# 9 "/home/napbad/Projects/dgc/gc/DataNode.h" 2
# 1 "/home/napbad/Projects/dgc/gc/../reserve/d_define.h" 1
# 10 "/home/napbad/Projects/dgc/gc/DataNode.h" 2

template <typename T>
class DataNode final : public GCable
{
    T _data;
    short _data_cnt_size = 1;

    explicit DataNode(T* data) : _data(*data)
    {
    }

    explicit DataNode(T data) : _data(data)
    {
    }

public:
    ~DataNode() override;

    void gc() override;
    void destroy() override;

    void add_ref();

    void remove_ref();

    T get();

    static DataNode* create(T* data);
    static DataNode* create(T data);
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
DataNode<T>* DataNode<T>::create(T* data)
{





    return new DataNode(*data);
}

template <typename T>
DataNode<T>* DataNode<T>::create(T data)
{





    return new DataNode(data);
}
# 6 "/home/napbad/Projects/dgc/gc/DataNode.cpp" 2
