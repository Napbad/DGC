//
// Created by napbad on 10/25/24.
//

#ifndef GO_32BC_H
#define GO_32BC_H
#include <atomic>
#include <cstdint>

#include "GO.h"


class GO_32bc : public GO {
    std::atomic_uint32_t _cnt = 1;

public:
    void add_cnt() override;
    void des_cnt() override;
    void destroy() override;
    int get_cnt() override;;
};

#endif //GO_32BC_H
