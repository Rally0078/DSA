#include "employee.h"

//implementation of abstract hash class for type Employee
template <> class hash<Employee>
{
    public:
    size_t operator()(const Employee & item)
    {
        static hash<string> hf;
        return hf(item.getName());
    }
};