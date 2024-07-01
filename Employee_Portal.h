#pragma once
#include "Employee.h"

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
        for (int i = 0; i < DM.employee.size(); i++)
        {
            if (id == DM.employee[i].ID)
            {
                DM.emp = &DM.employee[i];
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
                if (pass == DM.emp->Password)
                {
                    break;
                }
                else{
                    system("cls");
                    cout<<"wrong password, try again."<<endl;
                }
            }

            if (pass != DM.emp->Password)
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
                DM.emp->check_absent();
                DM.emp->check_late();
                do
                {
                    system("cls");
                    DM.emp->display();
                    cout<<"Press 1 to change password"<<endl;
                    cout<<"Press Esc to exit"<<endl;
                    op = getch();
                    if (op == '1')
                    {
                        DM.emp->change_password();
                    }
                } while (op!=27);
            }
        }
    }
}