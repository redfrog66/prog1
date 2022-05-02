#include "std_lib_facilities.h"

 /*6. Write a simple copy() operation,
template<typename Iter1, typename Iter2>
requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 copy(Iter1 f1, Iter1 e1, Iter2 f2);
that copies [f1,e1) to [f2,f2+(e1–f1)) and returns f2+(e1–f1) just like the 
standard library copy function. Note that if f1==e1 the sequence is empty, 
so that there is nothing to copy.*/

template<typename Iter1, typename Iter2>
Iter2 m_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	for (auto i=f1;i!=e1; i++)
		{
		*f2=*i;
		f2++;
		}
		return f2;
};
int main()
{	
//1. Define an array of ints with the ten elements { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }.
	int a[10] = {0,1,2,3,4,5,6,7,8,9};
	
//2. Define a vector<int> with those ten elements.
	vector<int> v {0,1,2,3,4,5,6,7,8,9}; 
	
//3. Define a list<int> with those ten elements.
	list<int> l {0,1,2,3,4,5,6,7,8,9};
	cout<<"Base numbers: "<<"{0,1,2,3,4,5,6,7,8,9}"<<endl;
	
 /*4. Define a second array, vector, and list, each initialized as a copy of the first 
array, vector, and list, respectively.*/	
	int a2[10]; //m_copy(begin(a),end(a),begin(a2));
	for (int i = 0; i < 10; i++)
		a2[i] = a[i];
		
	vector<int> v2 = v;
	list<int> l2 = l; 

 /*5. Increase the value of each element in the array by 2; increase the value of 
each element in the vector by 3; increase the value of each element in the 
list by 5.*/	
	cout << "Increased array: ";
	for (auto& x: a)
		{
		x+=2;
		cout << x << ", ";
		} 
		cout<<endl; 

	cout << "Increased list: ";
	for (auto& x: l)
		{
		x+=3;
		cout << x << ", ";
		} 
		cout<<endl;
	
	cout << "Increased vector: ";
	for (auto& x: v)
		{
		x+=5;
		cout << x << ", ";
		} 
		cout<<endl;

/*7. Use your copy() to copy the array into the vector and to copy the list into 
the array.*/	
	cout << "Copied increased array into base(second) vector: ";
	m_copy(begin(a),end(a),begin(v2)); 
	for (auto x: v2)
		cout << x << ", "; 
		cout << endl;

	cout << "Copied increased list into base(second) array: ";
	m_copy(l.begin(),l.end(),begin(a2)); 
	for (auto x: a2)
		cout << x << ", ";
		cout << endl;

/*8. Use the standard library find() to see if the vector contains the value 3 
and print out its position if it does; 
use find() to see if the list contains the 
value 27 and print out its position if it does. The “position” of the first 
element is 0, the position of the second element is 1, etc. Note that if find()
returns the end of the sequence, the value wasn’t found*/
	int element1 = 3, element2 = 27;  
	auto elem1 = find(v.begin(),v.end(),element1); 
	if (elem1 != v.end()) 
		cout << element1 << " is at "<< distance(v.begin(),elem1)  << " index." << endl;
	else
		cout << element1 << " is not in increased the vector." << endl;

	auto elem2 = find(l.begin(),l.end(),element2);
	if (elem2 != l.end())
		cout << element2 << " is at " << distance(l.begin(),elem2) << " index." <<endl;
	else
		cout << element2 << " is not in increased the list." << endl;

 	return 0;
}
