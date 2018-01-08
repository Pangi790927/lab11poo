#include <iostream>
#include <vector>

using namespace std;

template <typename T>

class Stiva
{
    private:
        vector<T> arr;

    public:

        bool Empty()
        {
            return arr.empty();
        }

        void push(const T &element)
        {
            arr.push_back(element);
        }

        void pop()
        {
            if (arr.empty()==0)
                arr.pop_back();
            else
                cout<<"\nStiva este goala";
        }

        T& top()
        {
            if (arr.empty()==0)
                return arr.back();
            else
                cout<<"\nStiva este goala.";
        }

        void print()
        {
            int i;
            for(i=arr.size()-1; i>=0; i--)
                cout<<arr.at(i)<<endl;
        }
};

int main()
{
    Stiva<int> _stiva;

    _stiva.push(7);
    _stiva.push(-5);
    _stiva.push(0);
    _stiva.print();
    cout<<endl;
    _stiva.pop();
    _stiva.print();
    cout<<"element din varf:"<<endl;
    cout<<_stiva.top();



    return 0;
}
