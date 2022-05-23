#include<iostream>
#include<cmath>
using namespace std;


namespace math
{
    class Mat;                          //Class inside Namespace
    inline namespace hypoten            //Inline Namespace and Nested Namespace
    {
        double val(int a, int b)
        {
            return(sqrt((a*a)+(b*b)));  //Mathematical Equation
        }
    }
}

class math :: Mat
{
public:
    void display()
    {
        cout<<"inside class mat";
    }
};

namespace hypoten = math :: hypoten;    //The Nested namespace is aliased

class Call
{
private:
    int aVal,bVal;
    double hyp;
public:
    Call(int a,int b)
    {
        aVal = a;
        bVal = b;
    }
    void cal()
    {
        hyp = hypoten::val(aVal,bVal);                  // The Namespace is imported into a separate class and inline namespace calling is done.
        cout<<"Value Of Hypotenuse is: " << hyp<<endl;
    }
};

int main()
{
    cout<<"A class is created, namespace is imported into the class and mathematical Equation is solved"<<endl;
    Call c(3,4);
    c.cal();
    cout<<endl;

    cout<<"A class is created inside namespace and called into main successfully"<<endl;
    math::Mat M;
    M.display();
    cout<<endl;

}
