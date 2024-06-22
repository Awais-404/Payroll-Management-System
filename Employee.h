#include <iostream>
#include <iomanip>
using namespace std;

class Employee
{
private:
    string Name, ID, Position;
    float Gross_Salary, Base_Salary, Bonus, Deductions,  Tax, Fine, Net_salary;
public:
    Employee(string name, string id, string position, float gross, float base, float bonus, float deduction, float tax, float fine, float net);

    void show();
    void display();
};

Employee::Employee(string name, string id, string position, float gross, float base, float bonus, float deduction, float tax, float fine, float net)
{
    Name = name;
    ID = id;
    Position = position;
    Gross_Salary = base + bonus;
    Base_Salary = base;
    Bonus = bonus;
    Tax = tax;
    Fine = fine;
    Deductions = Tax + Fine;
    Net_salary = net;
}

void Employee::show()
{
    cout<<setw(10)<<1<<setw(20)<<ID<<setw(20)<<Name<<setw(15)<<Position<<endl;
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