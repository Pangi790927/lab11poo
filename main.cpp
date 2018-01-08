#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

template <typename T>
class Stack
{
private:
    list<T> a;

public:
    bool emptyStack()
    {
        return a.empty();
    }
    void push(const T &item)
    {
        a.push_back(item);
    }
    T top()
    {
        if(a.empty())
        {
            cout<<"Eroare";
            return NULL;
        }
        return a.back();
    }
    void pop()
    {
        if( a.empty())
            return;
        a.pop_back();
    }
    void printStack()
    {
        for (std::list<int>::iterator it=a.begin(); it!=a.end(); ++it)
    std::cout << ' ' << *it;
    }

};


int main()
{
Stack<int> stiven;
cout<<"Elementele stivei sunt: ";
stiven.printStack();
cout<<"\n";
cout<<"Este stiva goala?(1/0): ";
cout<<stiven.emptyStack()<<"\n";
stiven.push(1);
stiven.push(2);
stiven.push(3);
stiven.push(4);
cout<<"Elementele stivei sunt: ";
stiven.printStack();
cout<<"\n";
cout<<"Este stiva goala?(1/0): ";
cout<<stiven.emptyStack()<<"\n";
cout<<"Cel mai recent element adaugat este: ";
cout<<stiven.top()<<"\n";
stiven.pop();
stiven.pop();
cout<<"Elementele stivei sunt: ";
stiven.printStack();
cout<<"\n";
cout<<"Cel mai recent element adaugat este: ";
cout<<stiven.top()<<"\n";
stiven.pop();
stiven.pop();
stiven.pop();
cout<<"Elementele stivei sunt: ";
stiven.printStack();
cout<<"\n";
cout<<"Este stiva goala?(1/0): ";
cout<<stiven.emptyStack()<<"\n";
cout<<"Cel mai recent element adaugat este: ";
cout<<stiven.top()<<"\n";

    return 0;
}
