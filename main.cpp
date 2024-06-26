#include <iostream>
#include <vector>
#include "Employee.h"
#include "Data_Manager.h"
using namespace std;

main(){
    get_employee_data();
    get_base_pays();
    cout<<left;
    for(int i =0; i < employee.size(); i++){
    employee[i].display();
    }
    return 0;
}