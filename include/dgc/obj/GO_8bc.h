//
// Created by napbad on 10/25/24.
//

#ifndef GO_8BC_H
#define GO_8BC_H
#include <atomic>
#include <cstdint>

#include "GO.h"


/// GCable Object base class
class GO_8bc : public GO {
    std::atomic_uint8_t _cnt = 1;
public:
    void add_cnt() override;
    void des_cnt() override;
    void destroy() override;
    int get_cnt() override;;
};



#endif //GO_8BC_H
