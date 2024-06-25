#include <iostream>
#include <vector>
#include <fstream>
#include "Employee.h"
using namespace std;
    
vector<Employee> employee;
vector<pair<string,int>> basepays;

void get_employee_data()
{
    string srno, name, id, position, gross, base, bonus, deduction, tax, fine, net;
    ifstream emp("Employee Data.csv");
    for(int i=0; !emp.eof(); i++){
    getline(emp,srno,'\t');
    getline(emp,id,'\t');
    getline(emp,name,'\t');
    getline(emp,position,'\t');
    getline(emp,gross,'\t');
    getline(emp,base,'\t');
    getline(emp,bonus,'\t');
    employee.push_back(Employee(stof(srno), name, id, position, stof(gross), stof(base), stof(bonus), stof(deduction), stof(tax), stof(fine), stof(net)));
    }
    emp.close();
}
void get_base_pays()
{
    string position, pay;
    ifstream bp("Base Pays.csv");
    for(int i=0; !bp.eof(); i++){
        getline(bp,position,'\t');
        getline(bp,pay,'\n');
        basepays[i].first = position;
        basepays[i].second = stof(pay);
    }
    bp.close();
}

void save_employee_data()
{
    ofstream emp("Employee Data.csv");
    for (int i = 0; i < employee.size(); i++)
    {
        emp<<employee[i].Sr_No<<"\t"<<employee[i].ID<<"\t"<<employee[i].Name<<"\t"<<employee[i].Position<<"\t"<<employee[i].Gross_Salary<<"\t"<<employee[i].Base_Salary<<"\t"<<employee[i].Bonus<<"\t"<<employee[i].Deductions<<"\t"<<employee[i].Tax<<"\t"<<employee[i].Fine<<"\t"<<employee[i].Net_salary<<endl;
    }
    emp.close();
}