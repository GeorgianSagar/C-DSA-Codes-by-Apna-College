#include<iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int currSize, cap;
    int f, r;
public:
    CircularQueue(int size) {
        cap=size;
        arr=new int[cap];
        f= 0;
        r= -1;
        currSize=0;
    }

    void push(int data) {
        if(currSize==cap) {
            cout<<"Queue is full"<<endl;
            return;
        }
        r=(r+1)%cap;
        arr[r]=data;
        currSize++;
    }
    void pop() {
        if(currSize==0) {
            cout<<"Queue is empty"<<endl;
            return;
        }
        f=(f+1)%cap;
        currSize--;
    }
    int front() {
        if(currSize==0) {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[f];
    }
};

int main() {
    CircularQueue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.front()<<endl; // 1
    q.pop();
    cout<<q.front()<<endl; // 2
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7); // Queue is full
    while(q.front() != -1) {
    cout<<q.front()<<endl;
    q.pop();
    if(q.front() == -1) break;
    }
    
    q.pop(); // Queue is empty
    return 0;
}   