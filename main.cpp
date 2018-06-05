#include "Header.h"

int main() {

	
	Supervisor sup(321111, "Bob");
	User* emp1 = new User(123456, "Mary");
	sup.addemp(emp1);

		cout << "done creating...";
		cout << "Enter 0 to sign up. Press any other key to sign in" << endl;
		int q;
		cin >> q;
		if (q == 0) {
			//ADD EMPLOYEE
			unsigned int id;
			cout << "Enter new ID#...";
			cin >> id;
			if (sup.findemployee(id) == NULL) {
				cout << endl << "Thank you." << endl << endl << "Please enter employee name...";
				string nam;
				cin >> nam;
				sup.addemp(new User(id, nam));
			}
			else { cout << "That ID# is already taken. Please try again with a different ID#." << endl; }
		}
		else {
			//SIGN IN (RUN FIND EMPLOYEE)
			unsigned int id;
			User* loggedin;
			cout << "Please enter your ID#...";
			cin >> id;
			loggedin = sup.findemployee(id);
			if (loggedin == NULL) { cout << "Unable to find employee. Please enter your ID#..." };
		}


	return 0;

}
