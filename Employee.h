#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

class Employee;

vector<Employee> employees;
vector<pair<string,int>> basepays;

class Employee
{
public:
    int Sr_No;
    string Name, ID, Position;
    float Gross_Salary, Base_Salary, Bonus=0, Deductions,  Tax, Fine=0, Net_salary;
public:
    Employee(int srno, string name, string id, string position, float gross, float base, float bonus, float deduction, float tax, float fine, float net);
    Employee(string name, string position);

    void show();
    void display();
};

Employee::Employee(string name, string position)
{
    Name = name;
    Position = position;
}

Employee::Employee(int srno, string name, string id, string position, float gross, float base, float bonus, float deduction, float tax, float fine, float net)
{
    Sr_No = srno;
    Name = name;
    ID = id;
    Position = position;
    Gross_Salary = base;
    Base_Salary = base;
    Bonus = bonus;
    Tax = tax;
    Fine = fine;
    Deductions = deduction;
    Net_salary = net;
}

void Employee::show()
{
    cout<<setw(10)<<Sr_No<<setw(20)<<ID<<setw(20)<<Name<<setw(15)<<Position<<endl;
}

void Employee::display()
{
    cout<<setw(15)<<"ID"<<setw(5)<<":"<<ID<<endl;
    cout<<setw(15)<<"Name"<<setw(5)<<":"<<Name<<endl;
    cout<<setw(15)<<"Position"<<setw(5)<<":"<<Position<<endl;
    cout<<endl;
    cout<<setw(15)<<"Gross Salary"<<setw(5)<<":"<<Gross_Salary<<endl;
    cout<<"\t"<<setw(12)<<"Base Salary"<<setw(5)<<":"<<Base_Salary<<endl;
    cout<<"\t"<<setw(12)<<"Bonus"<<setw(5)<<":"<<Bonus<<endl;
    cout<<endl;
    cout<<setw(15)<<"Deductoins"<<setw(5)<<":"<<Deductions<<endl;
    cout<<"\t"<<setw(12)<<"Tax"<<setw(5)<<":"<<Tax<<endl;
    cout<<"\t"<<setw(12)<<"Fine"<<setw(5)<<":"<<Fine<<endl;
    cout<<endl;
    cout<<setw(15)<<"Net Salary"<<setw(5)<<":"<<Net_salary<<endl;
}

void get_employee_data()
{
    int srno;
    string name, id, position;
    float gross, base, bonus, deduction, tax, fine, net;
    ifstream emp("Employee Data.csv");
    for(int i=0; !emp.eof(); i++){
    emp >> srno;
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
    employees.push_back(Employee (srno, name, id, position, gross, base, bonus, deduction, tax, fine, net));
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

// void save_employee_data()
// {
//     ofstream emp("Employee Data.csv");
//     for (int i = 0; i < employees.size(); i++)
//     {
//         emp<<employees[i].Sr_No<<"\t"<<employees[i].ID<<"\t"<<employees[i].Name<<"\t"<<employees[i].Position<<"\t"<<employees[i].Gross_Salary<<"\t"<<employees[i].Base_Salary<<"\t"<<employees[i].Bonus<<"\t"<<employees[i].Deductions<<"\t"<<employees[i].Tax<<"\t"<<employees[i].Fine<<"\t"<<employees[i].Net_salary<<endl;
//     }
//     emp.close();
// }