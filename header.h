#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

//******************** CLASSES ************************

class Shift;
class Supervisor;

//Base class
class User {
private:
    string name;
    unsigned int id;
    vector<Shift*> userhours;
    friend Supervisor;
public:
    User();
    User(unsigned int num, string a);
    void clockin();
    void clockout();
    void viewhours() const;
};

 //Derived class
class Supervisor : public User {
public:
    Supervisor(unsigned int num, string a) : User(num, a) {userhours[0];};
    Supervisor() : User(111111, "N/A") {userhours[0];};
    void viewemployeehours(User*);
};

//Shift class
class Shift {
private:
    time_t start;
    time_t end;
    double total;
public:
    double sumitup();
    
};


//******************** FUNCTIONS ************************

User::User(){
    name = "N/A";
    id = 111111;
    userhours[0];
}

User::User(unsigned int num, string a){
    id = num;
    name = a;
    userhours[0];
}

void User::clockin(){
    new Shift a;
    hoursworked.pushback(a);
    a.start = time;
    return;
}

void User::clockout(){
    Shift* a = hoursworked.back();
    a.end = time;
    return;
}

