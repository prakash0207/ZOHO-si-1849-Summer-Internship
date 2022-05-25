#include<iostream>
#include<cstdio>
#include<vector>
#include <functional>
using namespace std;
void displayOptions();


//Every Sensors and devices as Class
class TemperatureSensor
{
public:
    bool status;
    int val;
    TemperatureSensor(bool st, int v)
    {
        status = st;
        val = v;
    }
    void onConnect()
    {
        status = true;
    }
    void onDisconnect()
    {
        status = false;
    }
    void increaseVal()
    {
        val += 1;
    }
    void DecreaseVal()
    {
        val -= 1;
    }
};


class MotionSensor
{
public:
     bool status, val;
    MotionSensor(bool st,bool val)
    {
        status = st;
    }
    void onConnect()
    {
        status = true;
    }
    void onDisconnect()
    {
        status = false;
    }
    void detect()
    {
        val = true;
    }
    void notDetect()
    {
        val = false;
    }
};

class WaterLevelSensor
{
public:
     bool status;
    int val;
    WaterLevelSensor(bool st, int v)
    {
        status = st;
        val = v;
    }
    void onConnect()
    {
        status = true;
    }
    void onDisconnect()
    {
        status = false;
    }
    void increaseVal()
    {
        val += 1;
    }
    void DecreaseVal()
    {
        val -= 1;
    }
};

class GasDetectionSensor
{
public:
    bool status,val;
    GasDetectionSensor(bool st, bool v)
    {
        status = st;
        val = v;
    }
    void onConnect()
    {
        status = true;
    }
    void onDisconnect()
    {
        status = false;
    }
    void increaseVal()
    {
        val += 1;
    }
    void DecreaseVal()
    {
        val -= 1;
    }
};

class Fan
{
public:
     bool status;
    Fan(bool st)
    {
        status = st;
    }
    void onConnect()
    {
        status = true;
    }
    void onDisconnect()
    {
        status = false;
    }
};

class Light
{
public:
     bool status;
    Light(bool st)
    {
        status = st;
    }
    void onConnect()
    {
        status = true;
    }
    void onDisconnect()
    {
        status = false;
    }
};

class Door
{
public:
    bool status;
    Door(bool st)
    {
        status = st;
    }
    void onConnect()
    {
        status = true;
    }
    void onDisconnect()
    {
        status = false;
    }
};


int main()
{
    TemperatureSensor ts(true,22);
    MotionSensor ms(true, false);
    WaterLevelSensor ws(true, 5);
    GasDetectionSensor gs(true,false);
    Fan fob(false);
    Light lob(false);
    Door dob(false);
    int val;
    int status;
    int choice;


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
            int choice;
            int choice_sim;
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
                cin>>choice;
                if(choice == 1)
                {
                    displayOptions();
                    cin>>choice_sim;
                    if(choice_sim==1)
                        ts.increaseVal();
                    if(choice_sim==2)
                        ts.DecreaseVal();
                    if(choice_sim==3)
                        ts.onConnect();
                    if(choice_sim==4)
                        ts.onDisconnect();
                }
                if(choice == 2)
                {
                    displayOptions();
                    cin>>choice_sim;
                    if(choice_sim==1)
                        ms.detect();
                    if(choice_sim==2)
                        ms.notDetect();
                    if(choice_sim==3)
                        ms.onConnect();
                    if(choice_sim==4)
                        ms.onDisconnect();
                }
                if(choice == 3)
                {
                    displayOptions();
                    cin>>choice_sim;
                    if(choice_sim==1)
                        ws.increaseVal();
                    if(choice_sim==2)
                        ws.DecreaseVal();
                    if(choice_sim==3)
                        ws.onConnect();
                    if(choice_sim==4)
                        ws.onDisconnect();
                }
                if(choice == 4)
                {
                    displayOptions();
                    cin>>choice_sim;
                    if(choice_sim==1)
                        gs.increaseVal();
                    if(choice_sim==2)
                        gs.DecreaseVal();
                    if(choice_sim==3)
                        gs.onConnect();
                    if(choice_sim==4)
                        gs.onDisconnect();
                }
                if(choice == 5)
                {
                    cout<<"1)On"<<endl;
                    cout<<"1)Off"<<endl;
                    cin>>choice_sim;
                    if(choice_sim==1)
                        fob.onConnect();
                    if(choice_sim==2)
                        fob.onDisconnect();
                }
                if(choice == 6)
                {
                    cout<<"1)On"<<endl;
                    cout<<"1)Off"<<endl;
                    cin>>choice_sim;
                    if(choice_sim==1)
                        lob.onConnect();
                    if(choice_sim==1)
                        lob.onDisconnect();

                }
                if(choice == 7)
                {
                    cin>>choice_sim;
                    cout<<"1)Open"<<endl;
                    cout<<"1)Close"<<endl;
                    if(choice_sim==1)
                        dob.onConnect();
                    if(choice_sim==1)
                        dob.onDisconnect();
                }
            }
            while(choice!=8);
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

          //  auto Checker = [&]()     == Normal lambda function
            //store them in vectors of std::function for >,<,= conditions and fire them when activated by keypress and the conditions given in the automation menu is met.
            std::function<void()> Checker = [&]()       //Lambda Function: To check the automatic conditions with std :: function
    		{
    		    if(ifSyntax[0]=="temperature")
    		    {
    		        if(ifSyntax[1]=="<" && ts.val<valueToChange)
                    {
                        if(ifSyntax[2]=="fan" && ifSyntax[3] == "turnon")
                            fob.onConnect();
                        if(ifSyntax[2]=="fan" && ifSyntax[3] == "turnof")
                            fob.onDisconnect();
                        if(ifSyntax[2]=="light" && ifSyntax[3] == "turnon")
                            lob.onConnect();
                        if(ifSyntax[2]=="light" && ifSyntax[3] == "turnof")
                            lob.onDisconnect();
                        if(ifSyntax[2]=="door" && ifSyntax[3] == "turnon")
                            dob.onConnect();
                        if(ifSyntax[2]=="door" && ifSyntax[3] == "turnof")
                            dob.onDisconnect();
                    }
                    if(ifSyntax[1]==">" && ts.val>valueToChange)
                    {
                        if(ifSyntax[2]=="fan" && ifSyntax[3] == "turnon")
                            fob.onConnect();
                        if(ifSyntax[2]=="fan" && ifSyntax[3] == "turnof")
                            fob.onDisconnect();
                        if(ifSyntax[2]=="light" && ifSyntax[3] == "turnon")
                            lob.onConnect();
                        if(ifSyntax[2]=="light" && ifSyntax[3] == "turnof")
                            lob.onDisconnect();
                        if(ifSyntax[2]=="door" && ifSyntax[3] == "turnon")
                            dob.onConnect();
                        if(ifSyntax[2]=="door" && ifSyntax[3] == "turnof")
                            dob.onDisconnect();
                    }
                    if(ifSyntax[1]=="=" && ts.val==valueToChange)
                    {
                        if(ifSyntax[2]=="fan" && ifSyntax[3] == "turnon")
                            fob.onConnect();
                        if(ifSyntax[2]=="fan" && ifSyntax[3] == "turnof")
                            fob.onDisconnect();
                        if(ifSyntax[2]=="light" && ifSyntax[3] == "turnon")
                            lob.onConnect();
                        if(ifSyntax[2]=="light" && ifSyntax[3] == "turnof")
                            lob.onDisconnect();
                        if(ifSyntax[2]=="door" && ifSyntax[3] == "turnon")
                            dob.onConnect();
                        if(ifSyntax[2]=="door" && ifSyntax[3] == "turnof")
                            dob.onDisconnect();
                    }

    		    }
                if(ifSyntax[0]=="motion")
                {

                    if(ifSyntax[1]=="=" && ms.val==valueToChange)
                    {
                        if(ifSyntax[2]=="door" && ifSyntax[3] == "turnon")
                            dob.onConnect();
                        if(ifSyntax[2]=="door" && ifSyntax[3] == "turnof")
                            fob.onDisconnect();
                        if(ifSyntax[2]=="light" && ifSyntax[3] == "turnon")
                            lob.onConnect();
                        if(ifSyntax[2]=="light" && ifSyntax[3] == "turnof")
                            lob.onDisconnect();
                    }
                }
                if(ifSyntax[0]=="water")
                {
                    if(ifSyntax[1]=="<" && ws.val<valueToChange)
                    {
                        if(ifSyntax[2]=="fan" && ifSyntax[3] == "turnon")
                            fob.onConnect();
                        if(ifSyntax[2]=="fan" && ifSyntax[3] == "turnof")
                            fob.onDisconnect();
                        if(ifSyntax[2]=="light" && ifSyntax[3] == "turnon")
                            lob.onConnect();
                        if(ifSyntax[2]=="light" && ifSyntax[3] == "turnof")
                            lob.onDisconnect();
                        if(ifSyntax[2]=="door" && ifSyntax[3] == "turnon")
                            dob.onConnect();
                        if(ifSyntax[2]=="door" && ifSyntax[3] == "turnof")
                            dob.onDisconnect();
                    }
                    if(ifSyntax[1]==">" && ws.val>valueToChange)
                    {
                        if(ifSyntax[2]=="fan" && ifSyntax[3] == "turnon")
                            fob.onConnect();
                        if(ifSyntax[2]=="fan" && ifSyntax[3] == "turnof")
                            fob.onDisconnect();
                        if(ifSyntax[2]=="light" && ifSyntax[3] == "turnon")
                            lob.onConnect();
                        if(ifSyntax[2]=="light" && ifSyntax[3] == "turnof")
                            lob.onDisconnect();
                        if(ifSyntax[2]=="door" && ifSyntax[3] == "turnon")
                            dob.onConnect();
                        if(ifSyntax[2]=="door" && ifSyntax[3] == "turnof")
                            dob.onDisconnect();
                    }
                    if(ifSyntax[1]=="=" && ws.val==valueToChange)
                    {
                        if(ifSyntax[2]=="fan" && ifSyntax[3] == "turnon")
                            fob.onConnect();
                        if(ifSyntax[2]=="fan" && ifSyntax[3] == "turnof")
                            fob.onDisconnect();
                        if(ifSyntax[2]=="light" && ifSyntax[3] == "turnon")
                            lob.onConnect();
                        if(ifSyntax[2]=="light" && ifSyntax[3] == "turnof")
                            lob.onDisconnect();
                        if(ifSyntax[2]=="door" && ifSyntax[3] == "turnon")
                            dob.onConnect();
                        if(ifSyntax[2]=="door" && ifSyntax[3] == "turnof")
                            dob.onDisconnect();
                    }
                }
                if(ifSyntax[0]=="gas")
                {
                    if(ifSyntax[1]=="=" && gs.val==valueToChange)
                    {
                        if(ifSyntax[2]=="door" && ifSyntax[3] == "turnon")
                            dob.onConnect();
                        if(ifSyntax[2]=="door" && ifSyntax[3] == "turnof")
                            fob.onDisconnect();
                        if(ifSyntax[2]=="light" && ifSyntax[3] == "turnon")
                            lob.onConnect();
                        if(ifSyntax[2]=="light" && ifSyntax[3] == "turnof")
                            lob.onDisconnect();
                        if(ifSyntax[2]=="fan" && ifSyntax[3] == "turnon")
                            fob.onConnect();
                        if(ifSyntax[2]=="fan" && ifSyntax[3] == "turnof")
                            fob.onDisconnect();
                    }
                }
    		};
    		Checker();
        }
        if(choice == 3)
        {
            cout<<"If status 1 then On else Off"<<endl;
            cout<<"SENSORS        STATUS        Value"<<endl;
            cout<<"-------        ------        -----"<<endl;
            cout<<"Temperature    "<<ts.status<<"             "<<ts.val<<endl;
            cout<<"Motion         "<<ms.status<<"             "<<ms.val<<endl;
            cout<<"Water          "<<ws.status<<"             "<<ws.val<<endl;
            cout<<"Gas            "<<gs.status<<"             "<<gs.val<<endl;
            cout<<"---------------------------------------"<<endl;
            cout<<"DEVICES        STATUS"<<endl;
            cout<<"-------        ------"<<endl;
            cout<<"Fan            "<<fob.status<<endl;
            cout<<"Light          "<<lob.status<<endl;
            cout<<"Door           "<<dob.status<<endl;

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



