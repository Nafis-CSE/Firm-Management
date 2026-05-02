#include "main.h"
class Add_item : public Button {
public:
    Add_item():Button(80,5,"AddItem"){}

    void click(){
        system("cls");
        int quantity;
        string name;
        float price;
     cout<<string(5,'\n');
        cout <<setw(200) << color::cyan << "Enter Item Name: ";
        if(cin.peek() == '\n')
        {
            cin.ignore();
        }
        getline(cin, name);

         try{
            if (name.find(' ') != string::npos)
            {
                throw invalid_argument("Item Name e space deya jabe na!");
            }
        }
        catch (const invalid_argument &e)
        {
            cout << color::red << setw(200) << e.what() << string(5, '\n');
            sleep(2);
            cout << setw(200) << color::italic<< color::white << "Enter Item Name: ";
            getline(cin, name);
        }

        cout << setw(200) << color::cyan << "Enter Price per item: ";
        cin >> price;

        cout << setw(200) << color::cyan << "Enter Quantity: ";
        cin >> quantity;


        ofstream fout(user_id+"stocks.txt", ios::app);
        if (!fout) {
            cout << setw(200) << color::red << "File open error!" << endl;
            return;
        }

        fout << name << " "
             << price << " "
             << quantity << endl;

        fout.close();

        cout << setw(200) << color::green << "Item added successfully!" << endl;
        sleep(2);
        stock_screen();
    }
};
class Update_item : public Button {
public:
    Update_item():Button(80,11,"UpdateItem"){}
    void click(){
        system("cls");
        int quantity;
        string name;
        float price;
     cout<<string(5,'\n');
        cout <<setw(200) << color::cyan << "Enter Item Name to update: ";
        cin >> name;

        cout << setw(200) << color::cyan << "Enter New Price: ";
        cin >> price;

        cout << setw(200) << color::cyan << "Enter New Quantity: ";
        cin >> quantity;

        vector<tuple<string, float, float>> stock_list;

        ifstream fin(user_id+"stocks.txt");
        if (!fin) {
            cout << setw(200) << color::red << "File open error!" << endl;
            return;
        }

        string item_name;
        float item_price, item_quantity;

        while (fin >> item_name >> item_price >> item_quantity) {
            if (item_name == name) {
                stock_list.push_back(make_tuple(name, price, quantity));
            } else {
                stock_list.push_back(make_tuple(item_name, item_price, item_quantity));
            }
        }
        fin.close();

        ofstream fout(user_id+"stocks.txt");
        if (!fout) {
            cout << setw(200) << color::red << "File open error!" << endl;
            return;
        }

        for (auto &stock : stock_list) {
            fout << get<0>(stock) << " "
                 << get<1>(stock) << " "
                 << get<2>(stock) << endl;
        }

        fout.close();

        cout << setw(200) << color::green << "Item updated successfully!" << endl;
        sleep(2);
        stock_screen(); 
    }
};
class Remove_item : public Button {
public:    Remove_item():Button(80,17,"RemoveItem"){}
    void click(){
        system("cls");
        string name;
     cout<<string(5,'\n');
        cout << setw(200) << color::cyan << "Enter Item Name to remove: ";
        cin >> name;

        vector<tuple<string, float, float>> stock_list;

        ifstream fin(user_id+"stocks.txt");
        if (!fin) {
            cout << setw(200) << color::red << "File open error!" << endl;
            return;
        }

        string item_name;
        float item_price, item_quantity;

        while (fin >> item_name >> item_price >> item_quantity) {
            if (item_name != name) {
                stock_list.push_back(make_tuple(item_name, item_price, item_quantity));
            }
        }
        fin.close();

        ofstream fout(user_id+"stocks.txt");
        if (!fout) {
            cout << setw(200) << color::red << "File open error!" << endl;
            return;
        }

        for (auto &stock : stock_list) {
            fout << get<0>(stock) << " "
                 << get<1>(stock) << " "
                 << get<2>(stock) << endl;
        }

        fout.close();

        cout << setw(200) << color::green << "Item removed successfully!" << endl;
        sleep(2);
        stock_screen(); 
    }
};
class stock_to_screen2 : public Button {
public:    stock_to_screen2():Button(80,23,"Back"){}

    void click(){
        system("cls");
        screen2();
    }
};
void stock_screen() {
    system("cls");
  ifstream fin(user_id+"stocks.txt");
    if (!fin) {
        cout << color::red << " [!] Error: Could not open " << user_id << "stocks.txt" << color::reset << endl;
        return;
    }

    int consoleWidth = 80;
    int tableWidth = 66; 
    int padding = (consoleWidth - tableWidth) / 2;
    string indent(padding, ' ');
    
    string hLine = "────────────────────────────────────────────────────────────────";
    string name;
    float price, quantity;

    
    cout << "\n\n" << indent << color::blue << "╭" << hLine << "╮" << endl;
    
    
    cout << indent << "│ " << color::reset << color::bold << color::white 
         << left << setw(20) << "  STOCK NAME" 
         << setw(20) << "     PRICE" 
         << setw(22) << "    QUANTITY" 
         << color::reset << color::blue << " │" << endl;
    
  
    cout << indent << "├────────────────────┬────────────────────┬──────────────────────┤" << endl;

    bool hasData = false;
    while (fin >> name >> price >> quantity) {
        hasData = true;
        
    
        cout << indent << "│                    │                    │                      │" << endl;

    
        cout << indent << "│ " << color::white 
             << " " << left << setw(18) << name << color::blue << "│ " 
             << color::bright_green << "৳" << left << setw(18) << price << color::blue << "│ " 
             << color::bright_cyan << left << setw(20) << quantity << color::blue << " │" << endl;

       
        cout << indent << "│                    │                    │                      │" << endl;
        cout << indent << "├────────────────────┼────────────────────┼──────────────────────┤" << endl;
    }

    if (!hasData) {
        cout << indent << "│ " << color::red << setw(62) << "        NO STOCKS FOUND IN FILE         " << color::blue << " │" << endl;
        cout << indent << "├────────────────────┴────────────────────┴──────────────────────┤" << endl;
    }

   
    cout << indent << "╰────────────────────┴────────────────────┴──────────────────────╯" << color::reset << endl;
    
    fin.close();
    cout << string(3, '\n');
    Add_item addButton;
    Update_item updateButton;
    stock_to_screen2 backButton;
    Remove_item removeButton;   

    addButton.draw("bg_green", "white");
    updateButton.draw("bg_blue", "white");
    backButton.draw("bg_cyan", "white");
    removeButton.draw("bg_red", "white");
    run(addButton, updateButton, backButton, removeButton);
}