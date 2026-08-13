#include <iostream>
#include <string>
using namespace std;

class Vehicle{
public:
    void read(istream& is);
    void show()const;
    Vehicle(string b, string t, int ts) : brand(b), type(t), topspeed(ts){}; 
    Vehicle() : Vehicle("Audi", " ", 240){};
    Vehicle(istream& is) : Vehicle() {read(is);};

private:
    string brand;
    string type;
    int topspeed;
};

void Vehicle::read(istream& is){
    if(cin >> brand >> type >> topspeed)
        cout << "Input completed!" << endl;
}

void Vehicle::show()const{
    cout << "This is a " << brand << " " << type << ". And it can go for " << topspeed << "km/h."; 
};

int main(){
//cout << "Press 1 to input vehicle, press q to quit." << endl;
//int temp;
//int createvehicle = 1;
//cin >> temp;

Vehicle family_car(cin);
cout << "A vehicle's file has made.";
//cout << "Press 1 to show vehicle, press q to quit.";
//cin >> temp;
//while(temp == createvehicle){
family_car.show();
//};
return 0;
}