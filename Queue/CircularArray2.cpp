//第二種CircularArray 的作法是能將空間充分利用，陣列的每一格都能存放元素，
//其利用一個Tag來判斷Queue是否滿，因為要多花一道程序判斷Tag真偽，所以以時間換取

#include<iostream>
using namespace std;
#define MAX 5
//定義Queue類別
class Queue{
private:
    int front;
    int rear;
    bool Tag = false;
public:
    Queue(){
        front = 0;  //front"rear皆從零開始
        rear = 0;
    }
    int arr[MAX];

    void enqueue(int val){
        if (rear == front && Tag == true){
            cout<<"Queue is full\n";
        }
        else{
            rear = (rear + 1)%MAX;
            arr[rear] = val;
            if(rear == front){
                Tag = true;
            }
        }
    }

    void dequeue(){
        if(front == rear && Tag == false){
            cout<<"Queue is Empty\n";
        }
        else{
            front = (front + 1)%MAX;
            if (front == rear){
                Tag = false;
            }
        }
    }

    bool IsEmpty(){
        return (rear==front && Tag == false);
    }

    int getRear(){
        return arr[rear];
    }
    int getFront(){
        return (front==rear && Tag == true)?arr[front]:arr[front+1];
    }

    int size(){
        return (front==rear && Tag == true)?MAX:(rear-front)%MAX;
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















