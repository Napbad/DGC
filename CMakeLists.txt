cmake_minimum_required(VERSION 3.29)
project(dgc)

set(CMAKE_CXX_STANDARD 23)

add_library(dgc STATIC library.cpp
        util/debug_util.cpp
        util/debug_util.h
        gc/DataCopy.cpp
        gc/DataCopy.h
        gc/DataNode.cpp
        gc/DataNode.h
        gc/DataPath.cpp
        gc/DataPath.h
        gc/DataRoot.cpp
        gc/DataRoot.h
        gc/FunDataRoot.cpp
        gc/FunDataRoot.h
        gc/GCable.cpp
        gc/GCable.h
        reserve/d_define.h
        common/common_const.h
        common/common_const.cpp
        util/file_util.h
        util/file_util.cpp
        util/debug_util.cpp
        util/debug_util.h)
