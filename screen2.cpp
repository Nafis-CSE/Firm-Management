#include "main.h"
#include "cost_screen.h"
class Cost : public Button {
public:
    Cost():Button(40,7,"Expense"){}

    void click(){
        system("cls");
        cost_screen();
    }
};

class Earn : public Button {
public:
    Earn():Button(55,7,"Income"){}

    void click(){
        system("cls");
        earn_screen();
    }
};
class Manage_Employee : public Button 
{
public:
    Manage_Employee():Button(70,7,"Employees"){}

    void click(){
        system("cls");
        employee_screen();
    }
};
class stocks : public Button {
public:    stocks():Button(90,7,"Stocks"){}

    void click(){
        system("cls");
         stock_screen();
    }
};
void screen2(){
    system("cls");
    system("color DF");
    Cost b1;
    Earn b2;
    Manage_Employee b3;
    stocks b4;

    b1.draw("bg_red", "white");
    b2.draw("bg_green", "white");
    b3.draw("bg_blue", "white");
    b4.draw("bg_black", "white");
    run(b1,b2,b3,b4);
}
