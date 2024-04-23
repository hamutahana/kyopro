#include <bits/stdc++.h>
using namespace std;

class Person {
  private:
    int HP = 0;
  
  public:
    Person(int mm = 123) { cout << "Person constructor" << endl; };
    
    int get_HP() { return HP; };
    void set_HP(int HP) { this->HP = HP; };
    void say_hello(string message);
};

void Person::say_hello(string message) {
  cout << "hello, " << message << endl;
}

class Japanese :public Person {
  private:
    string language = "Japanese";
  
  public:
    Japanese() { cout << "Japanese constructor" << endl; };
    
    string get_language() { return language; };
};

int main() {
  Person p;
  p.say_hello("hamutahana");
  p.set_HP(100);
  cout << p.get_HP() << endl;
  
  Japanese j;
  cout << j.get_HP() << endl;
  cout << j.get_language() << endl;
}
