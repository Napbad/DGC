//
// Created by napbad on 10/25/24.
//

#ifndef GO_16BC_H
#define GO_16BC_H
#include <atomic>
#include <cstdint>

#include "GO.h"


/// GCable Object base class
class GO_16bc : public GO {
    std::atomic_uint16_t _cnt = 1;
public:
    void add_cnt() override;
    void des_cnt() override;
    void destroy() override;
    int get_cnt() override;;
};



#endif //GO_16BC_H
