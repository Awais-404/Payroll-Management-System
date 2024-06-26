#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <utility>
#include "Employee.h"
using namespace std;
    
vector<Employee> employee;
vector<pair<string,int>> basepays;
// vector<vector<int>> taxes;
float taxes[7][3] = {{0,0,0},
                    {50000,0,0},
                    {100000,0,2.5},
                    {200000,1250,12.5},
                    {300000,13750,22.5},
                    {500000,36250,27.5},
                    {00,91250,35}};

void get_employee_data()
{
    int srno;
    string name, id, position;
    float gross, base, bonus, deduction, tax, fine, net;
    ifstream emp("Employee Data.csv");
    for(int i=0; !emp.eof(); i++){
    srno=i+1;
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
    string position; float pay;
    pair<string,int> p;
    ifstream bp("Base Pays.csv");
    for(int i=0; !bp.eof(); i++){
        getline(bp,position,'\n');
        getline(bp,position,'\t');
        bp >> pay;
        p.first = position;
        p.second = pay;
        basepays.push_back(p);
    }
    bp.close();
    basepays.pop_back();
}

void sort_employees(){
    int n, min;
    int n = employee.size();
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (employee[j].ID < employee[min].ID){
                swap(employee[min], employee[i]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        employee[i].Sr_No = i+1;
    }
}

void save_employee_data()
{
    ofstream emp("Employee Data.csv");
    for (int i = 0; i < employee.size(); i++)
    {
        emp<<"\n"<<employee[i].ID<<"\t"<<employee[i].Name<<"\t"<<employee[i].Position<<"\t"<<employee[i].Gross_Salary<<"\t"<<employee[i].Base_Salary<<"\t"<<employee[i].Bonus<<"\t"<<employee[i].Deductions<<"\t"<<employee[i].Tax<<"\t"<<employee[i].Fine<<"\t"<<employee[i].Net_salary;
    }
    emp.close();
}

void set_case(string &str){
    for (int i = 0; i < str.length(); i++)
      {
         if (i==0 || str[i-1]==' ' || str[i-1]=='.'){
            str[i]=toupper(str[i]);
         }
         else{
            str[i]=tolower(str[i]);
         }
      }
}
