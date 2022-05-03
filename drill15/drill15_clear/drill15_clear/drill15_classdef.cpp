//Class definition drill:

#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>

using namespace std;

//1. Define a struct Person containing a string name and an int age.
//4. Give Person a constructor initializing name and age.
class Person
{ 
private:
        string f;
        string l;
        int a;
public:
        Person(){}
        Person(string first, string last, int age) : f(first), l(last), a(age)
        {
/*7. Modify the constructor to check that age is [0:150) and that name doesn’t contain any of the characters ; : " ' [ ] * & ^ % $ # @ !.
Use error() in case of error. Test.*/
            if(a < 0 || a >= 150)
            {
                throw runtime_error("Invalid age in Person");
            }
            string n = first + last;
            for (char c : n ){
                    switch (c){
                        case ';':
                        case ':':
                        case '"':
                        case '\'':
                        case '[':
                        case ']':
                        case '*':
                        case '&':
                        case '^':
                        case '%':
                        case '$':
                        case '#':
                        case '@':
                        case '!': runtime_error("Invalid character!");
                    default: break;                    
                    		}
                    		};
       };

//5. Make the representation of Person private, and provide const member functions name() and age() to read the name and age.
/*9. Change the representation of Person to have first_name and second_name instead of name. Make it an error not to
supply both a first and a second name. Be sure to fix >> and << also. Test.*/
        string first() const {return f;}
        string last() const {return l;}
        int age() const {return a;}
   
};


//3. Define an input (>>) and an output (<<) operator for Person; read in a Person from the keyboard (cin) and write it out to the screen (cout).
//6. Modify >> and << to work with the redefined Person.
ostream& operator<<(ostream &os, const Person &p)
{
    return os << p.first() << " " << p.last() << p.age();
}

istream& operator>>(istream &is, Person &p)
{
    string first;
    string last;
    int age;

    is >> first >> last >> age;
    p = Person(first, last, age);

    return is;
}

int main()
{
//2. Define a variable of type Person, initialize it with “Goofy” and 63, and write it to the screen (cout).
	Person p = Person("Goofy","Alma",23);
cout << p.first() << p.last() << p.age() << endl;
cout << p << endl;

Person p2;
cin >> p2;
cout << p2 << endl;

/*8. Read a sequence of Persons from input (cin) into a vector<Person>; write them out again to the screen (cout). Test
with correct and erroneous input.*/
vector<Person> vec;
for( Person p; cin >>p;)
{
    if(p.first() == "end") 
    	break;
    vec.push_back(p);
}

for(Person p : vec)
{
    cout << p << endl;
}

}
