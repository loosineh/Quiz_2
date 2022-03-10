#include <stdio.h>
#include <stdlib.h>
#include "employee.h"

int main(void)
{
    PtrToEmployee searchEmployeeByNumber(const Employee Table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee Table[], int sizeTable, char * nameToFind);
    PtrToEmployee searchEmployeeByPhoneNumber(const Employee Table[], int sizeTable, char * phoneToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee Table[], int sizeTable, double salaryToFind);

    //Defined in employeeTable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr;
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);
    if(matchPtr != NULL)
    {
        printf("Employee ID 1045 is in record %ld\n", matchPtr - EmployeeTable);
    }
    else
    {
        printf("Employee ID is not found in the record\n");
    }
    
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if(matchPtr != NULL)
    {
        printf("Employee Tony Bobcat is in record %ld\n", matchPtr - EmployeeTable);
    }
    else
    {
        printf("Employee Tony Bobcat is not found in the record\n");
    }

    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "909-555-2134");
    if(matchPtr != NULL)
    {
        printf("Employee phone number 909-555-2134 is in record %ld\n", matchPtr - EmployeeTable);
    }
    else
    {
        printf("Employee phone number is not found in the record\n");
    }

    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 6.34);
    if(matchPtr != NULL)
    {
        printf("Employee salary 6.34 is in record %ld\n", matchPtr - EmployeeTable);
    }
    else
    {
        printf("Employee salary is not found in the record\n");
    }
    return EXIT_SUCCESS;
}
