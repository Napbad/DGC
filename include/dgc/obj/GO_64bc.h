//
// Created by napbad on 10/25/24.
//

#ifndef GO_64BC_H
#define GO_64BC_H
#include <atomic>
#include <cstdint>

#include "GO.h"


class GO_64bc : public GO {
    std::atomic_uint64_t _cnt = 1;
public:
    void add_cnt() override;
    void des_cnt() override;
    void destroy() override;
    int get_cnt() override;;
};



#endif //GO_64BC_H
