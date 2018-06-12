#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<ctime>
#include<vector>
#include<string>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void clockin();
    void clockout();
        void adduser();
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
        void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

class Shift;
class Supervisor;

//Base class
class User {
private:
    QString name;
    QString id;
    std::vector<Shift> userhours;
    friend Supervisor;
    friend MainWindow;
public:
    User();
    User(QString num, QString a);
    void viewhours() const;
    QString getname() { return name; }

};

//Derived class
class Supervisor : public User {
private:
    std::vector<User*> employees;
public:
    Supervisor(QString num, QString a) : User(num, a) { };
    Supervisor() : User("111111", "N/A") {};
    void addemp(User*);
    User* findemployee(QString b);
    void viewemployeehours(QString a);
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
    friend MainWindow;
};


#endif // MAINWINDOW_H
