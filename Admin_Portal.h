#pragma once
#include "Employee.h"


string pass, star, password = "admin";
bool repeat, back, enter;
void view_employee_list();
void view_employee_details();
void add_employee();
void remove_employee();
void search_employee();
void view_base_pays();
void edit_base_pays();


void Admin_portal()
{
    repeat = false;
    back = false;
    enter = false;
    while (!back && !enter)
    {
        system("cls");
        if (repeat == false)
        {
        cout<<"Enter Password"<<endl;
        }
        else{
            cout<<"Wrong Password, Try again"<<endl;
        }    
        cout<<star<<endl;
        cout<<"\nPress Esc to Exit"<<endl;
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
            cout<<"\033[4m"<<"ADMIN PORTAL"<<"\033[24m"<<endl;
            cout<<"1-View employee list\t2-View base pays"<<endl;
            cout<<"Esc-Exit"<<endl;
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

void view_employee_list()
{
    while(!back){
        system("cls");
        cout<<"\033[4m"<<setw(10)<<"Sr_No"<<setw(20)<<"ID"<<setw(20)<<"Name"<<setw(15)<<"Position"<<"\033[24m"<<endl;
        for (int i = 0; i < DM.employee.size(); i++)
        {
            DM.employee[i].show();
        }
        cout<<"1-View employee details\t2-Add new employee"<<endl;
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

void view_base_pays()
{
    while(!back){
        system("cls");
        cout<<"\033[4m"<<setw(20)<<"Position"<<"Basepay"<<"\033[24m"<<endl;
        for (int i = 0; i < DM.basepays.size(); i++)
        {
            cout<<setw(20)<<DM.basepays[i].first<<DM.basepays[i].second<<endl;
        }
        cout<<"1-Edit list"<<endl;
        cout<<"Esc-Exit"<<endl;
        char op = getch();
        switch (op)
        {
        case '1':
            edit_base_pays();
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

void view_employee_details()
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
void add_employee()
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
}
void remove_employee()
{
    string search;
    cout<<"Enter Employee ID:"<<endl;
    getline(cin,search);
    if (DM.search_by_id(search))
    {
        system("cls");
        vector<Employee>::iterator it;
        int index = (DM.emp->Sr_No)-1;
        swap(DM.employee[index], DM.employee[DM.employee.size()+1]);
        it = DM.employee.end();
        DM.employee.erase(it);
        DM.sort_employees();
    }
    else{
        system("cls");
        cout<<"Employee not found.\nPress any key to continue..."<<endl;
        getch();
    }   
}
void search_employee()
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

void edit_base_pays()
{
    string position;
    double pay;
    cout<<"Enter Postion:"<<endl;
    getline(cin,position);
    DM.set_case(position);

    for (int i = 0; i < DM.basepays.size(); i++)
    {
        if (position == DM.basepays[i].first)
        {
            cout<<"Enter base pay for "<<position<<":"<<endl;
            cin>>pay;
            DM.basepays[i].second = pay;
            exit;
        }
    }
    cout<<"Enter base pay for "<<position<<":"<<endl;
    cin>>pay;
    pair<string,double> base;
    base.first = position;
    base.second = pay;
    DM.basepays.push_back(base);
    DM.sort_basepays();
}