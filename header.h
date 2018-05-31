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
	vector<Shift> userhours;
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
	Supervisor(unsigned int num, string a) : User(num, a) { userhours[0]; };
	Supervisor() : User(111111, "N/A") { userhours[0]; };
	void viewemployeehours(User*);
};

//Shift class
class Shift {
private:
	time_t start;
	time_t end;
public:
	Shift(time_t start) : start(start) {}
	double sumitup(); // TODO
	friend User;

};


//******************** FUNCTIONS ************************

User::User() {
	name = "N/A";
	id = 111111;
	userhours[0];
}

User::User(unsigned int num, string a) {
	id = num;
	name = a;
	userhours[0];
}

void User::clockin() {
	time_t current_time = time(NULL);
	Shift a(current_time);
	userhours.emplace_back(move(a));
	return;
}

void User::clockout() {
	time_t current_time = time(NULL);
	Shift& a = userhours.back();
	a.end = current_time;
	a.sumitup();
	return;
}

void User::viewhours() const{
	cout << name << ":" << endl;
	for (auto x : userhours) {
		unsigned int n = 1;
		double tot = 0;
		cout << n << ") " << x.sumitup()<<endl;
		tot += x.sumitup();
		++n;
	}
	return;
}

double Shift::sumitup() {
	return difftime(start, end);
}
