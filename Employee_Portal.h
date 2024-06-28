#pragma once
#include <iostream>
#include "Employee.h"
using namespace std;

void Employee_portal()
{
    string id, pass;
    int op;
    bool found = false;
    system("cls");
    cout<<"\033[4m"<<"EMPLOYEE PORTAL"<<"\033[24m"<<endl;
    cout<<"Enter your ID :"<<endl;
    if(getch() != 27){
        getline(cin,id);
        for (int i = 0; i < id.length(); i++)
        {
            id[i]=toupper(id[i]);
        }
        for (int i = 0; i < employee.size(); i++)
        {
            if (id == employee[i].ID)
            {
                emp = &employee[i];
                found = true;
                break;
            }
        }
        if (!found)
        {
            do
            {
                system("cls");
                cout<<"ID not found"<<endl;
                cout<<"Press Esc to exit"<<endl;
                op = getch();
            } while (op!=27);
            Employee_portal();
        }
        else{
            system("cls");
            for (int i = 0; i < 3; i++)
            {
                cout<<"Enter your password :"<<endl;
                getline(cin,pass);
                if (pass == emp->Password)
                {
                    break;
                }
                else{
                    system("cls");
                    cout<<"wrong password, try again."<<endl;
                }
            }

            if (pass != emp->Password)
            {
                do
                {
                    system("cls");
                    cout<<"If you have forgotten your password or having trouble signing in, please contact an administrator"<<endl;
                    cout<<"Press Esc to exit"<<endl;
                    op = getch();
                } while (op!=27);
            }else
            {
                do
                {
                    system("cls");
                    emp->display();
                    cout<<"Press 1 to change password"<<endl;
                    cout<<"Press Esc to exit"<<endl;
                    op = getch();
                    if (op == '1')
                    {
                        emp->change_password();
                    }
                } while (op!=27);
            }
        }
    }
}