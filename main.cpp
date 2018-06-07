#include "Header.h"

int main() {

	
	Supervisor sup(321111, "Bob");
	User* emp1 = new User(123456, "Mary");
	sup.addemp(emp1);

		cout << "done creating...";
		cout << "Enter 0 to sign up. Press any other key to sign in" << endl;
		int q;
		cin >> q;
	
		//ADD EMPLOYEE
		if (q == 0) {
			unsigned int id;
			do {
			cout << "Enter new ID#...";
			cin >> id;
			if (sup.findemployee(id) != NULL) {
				cout << "That ID# is already taken. Please try again with a different ID#." << endl;
			}
			} while (sup.findemployee(id) != NULL);

			if(sup.findemployee==NULL){
				cout << endl << "Thank you." << endl << endl << "Please enter employee name...";
				string nam;
				cin >> nam;
				sup.addemp(new User(id, nam));
			}
		}

		//SIGN IN (RUN FIND EMPLOYEE)
		else {
			unsigned int id;
			User* loggedin;
			cout << "Please enter your ID#...";
			cin >> id;
			loggedin = sup.findemployee(id);
			if (loggedin == NULL) { cout << "Unable to find employee. Please enter your ID#..."; }

			cout << endl<< "Welcome " << loggedin->getname() << "! Please select from the following options:"<<endl;
			int choice;
			do {
				cout << "To clock in, press 0.   To clock out, press 1.   To view your hours, press 2.";
				if (choice == 0) { loggedin->clockin(); }
				else if (choice == 1) { loggedin->clockout(); }
				else if (choice == 2) { loggedin->viewhours(); }
				else { cout << "Invalid choice."; }
			} while (choice != 0 || choice != 1 || choice != 2);
		}

	return 0;

}
