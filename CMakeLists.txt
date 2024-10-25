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
        include/dgc/common/common_const.h
        src/common/common_const.cpp
        include/dgc/util/file_util.h
        src/util/file_util.cpp
        src/util/debug_util.cpp
        include/dgc/util/debug_util.h
        include/dgc/util/debug_util.h
        test/gc_test.cpp
        include/dgc/common/d_define.h
        src/obj/GO_16bc.cpp
        include/dgc/obj/GO_16bc.h
        include/dgc/obj/GO.h
        src/obj/GO.cpp
        src/obj/GO.cpp
        include/dgc/obj/GO_32bc.h
        include/dgc/obj/GO_64bc.h
        src/obj/GO_32bc.cpp
        src/obj/GO_32bc.cpp
        src/obj/GO_64bc.cpp
        include/dgc/obj/GO_8bc.h
        src/obj/GO_8bc.cpp
        src/util/obj_util.cpp
        include/dgc/util/obj_util.h
        include/dgc/obj/GOWrapper.h
        src/obj/GOWrapper.cpp
        include/dgc/gc/BlockDataRoot.h
        src/gc/BlockDataRoot.cpp
        src/gc/BlockDataRoot.h
)


install(TARGETS dgc DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)
