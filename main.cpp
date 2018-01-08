#include <iostream>
#include <list>

using namespace std;

template <class T>
class stiva
{
private:
    list <T> data;
protected:

public:
    bool empty()
    {
        return data.empty();
    }

    void push (const T &item)
    {
        data.push_back(item);
    }

    T top()
    {
        return data.back();
    }

    void pop()
    {
        data.pop_back();
    }
};

int main()
{
    stiva<int> a;

    a.push(1); //adaug 1
    cout<<a.top()<<" "; //afisez ultimul element (1)
    a.push(5); //adaug 5
    cout<<a.top()<<" "; //afisez ultimul element (5)
    a.pop(); //sterg ultimul element
    cout<<endl<<a.empty()<<" "; //verific daca stiva e goala (trebuie sa afiseze 0)
    a.pop(); //sterg ultimul element din nou
    cout<<a.empty(); //verific daca stiva este goala (trebuie sa afiseze 1)

    return 0;
}
