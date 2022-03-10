#include <string.h>
#include "employee.h"

static PtrToEmployee searchEmployeeTable(PtrToConstEmployee Ptr, int tableSize, const void *targetPtr,
                                        int (*functionPtr)(const void *, PtrToConstEmployee))
{
    PtrToConstEmployee endPtr = Ptr + tableSize;
    for(;Ptr < endPtr; Ptr++)
    {
        if((*functionPtr)(targetPtr,Ptr) == 0)
        {
            return (PtrToEmployee) Ptr;
        }
    }
    return NULL;
}

//The function will point to one of these comparison functions to perform a check
static int compareEmployeeNumber(const void *targetPtr, PtrToConstEmployee tableValuePtr)
{
    return * (long *) targetPtr != tableValuePtr->number;
}

static int compareEmployeeName(const void *targetPtr, PtrToConstEmployee tableValuePtr)
{
    return strcmp((char *) targetPtr, tableValuePtr->name);
}

static int compareEmployeePhoneNumber(const void *targetPtr, PtrToConstEmployee tableValuePtr)
{
    return strcmp((char *) targetPtr, tableValuePtr->phone);
}

static int compareEmployeeSalary(const void *targetPtr, PtrToConstEmployee tableValuePtr)
{
    return * (double *) targetPtr != tableValuePtr->salary;
}


//Wrappers
PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee Ptr, int size, long number)
{
    return searchEmployeeTable(Ptr, size, &number, compareEmployeeNumber);
}

PtrToEmployee searchEmployeeByName(PtrToConstEmployee Ptr, int size, char * name)
{
    return searchEmployeeTable(Ptr, size, name, compareEmployeeName);
}

PtrToEmployee searchEmployeeByPhoneNumber(PtrToConstEmployee Ptr, int size, char * phone)
{
    return searchEmployeeTable(Ptr, size, phone, compareEmployeePhoneNumber);
}

PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee Ptr, int size, double salary)
{
    return searchEmployeeTable(Ptr, size, &salary, compareEmployeeSalary);
}