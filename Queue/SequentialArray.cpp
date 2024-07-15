#include<iostream>
using namespace std;
#define MAX 100
//定義Queue類別
class Queue{
private:
    int front;
    int rear;
public:
    Queue(){
        front = -1;
        rear = -1;
    }
    int arr[MAX];

    void enqueue(int val){
        if(rear == MAX-1){
            cout<<"Queue is Full\n";
        }
        else {arr[++rear] = val;}
    }

    void dequeue(){
        if(rear == front){
            cout<<"Queue is Empty\n";
        }
        else{front++;}
    }

    bool IsEmpty(){
        return (rear==front);
    }

    int getRear(){
        return arr[rear];
    }
    int getFront(){
        return arr[front+1];
    }

    int size(){
        return (rear - front);
    }

};

void printSequentialQueue (Queue queue){
    cout << "front: " << queue.getFront() << "    back: " << queue.getRear() << "\n"
    << " number of elements: " << queue.size() << "\n\n";
}
int main(){

    Queue q;
    if (q.IsEmpty()) {
        cout << "Queue is empty.\n\n";
    }
    q.enqueue(24);
    cout << "After push 24: \n";
    printSequentialQueue(q);
    q.enqueue(8);
    q.enqueue(23);
    cout << "After push 8, 23: \n";
    printSequentialQueue(q);
    q.dequeue();
    cout << "After pop 24: \n";
    printSequentialQueue(q);
    return 0;
}