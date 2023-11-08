#include "DSortedList.h"
#include<bits/stdc++.h>
using namespace std;
template <class T>
DSortedList<T>::DSortedList()
{
 length = 0;
 currentPos = - 1;
}


template <class T>
void DSortedList<T>::MakeEmpty()
{
 length = 0;
}


template <class T>
bool DSortedList<T>::IsFull()
{
 return (length == MAX_ITEMS);
}


template <class T>
int DSortedList<T>::LengthIs()
{
 return length;
}


template <class T>
void DSortedList<T>::ResetList()
{
 currentPos = - 1;
}


template <class T>
void DSortedList<T>::GetNextItem(T&
item)
{
 currentPos++;
 item = info [currentPos];
}

template <class T>
void DSortedList<T>::InsertItem(T item)
{
 int location = 0;
 bool moreToSearch = (location < length);
 while (moreToSearch)
 {
 if(item < info[location])
 {
 location++;
 moreToSearch = (location < length);
 }
 else if(item >= info[location])
 moreToSearch = false;
 }
 ///------------------
 if (location < length && item == info[location]){

    cout<<"A student with the same ID already exists. Skipping insertion."<<endl;
 }
 else{
 for (int index = length; index > location; index--){
 info[index] = info[index - 1];
 }
 info[location] = item;
 length++;
 }
}


template <class T>
void DSortedList<T>::DeleteItem(T item)
{
 int location = 0;
 while (item != info[location])
 location++;
 for (int index = location + 1; index < length;
index++)
 info[index - 1] = info[index];
 length--;
}


template <class T>
void DSortedList<T>::RetrieveItem(T& item, bool& found)
{
 int midPoint, first = 0, last = length - 1;
 bool moreToSearch = (first <= last);
 found = false;
 while (moreToSearch && !found)
 {
 midPoint = (first + last) / 2;
 if(item < info[midPoint])
 {
 last = midPoint - 1;
 moreToSearch = (first <= last);
 }
 else if(item > info[midPoint])
 {
 first = midPoint + 1;
 moreToSearch = (first <= last);
 }
 else
 {
 found = true;
 item = info[midPoint];
 }
 }
}

