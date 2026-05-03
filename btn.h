#ifndef BTN_H
#define BTN_H

#include <windows.h>
#include <iostream>
using namespace std;

class Button {
protected:
    int x1,y1,x2,y2;
    
    public:
    string label;
    Button(int a,int b,string t);
    void draw(std::string bgColorName="white", std::string textColorName="black");
    bool hit(int x,int y);
    
    virtual void click() = 0;
    virtual ~Button() = default;
};

 template<typename... T>
  void run( T... args) {
        HANDLE h = GetStdHandle(STD_INPUT_HANDLE);

    DWORD mode;
    GetConsoleMode(h,&mode);

    mode &= ~ENABLE_QUICK_EDIT_MODE;
    mode |= ENABLE_EXTENDED_FLAGS;
    mode |= ENABLE_MOUSE_INPUT;

    SetConsoleMode(h,mode);

    INPUT_RECORD rec;
    DWORD ev;

    while(true){
        ReadConsoleInput(h,&rec,1,&ev);

        if(rec.EventType == MOUSE_EVENT){   
            auto m = rec.Event.MouseEvent;

            if(m.dwEventFlags == 0 &&
               m.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED){

                int x = m.dwMousePosition.X;
                int y = m.dwMousePosition.Y;

                ((args.hit(x,y) ? args.click() : void()), ...);

            }
        }
    }
}
template<typename T>
void run(vector<T>& buttons) {
    HANDLE h = GetStdHandle(STD_INPUT_HANDLE);

    DWORD mode;
    GetConsoleMode(h, &mode);

    mode &= ~ENABLE_QUICK_EDIT_MODE;
    mode |= ENABLE_EXTENDED_FLAGS;
    mode |= ENABLE_MOUSE_INPUT;

    SetConsoleMode(h, mode);

    INPUT_RECORD rec;
    DWORD ev;

    while (true) {
        ReadConsoleInput(h, &rec, 1, &ev);

        if (rec.EventType == MOUSE_EVENT) {
            auto m = rec.Event.MouseEvent;

            if (m.dwEventFlags == 0 &&
                m.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {

                int x = m.dwMousePosition.X;
                int y = m.dwMousePosition.Y;

                for (auto &b : buttons) {
                    if (b->hit(x, y)) {
                        b->click();
                    }
                }
            }
        }
    }
}
#endif
