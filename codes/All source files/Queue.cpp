#include "Queue.h"
#include<bits/stdc++.h>
using namespace std;

template<class T>
Queue<T>::Queue(){
   rear = nullptr;
   fronts = nullptr;
}

template<class T>
Queue<T>::~Queue(){
  MakeEmpty();
}

template<class T>
void Queue<T>::MakeEmpty(){
   Node* temp;
   temp = fronts;
   while(fronts != rear){
    fronts = fronts->next;
    delete temp;
    temp = fronts;
   }
   rear = nullptr;
}

template<class T>
void Queue<T>::Enqueue(T item){
  if(IsFull()) throw FullQueue();

  else{
    Node* newNode = new Node;
    newNode->info = item;
    newNode->next = nullptr;
    if(fronts == nullptr){
        fronts = newNode;
    }
    else{
        rear->next = newNode;
    }
    rear = newNode;
  }
    //cout<<rear->info<<" ";
}

template<class T>
void Queue<T>::Dequeue(T& item){
   if(IsEmpty()) throw EmptyQueue();

   else{
    Node* temp;
    temp = fronts;
    item = fronts->info;
    fronts = fronts->next;
    delete temp;
    if(fronts == nullptr)
        rear = nullptr;
   }
   //cout<<item<<" ";
}

template<class T>
bool Queue<T>::IsFull(){
  Node* temp;
  try{
     temp = new Node;
     delete temp;
     return false;
  }
  catch(bad_alloc &exception){
     return true;
  }
}

template<class T>
bool Queue<T>::IsEmpty(){
   return (fronts == nullptr);
}

