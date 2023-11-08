#ifndef QUETYPE_H_INCLUDED
#define QUETYPE_H_INCLUDED
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


#endif // QUETYPE_H_INCLUDED
