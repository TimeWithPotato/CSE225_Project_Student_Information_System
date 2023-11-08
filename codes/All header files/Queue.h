#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
class FullQueue{
    const char* errorMessage;;
public :
    FullQueue(){
      errorMessage = "Queue is Full";
    }
    const char* getErrorMessage() const{
        return errorMessage;
    }
};

class EmptyQueue{
    const char* errorMessage;
    public:
    EmptyQueue(){
      errorMessage = "Queue is Empty";
    }
    const char* getErrorMessage() const{
        return errorMessage;
    }
};
template<class T>
class Queue{
  struct Node{
      T info;
      Node* next;
  };
 Node *rear, *fronts;

 public:
     Queue();
    ~Queue();
    void MakeEmpty();
    void Enqueue(T);
    void Dequeue(T&);
    bool IsEmpty();
    bool IsFull();

};

#endif // QUEUE_H_INCLUDED
