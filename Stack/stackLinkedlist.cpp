#include<iostream>
using namespace std;
#define MAX 100
//定義Node結構作為Stack的節點
struct Node{
    int data;
    Node *next;
};

class Stack{
private:
    Node *top;
public:
    Stack(){  //建構子，剛創建Stack時無元素，故top = NULL
        top = NULL;
    }
    bool isEmpty(){
        return (top == NULL);
    }

    void push(int val){
        struct Node *newNode = new struct Node; //創建新Node儲存新增元素
        newNode->data = val;
        newNode->next = top;
        top = newNode;
        return;
    }

    void pop(){
        if(top == NULL){
            cout<<"Stack is Empty\n";
            return;
        }
        else{
            Node *t = top;
            top = top->next;
            delete t;
        }
    }

    int Top(){
        return top->data;
    }

    int size(){
        int count = 0;
        Node *ptr = top;
        while(ptr!=NULL){
            ptr = ptr->next;
            count++;
        }
        return count;
    }
};

int main(){
    Stack s;
    s.pop();
    s.push(14);
    s.push(9);
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.size() << std::endl;
    s.push(7);
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.size() << std::endl;
    s.pop();
    s.pop();
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.size() << std::endl; 
    s.pop();
    std::cout << "\ntop: " << s.Top() << "\nsize: " << s.size() << std::endl;
    return 0;
}