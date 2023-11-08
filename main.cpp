
///*********************************************************************************
///*****                                                                       *****
///*****        Name: Mohammed Arif Mainuddin                                  *****
///*****        North South University                                         *****
///*****        CSE225 Project                                                 *****
///*****        Fac : MUO                                                      *****
///*****                                                                       *****
///*********************************************************************************

#include<bits/stdc++.h>
#include <conio.h>
#include"SortedType.h"
#include"SortedType.cpp"
#include"DSortedList.h"
#include"DSortedList.cpp"
#include"Queue.h"
#include"Queue.cpp"
#include"QueType.h"
#include"QueType.cpp"
#include"Student.h"
using namespace std;


///************************************ password is CarloAncelotti ****************************************************



///Here I have created a similar type to the private member of Student class's structure, since Student class's structure is private
struct clone{
 int id,semester;
 string name,department,email;
 double cgpa,credit;
};


///One global variable that will tell if List is sorted by credit or not
bool sortedByCredit = false;


///Function definition of printMsg() that will print he message at the very first time of program beginning
void const printMsg()
{
   cout<<"---------------------------------------Assalamualaikum--------------------------------------------";
}


///*********************************************************************************
///*****                                                                       *****
///*****             All function's prototype                                  *****
///*****                                                                       *****
///*********************************************************************************

bool login();
int menu();
template<class T>
void Insertion(SortedType<T>& ob, DSortedList<T>& dob);
template<class T>
void print(SortedType<T>& ob);
template<class T>
void printDSort(DSortedList<T>& dob);
template<class T>
void SearchStudentByID(SortedType<T>& ob);
template<class T>
void DeleteStudentByID(SortedType<T>& ob, DSortedList<T>&dob);
template<class T>
void SortByCredit(DSortedList<T>& dob);
template<class T>
void GenerateReportByID(SortedType<T>& ob, Queue<T>& ob1);
template<class T>
void GenerateReportByCredit(DSortedList<T>& dob, QueType<T>& dob1);

template<class T>
void OutputManipulation(SortedType<T>& ob,Queue<T>& ob1);
///End of all function's prototype





///*********************************************************************************
///*****                                                                       *****
///*****                                main()                                 *****
///*****                                                                       *****
///*********************************************************************************

int main(){
  printMsg();
  bool flag = login();
    if(!flag) {
        cout<<"Oopps! Wrong password.\n";
        return 0;
    }
    system("CLS");
 //Student stud;
 SortedType<Student> ob;        /// so that I can sorted the list by ID, this SortedList implemented using Linked List

 Queue<Student> ob1;           /// To save the information of student from ob into the file(named Report_By_ID), this Queue implemented using Linked List

 DSortedList<Student> dob;    /// so that I can sorted the list by credit, also this DSortedList implemented using Array

 QueType<Student> dob1;       /// To save the information of student from dob into the file(named Report_By_Credit), this QueType implemented using Array


 int n;
 bool loop = true;
 while(loop){

    n = menu();              /// Here menu is the function, that will contain all kind of instruction that I can do on this project

    switch(n){
       case 1 : Insertion(ob,dob);
       break;

       case 2 : SearchStudentByID(ob);
       break;

       case 3 : DeleteStudentByID(ob,dob);
       break;

       case 4 : print(ob);
       break;
       case 5 : SortByCredit(dob);    /// This function may store repetitive information for equal credit if this function invoke more then one,
                                         /// since I have overloaded the operator >= to compare the credit
                                         /// All overloaded operation is in the Student class
       break;
       case 6 : GenerateReportByID(ob, ob1);
       break;
       case 7 : GenerateReportByCredit(dob,dob1);  /// This function will use SortByCredit()
       break;

       default :{
          cout<<"---------------------- Thank You --------------------------\n                       \nAllah Hafez!                            "<<endl;
          loop = false;
       }


    }
 }
}



///*********************************************************************************
///*****                                                                       *****
///*****             Definition of all function's start from here              *****
///*****                                                                       *****
///*********************************************************************************


/// ------------------------  menu() ---------------------------------


int menu(){
    cout<<"\n\nEnter your choice from below: \n";
    cout<<"1. Insert new Student\n"<<"2. Search Student by ID\n"<<"3. Delete Student by ID\n"<<"4. Print Student Information\n"<<"5. Sort By Credit\n"<<"6. Generate report by ID\n"<<"\n7. Generate report by credit\n";
    int n;
    cout<<"------------------------------------------------------------------------\n";
    cin>>n;
switch(n){
  case 1 :
       return 1;
  case 2 :
       return 2;
  case 3 :
       return 3;
  case 4 :
       return 4;
  case 5 :
       return 5;
  case 6 :
       return 6;
  case 7 :
       return 7;
  default :
         return -1;

    }


}


///-----------------------  Insertion -----------------------------


template<class T>
void Insertion(SortedType<T>& ob, DSortedList<T>& dob){
  cout<<"How many student you want to add ?: \n";
  int n;
  cin>>n;

    for (int i = 1; i <=n; i++) {
        clone cl;

        if(i == 2) cout << "Enter the information of " << i << "nd student" << endl;
        else if(i == 3) cout << "Enter the information of " << i << "rd student" << endl;
        else if(i == 1) cout << "Enter the information of " << i << "st student" << endl;
        else cout << "Enter the information of " << i << "th student" << endl;
        cout << "Enter the ID: ";
        cin >> cl.id;
        cout << "Enter the Semester no: ";
        cin >> cl.semester;
        cin.ignore();
        cout << "Enter the name: ";
        getline(cin, cl.name);
        cout << "Enter the department: ";
        getline(cin, cl.department);
        cout << "Enter the email: ";
        cin >> cl.email;
        cout << "Enter the cgpa: ";
        cin >> cl.cgpa;
        cin.ignore();
        cout << "Enter the completed credit: ";
        cin >> cl.credit;
        cin.ignore();

        Student stud(cl.id, cl.semester, cl.name, cl.department, cl.email, cl.cgpa, cl.credit);
        ob.InsertItem(stud);
        dob.InsertItem(stud);
    }
  system("CLS");
  cout<<"Inserted Successfully\n";
}


/// ------------------------------------------- print ---------------------------------------

template<class T>
void print(SortedType<T>& ob){
 system("CLS");
 T value;
 ob.ResetList();
 int n = ob.LengthIs();
 while(n--){
    ob.GetNextItem(value);
    cout<<value<<endl;
 }
 ob.ResetList();

}


/// ------------------------------------------ Search Student By ID -------------------------------

template<class T>
void SearchStudentByID(SortedType<T>& ob){
    system("CLS");
    T value;
    clone cl;
    bool found = false;

    cout << "Enter ID: ";
    cin >> cl.id;
    T obj(cl.id,cl.semester,cl.name,cl.department,cl.email,cl.cgpa,cl.credit);

    int n = ob.LengthIs();
    ob.ResetList();

    while (n--) {
        ob.GetNextItem(value);
        if ( obj == value) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Student found! Details of the student:" << endl;
        cout << value << endl;
    } else {
        cout << "ID " << cl.id << " not found." << endl;
    }
    ob.ResetList();
}


/// ----------------------------- Delete Student By ID -----------------------------------


template<class T>
void DeleteStudentByID(SortedType<T>& ob, DSortedList<T>& dob){
   system("CLS");
   clone cl;

   cout<<"Enter the ID to delete: "; cin>>cl.id;
   T value(cl.id,cl.semester,cl.name,cl.department,cl.email,cl.cgpa,cl.credit);
   ob.DeleteItem(value);
   int sizeOf = dob.LengthIs();
   if(sizeOf>0){
    dob.DeleteItem(value);
   }
   cout<<"Delete Success !\n";
   ob.ResetList();
}



/// --------------------------- Generate Report By ID ----------------------------------


template<class T>
void GenerateReportByID(SortedType<T>& ob, Queue<T>& ob1){
    T value;
    ob.ResetList();
    int n= ob.LengthIs();
    while(n--){
        ob.GetNextItem(value);
        ob1.Enqueue(value);
    }
    ob.ResetList();

    OutputManipulation(ob,ob1);
}


///-------------------------- Output manipulation ------------------------------------------------


template<class T>
void OutputManipulation(SortedType<T>& ob,Queue<T>& ob1){
   system("CLS");
   fstream File;
   File.open("Report_By_ID.txt", ios::out);

   if(File.is_open()){
    int n = ob.LengthIs();
    File<<fixed<<setprecision(2);
    while(n--){
        T nd;
        ob1.Dequeue(nd);
       // string str_id = to_string(nd.id);
        File << nd.GetID() <<endl;
       // string str_semester = to_string(nd.semester);
        File << nd.GetSemester()<<endl;
        File << nd.GetName() << endl;
        File << nd.GetDepartment() << endl;
        File << nd.GetEmail() << endl;
        //string str_cgpa = to_string(nd.cgpa);
        File << nd.GetCgpa() << endl;
        File <<nd.GetCredit()<<endl;
    }

    cout<<"Successfully Updated!\n";
   }
}



///----------------------- Generate Report By Credit -----------------------------


template<class T>
void GenerateReportByCredit(DSortedList<T>& dob, QueType<T>& dob1){
    system("CLS");
  if(sortedByCredit){
     int n = dob.LengthIs();
     for(int i=0; i<n; i++){
        T value;
        dob.GetNextItem(value);
        dob1.Enqueue(value);
     }

         fstream File;
         File.open("Report_By_Credit.txt", ios::out);

         if(File.is_open()){
          while(n--){
           T nd;
           dob1.Dequeue(nd);
           File << nd.GetID() <<endl;
           File << nd.GetSemester()<<endl;
           File << nd.GetName() << endl;
           File << nd.GetDepartment() << endl;
           File << nd.GetEmail() << endl;
           File << nd.GetCgpa() << endl;
           File <<nd.GetCredit()<<endl;
         }
         cout<<"Successfully Updated!\n";
       }

     dob.ResetList();


  }
  else{
    cout<<"You haven't sorted by credit yet\n";
  }
}


/// ----------------------------- Sort By Credit --------------------------

template<class T>
void SortByCredit(DSortedList<T>& dob){
  system("CLS");
  sortedByCredit = true;
  printDSort(dob);

}

///------------------------ print DSort--------------------------------


template<class T>
void printDSort(DSortedList<T>& dob){

 T value;
 int n = dob.LengthIs();
 while(n--){
    dob.GetNextItem(value);
    cout<<value<<endl;
 }
 dob.ResetList();

}



///*************************This login() will cause to abort the program if password is incorrect ************************
bool login() {
    string pass;
    fstream newFile;
    newFile.open("Password.txt", ios::in);

    if (!newFile.is_open()) {
        cout << "\n\nError opening the file." << endl;
        return false;
    }

    getline(newFile, pass);
    newFile.close();
    cout << "\n\nEnter password (echoed with $ signs): ";

    string enteredPass;

    char inputChar;
    while (true) {
        inputChar = _getch();

        if (inputChar == 13) {
            break;
        }
        else if (inputChar == 8 && !enteredPass.empty()) {
            enteredPass.pop_back();
            cout << "\b \b";
        }
        else {
            enteredPass += inputChar;
            cout << '$';
        }
    }



    cout << endl;

    ///The password stored in the password.txt file is in the reverse form
    if (pass != string(enteredPass.rbegin(), enteredPass.rend())) {
        return false;
    }
    /// password is CarloAncelotti
    return true;
}

