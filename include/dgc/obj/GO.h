//
// Created by napbad on 10/25/24.
//

#ifndef GO_H
#define GO_H
#include "../gc/GCable.h"


class GO : public GCable{
public:
    virtual void add_cnt();
    void des_cnt() override;
    void destroy() override;
    int get_cnt() override;;
};



#endif //GO_H
