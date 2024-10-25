//
// Created by napbad on 10/20/24.
//

#ifndef DEBUG_UTIL_H
#define DEBUG_UTIL_H

#include <iostream>
#include <string>
#include "../common/d_define.h"

#include "../util/file_util.h"

namespace dbg_util {

    void dbg_print(std::ostream& stream, const std::string& message, file_util::FileColor color);
    void dbg_print(std::ostream& stream, const std::string& message);
    void print(std::ostream& stream, const std::string& message, file_util::FileColor color);

#ifdef _WIN32
    static int colorCode(FileColor color);
#else
    static std::string dbg_colorCode(file_util::FileColor color);
#endif

}// namespace dbg_util


#endif // DEBUG_UTIL_H
