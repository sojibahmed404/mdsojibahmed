#include<bits/stdc++.h>
using namespace std;

class Stack
{
public:
    vector<int>x;

    void push(int value)
    {
        x.push_back(value);
    }

    void pop()
    {
        x.pop_back();
    }

    void top()
    {
        cout<<"Element are in stack : "<<x.back()<<endl;
    }

    int size()
    {
        return x.size();
    }

    bool empty()
    {
        if(x.size()==0) return true;
        return false;
    }
};

int main()
{
    Stack s;

    s.push(500);
    s.push(400);
    s.push(300);
    s.push(200);
    s.push(100);

    cout<<"Stack Size is : "<<s.size()<<endl;

    while(s.empty()==false)
    {
        s.top();
        s.pop();
    }
    return 0;
}
