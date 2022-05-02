#include <iostream>
#include<string>
using namespace std;

/* 1. Define a class B1 with a virtual function vf() and a non-virtual function f(). Define both of these functions within class B1. Implement each function to output its name (e.g., B1::vf()). Make the functions public. Make a B1 object and call each function. */
class B1
{
public:
    virtual vf() { cout << "B1::vf()\n"; }
    void f() { cout << "B1::f()\n"; }
    /*5. Add a pure virtual function called pvf() to B1 and try to repeat 1–4. Explain the result.*/
    virtual void pvf() = 0;
};

//2. Derive a class D1 from B1 and override vf(). Make a D1 object and call vf() and f() for it.
class D1 : public B1
{
    public:
        virtual void vf() { cout << "D1::vf()\n"; }
        //4. Now define a function called f() for D1 and repeat 1–3. Explain the results.
        void f() { cout << "D1::f()\n"; }
};

/*6. Define a class D2 derived from D1 and override pvf() in D2. Make an object of class D2 and invoke f(), vf(), and pvf() for it.*/
class D2 : public D1
{
    public:
    void pvf() { cout << "D2::pvf()\n"; }
};
//Define a class B2 with a pure virtual function pvf().
class B2
{
    public:
    virtual void pvf() = 0;
};
/*Define a class D21 with a string data member and a member
function that overrides pvf(); D21::pvf() should output the value of the string.*/
class D21 : public B2 
 {
 	string s;
     void pvf() {cout << s << endl;}
     
 };
 /*Define a class D22 that is just like D21
except that its data member is an int.*/
 class D22 : public B2 {
 public:
 int n;
 void pvf() {cout << n << endl;}
 
 };
 //Define a function f() that takes a B2& argument and calls pvf() for its argument.
 void f(B2& b2ref){
 b2ref.pvf();
 };
 

int main()
{
    B1 b1;
    b1.vf();
    b1.f();

    D1 d1;
    d1.vf();
    d1.f();

/* 3. Define a reference to B1 (a B1&) and initialize that to the D1 object you just defined. Call vf() and f() for that reference.*/
    B1& bref = d1;
    bref.vf();
    bref.f();

    D2 d2;
    d2.vf();
    d2.f();
    d2.pvf();

    D21 d21;
    d21.s = "d21.s";
    d21.pvf();
    
    D22 d22;
    d22.n = 22;
    d22.pvf();
    
    f(d21);
    f(d22);
    
 }
