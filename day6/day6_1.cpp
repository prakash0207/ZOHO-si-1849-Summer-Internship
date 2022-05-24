#include <iostream>
#include <exception>
using namespace std;

class MyException : public exception
{
private:
    char * message;
public:
    MyException(char * msg) : message(msg)
    {
        cout<<"MyException[" <<msg<<"]."<<endl;
    }
    char * what ()
    {
        return message;
    }
};

int main()
{
    int a,b;
    //Division by zero:
    try
    {
        a=5;
        b=0;
        if(b==0)
        {
            throw MyException("Invalid division");
        }

    }
    catch (MyException myex)
    {
        cout << myex.what() <<endl;
    }

    //Creation of heap memory variable
    try
    {
        long long d = 1000000000000000;
        if(d > 0x88ffffff)
        {
            throw MyException("Memory is compromised!");
        }
        int *arr = new int[d];
    }
    catch (MyException myex)
    {
        cout << myex.what()<<endl;
    }

    //Accessing an invalid index in string
    try
    {
        string s = "prakash";
        if(typeid(s)!= typeid(a))
        {
            throw MyException("Format mismatch");
        }
        s = a;
    }
    catch (MyException myex)
    {
        cout << myex.what()<<endl;
    }

    //Accessing an invalid index in String
    try
    {
        cout<<"Enter a String value: ";
        string s;
        int index;
        cin>>s;
        cout<<"Enter Index: ";
        cin>>index;

        if(index<0 || index>s.size())
        {
            throw MyException("Index is invalid");
        }
        char ch = s[index];

    }
    catch (MyException myex)
    {
        cout << myex.what()<<endl;
    }

    //Accessing an invalid index in Array
    try
    {
        cout<<"Enter the size of array: ";
        int sizeArray;
        cin>>sizeArray;
        int arr[sizeArray];
        cout<<"Enter the values in array: ";
        for(int i=0;i<sizeArray;i++)
        {
            cin>>arr[i];
        }
        int index;
        cout<<"Enter the index: ";
        cin>>index;

        if(index<0 || index>sizeof(arr)/sizeof(int))
        {
            throw MyException("Index is invalid");
        }
        int val = arr[index];
    }
    catch (MyException myex)
    {
        cout << myex.what()<<endl;
    }

    //Exceptions other than mentioned above
    try
    {
        throw MyException("");
    }
    catch (int error)
    {
        cout << "Error: " << error << endl;
    }
    catch (...)
    {
        cout << "Exception encountered" << endl;
    }

    cout<<"Exception Handling Accomplished";

}
