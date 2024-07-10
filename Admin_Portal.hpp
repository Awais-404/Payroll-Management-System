#pragma once
#include "Employee.hpp"

class Admin_Portal{
private:
    bool repeat, back, enter;
public:
    void admin_portal();
    void view_employee_list();
    void view_employee_details();
    void add_employee();
    void remove_employee();
    void search_employee();
    void view_base_pays();
    void edit_base_pays();
    void remove_base_pay();
};

void Admin_Portal::admin_portal()
{
    string pass, star, password = "admin";
    repeat = false;
    back = false;
    enter = false;
    while (!back && !enter)
    {
        system("cls");
        if (repeat == false)
        {
        cout<<setw(35)<<" "<<"Enter Password"<<endl;
        }
        else{
            cout<<setw(35)<<" "<<"Wrong Password, Try again"<<endl;
        }    
        cout<<setw(35)<<" "<<star<<endl;
        cout<<"\n"<<setw(35)<<" "<<"Press Esc to Exit"<<endl;
        char c = getch();
        switch (c)
        {
        case 27:
            back = true;
            break;

        case 8:
            pass = pass.substr(0,pass.length()-1);
            star = star.substr(0,star.length()-1);
            break;

        case 13:
            if (pass == password)
            {
                enter = true;
            }else{
                pass="";
                star="";
                repeat = true;
            }
            break;
        default:
            pass = pass+c;
            star = star+"*";
            break;
        }
    }


    if(back){}
    else
    {
        while(!back){
            system("cls");
            cout<<setw(50)<<" "<<"\033[4m"<<"ADMIN PORTAL"<<"\033[24m \n"<<endl;
            cout<<setw(35)<<" "<<setw(30)<<"1-View employee list"<<"2-View base pays"<<endl;
            cout<<setw(35)<<" "<<"Esc-Exit"<<endl;
            char op = getch();
            switch (op)
            {
            case '1':
                view_employee_list();
                back = false;
                break;
            
            case '2':
                view_base_pays();
                back = false;
                break;
            
            case 27:
                back = true;
                break;
            
            default:
                break;
            }
        }
    }
}

void Admin_Portal::view_employee_list()
{
    while(!back){
        system("cls");
        cout<<"\033[4m"<<setw(10)<<"Sr. No"<<setw(20)<<"ID"<<setw(20)<<"Name"<<setw(15)<<"Position"<<"\033[24m"<<endl;
        for (int i = 0; i < DM.employee.size(); i++)
        {
            DM.employee[i].show();
        }
        cout<<"\n1-View employee details\t2-Add new employee"<<endl;
        cout<<"3-Remove employee\t4-Search employee"<<endl;
        cout<<"Esc-Exit"<<endl;
        char op = getch();
        switch (op)
        {
        case '1':
            view_employee_details();
            back = false;
            break;
        
        case '2':
            add_employee();
            back = false;
            break;

        case '3':
            remove_employee();
            back = false;
            break;
        
        case '4':
            search_employee();
            back = false;
            break;

        case 27:
            back = true;
            break;
        
        default:
        back = false;
            break;
        }
    }
}

void Admin_Portal::view_base_pays()
{
    while(!back){
        system("cls");
        cout<<"\033[4m"<<setw(20)<<"Position"<<"Basepay"<<"\033[24m"<<endl;
        for (int i = 0; i < DM.basepays.size(); i++)
        {
            cout<<setw(20)<<DM.basepays[i].first<<DM.basepays[i].second<<endl;
        }
        cout<<"\n1-Edit list\t2-Remove Position"<<endl;
        cout<<"Esc-Exit"<<endl;
        char op = getch();
        switch (op)
        {
        case '1':
            edit_base_pays();
            back = false;
            break;

        case '2':
            remove_base_pay();
            back = false;
            break;

        case 27:
            back = true;
            break;
        
        default:
        back = false;
            break;
        }
    }
}

void Admin_Portal::view_employee_details()
{
    string search;
    cout<<"Enter Employee ID:"<<endl;
    getline(cin,search);
    if (!DM.search_by_id(search))
    {   
        system("cls");
        cout<<"Employee not found.\nPress any key to continue..."<<endl;
        getch();
    }

}
void Admin_Portal::add_employee()
{
    string name,id;
    cout<<"Enter employee name:"<<endl;
    getline(cin,name);
    cout<<"Enter employee position:"<<endl;
    getline(cin,id);
    DM.emp = new Employee(name,id);
    DM.employee.push_back(*DM.emp);
    system("cls");
    DM.emp->display();
    DM.emp->edit();
    DM.sort_employees();
    DM.save_employee_data();
}
void Admin_Portal::remove_employee()
{
    string id;
    bool found = false;
    int i;
    cout<<"Enter ID:"<<endl;
    getline(cin,id);
    for (int i = 0; i < id.length(); i++)
    {
        id[i]=toupper(id[i]);
    }
    for (i = 0; i < DM.employee.size(); i++)
    {
        if (id == DM.employee[i].ID)
        {
            found = true;
            break;
        }
    }
    if(found)
    {
        for (int j = i; j < DM.employee.size(); j++)
        {
            DM.employee[j] = DM.employee[j+1];
        }
        DM.employee.erase(DM.employee.end());
        DM.save_employee_data();
    }
    else
    {
        system("cls");
        cout<<"ID not found.\nPress any key to continue..."<<endl;
        getch();
    }
}
void Admin_Portal::search_employee()
{
   string search;
    cout<<"Enter Employee ID or Name/Position:"<<endl;
    getline(cin,search);
    if (!DM.search_by_id(search))
    {
        if (!DM.search_by_name(search) || !DM.search_by_position(search))
        {
            system("cls");
            cout<<"Employee not found.\nPress any key to continue..."<<endl;
            getch();
        }
        else{
            if (!DM.search_by_id(search)){
                system("cls");
                cout<<"Employee not found.\nPress any key to continue..."<<endl;
                getch();
            }
        }
    }
}

void Admin_Portal::edit_base_pays()
{
    string position;
    double pay;
    bool found = false;
    cout<<"Enter Postion:"<<endl;
    getline(cin,position);
    DM.set_case(position);

    for (int i = 0; i < DM.basepays.size(); i++)
    {
        if (position == DM.basepays[i].first)
        {
            cout<<"Enter base pay for "<<position<<":"<<endl;
            cin>>pay;
            cin.ignore();
            DM.basepays[i].second = pay;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout<<"Enter base pay for "<<position<<":"<<endl;
        cin>>pay;
        cin.ignore();
        pair<string,double> base;
        base.first = position;
        base.second = pay;
        DM.basepays.push_back(base);
    }
    DM.save_base_pays();
}

void Admin_Portal::remove_base_pay()
{
    string position;
    bool found = false;
    int i;
    cout<<"Enter Postion:"<<endl;
    getline(cin,position);
    DM.set_case(position);
    for (i = 0; i < DM.basepays.size(); i++)
    {
        if (position == DM.basepays[i].first)
        {
            found = true;
            break;
        }
    }
    if(found)
    {
        for (int j = i; j < DM.basepays.size(); j++)
        {
            DM.basepays[j] = DM.basepays[j+1];
        }
        DM.basepays.erase(DM.basepays.end());
        DM.save_base_pays();
    }
    else
    {
        system("cls");
        cout<<"Position not found.\nPress any key to continue..."<<endl;
        getch();
    }
}