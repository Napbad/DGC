#include "../include/dgc/gc/DataNode.h"
//
// Created by napbad on 10/25/24.
//
int main()
{
    FunDataRoot* fun_data_root = FunDataRoot::init();
    const auto data = new std::vector<int>();
    DataNode<std::vector<int>>::link(data, fun_data_root);

    fun_data_root->exit_fun();
}