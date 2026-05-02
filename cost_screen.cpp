#include "main.h"
class AddCost : public Button
{
public:
    AddCost() : Button(50, 7, "Add Cost") {}

    void click()
    {
        system("cls");
        string item, date, amount;
        cout << string(5, '\n');
        cout << setw(200) << color::italic << color::white << "Enter Item Name: ";
        if (cin.peek() == '\n')
        {
            cin.ignore();
        }
        getline(cin, item);
        try
        {
            if (item.find(' ') != string::npos)
            {
                throw invalid_argument("Item name e space deya jabe na!");
            }
        }
        catch (const invalid_argument &e)
        {
            cout << color::red << setw(200) << e.what() << string(5, '\n');
            sleep(2);
            cout << setw(200) << color::italic << color::white << "Enter Item Name: ";
            getline(cin, item);
        }
        cout << setw(200) << color::italic << color::white << "Enter Amount: ";

        getline(cin, amount);
        try
        {
            if (amount.find(' ') != string::npos)
            {
                throw invalid_argument("Amount e space deya jabe na!");
            }
        }
        catch (const invalid_argument &e)
        {
            cout << color::red << setw(200) << e.what() << string(5, '\n');
            sleep(2);
            cout << setw(200) << color::italic << color::white << "Enter Amount: ";

            getline(cin, amount);
        }

        cout << setw(200) << color::italic << color::white << "Enter Date (DD-MM-YYYY): ";

        getline(cin, date);
        try
        {
            if (date.find(' ') != string::npos)
            {
                throw invalid_argument("Date e space deya jabe na!");
            }
        }
        catch (const invalid_argument &e)
        {
            cout << color::red << setw(200) << e.what() << string(5, '\n');
            sleep(2);
            cout << setw(200) << color::italic << color::white << "Enter Date (DD-MM-YYYY): ";
            getline(cin, date);
        }

        string filename = user_id + "_costs.txt";
        ofstream fout(filename, ios::app);

        if (!fout)
        {
            cout << setw(200) << color::red << "File open error!" << endl;
            sleep(2);
            cost_screen();
            return;
        }

        fout << item << " " << amount << " " << date << endl;

        fout.close();

        cout << setw(200) << color::green << "Cost added successfully!" << endl;
        sleep(2);
        cost_screen();
    }
};
class ViewCost : public Button
{
public:
    ViewCost() : Button(70, 7, "View Cost") {}

    void click()
    {
        string filename = user_id + "_costs.txt";
        ifstream fin(filename);
        system("cls");

        string indent(40, ' ');

      
        cout << "\n\n"; 
        cout << indent << color::cyan << "╭──────────────────────────────────────────────────╮" << endl;
        cout << indent << "│ " << color::reset << color::bold << color::white << "                  COST DETAILS                  " << color::reset << color::cyan << " │" << endl;
        cout << indent << "├──────────────┬──────────────┬────────────────────┤" << endl;
        cout << indent << "│ " << color::yellow << left << setw(12) << "Item" << color::cyan << " │ "
             << color::yellow << setw(12) << "Amount" << color::cyan << " │ "
             << color::yellow << setw(18) << "Date" << color::cyan << " │" << color::reset << endl;
        cout << indent << color::cyan << "├──────────────┼──────────────┼────────────────────┤" << endl;

        string item, date;
        string amount;
        bool empty = true;

        while (fin >> item >> amount >> date)
        {
            empty = false;
            cout << indent << color::cyan << "│ " << color::reset
                 << left << setw(12) << item << color::cyan << " │ "
                 << color::reset << setw(12) << amount << color::cyan << " │ "
                 << color::reset << setw(18) << date << color::cyan << " │" << endl;
        }

        if (empty)
        {
            cout << indent << "│ " << color::red << setw(48) << "      NO COST DATA FOUND      " << color::cyan << " │" << endl;
        }

        cout << indent << "╰──────────────────────────────────────────────────╯" << color::reset << endl;

        fin.close();

        
        cout << "\n"
             << indent << color::bright_black << "Press Enter to go back..." << color::reset;
        cin.ignore();
        cin.get();
        cost_screen();
    }
};
class Back_to_screen2 : public Button
{
public:
    Back_to_screen2() : Button(60, 12, "Back") {}

    void click()
    {
        system("cls");
        screen2();
    }
};
void cost_screen()
{
    system("cls");
    system("color F0");
    AddCost b1;
    ViewCost b2;
    Back_to_screen2 b3;

    b1.draw("bg_green", "bright_white");
    b2.draw("bg_cyan", "bright_white");
    b3.draw("bg_red", "bright_white");
    run(b1, b2, b3);
}