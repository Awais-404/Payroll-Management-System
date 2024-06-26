#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "Employee.h"
using namespace std;
    
vector<Employee> employee;
vector<pair<string,int>> basepays;

void get_employee_data()
{
    int srno;
    string name, id, position;
    float gross, base, bonus, deduction, tax, fine, net;
    ifstream emp("Employee Data.csv");
    for(int i=0; !emp.eof(); i++){
    srno=i;
    getline(emp,name,'\n');
    getline(emp,id,'\t');
    getline(emp,name,'\t');
    getline(emp,position,'\t');
    emp >> gross;
    emp >> base;
    emp >> bonus;
    emp >> deduction;
    emp >> tax;
    emp >> fine;
    emp >> net;
    employee.push_back(Employee(srno, name, id, position, gross, base, bonus, deduction, tax, fine, net));
    }
    emp.close();
    employee.pop_back();
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
        emp<<"\n"<<employee[i].Sr_No<<"\t"<<employee[i].ID<<"\t"<<employee[i].Name<<"\t"<<employee[i].Position<<"\t"<<employee[i].Gross_Salary<<"\t"<<employee[i].Base_Salary<<"\t"<<employee[i].Bonus<<"\t"<<employee[i].Deductions<<"\t"<<employee[i].Tax<<"\t"<<employee[i].Fine<<"\t"<<employee[i].Net_salary;
    }
    emp.close();
}