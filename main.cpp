#include "Header.h"



int main() {





	Supervisor sup(321111, "Bob");

	User* emp1 = new User(123456, "Mary");

	sup.addemp(emp1);



	cout << "done creating..." << endl << endl;
	int counter;

	do {
		cout << "Enter 0 to sign up. Press any other key to sign in." << endl;

		int q;

		cin >> q;

		unsigned int id;

		//ADD EMPLOYEE

		if (q == 0) {

			do {

				cout << "Enter new ID#..."<<endl;

				cin >> id;

				if (sup.findemployee(id) != NULL) {

					cout << "That ID# is already taken. Please try again with a different ID#." << endl;

				}

			} while (sup.findemployee(id) != NULL);



			if (sup.findemployee(id) == NULL) {

				cout << endl << "Thank you." << endl << endl << "Please enter employee name..."<< endl;

				string nam;

				cin >> nam;

				sup.addemp(new User(id, nam));

			}

		}



		//SIGN IN (RUN FIND EMPLOYEE)

		User* loggedin;

		cout << "Please enter your ID#..."<<endl;

		cin >> id;

		loggedin = sup.findemployee(id);

		if (loggedin == NULL) { cout << "Unable to find employee. Please enter your ID#..."<<endl; }



		cout << endl << "Welcome " << loggedin->getname() << "! Please select from the following options:" << endl;

		int choice;

		do {
		
			cout << endl << "To clock in, press 0." << endl << "To clock out, press 1." << endl << "To view your hours, press 2." << endl << "To log out, press 3."<<endl;

			cin >> choice;

			if (choice == 0) { loggedin->clockin(); }

			else if (choice == 1) { loggedin->clockout(); }

			else if (choice == 2) { loggedin->viewhours(); }

			else if (choice == 3) { counter = 1; }

			else if (choice == 4) { counter = 0; }

			else { cout << "Invalid choice."; }
		
		} while (choice < 0 || choice > 4);



	} while (counter != 0);

	cout << endl << "Press any key to shut down.";
	return 0;



}
