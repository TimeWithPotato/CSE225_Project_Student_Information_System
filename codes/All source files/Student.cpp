#include<bits/stdc++.h>
#include"Student.h"
using namespace std;

Student::Student(){
  id =0;
  semester = 0;
  name ="";
  department = "";
  email = "";
  cgpa = 0;
  credit = 0;
}
Student::Student(int& id,int& semester,string& name,string& department, string& email, double& cgpa, double& credit){
   this->id = id;
   this-> semester = semester;
   this->name = name;
   this->department = department;
   this->email = email;
   this-> cgpa = cgpa;
   this->credit = credit;
}

bool Student:: operator == (Student& stud){
  return id == stud.id;
}

bool Student:: operator < (Student& stud){
   return id < stud.id;
}

bool Student:: operator != (Student& stud){
  return id != stud.id;
}


bool Student:: operator > (Student& stud){
   return credit > stud.credit;
}

bool Student:: operator >= (Student& stud){
   return  credit >= stud.credit;
}

int Student:: GetID(){
  return id;
}

int Student:: GetSemester(){
  return semester;
}

string Student:: GetName(){
  return name;
}

string Student:: GetDepartment(){
  return department;
}

string Student:: GetEmail(){
  return email;
}

double Student::GetCgpa(){
 return cgpa;
}

double Student::GetCredit(){
 return credit;
}


ostream& operator << (ostream& os, Student& stud){

 os << "\nID: "<<stud.id<<"\nSemester: "<<stud.semester<<"\nName: "<<stud.name<<"\nDepartment: "<<stud.department<<"\nEmail: "<<stud.email<<fixed<<setprecision(2)<<"\nCGPA: "<<stud.cgpa<<"\nCredit: "<<stud.credit<<endl;

}

