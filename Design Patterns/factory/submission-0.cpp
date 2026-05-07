class Vehicle {
public:
    virtual string getType() = 0;
};

class Car : public Vehicle {
public:
    string getType() override {
        return "Car";
    }
};

class Bike : public Vehicle {
public:
    string getType() override {
        return "Bike";
    }
};

class Truck : public Vehicle {
public:
    string getType() override {
        return "Truck";
    }
};

class VehicleFactory {
public:
    virtual Vehicle* createVehicle() = 0;
};

class CarFactory : public VehicleFactory {
    // Write your code here
    public:
    Car* createVehicle() override{
        Car* car = new Car();
        return car;
    }
};

class BikeFactory : public VehicleFactory {
    // Write your code here
    public:
    Bike* createVehicle() override{
        Bike* bike = new Bike();
        return bike;
    }
};

class TruckFactory : public VehicleFactory {
    // Write your code here
    public:
      Truck* createVehicle() override{
        Truck* truck = new Truck();
        return truck;
    }
};
