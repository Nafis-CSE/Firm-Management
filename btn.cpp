#include "main.h"

Button::Button(int a, int b, string t)
    : x1(a), y1(b), label(t) {}

#include <unordered_map>
#include <string>

typedef std::ostream &(*ColorFunc)(std::ostream &);

void Button::draw(std::string bgColorName, std::string textColorName)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    static std::unordered_map<std::string, ColorFunc> colorMap = {
        {"black", color::black}, {"red", color::red}, {"green", color::green}, {"yellow", color::yellow}, {"blue", color::blue}, {"magenta", color::magenta}, {"cyan", color::cyan}, {"white", color::white}, {"bright_black", color::bright_black}, {"bright_red", color::bright_red}, {"bg_black", color::bg_black}, {"bg_red", color::bg_red}, {"bg_green", color::bg_green}, {"bg_yellow", color::bg_yellow}, {"bg_blue", color::bg_blue}, {"bg_magenta", color::bg_magenta}, {"bg_cyan", color::bg_cyan}, {"bg_white", color::bg_white}

    };

    std::string content = "  " + label + "  ";
    int width = (int)content.length();

    if (colorMap.count(bgColorName))
        colorMap[bgColorName](std::cout);
    if (colorMap.count(textColorName))
        colorMap[textColorName](std::cout);

    SetConsoleCursorPosition(h, {(SHORT)x1, (SHORT)y1});
    std::cout << std::string(width, ' ');

    SetConsoleCursorPosition(h, {(SHORT)x1, (SHORT)(y1 + 1)});
    std::cout << content;

    SetConsoleCursorPosition(h, {(SHORT)x1, (SHORT)(y1 + 2)});
    std::cout << std::string(width, ' ');

    std::cout << color::reset << std::flush;

    x2 = x1 + width - 1;
    y2 = y1 + 2;
}

bool Button::hit(int x, int y)
{
    return (x >= x1 && x <= x2 && y >= y1 && y <= y2);
}