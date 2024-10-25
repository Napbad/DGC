//
// Created by napbad on 10/20/24.
//

#include "debug_util.h"

#include "util/file_util.h"


void dbg_util::dbg_print(std::ostream& stream, const std::string& message, file_util::FileColor color)
{
    file_util::print(stream, "DEBUG: ", file_util::FileColor::BRIGHT_YELLOW);
    file_util::print(stream, message, color);
}

void dbg_util::dbg_print(std::ostream& stream, const std::string& message)
{
    file_util::print(stream, "DEBUG: ", file_util::FileColor::BRIGHT_YELLOW);
    file_util::print(stream, message, file_util::FileColor::WHITE);
}

void dbg_util::print(std::ostream& stream, const std::string& message, file_util::FileColor color)
{
    if (stream.rdbuf() == std::cout.rdbuf())
    {
#ifdef _WIN32
        dbgSetColor(colorCode(color));
#else
        std::cout << dbg_colorCode(color);
#endif
    }
    stream << message;
    if (stream.rdbuf() == std::cout.rdbuf())
    {
#ifdef _WIN32
        setColor(color); // Default white
#else
        setColor(dbg_colorCode(file_util::FileColor::BLACK).c_str()); // Reset color
#endif
    }

    stream.flush();
}

#ifdef _WIN32
inline int file_util::colorCode(FileColor color) {
    switch (color) {
        case FileColor::GREEN: return FOREGROUND_GREEN;
        case FileColor::WHITE: return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
        case FileColor::RED: return FOREGROUND_RED;
        case FileColor::YELLOW: return FOREGROUND_RED | FOREGROUND_GREEN;
        case FileColor::BLUE: return FOREGROUND_BLUE;
        case FileColor::BLACK: return 0;
        case FileColor::MAGENTA: return FOREGROUND_RED | FOREGROUND_BLUE;
        case FileColor::CYAN: return FOREGROUND_GREEN | FOREGROUND_BLUE;
        case FileColor::BRIGHT_GREEN: return FOREGROUND_GREEN | FOREGROUND_INTENSITY;
        case FileColor::BRIGHT_WHITE: return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        case FileColor::BRIGHT_RED: return FOREGROUND_RED | FOREGROUND_INTENSITY;
        case FileColor::BRIGHT_YELLOW: return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
        case FileColor::BRIGHT_BLUE: return FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        case FileColor::BRIGHT_MAGENTA: return FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        case FileColor::BRIGHT_CYAN: return FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        default: return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
    }
}
#else
std::string dbg_util::dbg_colorCode(file_util::FileColor color)
{
    switch (color)
    {
    case file_util::FileColor::GREEN: return "\033[32m";
    case file_util::FileColor::WHITE: return "\033[37m";
    case file_util::FileColor::RED: return "\033[31m";
    case file_util::FileColor::YELLOW: return "\033[33m";
    case file_util::FileColor::BLUE: return "\033[34m";
    case file_util::FileColor::BLACK: return "\033[30m";
    case file_util::FileColor::MAGENTA: return "\033[35m";
    case file_util::FileColor::CYAN: return "\033[36m";
    case file_util::FileColor::BRIGHT_GREEN: return "\033[92m";
    case file_util::FileColor::BRIGHT_WHITE: return "\033[97m";
    case file_util::FileColor::BRIGHT_RED: return "\033[91m";
    case file_util::FileColor::BRIGHT_YELLOW: return "\033[93m";
    case file_util::FileColor::BRIGHT_BLUE: return "\033[94m";
    case file_util::FileColor::BRIGHT_MAGENTA: return "\033[95m";
    case file_util::FileColor::BRIGHT_CYAN: return "\033[96m";
    default: return "\033[37m";
    }
}

#endif
