#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

//******************** CLASSES ************************

class Hours;
class Supervisor;

//Base class
class User {
private:
    string name;
    unsigned int id;
    vector<Hours*> userhours;
 //   Hours* userhours;
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
private:
    string position;
public:
    Supervisor(unsigned int num, string a, string pos) : User(num, a), position(pos) {userhours[0];};
    Supervisor() : User(111111, "N/A"), position("N/A") {userhours[0];};
    //Supervisor(unsigned int num, string a, string pos);
    virtual void viewhours();
    void viewhours (User n);
};

//Hours class
class Hours {
private:
    time_t start;
    time_t end;
public:
    double sum;
    
};


//**************** FUNCTIONS ********************


User::User(){
    name = "N/A";
    id = 111111;
    
}

User::User(unsigned int num, string a){
    id = num;
    name = a;
    userhours[0];
}

