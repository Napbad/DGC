//
// Created by napbad on 10/25/24.
//

#ifndef GCABLE_8DCNT_8FCNT_H
#define GCABLE_8DCNT_8FCNT_H
#include <cstdint>

#include "GCable.h"

// GCable class with 8-bit reference from data and 8-bit reference from function
class  GCable_8dcnt_8fcnt final : public GCable {
public:
    uint8_t _cnt = 0;
    uint8_t _fcnt = 1;


};

#endif //GCABLE_8DCNT_8FCNT_H
