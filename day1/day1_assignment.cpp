#include<iostream>
using namespace std;

// Create a class for vehicle which contains vehicleType (petrol, diesel ,ev ,…), brand , model, color, mileage, price.
enum vehicleType
{
    petrol,
    diesel,
    ev
};
const char *vehicleTypeS[] = {"petrol", "diesel", "ev"};
class vehicle
{
public:
    vehicleType vehicletype;
    string brand;
    string model;
    string color;
    float mileage;
    int price;
    vehicle(vehicleType type, string brand, string model, string color, float mileage, int price)
    {
        this->vehicletype = type;
        this->brand = brand;
        this->model = model;
        this->color = color;
        this->mileage = mileage;
        this->price = price;
    }
    virtual int getNoOfWheels() = 0;
    friend ostream &operator<<(ostream &print, const vehicle &vehicle_ad)  //Operator overloading
    {
        print << "Vehicle Type: " << vehicleTypeS[vehicle_ad.vehicletype] << endl;
        print << "Brand: " << vehicle_ad.brand << endl;
        print << "Model: " << vehicle_ad.model << endl;
        print << "Color: " << vehicle_ad.color << endl;
        print << "Price: " << vehicle_ad.price << endl;
        return print;
    }
    bool operator<(const vehicle &vehicle)
    {
        return price < vehicle.price;
    }
    bool operator>(const vehicle &vehicle)
    {
        return price > vehicle.price;
    }
};

// Derive car and bike from vehicle
//Car should have attributes no of persons, carType (suv, sedan, etc)
enum carType
{
    suv,
    sedan
};
class car : public vehicle
{
public:
    carType cartype;
    int noOfPersons;
    car(vehicleType vehicletype, string brand, string model, string color, float mileage, int price, int noOfPersons, carType cartype) : vehicle(vehicletype, brand, model, color, mileage, price)
    {
        this->noOfPersons = noOfPersons;
        this->cartype = cartype;
    }
    int getNoOfWheels()  //overridden in derived class
    {
        return 4;
    }
};
//Bike should have attributes weight, bikeType(scooter, motorbikes ,etc)
enum bikeType
{
    scooter,
    motorbike
};
class bike : public vehicle
{
public:
    bikeType biketype;
    int weight;
    bike(vehicleType vehicletype, string brand, string model, string color, float mileage, int price, int weight, bikeType biketype) : vehicle(vehicletype, brand, model, color, mileage, price)
    {
        this->weight = weight;
        this->biketype = biketype;
    }
    int getNoOfWheels()  //overridden in derived class
    {
        return 2;
    }
};


int main()
{
    car c1(diesel, "Honda", "City", "Black", 25, 1200000, 200000, suv);
    bike b1(petrol, "Honda", "cb-twister", "Red", 80, 80000, 100, motorbike);
    //Using operator overloading (<<) to display, brand, model, type, color, price.
    cout << "Car Information:- \n" << c1 <<endl;
    cout << "Bike Information:- \n" << b1 <<endl;

    cout << "Press Enter to Continue";
    cin.ignore();
    system("CLS");

    //print the noofWheels
    cout << "No Of Wheels in car vehicle: " <<c1.getNoOfWheels() <<endl;
    cout << "No Of Wheels in bike vehicle: " <<b1.getNoOfWheels() <<endl;

    cout << "Press Enter to Continue";
    cin.ignore();
    system("CLS");

    //Comparison of two vehicles
    if(c1>b1)
    {
        cout<<"\nbike is cheaper" <<endl;
    }
    else
    {
        cout<<"car is cheaper" <<endl;
    }
    return 0;
}


