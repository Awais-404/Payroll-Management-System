#pragma once
#include "Employee.hpp"

bool check_id(string search);
void get_password();
void show_account();

void Employee_portal()
{
    bool repeat, back, enter;
    string id;
    char c;
    while(!back){
        system("cls");
        cout<<setw(45)<<" "<<"\033[4m"<<"EMPLOYEE PORTAL"<<"\033[24m \n"<<endl;
        if (repeat == false)
        {
        cout<<"Enter your ID"<<endl;
        }
        else{
            cout<<"ID not found, Try again"<<endl;
        }
        cout<<id<<endl;
        cout<<"\nPress Esc to Exit"<<endl;
        c = getch();
        switch (c)
        {
        case 27:
            back = true;
            break;

        case 8:
            id = id.substr(0,id.length()-1);
            break;

        case 13:
            if (check_id(id))
            {
                get_password();
                back = true;
            }else{
                id="";
                repeat = true;
            }
            break;
        default:
            id = id+c;
            break;
        }
    }
}

bool check_id(string search){
    bool found = false;
    for (int i = 0; i < search.length(); i++)
    {
        search[i]=toupper(search[i]);
    }
    for (int i = 0; i < DM.employee.size(); i++)
    {
        if (search == DM.employee[i].ID)
        {
            DM.emp = &DM.employee[i];
            found = true;
            break;
        }
    }
    return found;
}

void get_password(){
    bool repeat=false, back=false, enter=false;
    string pass, star;
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
            break;

        case 13:
            if (pass == DM.emp->Password)
            {
                show_account();
                back = true;
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
}

void show_account(){
    DM.emp->check_absent();
    DM.emp->check_late();
    bool back;
    while (!back)
    {
        system("cls");
        DM.emp->display();
        cout<<"Press 1 to change password"<<endl;
        cout<<"Press Esc to exit"<<endl;
        char op = getch();
        switch (op)
        {
        case 27:
            back = true;
            break;
        case 1:
            DM.emp->change_password();
            break;
        default:
            break;
        }
    }
}