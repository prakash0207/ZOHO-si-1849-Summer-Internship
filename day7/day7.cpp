#include<iostream>
#include<cstdio>
#include<vector>
#include <functional>
typedef std::function<void()> f_t;
using namespace std;
void displayOptions();

enum deviceType
{
    temperature,
    motion,
    water,
    gas,
    fan,
    light,
    door
};

const char *deviceTypeString[] = {"temperature","motion","water","gas","fan","light","door"};

class Device
{
public:
    deviceType devicetype;
    bool status=false;
    int val=0;
    void onConnect()
    {
        status = true;
    }
    void onDisconnect()
    {
        status = false;
    }
    bool getStatus()
    {
        return status;
    }
    int getVal()
    {
        return val;
    }
    void increaseVal()
    {
        val += 1;
    }
    void DecreaseVal()
    {
        val -= 1;
    }
    void putDeviceType(deviceType dt)
    {
        devicetype = dt;
    }
};



int main()
{
    Device *d = new Device[7];
    int val;
    int status;
    int choice;
    d[0].putDeviceType(temperature);
    d[1].putDeviceType(motion);
    d[2].putDeviceType(water);
    d[3].putDeviceType(gas);
    d[4].putDeviceType(fan);
    d[5].putDeviceType(light);
    d[6].putDeviceType(door);


    do
    {
        //Options to work with
        cout<<"1)Enter to do sensor and device control"<<endl;
        cout<<"2)Enter to do automations"<<endl;
        cout<<"3)Shows status of Sensors"<<endl;
        cout<<"4)Quit"<<endl;
        cin>>choice;
        if(choice == 1)                         //To do all the changes in the value and status of sensors and devices manually
        {
            int choiceSensorSelection;
            int choiceSensorConfiguration;
            do
            {
                cout<<"1)Temperature Sensor"<<endl;
                cout<<"2)Motion Sensor"<<endl;
                cout<<"3)Water level Sensor"<<endl;
                cout<<"4)Gas detection Sensor"<<endl;
                cout<<"5)Fan"<<endl;
                cout<<"6)Light"<<endl;
                cout<<"7)Door"<<endl;
                cout<<"8)Quit"<<endl;
                cin>>choiceSensorSelection;

                if(choiceSensorSelection != 8)
                {
                    displayOptions();
                    cin>>choiceSensorConfiguration;
                    if(choiceSensorConfiguration==1)
                        d[choiceSensorSelection-1].increaseVal();
                    if(choiceSensorConfiguration==2)
                        d[choiceSensorSelection-1].DecreaseVal();
                    if(choiceSensorConfiguration==3)
                        d[choiceSensorSelection-1].onConnect();
                    if(choiceSensorConfiguration==4)
                        d[choiceSensorSelection-1].onDisconnect();
                }
            }
            while(choiceSensorSelection!=8);
        }

        if(choice == 2)                     //To do all the changes in the value and status of sensors and devices Automatically
        {
            string s,s1;
            char stri1[101];
            char stri2[101];
            char ch;
            int valueToChange;
            const char* str;
            cout<<"Type as per syntax for if: <sensor_name> <comparison> <sensor_value>"<<endl;
            cout<<"Type as per syntax for then: <device> <function>\n"<<endl;
            cout<<"sensor_name:- 1)temperature 2)motion 3)water 4)gas"<<endl;
            cout<<"comparison:- 1)< 2)> 3)= "<<endl;
            cout<<"sensor_value:- any number"<<endl;
            cout<<"Devices:- 1)fan 2)light 3)door"<<endl;
            cout<<"functions:- 1)turnon 2)turnof\n"<<endl;
            cout<<"Note: Motion and gas can only do detection work hence for comparison '=' must be used and for sensor value\n if it is detected then 1, if it is not detected then 0 must be provided"<<endl;
            cin.get();
            getline(cin,s);
            str = s.c_str();
            sscanf(str,"%99s %c %d", stri1,&ch,&valueToChange);
            vector<string> ifSyntax ;                                                         //Vector is used for the syntax
            string str1;
            str1 = stri1;
            string str2;
            str2 = ch;
            ifSyntax.push_back(str1);
            ifSyntax.push_back(str2);

            getline(cin,s1);
            str = s1.c_str();
            sscanf(str,"%99s %99s", stri1,stri2);
            str1 = stri1;
            str2 = stri2;
            ifSyntax.push_back(str1);
            ifSyntax.push_back(str2);

            //Lambda function to for less than condition
            auto checkerForLessthan = [&]()
    		{
    		    if(ifSyntax[1]== "<" )
    		    {
    		        for(int j=0;j<7;j++)
                    {
                       if(ifSyntax[0] == deviceTypeString[d[j].devicetype])
                       {
                           if(d[j].getVal()<valueToChange)
                           {
                                if(ifSyntax[2]=="fan" && ifSyntax[3] == "turnon")
                                    d[4].onConnect();
                                if(ifSyntax[2]=="fan" && ifSyntax[3] == "turnof")
                                    d[4].onDisconnect();
                                if(ifSyntax[2]=="light" && ifSyntax[3] == "turnon")
                                    d[5].onConnect();
                                if(ifSyntax[2]=="light" && ifSyntax[3] == "turnof")
                                    d[5].onDisconnect();
                                if(ifSyntax[2]=="door" && ifSyntax[3] == "turnon")
                                    d[6].onConnect();
                                if(ifSyntax[2]=="door" && ifSyntax[3] == "turnof")
                                    d[6].onDisconnect();
                           }
                       }
                    }
    		    }

    		};
    		//Lambda function for greater than condition
    		auto checkerForGreaterthan = [&]()
    		{
    		    if(ifSyntax[1]== ">")
                {
                    for(int j=0;j<7;j++)
                    {
                       if(ifSyntax[0] == deviceTypeString[d[j].devicetype])
                       {
                           if(d[j].getVal()>valueToChange )
                           {
                               if(ifSyntax[2]=="fan" && ifSyntax[3] == "turnon")
                                    d[4].onConnect();
                                if(ifSyntax[2]=="fan" && ifSyntax[3] == "turnof")
                                    d[4].onDisconnect();
                                if(ifSyntax[2]=="light" && ifSyntax[3] == "turnon")
                                    d[5].onConnect();
                                if(ifSyntax[2]=="light" && ifSyntax[3] == "turnof")
                                    d[5].onDisconnect();
                                if(ifSyntax[2]=="door" && ifSyntax[3] == "turnon")
                                    d[6].onConnect();
                                if(ifSyntax[2]=="door" && ifSyntax[3] == "turnof")
                                    d[6].onDisconnect();
                           }
                       }
                    }
                }
    		};

            //Lambda function for equal to condition
    		auto checkerForEqual = [&]()
    		{
    		    if(ifSyntax[1]== "=")
                {
                    for(int j=0;j<7;j++)
                    {
                       if(ifSyntax[0] == deviceTypeString[d[j].devicetype])
                       {
                           if(d[j].getVal()==valueToChange)
                           {
                               if(ifSyntax[2]=="fan" && ifSyntax[3] == "turnon")
                                    d[4].onConnect();
                                if(ifSyntax[2]=="fan" && ifSyntax[3] == "turnof")
                                    d[4].onDisconnect();
                                if(ifSyntax[2]=="light" && ifSyntax[3] == "turnon")
                                    d[5].onConnect();
                                if(ifSyntax[2]=="light" && ifSyntax[3] == "turnof")
                                    d[5].onDisconnect();
                                if(ifSyntax[2]=="door" && ifSyntax[3] == "turnon")
                                    d[6].onConnect();
                                if(ifSyntax[2]=="door" && ifSyntax[3] == "turnof")
                                    d[6].onDisconnect();
                           }
                       }
                    }
                }
    		};








            //The above conditioned lambda functions are stored in vector functions
    		vector<f_t> *renderFunctions = new vector<f_t>;
            f_t x = checkerForLessthan;
            f_t y = checkerForGreaterthan;
            f_t z = checkerForLessthan;
            renderFunctions->push_back(x);
            renderFunctions->push_back(y);
            renderFunctions->push_back(z);
            vector<f_t>::iterator it;
            //Automatic Execution of all three while keypressed
            for ( it = renderFunctions->begin() ; it != renderFunctions->end(); ++it )
            {
                (*it)();
            }

        }
        if(choice == 3)
        {
            cout<<"If status 1 then On else Off"<<endl;
            cout<<"SENSORS        STATUS        Value"<<endl;
            cout<<"-------        ------        -----"<<endl;
            cout<<"Temperature    "<<d[0].getStatus()<<"             "<<d[0].val<<endl;
            cout<<"Motion         "<<d[1].getStatus()<<"             "<<d[1].val<<endl;
            cout<<"Water          "<<d[2].getStatus()<<"             "<<d[2].val<<endl;
            cout<<"Gas            "<<d[3].getStatus()<<"             "<<d[3].val<<endl;
            cout<<"---------------------------------------"<<endl;
            cout<<"DEVICES        STATUS"<<endl;
            cout<<"-------        ------"<<endl;
            cout<<"Fan            "<<d[4].getStatus()<<endl;
            cout<<"Light          "<<d[5].getStatus()<<endl;
            cout<<"Door           "<<d[6].getStatus()<<endl;
        }
    }
    while(choice != 4);
}


void displayOptions()
{
    cout<<"1)Increase Value"<<endl;
    cout<<"2)Decrease Value"<<endl;
    cout<<"3)Connect Device"<<endl;
    cout<<"4)Disconnect Device"<<endl;
}



