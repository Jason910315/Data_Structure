#include<iostream>
using namespace std;
#define MAX 100
//定義Stack類別
class Stack{
private:
    int top;
public:
    int arr[MAX];
    Stack(){
        top = -1;
    }
    void push(int val);
    void pop();
    bool isEmpty();
    int Top();
    int size();
};

//實作Stack的各式方法
void Stack::push(int val){
    if (top == MAX-1){
        cout<<"Stack is full\n";
        return;
    }
    else arr[++top] = val;
}

void Stack::pop(){
    if (top == -1){
        cout<<"Stack is Empty\n";
        return;
    }
    else arr[top--];
}

bool Stack::isEmpty(){
    return (top == -1);
}

int Stack::Top(){
    if (top == -1){
        cout<<"Stack is Empty\n";
        return -1;
    }
    return arr[top];
}
 
int Stack::size(){
    return top + 1;
}

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