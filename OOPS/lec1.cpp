#include<iostream>
using namespace std;

class Hero {
    
    //properties
    private:
    int health;

    public:
    char *name;
    char level;
    static int timeToComplete;

    Hero() {
        cout << "Simple constructor called" << endl;
        name = new char[100];
    }

    //Paramerterised Constructor
    Hero(int health) {
        this -> health = health;
    }

    Hero(int health, char level) {
        this -> level = level;
        this -> health = health;
    }

    //copy constructor
    Hero(Hero& temp) {

        // char *ch = new char[strlen(temp.name) + 1];
        // strcpy(ch, temp.name);
        // this->name = ch;

        cout << "Copy constructor called" << endl;
        this->health = temp.health;
        this->level = temp.level;
    }

    void print(){
        cout << endl;
        cout << "[ Name: " << this->name<< " ,";
        cout << "health: " << this->health << " ,";
        cout <<"level: " << this->level << " ]";
        cout << endl << endl;
    }

    int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }

    void setHealth(int h) {
        health = h;
    }

    void setLevel(char ch) {
        level = ch;
    }

    

    static int random() {
        return timeToComplete ;
    }

    //Destructor
    ~Hero() {   
        cout << "Destructor bhai called" << endl;
    }

};

int main(){
    // Hero sahil;
    // cout<<sizeof(sahil)<<endl;
    // Hero sahil;
    // cout<< sahil.getHealth() <<endl;
    // sahil.setHealth(50);
    // cout<< sahil.getHealth() <<endl;
    // Hero sahil(50);

     // //Hero tt;

    // //object created statically
    Hero ramesh(10);
    ramesh.print();
    // //cout << "Address of ramesh " << &ramesh << endl;
    // ramesh.print();

    // //dynamically
    // Hero *h =  new Hero(11);
    // h->print();

    // Hero temp(22, 'B');
    // temp.print();
}