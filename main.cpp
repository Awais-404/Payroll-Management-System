#include "Employee.h"
#include "Employee_Portal.h"
#include "Admin_Portal.h"
using namespace std;

main(){
    bool quit = false;
    cout<<left;
    while(!quit){
        system("cls");
        cout<<setw(45)<<" "<<"\033[4m"<<"PAYROLL MANAGEMENT SYSTEM"<<"\033[24m  \n"<<endl;
        cout<<setw(35)<<" "<<setw(30)<<"1-Employee Portal"<<"2-Admin Portal"<<endl;
        cout<<setw(35)<<" "<<"Esc-Exit"<<endl;
        char op = getch();
        switch (op)
        {
        case '1':
            Employee_portal();
            break;
        
        case '2':
            Admin_portal();
            break;
        
        case 27:
            quit = true;
            break;
        
        default:
            break;
        }
    }
    DM.save_employee_data();
    DM.save_base_pays();
    return 0;
}