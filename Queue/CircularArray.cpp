//此法用環狀陣列實現，能用的空格為n-1格，以空間換取時間又能利用大部分空間，
//一開始front,rear都從0開始，是因為front這格為空格不能使用，若從-1開始，第0格會被填充元素導致front不為空格

#include<iostream>
using namespace std;
#define MAX 5
//定義Queue類別
class Queue{
private:
    int front;
    int rear;
public:
    Queue(){
        front = 0;  //front"rear皆從零開始，表示有一格不能用
        rear = 0;
    }
    int arr[MAX];

    void enqueue(int val){
        rear = (rear + 1)%MAX;  //以mod運算來實現環狀
        if(rear == front){
            cout<<"Queue is Full";
            if(rear==0){
                rear = MAX - 1;
            }
            else{
                rear = (rear - 1)%MAX;  //若其滿了要回復到原始狀態的rear
            }
            return;
        }
        else{
            arr[rear] = val;
        }
    }

    void dequeue(){
        if(rear == front){
            cout<<"Queue is Empty";
            return;
        }
        else{
            front = (front + 1)%MAX;
        }
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
        return (rear - front)%MAX;
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
    
    
    
    
    
    
    
    















