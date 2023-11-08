#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include<bits/stdc++.h>
using namespace std;
class Student{
    int id,semester;
    string name,department,email;
    double cgpa,credit;
public :
    Student();
    Student(int&,int&,string&,string&,string&,double&,double&);
    //~Student();
    bool operator == (Student&);
    bool operator < (Student&);
    bool operator > (Student&);
    bool operator != (Student&);
    bool operator >= (Student&);
    int GetID();
    int GetSemester();
    string GetName();
    string GetDepartment();
    string GetEmail();
    double GetCgpa();
    double GetCredit();
    friend ostream &operator << (ostream&, Student&);


};

#endif // STUDENT_H_INCLUDED
