#pragma once
#include "hash2.h"
class Employee
{
    public:
        Employee();
        Employee(const string name, const double salary, const int seniority): name(name), 
                                                                                salary(salary), 
                                                                                seniority(seniority){}
        const string & getName() const
        {
            return name;
        }
        bool operator==(const Employee &rhs) const
        {
            return getName() == rhs.getName();
        }
        bool operator!=(const Employee &rhs) const
        {
            return !(*this == rhs); 
        }
    private:
        string name;
        double salary;
        int seniority;
};

template <> class hash<Employee>
{
    public:
    size_t operator()(const Employee & item)
    {
        static hash<string> hf;
        return hf(item.getName());
    }
};