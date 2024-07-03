#pragma once
#include "Employee.h"


string pass, star, password = "admin";
bool repeat = false, quit = false, enter = false;
void view_employee_list();
void view_base_pays();
void Admin_portal()
{
    while (!quit && !enter)
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
            quit = true;
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


    if(quit){}
    else
    {
        system("cls");
        cout<<"\033[4m"<<"ADMIN PORTAL"<<"\033[24m"<<endl;
        cout<<"1-View employee list\t2-View base pays"<<endl;
        char op = getch();
        switch (op)
        {
        case '1':
            view_employee_list();
            break;
        
        case '2':
            view_base_pays();
            break;
        
        default:
            break;
        }
    }
}

void view_employee_list()
{
    cout<<"\033[4m"<<setw(10)<<"Sr_No"<<setw(20)<<"ID"<<setw(20)<<"Name"<<setw(15)<<"Position"<<"\033[24m"<<endl;
    for (int i = 0; i < DM.employee.size(); i++)
    {
        DM.employee[i].show();
    }
}

void view_base_pays()
{
    cout<<"\033[4m"<<setw(20)<<"Position"<<"Basepay"<<"\033[24m"<<endl;
    for (int i = 0; i < DM.basepays.size(); i++)
    {
        cout<<setw(20)<<DM.basepays[i].first<<DM.basepays[i].second<<endl;
    }
}
