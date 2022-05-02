#include<iostream>
#include<vector>

//1. Define template<typename T> struct S { T val; };.
//2. Add a constructor, so that you can initialize with a T.

using namespace std;
template<typename T>
struct S{
	S(T vv = 0) : val{vv} {}
	
//5. Add a function template get() that returns a reference to val.
	T& get();
	
//11. Provide const and non-const versions of get().
	const T& get() const;
	
 //9. Add a set() function template so that you can change val.
	void set(T new_t) {val = new_t;}
	
//10. Replace set() with an S<T>::operator=(const T&). Hint: Much simpler than §19.2.5.
	S<T>& S<T>::operator=(const T& s){}
	
        //7. Make val private.
	private:
		T val;
};

template<typename T>
T& S<T>::get(){return val;}

//6. Put the definition of get() outside the class.
template<typename T>
const T& S<T>::get() const;

template<typename T>
S<T>& S<T>::operator=(const T& s){
val = s;
return *this;}

//12. Define a function template<typename T> read_val(T& v) that reads from cin into v.
template<typename T> void read_val(T& v){cin >> v;}

/*14. Bonus: Define input and output operators (>> and <<) for vector<T>s. For both input and output use a { val, val, val }
format. That will allow read_val() to also handle the S<vector<int>> variable. */
template<typename T>
std::ostream& operator<<(ostream& os, vector<T>& v){
os << "{";
for (int i = 0; i < v.size(); ++i)
{ os << v[i] << (i < v.size()-1 ? ",": " ");
}
os << "}\n";
return os;}

template<typename T>
istream& operator>>(istream& is, vector<T>& v)
{
char ch = 0;
is >> ch;
if (ch != '{')
{is.unget();
return is;
}
for (T val; is >> val;){
v.push_back(val);
is >> ch;
if (ch != ',') break;}

return is;
}


//-----------------------------------------------------------

int main(){
    try{
    
    
//3. Define variables of types S<int>, S<char>, S<double>, S<string>, and S<vector<int>>; initialize them with values of your choice.    
S<int> s;
S<int> si {37};
S<char> sc {'c'};
S<double> sd {10.2};
S<string> ss {"alma"};
S<std::vector<int>> svi {std : vector<int>{1,2,3,4,5}};
 
 
//4. Read those values and print them.
cout << "S<int> :" << s << endl;
cout << "S<int> :" << si << endl;
cout << "S<char> :" << sc << endl;
cout << "S<double> :" << sd << endl;
cout << "S<string> :" << ss << endl;


//8. Do 4 again using get().
cout << "S<int> :" << s.get() << endl;
cout << "S<int> :" << si.get() << endl;
cout << "S<char> :" << sc.get() << endl;
cout << "S<double> :" << sd.get() << endl;
cout << "S<string> :" << ss.get() << endl;

for(auto& a : svi.get()){cout << a << ' ';}
cout<<endl;
	


sc.set('s');

//13. Use read_val() to read into each of the variables from 3 except the S<vector<int>> variable.

int ii;
read_val(ii);
S<int> si2 {ii};

char cc;
read_val(cc);
S<char> sc2{cc};

double dd;
read_val(dd);
S<double> sd2{dd};

cout<< "S<int> :" << si2.get() << endl
<< "S<char> : " << sc2.get() << endl;
<< "S<double> :" << sd2.get() << endl;

}
catch(exception& e)
	{
	cerr << "error: " << e.what() << '\n'; 
	return 1;
	}
catch(...)
	{
	cerr << "Unknown Expcetion." << '\n'; 
	return 2;
	}
}



