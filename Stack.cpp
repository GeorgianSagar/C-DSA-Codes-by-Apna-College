#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

// Implementation of Stack using Array/Vector
class Stack
{
    vector<int> v;

public:
    void push(int val)
    {
        v.push_back(val);
    }

    void pop()
    {
        v.pop_back();
    }

    int top()
    {
        return v[v.size() - 1];
    }

    bool empty()
    {
        return v.size() == 0;
    }
};

// Implementation of Stack using Linked List
class Stack
{
    list<int> ll;

public:
    void push(int val)
    {
        ll.push_front(val);
    }

    void pop()
    {
        ll.pop_front();
    }

    int top()
    {
        return ll.front();
    }

    bool empty()
    {
        return ll.size() == 0;
    }
};

int main()
{
    Stack s;      // for implementing using Vector and Linked List
    stack<int> s; // using STL

    s.push(10);
    s.push(20);
    s.push(30);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}