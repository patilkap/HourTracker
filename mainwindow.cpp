#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  //Supervisor sup("321111", "Bob");
    QObject::connect(ui->adduser, SIGNAL(clicked()), this, SLOT(adduser()));
    QObject::connect(ui->clockin, SIGNAL(clicked()), this, SLOT(clockin()));
    QObject::connect(ui->clockout, SIGNAL(clicked()), this, SLOT(clockout()));


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
    }}


/*User::User() {
    name = "N/A";
    id = "111111";
    userhours[0];
}
*/

User::User(QString num, QString a) {
    id = num;
    name = a;
}


void MainWindow::clockin() {
    time_t current_time = time(NULL);
    Shift a(current_time);
    User *user = sup.findemployee(ui->ID_2->text());
    user->userhours.push_back(a);
    return;
}



void MainWindow::clockout() {
    time_t current_time = time(NULL);
    User *user = sup.findemployee(ui->ID_2->text());
    Shift& a = user->userhours.back();
    a.end = current_time;
    a.sumitup();
    return;

}

/*void User::viewhours() const {
  //  cout << name << ":" << endl;
    for (auto x : userhours) {
        unsigned int n = 1;
        double tot = 0;
      //  cout << n << ") " << x.sumitup() << endl;
        tot += x.sumitup();
        ++n;
    }
    return;

}*/

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

void MainWindow::on_pushButton_clicked()
{     double tot = 0;
      QString print;
      User *user = sup.findemployee(ui->ID_2->text());
    for (int i=0; i<user->userhours.size();++i) {
        print = QString::number(user->userhours[i].sumitup());
        tot += user->userhours[i].sumitup();
        ui->listWidget->addItem(print);
    }
     ui->listWidget->addItem("DONE");
       QString valueAsString = QString::number(tot);
    ui->listWidget->addItem("Total: "+ valueAsString);
}
