#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  //Supervisor sup("321111", "Bob");
    QObject::connect(ui->adduser, SIGNAL(clicked()), this, SLOT(adduser()));


}

Supervisor sup("321111", "Bob");

void MainWindow::adduser(){
    if(ui->sup->checkState()==0){
        if(ui->Name->text()!="" && ui->ID->text()!=""){
            if (sup.findemployee(ui->ID->text()) != NULL) {
                  // cout << "That ID# is already taken. Please try again with a different ID#." << endl;
                      return;  }
            if(sup.findemployee(ui->ID->text())==NULL){
              //  cout << endl << "Thank you." << endl << endl << "Please enter employee name...";
                sup.addemp(new User(ui->ID->text(), ui->Name->text()));
        }
    }
        if(ui->sup->checkState()!=0){
            if(ui->Name->text()!=""&&ui->ID->text()!=""){
                if (sup.findemployee(ui->ID->text()) != NULL) {
                       //cout << "That ID# is already taken. Please try again with a different ID#." << endl;
                         return;   }
                if(sup.findemployee(ui->ID->text())==NULL){
                 //   cout << endl << "Thank you." << endl << endl << "Please enter employee name...";
                    sup.addemp(new Supervisor(ui->ID->text(), ui->Name->text()));
            }
        }

        }
return;
}

/*User::User() {
    name = "N/A";
    id = "111111";
    userhours[0];
}


User::User(QString num, QString a) {
    id = num;
    name = a;
}*/


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
  //  cout << name << ":" << endl;
    for (auto x : userhours) {
        unsigned int n = 1;
        double tot = 0;
        cout << n << ") " << x.sumitup() << endl;
        tot += x.sumitup();
        ++n;
    }
    return;

}

void Supervisor::addemp(User* u) {
    employees.push_back(u);
}

User* Supervisor::findemployee(QString b) {
    User* t;
    for (auto x : employees) {
        if (x->id == b) {
            t = x;
        }
        else { return NULL; }
    }
    return t;
}

void Supervisor::viewemployeehours(QString a) {
    User* emp = findemployee(a);
    emp->viewhours();
}

double Shift::sumitup() {
    double seconds, minutes;
    seconds = end - start;
    minutes = seconds / 60;
    return minutes / 60;
}











MainWindow::~MainWindow()
{
    delete ui;
}
