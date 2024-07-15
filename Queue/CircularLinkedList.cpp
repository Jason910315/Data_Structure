//此Queue使用CircularLinkedList實作，只需使用一個rear指標即可實現rear、front

#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    Node *next;
}Node;

class Queue{
private:
    Node *rear = new Node;
    int size;
public:
    Queue(){
        rear = NULL;
        size = 0;
    }
    void enqueue(int val);
    int dequeue();
    bool IsEmpty();
    int getSize();
    void printSequential();
};

void Queue::enqueue(int val){
    Node *t = new Node;
    t->data = val;
    if(rear == NULL){  //case1，一開始無元素
        t->next = t;   //新節點指回自己
    }
    else{              //case2，Queue有多個元素
        t->next = rear->next;  //rear->next即為front，新節點t成為新尾端
        rear->next = t;
    }
    rear = t;
    size++;
}

int Queue::dequeue(){  //注意dequeue是刪除front元素，此處front為rear->next
    Node *t = new Node;
    t = rear->next;  //front元素
    int item = t->data;
    if(rear->next == rear){ //case1，原先Queue裡只有一個元素
        rear = NULL;
    }
    else{  //case2，有多個元素
        rear->next = rear->next->next; //尾端指向原先front的下一個元素
    }
    delete t;
    size--;
    return item;
}

bool Queue::IsEmpty(){
    return (rear==NULL);
}

int Queue::getSize(){
    return size;
}

void Queue::printSequential (){  //將Queue內容依序列印
    Node *t = new Node;
    t = rear->next;
    cout<<"Queue:";
    while(t!=rear){
        cout<<t->data<<",";
        t = t->next;
    }
    cout<<t->data<<"\n\n";

}

int main(){
    Queue q;

    if (q.IsEmpty()) {
        cout << "Queue is empty.\n\n";
    }
    q.enqueue(24);
    cout << "After push 24: \n";
    q.printSequential();
    q.enqueue(8);
    q.enqueue(23);
    cout << "After push 8, 23: \n";
    q.printSequential();
    int item = q.dequeue();
    cout << "After pop "<<item<< ":\n";
    q.printSequential();
    return 0;
}



