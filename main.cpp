#include <iostream>
#include <vector>

using namespace std;

template <typename T>

class Stack
{
    private:
        vector<T> v;

    public:
        bool Empty()
        {
            return v.empty();
        }

        void push(const T &item)
        {
            v.push_back(item);
        }

        void pop()
        {
            if (v.empty()==0)
                v.pop_back();
            else
                cout<<"\nStiva este goala!";
        }

        T& top()
        {
            if (v.empty()==0)
                return v.back();
            else
                cout<<"\nStiva este goala!";
        }

        void afisare()
        {
            int i;
            for(i=v.size()-1; i>=0;i--)
                cout<<v.at(i)<<endl;
        }
};

int main()
{
    Stack<int> s;

    if( s.Empty()==1)
        cout<<"Stiva este goala.";
    else
        cout<<"Stiva nu este goala.";

    cout<<"\nAdaug in stiva elementele: 10, 4, -2, 1\n";
    s.push(10);
    s.push(4);
    s.push(-2);
    s.push(1);
    s.afisare();
    cout<<"\nVarful stivei: ";
    cout<<s.top();
    cout<<"\n\nEliminarea ultimului element din stiva:\n";
    s.pop();
    s.afisare();
    cout<<"mateighei";

    return 0;
}
