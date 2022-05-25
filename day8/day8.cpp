#include<iostream>
using namespace std;

static int mobile_connection_counter=0;
static int landline_connection_counter=0;

//Class for Mobile Connection
class MobileConnection
{
    string mobileNumber;
    int billAmount;
public:
    void putMobileNumber(string mn)
    {
        mobileNumber = mn;
    }
    void putBillAmount(int ba)
    {
        billAmount = ba;
    }
    string getMobileNumber()
    {
        return mobileNumber;
    }
    int getBillAmount()
    {
        return billAmount;
    }
};

//Class for Land line connections
class LandlineConnection
{
    string landlineNumber;
    string stdCode;
    int billAmount;
public:
    void putLandlineNumber(string ln)
    {
        landlineNumber = ln;
    }
    void putStdCode(string sc)
    {
        stdCode = sc;
    }
    void putBillAmount(int ba)
    {
        billAmount = ba;
    }
    string getStdCode()
    {
        return stdCode;
    }
    string getLandlineNumber()
    {
        return landlineNumber;
    }
    int getBillAmount()
    {
        return billAmount;
    }
    string getMobileNumber()
    {
        return stdCode+landlineNumber;
    }

};

template <class T,class U>      //Class Template

// Class to process bill payments.
class BillPayments
{
public:
    MobileConnection mc[101];
    LandlineConnection lc[101];
    void storeConnectionMobile(T mn)                    //Function to store mobile connections
    {
        mc[mobile_connection_counter].putMobileNumber(mn);
        mc[mobile_connection_counter].putBillAmount(1000);
        mobile_connection_counter += 1;
        cout<<"User: "<<mobile_connection_counter<<endl;
        cout<<"Mobile no: "<<mc[mobile_connection_counter-1].getMobileNumber()<<endl;
        cout<<"Bill amount: "<<mc[mobile_connection_counter-1].getBillAmount()<<endl;
    }
    void storeConnectionLandline(T mn)                  //Function to store Land line connections
    {
        T s1,s2;
        s1 = mn.substr(0,4);
        s2 = mn.substr(4,10);
        lc[landline_connection_counter].putStdCode(s1);
        lc[landline_connection_counter].putLandlineNumber(s2);
        lc[landline_connection_counter].putBillAmount(1000);
        landline_connection_counter += 1;
        cout<<"User: "<<landline_connection_counter<<endl;
        cout<<"STD no: "<<lc[landline_connection_counter-1].getStdCode()<<endl;
        cout<<"Mobile no: "<<lc[landline_connection_counter-1].getLandlineNumber()<<endl;
        cout<<"Bill amount: "<<lc[landline_connection_counter-1].getBillAmount()<<endl;

    }

    void payBills(T mn)                                 //Function to pay bills using connection numbers.
    {
        U i;
        U findConnection = 0;
        for(i=0;i<mobile_connection_counter;i++)
        {
            if(mc[i].getMobileNumber() == mn)
                findConnection = 1;
        }
        for(i=0;i<landline_connection_counter;i++)
        {
            if(lc[i].getMobileNumber() == mn)
                findConnection = 2;
        }
        if(findConnection == 1)
        {
            cout<<"It is a Mobile Number"<<endl;
            mc[i].putBillAmount(0);
            findConnection = 0;
            cout<<"Bill Amount: "<<mc[i].getBillAmount()<<endl;
        }
        if(findConnection == 2)
        {
            cout<<"It is a Landline Number"<<endl;
            lc[i].putBillAmount(0);
            findConnection = 0;
            cout<<"Bill Amount: "<<lc[i].getBillAmount()<<endl;
        }

    }
    void updateBills(T mn, U bl)                                //Function to update new bill amount using connection number.
    {
        U i;
        U findConnection = 0;
        for(i=0;i<mobile_connection_counter;i++)
        {
            if(mc[i].getMobileNumber() == mn)
                findConnection = 1;
        }
        for(i=0;i<landline_connection_counter;i++)
        {
            if(lc[i].getMobileNumber() == mn)
                findConnection = 2;
        }
        if(findConnection == 1)
        {
            cout<<"It is a Mobile Number"<<endl;
            mc[i].putBillAmount(mc[i].getBillAmount()+bl);
            findConnection = 0;
            cout<<"Updated Bill Amount: "<<mc[i].getBillAmount()<<endl;
        }
        if(findConnection == 2)
        {
            cout<<"It is a Landline Number"<<endl;
            lc[i].putBillAmount(lc[i].getBillAmount()+bl);
            findConnection = 0;
            cout<<"Updated Bill Amount: "<<lc[i].getBillAmount()<<endl;
        }
    }

};

int main()
{
    BillPayments<string,int> bp;
    int bill;
    int choice;
    string mobileNumber;
    do
    {
        cout<<"1)Add a new mobile connection."<<endl;
        cout<<"2)Add a new landline connection."<<endl;
        cout<<"3)Pay bill using the connection number."<<endl;
        cout<<"4)Update bill amount using the connection number."<<endl;
        cout<<"5)Quit"<<endl;
        cin>>choice;
        if(choice == 1)
        {
            cout<<"Enter the 10 digit mobile number: ";
            cin>>mobileNumber;
            bp.storeConnectionMobile(mobileNumber);
        }
        if(choice == 2)
        {
            cout<<"Enter landline number with the STD code: ";
            cin>>mobileNumber;
            bp.storeConnectionLandline(mobileNumber);
        }
        if(choice == 3)
        {
            cout<<"Enter the connection number to pay bills: ";
            cin>>mobileNumber;
            bp.payBills(mobileNumber);
        }
        if(choice == 4)
        {
            cout<<"Enter the connection number to update bills: ";
            cin>> mobileNumber;
            cout<<"Enter the bill to be updated: ";
            cin>> bill;
            bp.updateBills(mobileNumber,bill);

        }
    }
    while(choice != 5);
    return 0;
}
