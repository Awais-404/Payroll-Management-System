#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <ctime>
#include <utility>
using namespace std;

class Employee;

vector<Employee> employee;
vector<Employee> searchV;
Employee *emp;
vector<pair<string,double>> basepays;
float taxes[6][3] = {{50000,0,0},
                    {100000,0,0.025},
                    {200000,1250,0.125},
                    {300000,13750,0.225},
                    {500000,36250,0.275},
                    {00,91250,0.35}};

void get_employee_data();           // Read data from file
void get_base_pays();               // 
void sort_employees();      // sorts by ID
void save_employee_data();        //write to file
void save_base_pays();            //
void search_by_id();
void set_case(string &str);     //Capitalize first letter of each word
int today();        //Gives day of the year

class Employee
{
public:
    int Sr_No, Last_Day;
    string Name, ID, Position, Password;
    float Gross_Salary, Base_Salary, Bonus=0, Deductions,  Tax, Fine=0, Net_salary;
public:
    Employee(){}
    Employee(int srno, string name, string id, string position, float gross, float base, float bonus, float deduction, float tax, float fine, float net, string password, int last);
    Employee(string name, string position);
    void make_id();
    void set_base_pay();
    void set_tax();

    void show();
    void display();
    void edit();
    void change_password();
    void check_absent();        //Adds fine for absents except sunday
    void check_late();
};

Employee::Employee(int srno, string name, string id, string position, float gross, float base, float bonus, float deduction, float tax, float fine, float net, string password, int last)
{
    Sr_No = srno;
    Name = name;
    ID = id;
    Position = position;
    Gross_Salary = gross;
    Base_Salary = base;
    Bonus = bonus;
    Tax = tax;
    Fine = fine;
    Deductions = deduction;
    Net_salary = net;
    Password = password;
    Last_Day = last;
}

Employee::Employee(string name, string position)
{
    Name = name;
    Position = position;
    set_case(Position);
    make_id();
    Bonus = 0;
    set_base_pay();
    Gross_Salary = Base_Salary;
    Tax = 0;
    Fine = 0;
    set_tax();
    Deductions = Tax;
    Net_salary = Gross_Salary - Deductions;
    Password = "123";
    Last_Day = today();
}

void Employee::make_id(){
    int a=0;
    char c[5];
    for(int i = 0; i < Position.length(); i++){
        if (i==0 || Position[i-1]==' ' || Position[i-1]=='.'){
            c[a] = Position[i];
            ID.append(c);
            a++;
        }
    }
    string s;
    time_t now = time(0);
    tm ltm = *localtime(&now);
    strftime(c, 5, "%y", &ltm);
    s = c;
    ID.append(s);
    a=0;
    for(int i = 0; i < employee.size(); i++){
        if(Position == employee[i].Position){
            a++;
        }
    }
    ID.append(to_string(a+1));
}

void Employee::set_base_pay(){
    bool found = false;
    for (int i = 0; i < basepays.size(); i++)
    {
        if(Position == basepays[i].first){
            Base_Salary = basepays[i].second;
            found = true;
            break;
        }
    }
    if (found==false)
    {
        cout<<"Position not found in data base\nEnter base salary for "<<Position<<" position"<<endl;
        cin>>Base_Salary;
    }
}

void Employee::set_tax(){
    if (Gross_Salary <= taxes[0][0])
    {
        Tax = 0;
    }
    else if(Gross_Salary <= taxes[1][0])
    {
        Tax = abs(taxes[1][1] + (((Gross_Salary-taxes[0][0])*taxes[1][2])));
    }
    else if(Gross_Salary <= taxes[2][0])
    {
        Tax = abs(taxes[2][1] + (((Gross_Salary-taxes[1][0])*taxes[2][2])));
    }
    else if(Gross_Salary <= taxes[3][0])
    {
        Tax = abs(taxes[3][1] + (((Gross_Salary-taxes[2][0])*taxes[3][2])));
    }
    else if(Gross_Salary <= taxes[4][0])
    {
        Tax = abs(taxes[4][1] + (((Gross_Salary-taxes[3][0])*taxes[4][2])));
    }
    else if(Gross_Salary > taxes[4][0])
    {
        Tax = abs(taxes[5][1] + (((Gross_Salary-taxes[4][0])*taxes[5][2])));
    }
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

void Employee::edit()
{
    cout<<"choose which field you want to edit:"<<endl;
    cout<<"1-Name\t2-Position"<<endl;
    cout<<"3-Bonus\t4-Fine"<<endl;
    cout<<"Press Esc to exit edit mode..."<<endl;
    int op = getch();
    switch (op)
    {
    case '1':
        cout<<"Enter new Name"<<endl;
        getline(cin,Name);
        break;
    case '2':
        cout<<"Enter new Position"<<endl;
        getline(cin,Position);
        break;
    case '3':
        cout<<"Enter new Bonus"<<endl;
        cin >> Bonus;
        break;
    case '4':
        cout<<"Enter new Fine"<<endl;
        cin >> Fine;
        break;
    case 27:
        break;

    default:
        edit();
        break;
    }
}

void Employee::change_password()
{
    string pass;
    cout<<"Enter new password:"<<endl;
    getline(cin,pass);
    Password = pass;
}

void Employee::check_absent()
{
    int a = today() - Last_Day;
    if (a!=0 && a!=1)
    {
        time_t now = time(0);
        tm ltm = *localtime(&now);
        if(ltm.tm_wday - 1 != 0){
            a++;
            Fine += a*1000;
        }
    }
    
}

void Employee::check_late()
{
    int a = today() - Last_Day;
    if(a!=0){
        time_t now = time(0);
        tm t = *localtime(&now);
        t.tm_hour = 8;
        t.tm_min = 0;
        int reporting = mktime(&t);
        float a = difftime(now, reporting);
        a = a/3600;
        if (a>0.25)
        {
            if (a<0.5)
            {
                Fine += 250;
            }
            else if (a<1)
            {
                Fine += 500;
            }
            else if (a<2)
            {
                Fine += 750;
            }
            else{
                Fine += 1000;
            }
        }
    }
}



void get_employee_data()
{
    int srno, last;
    string name, id, position, password;
    float gross, base, bonus, deduction, tax, fine, net;
    ifstream emp("Employee Data.csv");
    getline(emp,name,'\n');
    for(int i=0; !emp.eof(); i++){
    srno=i+1;
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
    emp >> last;
    getline(emp,password,'\n');
    employee.push_back(Employee(srno, name, id, position, gross, base, bonus, deduction, tax, fine, net, password, last));
    }
    emp.close();
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
}

void sort_employees()
{
    int n, min;
    n = employee.size();
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
        emp<<"\n"<<employee[i].ID<<"\t"<<employee[i].Name<<"\t"<<employee[i].Position<<"\t"<<employee[i].Gross_Salary<<"\t"<<employee[i].Base_Salary<<"\t"<<employee[i].Bonus<<"\t"<<employee[i].Deductions<<"\t"<<employee[i].Tax<<"\t"<<employee[i].Fine<<"\t"<<employee[i].Net_salary<<"\t"<<today()<<"\t"<<employee[i].Password;
    }
    emp.close();
}

void search_by_id()
{
    string search;
    Employee *emp;
    cout<<"Enter ID : ";
    getline(cin,search);
    for (int i = 0; i < search.length(); i++)
    {
        search[i]=toupper(search[i]);
    }
    system("cls");
    for (int i = 0; i < employee.size(); i++)
    {
        if (search == employee[i].ID)
        {
            emp = &employee[i];
            break;
        }
    }
    emp->show();
}

void search_by_name()
{
    string search;
    cout<<"Enter name : ";
    getline(cin,search);
    set_case(search);
    system("cls");
    for (int i = 0; i < employee.size(); i++)
    {
        if (search == employee[i].Name)
        {
            searchV.push_back(employee[i]);
        }
        
    }
    for (int i = 0; i < searchV.size(); i++)
    {
        searchV[i].show();
    }
    
}
void search_by_position()
{
    string search;
    cout<<"Enter position : ";
    getline(cin,search);
    set_case(search);
    system("cls");
    for (int i = 0; i < employee.size(); i++)
    {
        if (search == employee[i].Position)
        {
            searchV.push_back(employee[i]);
        }
        
    }
    for (int i = 0; i < searchV.size(); i++)
    {
        searchV[i].show();
    }
    
}

void set_case(string &str)
{
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

int today()
{
    time_t now = time(0);
    tm ltm = *localtime(&now);
    return ltm.tm_yday + 1;
}