cmake_minimum_required(VERSION 3.29)
project(dgc)

set(CMAKE_CXX_STANDARD 23)

add_library(dgc STATIC library.cpp
        src/util/debug_util.cpp
        include/dgc/util/debug_util.h
        src/gc/DataCopy.cpp
        include/dgc/gc/DataCopy.h
        src/gc/DataNode.cpp
        include/dgc/gc/DataNode.h
        src/gc/DataPath.cpp
        include/dgc/gc/DataPath.h
        src/gc/DataRoot.cpp
        include/dgc/gc/DataRoot.h
        src/gc/FunDataRoot.cpp
        include/dgc/gc/FunDataRoot.h
        include/dgc/gc/GCable.h
        include/dgc/reserve/d_define.h
        include/dgc/common/common_const.h
        src/common/common_const.cpp
        include/dgc/util/file_util.h
        src/util/file_util.cpp
        src/util/debug_util.cpp
        include/dgc/util/debug_util.h
        include/dgc/util/debug_util.h
        test/gc_test.cpp
        include/dgc/gc/GCable_8dcnt_8fcnt.h)


install(TARGETS dgc DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)
