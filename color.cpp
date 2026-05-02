// color.cpp
#include "color.h"

namespace color {

    // Reset
    std::ostream& reset(std::ostream& os) {
        return os << "\033[0m";
    }

    // Regular Colors
    std::ostream& black(std::ostream& os)   { return os << "\033[30m"; }
    std::ostream& red(std::ostream& os)     { return os << "\033[31m"; }
    std::ostream& green(std::ostream& os)   { return os << "\033[32m"; }
    std::ostream& yellow(std::ostream& os)  { return os << "\033[33m"; }
    std::ostream& blue(std::ostream& os)    { return os << "\033[34m"; }
    std::ostream& magenta(std::ostream& os) { return os << "\033[35m"; }
    std::ostream& cyan(std::ostream& os)    { return os << "\033[36m"; }
    std::ostream& white(std::ostream& os)   { return os << "\033[37m"; }

    // Bright Colors
    std::ostream& bright_black(std::ostream& os)   { return os << "\033[90m"; }
    std::ostream& bright_red(std::ostream& os)     { return os << "\033[91m"; }
    std::ostream& bright_green(std::ostream& os)   { return os << "\033[92m"; }
    std::ostream& bright_yellow(std::ostream& os)  { return os << "\033[93m"; }
    std::ostream& bright_blue(std::ostream& os)    { return os << "\033[94m"; }
    std::ostream& bright_magenta(std::ostream& os) { return os << "\033[95m"; }
    std::ostream& bright_cyan(std::ostream& os)    { return os << "\033[96m"; }
    std::ostream& bright_white(std::ostream& os)   { return os << "\033[97m"; }

    // Background Colors
    std::ostream& bg_black(std::ostream& os)   { return os << "\033[40m"; }
    std::ostream& bg_red(std::ostream& os)     { return os << "\033[41m"; }
    std::ostream& bg_green(std::ostream& os)   { return os << "\033[42m"; }
    std::ostream& bg_yellow(std::ostream& os)  { return os << "\033[43m"; }
    std::ostream& bg_blue(std::ostream& os)    { return os << "\033[44m"; }
    std::ostream& bg_magenta(std::ostream& os) { return os << "\033[45m"; }
    std::ostream& bg_cyan(std::ostream& os)    { return os << "\033[46m"; }
    std::ostream& bg_white(std::ostream& os)   { return os << "\033[47m"; }

    // Text Styles
    std::ostream& bold(std::ostream& os)      { return os << "\033[1m"; }
    std::ostream& underline(std::ostream& os) { return os << "\033[4m"; }
    std::ostream& italic(std::ostream& os)    { return os << "\033[3m"; }

} 