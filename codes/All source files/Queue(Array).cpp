#include"Queue(Array).h"

template<class ItemType>
QueType<ItemType>::QueType(int MAX)
{
 maxQue = MAX + 1;
 fronts = maxQue - 1;
 rear = maxQue - 1;
 items = new ItemType[maxQue];
}


template<class ItemType>
QueType<ItemType>::QueType()
{
 maxQue = 11;
 fronts = maxQue - 1;
 rear = maxQue - 1;
 items = new ItemType[maxQue];
}

template<class ItemType>
QueType<ItemType>::~QueType()
{
 delete [] items;
}
template<class ItemType>
void QueType<ItemType>::MakeEmpty()
{
 fronts = maxQue - 1;
 rear = maxQue - 1;
}


template<class ItemType>
bool QueType<ItemType>::IsEmpty()
{
 return (rear == fronts);
}
template<class ItemType>
bool QueType<ItemType>::IsFull()
{
 return ((rear+1)%maxQue == fronts);
}


template<class ItemType>
void QueType<ItemType>::Enqueue(ItemType newItem)
{


 rear = (rear +1) % maxQue;
 items[rear] = newItem;

}


template<class ItemType>
void QueType<ItemType>::Dequeue(ItemType& item)
{

 fronts = (fronts + 1) % maxQue;
 item = items[fronts];

}

