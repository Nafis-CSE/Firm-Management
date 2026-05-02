#include "main.h"
class Employee
{
public:
   string emp_id,first_name, last_name, address, phone, joining_date, position;
    float salary;
    bool payment_status = false;
    Employee( string empid, string first_name, string last_name, string address, const string phone, string joining_date, string position, float salary, bool payment_status) {
        this->emp_id = empid;
        this->salary = salary;
        this->payment_status = payment_status;
        this->first_name = first_name;
        this->last_name = last_name;
        this->address = address;
        this->phone = phone;
        this->joining_date = joining_date;
        this->position = position;
    }

};
void get_employees(vector<Employee> &employees)
{
    ifstream fin(user_id + "_employees.txt");
    if (!fin)
    {
        cout << "File open error!" << endl;
        return;
    }

   string empid, first_name, last_name, address, phone, joining_date, position;
    float salary;    bool payment_status;
    while (fin >> empid >> first_name >> last_name >> address >> phone >> joining_date >> position >> salary >> payment_status)
    {
        employees.push_back( Employee(empid, first_name, last_name, address, phone, joining_date, position, salary, payment_status));
    }
    fin.close();
   
}
void put_employees(const vector<Employee> &employees)
{
    ofstream fout(user_id + "_employees.txt");
    if (!fout)
    {
        cout << "File open error!" << endl;
        return;
    }
    for (const auto &emp : employees)
    {
        fout << emp.emp_id << " "
             << emp.first_name << " "
             << emp.last_name << " "
             << emp.address << " "
             << emp.phone << " "
             << emp.joining_date << " "
             << emp.position << " "
             << emp.salary << " "
             << emp.payment_status << endl;
    }
    fout.close();
}
class Salary_button : public Button
{
public:
    string emp_id;

    Salary_button(int x, int y, string label, string  id)
        : Button(x, y, label), emp_id(id) {}

    void click()
    {
        vector<Employee> employee_list;

        get_employees(employee_list);
        for (auto &emp : employee_list)
        {
            if (emp.emp_id == emp_id)
            {
                emp.payment_status = !emp.payment_status; 
                break;
            }
        }

        put_employees(employee_list);
        employee_screen(); 
    }
};
       
class AddEmployee : public Button
{
public:
    AddEmployee() : Button(80, 7, "Add Employee") {}

    void click()
    {
        system("cls");
        string e_id,first_name, last_name, address, phone, joining_date, position, salary;
       

        cout << string(5, '\n');
        cout << setw(200) << color::cyan << "Enter Employee ID: ";
        if (cin.peek() == '\n')
        {
            cin.ignore();
        }
        getline(cin, e_id);
        try
        {
            if (e_id.find(' ') != string::npos)
            {
                throw invalid_argument("ID e space deya jabe na!");
            }
        }
        catch (const invalid_argument &e)
        {
            cout << color::red << setw(200) << e.what() << string(5, '\n');
            sleep(2);
            cout << setw(200) << color::italic << color::white << "Enter Employee ID: ";
            getline(cin, e_id);
        }

        cout << setw(200) << color::cyan << "Enter First Name: ";
        getline(cin, first_name);
        try
        {
            if (first_name.find(' ') != string::npos)
            {
                throw invalid_argument("First Name e space deya jabe na!");
            }
        }
        catch (const invalid_argument &e)
        {
            cout << color::red << setw(200) << e.what() << string(5, '\n');
            sleep(2);
            cout << setw(200) << color::italic << color::white << "Enter First Name: ";
            getline(cin, first_name);
        }

        cout << setw(200) << color::cyan << "Enter Last Name: ";
        getline(cin, last_name);
        try
        {
            if (last_name.find(' ') != string::npos)
            {
                throw invalid_argument("Last Name e space deya jabe na!");
            }
        }
        catch (const invalid_argument &e)
        {
            cout << color::red << setw(200) << e.what() << string(5, '\n');
            sleep(2);
            cout << setw(200) << color::italic << color::white << "Enter Last Name: ";
            getline(cin, last_name);
        }
        cout << setw(200) << color::cyan << "Enter Position: ";
        getline(cin, position);
        try
        {
            if (position.find(' ') != string::npos)
            {
                throw invalid_argument("Position e space deya jabe na!");
            }
        }
        catch (const invalid_argument &e)
        {
            cout << color::red << setw(200) << e.what() << string(5, '\n');
            sleep(2);
            cout << setw(200) << color::italic << color::white << "Enter Position: ";
            getline(cin, position);
        }
            cout << setw(200) << color::cyan << "Enter Address: ";
        getline(cin, address);
        try{
            if (address.find(' ') != string::npos)
            {
                throw invalid_argument("Address e space deya jabe na!");
            }
        }
        catch (const invalid_argument &e)
        {
            cout << color::red << setw(200) << e.what() << string(5, '\n');
            sleep(2);
            cout << setw(200) << color::italic << color::white << "Enter Address: ";
            getline(cin, address);
        }
        cout << setw(200) << color::cyan << "Enter Phone: ";
        getline(cin, phone);
        try
        {
            if (phone.find(' ') != string::npos)
            {
                throw invalid_argument("Phone e space deya jabe na!");
            }
        }
        catch (const invalid_argument &e)
        {
            cout << color::red << setw(200) << e.what() << string(5, '\n');
            sleep(2);
            cout << setw(200) << color::italic << color::white << "Enter Phone: ";
            getline(cin, phone);
        }
        cout << setw(200) << color::cyan << "Enter Salary: ";

        getline(cin, salary);
        try
        {
            if (salary.find(' ') != string::npos)
            {
                throw invalid_argument("Salary e space deya jabe na!");
            }
        }
        catch (const invalid_argument &e)
        {
            cout << color::red << setw(200) << e.what() << string(5, '\n');
            sleep(2);
            cout << setw(200) << color::italic << color::white << "Enter Salary: ";
            getline(cin, salary);
        }
        cout<< setw(200) << color::cyan << "Enter Joining Date: ";
        getline(cin, joining_date);
        try
        {
            if (joining_date.find(' ') != string::npos)
            {
                throw invalid_argument("Joining Date e space deya jabe na!");
            }
        }
        catch (const invalid_argument &e)
        {
            cout << color::red << setw(200) << e.what() << string(5, '\n');
            sleep(2);
            cout << setw(200) << color::italic << color::white << "Enter Joining Date: ";
            getline(cin, joining_date);
        }
        ofstream fout(user_id + "_employees.txt", ios::app);
        if (!fout)
        {
            cout << setw(200) << color::red << "File open error!" << endl;
            return;
        }
        fout << e_id << " " << first_name << " " << last_name << " " << address << " " << phone << " " << joining_date << " " << position << " " << salary << " " << 0  << endl;

        fout.close();

        cout << setw(200) << color::green << "Employee added successfully!" << endl;
        sleep(2);
        employee_screen();
    }
};
class RemoveEmployee : public Button
{
public:
    RemoveEmployee() : Button(80, 11, "Remove Employee") {}

    void click()
    {
        system("cls");
        string id;
        cout << string(5, '\n');
        cout << setw(200) << color::cyan << "Enter Employee ID to remove: ";
        cin >> id;

        vector<Employee> employee_list;

        get_employees(employee_list);
        employee_list.erase(remove_if(employee_list.begin(), employee_list.end(),
                                      [id](const Employee &emp)
                                      { return emp.emp_id == id; }),
                            employee_list.end());
        put_employees(employee_list);
        cout << setw(200) << color::green << "Employee removed successfully!" << endl;
        sleep(2);
        employee_screen();
    }
};  
class to_screen2 : public Button
{
public:
    to_screen2() : Button(80, 17, "Back") {}

    void click()
    {
        system("cls");
        screen2();
    }
};
class reset_payment : public Button {
public:    reset_payment():Button(80,23,"Reset Payments"){}
    void click(){
        vector<Employee> employee_list;
        get_employees(employee_list);
        for(auto &emp : employee_list){
            emp.payment_status = false;
        }
        put_employees(employee_list);
        employee_screen();
    }
};
class view_employee : public Button {

public:  
  string id;
        view_employee(int x, int y, string lebel,string id): Button(x,y,lebel), id(id){}

    void click(){
        system("cls");
       
        cout << string(5, '\n');
        

        vector<Employee> employee_list;
        get_employees(employee_list);

        auto it = find_if(employee_list.begin(), employee_list.end(),
                          [this](const Employee &emp)
                          { return emp.emp_id == id; });
        if (it != employee_list.end()) {
            const Employee &emp = *it;
            cout << setw(200) << color::green << "Employee Details:" << endl;
            cout << setw(200) << color::white << "ID: " << emp.emp_id << endl;
            cout << setw(200) << color::white << "Name: " << emp.first_name << " " << emp.last_name << endl;
            cout << setw(200) << color::white << "Address: " << emp.address << endl;
            cout << setw(200) << color::white << "Phone: " << emp.phone << endl;
            cout << setw(200) << color::white << "Joining Date: " << emp.joining_date << endl;
            cout << setw(200) << color::white << "Position: " << emp.position << endl;
            cout << setw(200) << color::white << "Salary: " << emp.salary << endl;
            cout << setw(200) << color::white << "Payment Status: " << (emp.payment_status ? "Paid" : "Unpaid") << endl;
        } else {
            cout<<setw(200)<<color::red<<"Employee not found!"<<endl;
        }
        cout << setw(200) << color::cyan << "Press Enter to go back..." << color::reset;
        cin.ignore();
        cin.get();
        employee_screen();
    }
};
void employee_screen()
{
    system("cls");
    SetConsoleOutputCP(CP_UTF8);
    vector<Employee> employees;
    vector<Button *> buttons;

    ifstream fin(user_id + "_employees.txt");
    if (!fin)
    {
        cout << "File open error!" << endl;
        return;
    }

    int x1= 62,x2=32, y = 7;

   get_employees(employees);

    for (const auto &emp : employees)
    {
        string label = emp.payment_status ? " Paid " : "Unpaid";
        buttons.push_back(new Salary_button(x1, y, label, emp.emp_id));
            buttons.push_back(new view_employee(x2, y,"   View   ", emp.emp_id));
        y += 4;
    }

    fin.close();

    int consoleWidth = 80;
    int tableWidth = 66;
    int padding = (consoleWidth - tableWidth) / 2;
    string indent(padding, ' ');
    string hLine = "────────────────────────────────────────────────────────────────";

    cout << "\n\n"
         << indent << color::blue << "╭" << hLine << "╮" << endl;
    cout << indent << "│ " << color::reset << color::bold << color::white
         << "                       EMPLOYEE DATABASE                       "
         << color::reset << color::blue << "│" << endl;

    cout << indent << "├──────┬────────────────┬────────────────┬────────────┬──────────┤" << endl;
    cout << indent << "│ " << color::bright_blue << left
         << setw(4) << "ID" << color::blue << " │ "
         << color::bright_blue << setw(14) << "Name" << color::blue << " │ "
         << color::bright_blue << setw(14) << "Details" << color::blue << " │ "
         << color::bright_blue << setw(10) << "Salary" << color::blue << " │ "
         << color::bright_blue << setw(8) << "Status" << color::blue << " │" << endl;
    cout << indent << "├──────┼────────────────┼────────────────┼────────────┼──────────┤" << endl;

    if (employees.empty())
    {
        cout << indent << "│ " << color::red << setw(62) << "          NO EMPLOYEE RECORDS FOUND           " << color::blue << " │" << endl;
    }
    else
    {
        for (size_t i = 0; i < employees.size(); ++i)
        {
            const auto &e = employees[i];

            cout << indent << color::blue << "│      │                │                │            │          │" << endl;

            cout << indent << color::blue << "│ " << color::reset
                 << left << setw(4) << e.emp_id << color::blue << " │ "
                 << color::reset << setw(14) << e.first_name << color::blue << " │ "
                 << color::reset << setw(14) <<e.phone << color::blue << " │ "
                 << color::reset << setw(10) << e.salary << color::blue << " │ "
                 << "        " << color::blue << " │" << endl;

            cout << indent << "│      │                │                │            │          │" << endl;
            cout << indent << "├──────┼────────────────┼────────────────┼────────────┼──────────┤" << endl;
        }
    }

    cout << indent << color::blue << "╰──────┴────────────────┴────────────────┴────────────┴──────────╯" << color::reset << endl;

    AddEmployee add_btn;
    RemoveEmployee remove_btn;
    to_screen2 back_btn;
    reset_payment reset_btn;
    add_btn.draw("bg_blue", "white");
    remove_btn.draw("bg_red", "white");
    back_btn.draw("bg_green", "white");
    reset_btn.draw("bg_yellow", "black");
        for (auto &button : buttons)
    {

        if(button->label == " Paid "){
            button->draw("bg_green", "white");
           
        }
        else if(button->label == "Unpaid"){
            button->draw("bg_red", "white");
           
        }
        else{
            button->draw("bg_cyan", "white");
            cout<<color::reset;
        }
    }
    buttons.push_back(&add_btn);
    buttons.push_back(&remove_btn);
    buttons.push_back(&back_btn);
    buttons.push_back(&reset_btn);

    run(buttons);
}