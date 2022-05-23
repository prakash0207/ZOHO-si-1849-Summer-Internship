#include<iostream>
#include <cmath>

using namespace std;

//class named Rectangle with members left, top, width, height with int* datatype.
class Rectangle
{
private:
    int *left, *top, *width, *height, *area;
public:

    Rectangle()  //Create a default constructor which initializes all the values with zero
    {
        left = new int(0);
        top = new int(0);
        width = new int(0);
        height = new int(0);
    }
    Rectangle(int w, int h)  // Create a parameterized constructor with parameters width, height. where left, top will be initialized with zero.
    {
        left = new int(0);
        top = new int(0);
        width = new int(w);
        height = new int(h);
    }
    Rectangle(int l, int t, int w, int h)  // Create another parameterized constructor with all values as parameters.
    {
        left = new int(l);
        top = new int(t);
        width = new int(w);
        height = new int(h);
    }


    Rectangle(float l, float t, float w, float h) //  parameterized constructor with all values as parameters with float data type. Float data type should be rounded off to nearest int value and set.
    {
        left = new int(round(l));
        top = new int(round(t));
        width = new int(round(w));
        height = new int(round(h));
    }



    Rectangle(const Rectangle &R) // Write a copy constructor that will copy all the values from one obj to other.
    {
        left = R.left;
        top = R.top;
        width = R.width;
        height = R.height;
        area = new int(*left * *top);
    }

    void display()
    {
        cout<<"Left  is : "  << *left << endl;
        cout<<"Top  is : "  << *top << endl;
        cout<<"Width is : "  << *width << endl;
        cout<<"Height  is : "  << *height << endl;

    }

    void displayArea()
    {
        cout<<"Area  is : "  << *area << endl;
        delete area;        //Deallocation of memory
        delete top;         //Deallocation of memory
        delete width;       //Deallocation of memory
        delete height;      //Deallocation of memory
        delete left;        //Deallocation of memory
    }



    ~Rectangle()
    {
        cout<<"Inside Destructor" <<endl;
    }

};

int main()
{
    cout<<"1. Create a default constructor which initializes all the values with zero. ) " <<endl;
    Rectangle r1();
//    r1.display();
    cout<<endl;

    cout<<"2. Create a parameterized constructor with parameters width, height. where left, top will be initialized with zero."<<endl;
    Rectangle r2(5,2);
    r2.display();
    cout<<endl;

    cout<<"3. Create another parameterized constructor with all values as parameters."<<endl;
    Rectangle r3(5,2,2,5);
    r3.display();
    cout<<endl;

    cout<<"4. Create another parameterized constructor with all values as parameters with float data type."<<endl;
    Rectangle r4(5.2f,1.7f,1.7f,5.3f);
    r4.display();
    cout<<endl;

    cout<<"5. Write a copy constructor that will copy all the values from one obj to other."<<endl;
    Rectangle r5(r4);
    r5.display();
    r5.displayArea();
    cout<<endl;


    return 0;
}
