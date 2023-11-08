#ifndef QUEUE(ARRAY)_H_INCLUDED
#define QUEUE(ARRAY)_H_INCLUDED

template<class ItemType>
class QueType
{
 public:
 QueType();
 QueType(int);
 ~QueType();
 void MakeEmpty();
 bool IsEmpty();
 bool IsFull();
 void Enqueue(ItemType);
 void Dequeue(ItemType&);
 private:
 int fronts;
 int rear;
 ItemType* items;
 int maxQue;
};


#endif // QUEUE(ARRAY)_H_INCLUDED
