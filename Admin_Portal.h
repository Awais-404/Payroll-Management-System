#pragma once
#include "Employee.h"
// #include "main.cpp"


string pass, star, password = "admin";
bool repeat = false, quit = false, enter = false;

void Admin_portal()
{
    while (!quit && !enter)
    {
        system("cls");
        // cout<<"\033[4m"<<"ADMIN PORTAL"<<"\033[24m"<<endl;
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
    if (quit)
    {
        cout<<"quit";
    }
    else{
        cout<<"enter";
    }
    
}