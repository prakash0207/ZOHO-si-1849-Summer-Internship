#include<iostream>
using namespace std;

//We should have two Base/Parent class named Bank
class Bank
{
public:
    string name,establishedDate,bankType,branchName;
    Bank(string n, string ed, string bt, string bn)
    {
        name = n;
        establishedDate = ed;
        bankType = bt;
        branchName = bn;
    }
    virtual string getName() = 0;               // Virtual Methods for overriding
    virtual string getEstablishedDate() = 0;    // Virtual Methods for overriding
    void getInfo()
    {
        cout<<"Name :" <<name << endl;
        cout<<"Established Date :" <<establishedDate << endl;
        cout<<"bank Type :" <<bankType << endl;
        cout<<"Branch Name :" <<branchName << endl;
    }
};

//We should have two Base/Parent class named Loan
class Loan
{
public:
    string selectedLoan, documentSelected;
    int interestRate;
    Loan(string sl, int ir, string ds)
    {
        selectedLoan = sl;
        interestRate = ir;
        documentSelected = ds;
    }
    virtual string getAvailableLoan() = 0;      // Virtual Methods for overriding
    virtual int getInterestRate() = 0;          // Virtual Methods for overriding
    virtual string documentRequired() = 0;      // Virtual Methods for overriding
};

//Derived class from Bank and Loan
class Hdfc : public Bank,Loan
{
public:
    Hdfc(string na, string esd, string bat, string brn, string sel, int inr, string dos) : Bank(na,esd,bat,brn), Loan(sel,inr,dos) {}

    string getName()    //Method Overriden
    {
        return name;
    }
    string getEstablishedDate() //Method Overriden
    {
        return establishedDate;
    }

    string getAvailableLoan()   //Method Overriden
    {
        return selectedLoan;
    }
    int getInterestRate()   //Method Overriden
    {
        return interestRate;
    }
    string documentRequired()   //Method Overriden
    {
        return documentSelected;
    }

};

//Derived class from Bank and Loan
class Sbi : public Bank,Loan
{
public:
    Sbi(string na, string esd, string bat, string brn, string sel, int inr, string dos) : Bank(na,esd,bat,brn), Loan(sel,inr,dos) {}

    string getName()
    {
        return name;
    }
    string getEstablishedDate()
    {
        return establishedDate;
    }

    string getAvailableLoan()
    {
        return selectedLoan;
    }
    int getInterestRate()
    {
        return interestRate;
    }
    string documentRequired()
    {
        return documentSelected;
    }
};

//Derived class from Bank and Loan
class Icici : public Bank,Loan
{
public:
    Icici(string na, string esd, string bat, string brn, string sel, int inr, string dos) : Bank(na,esd,bat,brn), Loan(sel,inr,dos) {}

    string getName()
    {
        return name;
    }
    string getEstablishedDate()
    {
        return establishedDate;
    }

    string getAvailableLoan()
    {
        return selectedLoan;
    }
    int getInterestRate()
    {
        return interestRate;
    }
    string documentRequired()
    {
        return documentSelected;
    }
};

//Derived class from Bank and Loan
class IndianBank : public Bank,Loan
{
public:
    IndianBank(string na, string esd, string bat, string brn, string sel, int inr, string dos) : Bank(na,esd,bat,brn), Loan(sel,inr,dos) {}

    string getName()
    {
        return name;
    }
    string getEstablishedDate()
    {
        return establishedDate;
    }

    string getAvailableLoan()
    {
        return selectedLoan;
    }
    int getInterestRate()
    {
        return interestRate;
    }
    string documentRequired()
    {
        return documentSelected;
    }
};

//Create a Class named Broker to compare the  interestRate of Banks using overloading
class Broker
{
public:
    int minimum(int a,int b,int c,int d)  //Overloading function
    {
       int mini = a;
       if(mini>b)
       {
           mini = b;
       }
       if(mini>c)
       {
           mini = c;
       }
       if(mini>d)
       {
           mini = d;
       }
       return mini;
    }
    int minimum(int a,int b,int c)      //Overloading function
    {
       int mini = a;
       if(mini>b)
       {
           mini = b;
       }
       if(mini>c)
       {
           mini = c;
       }
       return mini;
    }
    int minimum(int a,int b)        //Overloading function
    {
       int mini = a;
       if(mini>b)
       {
           mini = b;
       }
       return mini;
    }
    int minimum(int a[],int n)
    {
        int small = a[0];
        for(int i=1;i<n;i++)
        {
            if(a[i]<small)
            {
                small = a[i];
            }
        }
        return small;
    }
};

int main()
{
    Hdfc bank1("HDFC","01/01/2001","Private","Madurai","Gold Loan",13,"Adhar Card");
    Sbi bank2("SBI","01/01/2001","Public","Chennai","Land Loan",10,"Pan Card");
    Icici bank3("ICICI","01/01/2001","Private","Coimbatore","Personal",9,"Adhar Card");
    IndianBank bank4("Indian Bank","01/01/2001","Public","Virudunagar","Gold Loan",12,"Pan Card");

    Broker b1;
    int mini;
    int interestRateArray[4];
    int nVal;
    interestRateArray[0] = bank1.getInterestRate();
    interestRateArray[1] = bank2.getInterestRate();
    interestRateArray[2] = bank3.getInterestRate();
    interestRateArray[3] = bank4.getInterestRate();

    mini = b1.minimum(interestRateArray[0],interestRateArray[1],interestRateArray[2],interestRateArray[3]);     //Compare Bank Interest rate and Display the bank which has low interest rate
    cout<<"Lowest Interest rate among the 4 banks is: " << mini <<endl;

    mini = b1.minimum(interestRateArray[1],interestRateArray[2],interestRateArray[3]);       //Compare three banks loan rates
    cout<<"Lowest Interest rate among the 3 banks is: " << mini <<endl;

    mini = b1.minimum(interestRateArray[1],interestRateArray[0]);         //Compare two banks loan rates
    cout<<"Lowest Interest rate among the 2 banks is: " << mini <<endl;

    cout<<"Enter n banks to be compared: ";
    cin>>nVal;

    mini = b1.minimum(interestRateArray,nVal);      //Compare n banks with an array parameter.
    cout<<"Lowest Interest rate among "<<nVal<<" banks is: "<<mini<<endl;

    //1. Print the Details of single bank
    cout<<endl;
    cout<<"Details of single Bank:-"<<endl;
    bank1.getInfo();
    cout<<endl;

    //2. Print the details of the multiple banks
    cout<<"Details of all Bank:-"<<endl;
    bank1.getInfo();
    cout<<endl;
    bank2.getInfo();
    cout<<endl;
    bank3.getInfo();
    cout<<endl;
    bank4.getInfo();
    cout<<endl;

}
