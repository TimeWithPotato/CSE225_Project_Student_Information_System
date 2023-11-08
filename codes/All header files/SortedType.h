#ifndef SORTEDTYPE_H_INCLUDED
#define SORTEDTYPE_H_INCLUDED
template<class T>
class SortedType{
   struct NodeType{
      T info;
      NodeType* next;

   };

   public:
       SortedType();
       ~SortedType();
       int LengthIs();
       bool IsFull();
       void MakeEmpty();
       void InsertItem(T);
       void RetrieveItem(T&, bool&);
       void DeleteItem(T);
       void ResetList();
       void GetNextItem(T&);
       //friend void print(timeStamp&);
   private:
    NodeType* listData;
    int length;
    NodeType* currentPos;

};
#endif // SORTEDTYPE_H_INCLUDED
