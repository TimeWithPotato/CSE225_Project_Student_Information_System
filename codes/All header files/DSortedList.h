#ifndef DSORTEDLIST_H_INCLUDED
#define DSORTEDLIST_H_INCLUDED
#include<bits/stdc++.h>
const int MAX_ITEMS = 501;
template <class T>
class DSortedList
{
 public :
 DSortedList();
 void MakeEmpty();
 bool IsFull();
 int LengthIs();
 void InsertItem(T);
 void DeleteItem(T);
 void RetrieveItem(T&,
bool&);
 void ResetList();
 void GetNextItem(T&);
 private:
 int length;
 T info[MAX_ITEMS] ={};
 int currentPos;
};
#endif // SORTEDTYPE_H_INCLUDED


