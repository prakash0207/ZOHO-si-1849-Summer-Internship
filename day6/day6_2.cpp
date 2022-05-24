#include<iostream>
#include<exception>
using namespace std;

int main()
{
    try     //Outer try block
    {
        try     //Inner try block
        {
            int *arr = new int[1000000000000000];
        }
        catch(exception &e)
        {
            cout<<"Error Occurred: "<<e.what()<<endl;
            throw;      //Re throwing the exceptions
        }
        int *arr = new int[1000000000000000];

    }
    catch(exception &e)
    {
        cout<<"Error Occurred: "<<e.what()<<endl;
    }
    try
    {
        throw 5;
    }
    catch(...)      //No notable Exceptions
    {
        cout<<"Unknown problem";
    }

}
