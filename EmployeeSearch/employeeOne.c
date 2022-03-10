#include <string.h>
#include "employee.h"

//Searching an employee by using phone number
PtrToEmployee searchEmployeeByPhoneNumber(PtrToConstEmployee ptr, int tableSize, char * targetPhone)
{
    const PtrToConstEmployee endPtr = ptr + tableSize;

    //Check until end of the table
    for(;ptr < endPtr; ptr++) 
    {
        if(strcmp(ptr->phone,targetPhone) == 0) //To check if it is equal to the employee phone number.
        {
            return (PtrToEmployee) ptr;
        }
    }
    return NULL; //If no employee phone number matches in the loop.
}

//Searching an employee by using salary
PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int tableSize, double targetSalary)
{
    const PtrToConstEmployee endPtr = ptr + tableSize;

    //Check until end of the table
    for(;ptr < endPtr; ptr++)
    {
        if(ptr->salary == targetSalary) //To check if it is equal to the employee salary.
        {
            return (PtrToEmployee) ptr;
        }
    }
    return NULL; //If no employee salary matches in the loop.
}

//Searching an employee by using employee number
PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int tableSize, long targetNumber)
{
    const PtrToConstEmployee endPtr = ptr + tableSize;

    //Check until end of the table
    for(;ptr < endPtr; ptr++) 
    {
        if(ptr->number == targetNumber) //To check if it is equal to the employee phone number.
        {
            return (PtrToEmployee) ptr;
        }
    }
    return NULL; //If no employee phone number matches in the loop.
}

//Searching an employee by using employee name
PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int tableSize, char * targetName)
{
    const PtrToConstEmployee endPtr = ptr + tableSize;

    //Check until end of the table
    for(;ptr < endPtr; ptr++)
    {
        if(strcmp(ptr->name,targetName) == 0)
        {
             return (PtrToEmployee) ptr;
        }
    }
    return NULL;
}