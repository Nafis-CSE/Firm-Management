#include "main.h"
string user_id, password;
class SignUp : public Button
{
public:
    SignUp() : Button(50, 15, "Sign Up") {}

    void click()
    {
       

        system("cls");
        system("color 3F");
        cout<<string(5,'\n');
        cout << setw(200) << color::italic << "Enter User ID: ";
      getline(cin, user_id);
        cout << setw(200) << color::italic << "Enter Password: ";
        getline(cin, password);
try{
      if(user_id.find(' ') != string::npos) {
            throw invalid_argument("User ID e space deya jabe na!");
        }
        if(password.find(' ') != string::npos) {
            throw invalid_argument("Password e space deya jabe na!");
        }

}
catch(const invalid_argument& e) {
        cout << color::red << setw(195)<<" " << e.what() << string(5, '\n');
        sleep(2);
        screen1();
    }
        string filename = user_id + ".bin";

        ifstream check(filename);
        if (check.is_open())
        {
            check.close();
            cout <<color::red<< setw(195)<<" " << "User already exists! Please login."<<string(5,'\n');
            sleep(2);
            screen1();
        }
        check.close();

        ofstream fout(filename, ios::binary);
        if (!fout)
        {
            cout << color::red << setw(195)<<" " << "File create error!" << string(5, '\n');
             sleep(2);
            screen1();
        }

        int len = password.size();
        fout.write((char *)&len, sizeof(len));
        fout.write(password.c_str(), len);
        fout.close();

        cout << setw(195) << color::green<< "Account created successfully!" << string(5, '\n');
        screen2();
    }
};

class LogIn : public Button
{
public:
    LogIn() : Button(70, 15, "Log In") {}

    void click()
    {
        system("cls");
        system("color 3F");
        cout<<string(5,'\n');
        cout << setw(200) << color::italic << "Enter User ID: ";
        cin >> user_id;
        string filename = user_id + ".bin";

        ifstream fin(filename, ios::binary);
        if (!fin.is_open())
        {
            cout << color::red << setw(200) << "User not found!";
                sleep(2);
            screen1();
        }
        cout << setw(200) <<color::italic<< "Enter Password: ";
        cin >> password;


        int len;
        fin.read((char *)&len, sizeof(len));
        char *buffer = new char[len + 1];
        fin.read(buffer, len);
        buffer[len] = '\0';
        string savedPass(buffer);
        delete[] buffer;
        fin.close();

        if (savedPass == password)
        {
            screen2(); 
        }
        else
        {

            cout <<setw(195)<<" " << color::red<< "Wrong Password!"<<string(5,'\n');
             sleep(2);
            screen1();
        }
    }
};
void printBanner();
void screen1()
{
    system("cls");
    system("color 8F");
    printBanner();
    SignUp b1;
    LogIn b2;

    b1.draw("bg_white", "black");
    b2.draw("bg_bright_black", "white");

    run(b1, b2);
}
void printBanner() {
    cout << string(5, '\n');

    string title = "A FIRM MANAGEMENT SYSTEM";
    string subtitle = "Efficient • Reliable • Professional";

   
    int padding = 35;
    string indent(padding, ' ');

    string hLine = "────────────────────────────────────────────────────────────────";

    // Top border
    cout << indent << color::bright_magenta << "╭" << hLine << "╮"  << endl;
    cout << indent << color::bright_magenta << "│╭" << "──────────────────────────────────────────────────────────────"  << "╮│" << endl;

    // Empty line
    cout << indent << color::bright_magenta << "││" 
         << string(62, ' ') 
         << "││" << endl;

    // Title Line
    
    cout << indent << color::bright_magenta << "││" 
      << color::bold << color::magenta<<color::italic<<color::bold 
         << left << setw(20) <<" "<<  title <<setw(18)<<" "
         << color::bright_magenta << "││"  << endl;

    // Empty line
    cout << indent << color::bright_magenta << "││" 
         << string(62, ' ') 
         << "││" << endl;

    // Separator
    cout << indent << color::bright_magenta << "│├" <<"──────────────────────────────────────────────────────────────" << "┤│"<< endl;

    // Subtitle
    cout << indent << color::bright_magenta << "││" 
          << color::bright_white 
         << left << setw(16)<<" " << subtitle  << setw(11)<<" "
      << color::bright_magenta << "││" << endl;

    // Bottom border
    cout << indent << color::bright_magenta << "│╰" << "──────────────────────────────────────────────────────────────"  << "╯│" << endl;
    cout << indent << color::bright_magenta << "╰" << hLine << "╯" <<color::reset<< endl;

    cout << "\n";
}