// Self implementation of
// the Vector Class in C++
#pragma once
#include <iostream>
using namespace std;
template <typename T>
class Vector
{
private:
    int cap;
    int cur;
    T *arr;

public:
    Vector()
    {
        cap = 1;
        cur = 0;
        arr = new T[1];
    }

    void push_back(T data)
    {
        if (cur == cap)
        {
            T *temp = new T[cap + 5]; //if the cap is reached, create a new vector with 5 more slots and copy the old one in there
            for (int i = 0; i < cap; i++)
            {
                temp[i] = arr[i];
            }
            delete[] arr; //delete the old one
            cap += 5;
            arr = temp;
        }
        arr[cur] = data;
        cur++;
    }

    int size() { return cur; }

    T &operator[](const int i)
    {
        if (i >= 0 && i < cap)
            return arr[i];
        else
        {
            cerr << "you dont got the fasciilties fo that big man";
            exit(1);
        }
    }

    void print()
    {
        for (int i = 0; i < cur; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
// Tester code
// int main()
// {
//     Vector<int> vec;
//     vec.push_back(5);
//     vec.push_back(4);
//     vec.push_back(3);
//     vec.push_back(2);
//     vec.push_back(1);

//     cout << "size: " << vec.size() << endl;
//     cout << "elements: ";
//     vec.print();
//     vec.push_back(2);
//     vec.push_back(3);
//     cout << "elements WITH 2 3 AT THE END: " << endl;
//     vec.print();
//     cout << "new size: " << vec.size();
//     return 0;
// }