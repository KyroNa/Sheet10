// Sheet10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct BlueRay
{
    string title;
    string actress;
    float price;
};

//Problem 2
struct Auto
{
    string Manufacturer;
    int ManufactureYear;
    float price;
};

//Problem 3
struct Student
{
    int id;
    string name;
    int subsc[5];
    int avgsc;
    char grade;
};

//Problem 4
struct Name
{
    string first;
    string middle;
    string last;
};

struct Address
{
    string address1;
    string address2;
    string city;
    int zip_code;
};

struct HiringDate
{
    int day;
    int month;
    int year;
};

struct ContactInfo
{
    int phone;
    int cellphone;
    int fax;
    string email;
};

struct Employee
{
    Name EmpName;
    Address EmpAdd;
    HiringDate EmpHirDate;
    ContactInfo EmpContInfo;
};

void EnterAutoData(Auto car[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Manufacturer of car no. " << i + 1 << ": ";
        getline(cin >> ws, car[i].Manufacturer); //ws here is used to ignore the whitespace from cin >> movie[i].price;
        cout << "Manufacture Year of car no. " << i + 1 << ": ";
        cin >> car[i].ManufactureYear;
        cout << "Price of car no. " << i + 1 << ": ";
        cin >> car[i].price;
        cout << endl;
    }
}

void PrintAutoData(Auto car[], int size, int year)
{
    for (int i = 0; i < size; i++)
    {
        if (year == car[i].ManufactureYear)
        {
            cout << "The car manufactured by " << car[i].Manufacturer << " is manufactured in year " << year << endl;
            cout << "Its price is: " << car[i].price << endl;
        }
    }
}

void ModifyEmployee(Employee CompanyEmployee, int number)
{
    cout << "You are about to modify employee no. " << number << "data. Do you want to proceed?"
        << "\n" << "1: Proceed\n" << "2: Quit\n";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Insert Employee first name" << "\n";
        getline(cin, CompanyEmployee.EmpName.first);
        cout << "Insert Employee middle name" << "\n";
        getline(cin, CompanyEmployee.EmpName.middle);
        cout << "Insert Employee last name" << "\n";
        getline(cin, CompanyEmployee.EmpName.last);
        cout << "Insert Employee Address 1" << "\n";
        getline(cin >> ws, CompanyEmployee.EmpAdd.address1);
        cout << "Insert Employee Address 2" << "\n";
        getline(cin, CompanyEmployee.EmpAdd.address2);
        cout << "Insert Employee City" << "\n";
        getline(cin, CompanyEmployee.EmpAdd.city);
        cout << "Insert Employee Zip Code" << "\n";
        cin >> CompanyEmployee.EmpAdd.zip_code;
        cout << "Insert Employee Hiring Day" << "\n";
        cin >> CompanyEmployee.EmpHirDate.day;
        cout << "Insert Employee Hiring Month" << "\n";
        cin >> CompanyEmployee.EmpHirDate.month;
        cout << "Insert Employee Hiring Year" << "\n";
        cin >> CompanyEmployee.EmpHirDate.year;
        cout << "Insert Employee Phone" << "\n";
        cin >> CompanyEmployee.EmpContInfo.phone;
        cout << "Insert Employee Cellphone" << "\n";
        cin >> CompanyEmployee.EmpContInfo.cellphone;
        cout << "Insert Employee Fax" << "\n";
        cin >> CompanyEmployee.EmpContInfo.fax;
        cout << "Insert Employee Email" << "\n";
        getline(cin >> ws, CompanyEmployee.EmpContInfo.email);
    case 2:
    default:
        break;
    }
}

void AddEmp(Employee CmpEmp[], int size)
{
    int newsize = size++;
    Employee *NewCmpEmp = new Employee[newsize];

    for (int i = 0; i < size; i++)
    {
        NewCmpEmp[i] = CmpEmp[i];
    }
    delete[] CmpEmp;
    CmpEmp = NewCmpEmp;

    cout << "Add new employee data\n";
    cout << "Insert Employee first name" << "\n";
    getline(cin, NewCmpEmp[newsize-1].EmpName.first);
    cout << "Insert Employee middle name" << "\n";
    getline(cin, NewCmpEmp[newsize - 1].EmpName.middle);
    cout << "Insert Employee last name" << "\n";
    getline(cin, NewCmpEmp[newsize - 1].EmpName.last);
    cout << "Insert Employee Address 1" << "\n";
    getline(cin >> ws, NewCmpEmp[newsize - 1].EmpAdd.address1);
    cout << "Insert Employee Address 2" << "\n";
    getline(cin, NewCmpEmp[newsize - 1].EmpAdd.address2);
    cout << "Insert Employee City" << "\n";
    getline(cin, NewCmpEmp[newsize - 1].EmpAdd.city);
    cout << "Insert Employee Zip Code" << "\n";
    cin >> NewCmpEmp[newsize - 1].EmpAdd.zip_code;
    cout << "Insert Employee Hiring Day" << "\n";
    cin >> NewCmpEmp[newsize - 1].EmpHirDate.day;
    cout << "Insert Employee Hiring Month" << "\n";
    cin >> NewCmpEmp[newsize - 1].EmpHirDate.month;
    cout << "Insert Employee Hiring Year" << "\n";
    cin >> NewCmpEmp[newsize - 1].EmpHirDate.year;
    cout << "Insert Employee Phone" << "\n";
    cin >> NewCmpEmp[newsize - 1].EmpContInfo.phone;
    cout << "Insert Employee Cellphone" << "\n";
    cin >> NewCmpEmp[newsize - 1].EmpContInfo.cellphone;
    cout << "Insert Employee Fax" << "\n";
    cin >> NewCmpEmp[newsize - 1].EmpContInfo.fax;
    cout << "Insert Employee Email" << "\n";
    getline(cin >> ws, NewCmpEmp[newsize - 1].EmpContInfo.email);
}

void DeleteEmp(Employee* CmpEmpPtr)
{
    delete CmpEmpPtr;
}

int main()
{
    
    //Problem 1
    BlueRay movie[5];

    for (int i = 0; i < 5; i++)
    {
        cout << "Title of movie " << i + 1 << ": ";
        getline(cin >> ws, movie[i].title); //ws here is used to ignore the whitespace from cin >> movie[i].price;
        cout << "Lead actress of movie " << i + 1 << ": ";
        getline(cin, movie[i].actress);
        cout << "Price of movie " << i + 1 << ": ";
        cin >> movie[i].price;
    }

    float max_price = 0;
    int offset = 0;
    for (int i = 0; i < 5; i++)
    {
        if (movie[i].price > max_price)
        { 
            max_price = movie[i].price;
            offset = i;
        }
            
    }

    cout << "The most expensive movie is " << movie[offset].title << endl;
    

    //Problem 2 are written as function above main 

    /*
    //Problem 3
    const int students_number = 50;
    Student CSE131_Students[students_number];

    for (int i = 0; i < students_number; i++)
    {
        cout << "Insert Student id: ";
        cin >> CSE131_Students[i].id;
        cout << "Insert Student name: ";
        getline(cin >> ws, CSE131_Students[i].name);
        
        int sum = 0;
        for (int j = 0; j < 5; j++)
        {
            cout << "Insert the score of subject " << j + 1 << " :";
            cin >> CSE131_Students[i].subsc[j];
            sum += CSE131_Students[i].subsc[j];
        }

        CSE131_Students[i].avgsc = sum / 5.0;

        if (CSE131_Students[i].avgsc >= 90)
            CSE131_Students[i].grade = 'A';
        else if (CSE131_Students[i].avgsc >= 80 && CSE131_Students[i].avgsc < 90)
            CSE131_Students[i].grade = 'B';
        else if (CSE131_Students[i].avgsc >= 70 && CSE131_Students[i].avgsc < 80)
            CSE131_Students[i].grade = 'C';
        else if (CSE131_Students[i].avgsc >= 60 && CSE131_Students[i].avgsc < 70)
            CSE131_Students[i].grade = 'D';
        else
            CSE131_Students[i].grade = 'F';
    }

    for (int i = 0; i < students_number; i++)
    {
        cout << "\n" << "Student " << i + 1 << " : \n"
            << "Id: " << CSE131_Students[i].id << "\n"
            << "Name: " << CSE131_Students[i].name << "\n";
        for (int j = 0; j < 5; j++)
            cout << "Subject " << j + 1 << " score: " << setfill('0') << setw(3) << CSE131_Students[i].subsc[j] << endl;
        cout << "Average score: " << CSE131_Students[i].avgsc << "\n"
            << "Grade letter: " << CSE131_Students[i].grade << "\n";
    }

    //refer to sheet 8 for sort y name function
    */

    /*
    //Problem 4
    int EmployeeNumber = 100;
    Employee *CompanyEmployees = new Employee[EmployeeNumber];

    for (int i = 0; i < EmployeeNumber; i++)
    {
        cout << "Insert Employee " << i + 1 << " first name" << "\n";
        getline(cin, CompanyEmployees[i].EmpName.first);
        cout << "Insert Employee " << i + 1 << " middle name" << "\n";
        getline(cin, CompanyEmployees[i].EmpName.middle);
        cout << "Insert Employee " << i + 1 << " last name" << "\n";
        getline(cin, CompanyEmployees[i].EmpName.last);
    }
    for (int i = 0; i < EmployeeNumber; i++)
    {
        cout << "Insert Employee " << i + 1 << " Address 1" << "\n";
        getline(cin >> ws, CompanyEmployees[i].EmpAdd.address1);
        cout << "Insert Employee " << i + 1 << " Address 2" << "\n";
        getline(cin, CompanyEmployees[i].EmpAdd.address2);
        cout << "Insert Employee " << i + 1 << " City" << "\n";
        getline(cin, CompanyEmployees[i].EmpAdd.city);
        cout << "Insert Employee " << i + 1 << " Zip Code" << "\n";
        cin >> CompanyEmployees[i].EmpAdd.zip_code;
    }
    for (int i = 0; i < EmployeeNumber; i++)
    {
        cout << "Insert Employee " << i + 1 << " Hiring Day" << "\n";
        cin >> CompanyEmployees[i].EmpHirDate.day;
        cout << "Insert Employee " << i + 1 << " Hiring Month" << "\n";
        cin >> CompanyEmployees[i].EmpHirDate.month;
        cout << "Insert Employee " << i + 1 << " Hiring Year" << "\n";
        cin >> CompanyEmployees[i].EmpHirDate.year;
    }
    for (int i = 0; i < EmployeeNumber; i++)
    {
        cout << "Insert Employee " << i + 1 << " Phone" << "\n";
        cin >> CompanyEmployees[i].EmpContInfo.phone;
        cout << "Insert Employee " << i + 1 << " Cellphone" << "\n";
        cin >> CompanyEmployees[i].EmpContInfo.cellphone;
        cout << "Insert Employee " << i + 1 << " Fax" << "\n";
        cin >> CompanyEmployees[i].EmpContInfo.fax;
        cout << "Insert Employee " << i + 1 << " Email" << "\n";
        getline(cin >> ws, CompanyEmployees[i].EmpContInfo.email);
    }


    */
}

