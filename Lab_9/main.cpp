#include <iostream>

using namespace std;

int current_year = 2018;   // used to calculate age of a rail_car (changed to current year
const double PI = 3.14159; // constant used to calculate volume of a cylinder

class container
{
public:
    int percent_loaded; // unused. we won't be going deep into what's actually IN the rail_cars anyway
    container()
    {
        cout << " Calling container default constructor." << endl;
    }
};

// Syntax:
// class subclass_name : public superclass_name { };
class box : public container
{
public:
    double height, width, length;
    box()
    {
        cout << " Calling box default constructor." << endl;
    }
    double volume()
    {
        return height * length * width;
    }
};

class cylinder : public container
{
public:
    cylinder()
    {
    }
    cylinder(double rad, double len)
    {
        radius = rad;
        length = len;
    }
    double radius, length;
    double volume()
    {
        return PI * radius * radius * length;
    }
};

class rail_car
{
public:
    int year_built;         // used to determine age
    rail_car *front, *back; // points to rail_car in front of and to the back of this rail_car respectively
    rail_car()
    {
        cout << " Calling rail_car default constructor." << endl;
    }
    int age()
    {
        return current_year - year_built;
    }
};

class box_car : public rail_car, public box
{
public:
    box_car()
    {
        cout << "Box car constructed." << endl;
        height = 10.0;
        length = 40.0;
        width = 9.0;
    }
};

class tank_car : public rail_car, public cylinder
{
public:
    tank_car()
        : cylinder(3.5, 40.0)
    {
        cout << "Tank car constructed." << endl;
    }
};

class engine : public rail_car
{
public:
    engine()
    {
        cout << "Engine constructed." << endl;
    }
};

class caboose : public rail_car
{
public:
    caboose()
    {
        cout << "Caboose constructed." << endl;
    }
};

// Train class to hold rail_cars instead of the given train array
// Has addfront, addback, remove front, removeback functions
// Basically, its a deque for rail_cars
class train
{
public:
    // Default constructor
    train()
    {
        car_count = 0;
    }

    // Adds rail_car object to front of train
    void addFront(rail_car* newCar)
    {
        if(car_count == 0) // if no car(s) in train...
        {
            head = newCar;
            tail = newCar;
            car_count++;
        } else // if car(s) in train...
        {
            head->front = newCar; // put newCar in front of current head of train...
            newCar->back = head;  // and put current head to back of newCar..
            head = newCar;        // set head of train to newCar
            car_count++;
        }
        cout << "Car added to front of train." << endl;
    }

    // Adds rail_car pbject to back of train
    void addBack(rail_car* newCar)
    {
        if(car_count == 0) // if no car(s) in train...
        {
            head = newCar;
            tail = newCar;
            car_count++;
        } else // if car(s) in train...
        {
            tail->back = newCar;  // put newCar in back of current tail of train...
            newCar->front = tail; // and put current tail to font of newCar..
            tail = newCar;        // set head of train to newCar
            car_count++;
        }
        cout << "Car added to back of train." << endl;
    }

    // Removes rail_car object from front of train
    void removeFront()
    {
        if(car_count == 1) // if train is has only one car...
        {
            car_count--;
            cout << "Front car removed." << endl;

        } else if(car_count > 0) // if train is not empty and more than 1 car...
        {
            head = head->back; // set head of train to the car behind it
            car_count--;
            cout << "Front car removed." << endl;
        } else
            cout << "Train has no car to remove." << endl;
    }

    // Removes rail_car pbject from back of train
    void removeBack()
    {
        if(car_count == 1) // if train is has only one car...
        {
            car_count--;
            cout << "Back car removed." << endl;

        } else if(car_count > 0) // if train is not empty and more than 1 car...
        {
            tail = tail->front; // set tail of train to the car in front of it
            car_count--;
            cout << "Back car removed." << endl;
        } else
            cout << "Train has no car to remove." << endl;
    }

    // Returns number of cars in train
    int getCarCount()
    {
        return car_count;
    }

private:
    rail_car* head; // rail_car at beginning of train
    rail_car* tail; // rail_car at end of train
    int car_count;  // number of cars in train
};

// Array to hold rail_car pointers
// rail_car* train[100];

// train object to hold rail_cars
train testTrain;

// Peompts user to create a train, car by car.
main()
{
    string type_code; // used to determine action desired by user

    while(true) {
        cout << "Would you like to add or remove a car? (Enter 0 to add, 1 to remove, -1 to exit)" << endl;
        cin >> type_code;
        if(type_code == "0") { // adding car
            cout << "Are you adding to the front or back of the train? (Enter 0 for front, 1 for back, -1 to exit)"
                 << endl;
            cin >> type_code;
            if(type_code == "-1") // terminate
                goto endTest;
            else if(type_code == "0") { // adding front
                cout << "What type of car would you like to add?\n(Enter 0 for engine, 1 for box car, 2 for tank car, "
                        "3 for caboose, -1 to exit)"
                     << endl;
                cin >> type_code;
                if(type_code == "-1") // terminate
                    goto endTest;
                else if(type_code == "0")
                    testTrain.addFront(new engine);
                else if(type_code == "1")
                    testTrain.addFront(new box_car);
                else if(type_code == "2")
                    testTrain.addFront(new tank_car);
                else if(type_code == "3")
                    testTrain.addFront(new caboose);
            } else if(type_code == "1") { // adding back
                cout << "What type of car would you like to add?\n(Enter 0 for engine, 1 for box car, 2 for tank car, "
                        "3 for caboose, -1 to exit)"
                     << endl;
                cin >> type_code;
                if(type_code == "-1") // terminate
                    goto endTest;
                else if(type_code == "0")
                    testTrain.addBack(new engine);
                else if(type_code == "1")
                    testTrain.addBack(new box_car);
                else if(type_code == "2")
                    testTrain.addBack(new tank_car);
                else if(type_code == "3")
                    testTrain.addBack(new caboose);
            }

        } else if(type_code == "1") { // removing car
            cout << "Are you removing from the front or back of the train? (Enter 0 for front, 1 for back, -1 to exit)"
                 << endl;
            cin >> type_code;
            if(type_code == "-1") // terminate
                goto endTest;
            else if(type_code == "0") // removing front
            {
                testTrain.removeFront();
            } else if(type_code == "1") { // removing back
                testTrain.removeBack();
            }
        } else if(type_code == "-1") // terminate
            goto endTest;
    }
endTest:
    cout << "Number of cars in train is " << testTrain.getCarCount() << endl;

    // car_count tracks number of rail_cars.
    // type_code takes user input and adds a certain subclass of rail_car to trains depending on that input
    /*int car_count, type_code;

    // Read type number and create corresponding objects. Input a non-int value to stop:
    for(car_count = 0; cin >> type_code; ++car_count)
        if(type_code == 0)
            train[car_count] = new engine;
        else if(type_code == 1)
            train[car_count] = new box_car;
        else if(type_code == 2)
            train[car_count] = new tank_car;
        else if(type_code == 3)
            train[car_count] = new caboose;

    // Displays the number of rail_cars in the train array
    cout << "There are " << car_count << " cars in the array." << endl;*/
}
