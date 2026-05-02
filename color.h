// color.h
#pragma once
#include <iostream>

// Namespace for colored console output
namespace color {

    // Reset
    std::ostream& reset(std::ostream& os);

    // Regular Colors
    std::ostream& black(std::ostream& os);
    std::ostream& red(std::ostream& os);
    std::ostream& green(std::ostream& os);
    std::ostream& yellow(std::ostream& os);
    std::ostream& blue(std::ostream& os);
    std::ostream& magenta(std::ostream& os);
    std::ostream& cyan(std::ostream& os);
    std::ostream& white(std::ostream& os);

    // Bright Colors
    std::ostream& bright_black(std::ostream& os);
    std::ostream& bright_red(std::ostream& os);
    std::ostream& bright_green(std::ostream& os);
    std::ostream& bright_yellow(std::ostream& os);
    std::ostream& bright_blue(std::ostream& os);
    std::ostream& bright_magenta(std::ostream& os);
    std::ostream& bright_cyan(std::ostream& os);
    std::ostream& bright_white(std::ostream& os);

    // Background Colors
    std::ostream& bg_black(std::ostream& os);
    std::ostream& bg_red(std::ostream& os);
    std::ostream& bg_green(std::ostream& os);
    std::ostream& bg_yellow(std::ostream& os);
    std::ostream& bg_blue(std::ostream& os);
    std::ostream& bg_magenta(std::ostream& os);
    std::ostream& bg_cyan(std::ostream& os);
    std::ostream& bg_white(std::ostream& os);

    // Text Styles
    std::ostream& bold(std::ostream& os);
    std::ostream& underline(std::ostream& os);
    std::ostream& italic(std::ostream& os);

} // namespace ConsoleColor