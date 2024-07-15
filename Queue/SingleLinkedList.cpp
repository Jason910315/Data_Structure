//此資料結構Node、Queue皆用Struct實作
#include<iostream>
using namespace std;
#define MAX 100

typedef struct Node{
    int data;
    Node *next;
}Node;

typedef struct Queue{
    int size = 0;
    Node *front;
    Node *rear;
}Queue;

void initQueue(Queue *q){
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(Queue *q,int val){
    Node *t = new Node;  //新節點
    t->data = val;       //新節點的值
    t->next = NULL;      //新節點插到尾端所以next一定指向NULL
    if(q->front == NULL){  //case1，一開始Queue無元素
        q->front = t;
    }
    else{
        q->rear->next = t; //case2，一開始節點有元素，故原先尾端元素的next指向新節點t
    }
    q->rear = t;
    (q->size)++;
}

int dequeue(Queue *q){
    if(q->front == NULL){  //如果原本為空，無元素
        cout<<"Queue is Empty\n";
    }
    else{
        Node *t = new Node;
        t = q->front;
        int item = q->front->data;
        q->front = q->front->next; //case1、2都要執行此步驟
        if(q->front == NULL){  //case1，原本Queue裡無元素，dequeue後rear也要指向NULL
            q->rear = NULL;
        }
        delete t;
        (q->size)--;
        return item;
    }
}

bool IsEmpty(Queue *q){
    return (q->front==NULL && q->rear==NULL);
}

int size(Queue *q){ //與先前不一樣有在strut裡宣告size，在enqueue與dequeue裡都有紀錄size
    return q->size;
}

void printSequential (Queue *q){  //將Queue內容依序列印
    Node *t = new Node;
    t = q->front;
    cout<<"Queue:";
    while(t!=NULL){
        cout<<t->data<<",";
        t = t->next;
    }
    cout<<"\n\n";
}
int main(){
    Queue *q;
    initQueue(q); //初始化Queue，讓頭跟尾都指向NULL

    if (IsEmpty(q)) {
        cout << "Queue is empty.\n\n";
    }
    enqueue(q,24);
    cout << "After push 24: \n";
    printSequential(q);
    enqueue(q,8);
    enqueue(q,23);
    cout << "After push 8, 23: \n";
    printSequential(q);
    dequeue(q);
    cout << "After pop 24: \n";
    printSequential(q);
    return 0;
}



