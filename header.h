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



	string getname() { return name; }





};



//Derived class

class Supervisor : public User {

private:

	vector<User*> employees;

public:



	Supervisor(unsigned int num, string a) : User(num, a) { };



	Supervisor() : User(111111, "N/A") { userhours[0]; };

	void addemp(User*);

	User* findemployee(unsigned int b);

	void viewemployeehours(unsigned int a);



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
	
}


User::User(unsigned int num, string a) {


	id = num;

	name = a;

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

void User::viewhours() const {



	cout << name << ":" << endl;

	double tot = 0;

	for (int i = 0; i < userhours.size();++i) {




		cout << i+1 << ") " << userhours[i].sumitup() << endl;



		tot += userhours[i].sumitup();


	}

	cout << endl << "Your total number of hours is: " << tot <<" hrs."<< endl;


	return;



}



void Supervisor::addemp(User* u) {

	employees.push_back(u);

}



User* Supervisor::findemployee(unsigned int b) {

	User* t;

	for (int i = 0; i < employees.size();++i) {

		if (employees[i]->id == b) {

			t = employees[i];

		}

		else { t= NULL; }

	}

	return t;

}



void Supervisor::viewemployeehours(unsigned int a) {

	User* emp = findemployee(a);

	emp->viewhours();

}





double Shift::sumitup() {



	double seconds, minutes;



	seconds = end - start;



	minutes = seconds / 60;



	return minutes / 60;



}
