#include <iostream>
#include "employee.h"

int main(void)
{
    Employee emp1("Alice", 65000.0, 1);
    Employee emp2("Bob", 55000.0, 2);
    Employee emp3("Charles", 42000.0, 1);
    HashTable<Employee> hashEmp(101);

    if(hashEmp.insert(emp1))
        std::cout<<"Inserted "<<emp1.getName()<<" into the hashtable successfully\n";
    if(hashEmp.insert(emp2))
        std::cout<<"Inserted "<<emp2.getName()<<" into the hashtable successfully\n";

    
    if(hashEmp.contains(emp1))
        std::cout<<emp1.getName()<<" is in the hash table\n";
    else
        std::cout<<emp1.getName()<<" is not in the hash table\n";

    if(hashEmp.contains(emp2))
        std::cout<<emp2.getName()<<" is in the hash table\n";
    else
        std::cout<<emp2.getName()<<" is not in the hash table\n";

    if(hashEmp.contains(emp3))
        std::cout<<emp3.getName()<<" is in the hash table\n";
    else
        std::cout<<emp3.getName()<<" is not in the hash table\n";

}

