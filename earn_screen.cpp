#include "main.h"
class AddEarn : public Button
{
public:
    AddEarn() : Button(50, 7, "Add Earn") {}

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
        cout << setw(200) << color::italic << color::white << "Enter Date (YYYY-MM-DD): ";
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
            cout << setw(200) << color::italic << color::white << "Enter Date (YYYY-MM-DD): ";
            getline(cin, date);
        }

        string filename = user_id + "_earn.txt";
        ofstream fout(filename, ios::app);

        if (!fout)
        {
            cout << setw(200) << color::red << "File open error!" << endl;
            return;
        }

        fout << item << " " << amount << " " << date << endl;

        fout.close();

        cout << setw(200) << color::green << "Earn added successfully!" << endl;
        sleep(2);
        earn_screen();
    }
};
class ViewEarn : public Button
{
public:
    ViewEarn() : Button(70, 7, "View Earn") {}

    void click()
    {
        string filename = user_id + "_earn.txt";
        ifstream fin(filename);
        system("cls");
        string indent(40, ' ');

        // Header styling
        cout << "\n\n";
        cout << indent << color::green << "╭──────────────────────────────────────────────────╮" << endl;
        cout << indent << "│ " << color::reset << color::bold << color::white << "                 EARNING DETAILS                 " << color::reset << color::green << "│" << endl;
        cout << indent << "├──────────────┬──────────────┬────────────────────┤" << endl;
        cout << indent << "│ " << color::bright_green << left << setw(12) << "Source" << color::green << " │ "
             << color::bright_green << setw(12) << "Amount" << color::green << " │ "
             << color::bright_green << setw(18) << "Date" << color::green << " │" << color::reset << endl;
        cout << indent << color::green << "├──────────────┼──────────────┼────────────────────┤" << endl;

        string item, date;
        double amount;
        double totalEarned = 0;
        bool empty = true;

        while (fin >> item >> amount >> date)
        {
            empty = false;
            totalEarned += amount;
            cout << indent << color::green << "│ " << color::reset
                 << left << setw(12) << item << color::green << " │ "
                 << color::reset << setw(12) << amount << color::green << " │ "
                 << color::reset << setw(18) << date << color::green << " │" << endl;
        }

        if (empty)
        {
            cout << indent << "│ " << color::red << setw(48) << "      NO EARNING DATA FOUND      " << color::green << " │" << endl;
        }
        else
        {
            // Add a Footer Row for the Total
            cout << indent << "├──────────────┴──────────────┴────────────────────┤" << endl;
            cout << indent << "│ " << color::bold << color::white << left << setw(27) << " TOTAL INCOME:"
                 << color::bright_green << "$" << right << setw(19) << totalEarned << " " << color::green << " │" << endl;
        }

        // Closing the Box
        cout << indent << "╰──────────────────────────────────────────────────╯" << color::reset << endl;

        fin.close();

        // Footer interaction
        cout << "\n"
             << indent << color::bright_black << "Press Enter to go back..." << color::reset;
        cin.ignore();
        cin.get();
        earn_screen();
    }
};
class Bk_to_screen2 : public Button
{
public:
    Bk_to_screen2() : Button(60, 12, "Back") {}

    void click()
    {
        system("cls");
        screen2();
    }
};
void earn_screen()
{
    system("cls");
    system("color F0");
    AddEarn b1;
    ViewEarn b2;
    Bk_to_screen2 b3;

    b1.draw("bg_green", "bright_white");
    b2.draw("bg_cyan", "bright_white");
    b3.draw("bg_red", "bright_white");
    run(b1, b2, b3);
}