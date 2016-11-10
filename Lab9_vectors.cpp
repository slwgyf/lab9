// Lab9_vectors.cpp
// This program shows some simple vector examples, and asks for simple tasks.
// Reference: Lippman, section 3.3

// Author: Luis Rivera

// IMPORTANT NOTE: YOU MAY NEED TO COMPILE ADDING THE FOLLOWING FLAG: -std=c++11
// Example: g++ Lab9_vectors.cpp -o Lab9_vectors -std=c++11
// Some initialization methods and other things are not supported by the old standard.

#include <iostream>
#include <vector>

using namespace std;

// Main function. Shows a few examples. Complete the assignments stated in the comments.
int main()
{
	vector<int> ivec1(5), ivec2;
	vector<double> dvec1{5.1}, dvec2(5,1.5);
	vector<string> svec1 = {"hello", "world"};
	vector<int> ivec3 = ivec1;
	
	
	// vector<myClass> myCvec;	// you can have vectors of objects
	// in general: vector<Type> vec;	// vector is a template

	for(int i = 0; i < ivec1.size(); i++)
		cout << ivec1[i] << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
	for(auto i:ivec1)	// This is equivalent to the above for loop
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
	for(auto i:dvec1)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
	for(auto i:dvec2)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
	for(auto i:svec1)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
		
	cout << "Original size: " << ivec2.size() << endl;
	ivec2.push_back(50);
	cout << "New size: " << ivec2.size() << "\nAdded element: " << ivec2[0] << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
	cout<< "---------------------------All the ways to initialize---------------------------------------"<<endl;
	//all different ways to initialize
	vector <int> iv1;//default
	vector <int> iv2(iv1);
	vector <int> iv3 = iv1;
	cout<< "made it through ints"<< endl;
	int x = 6;
	vector <double> dv1 (x, 9);	
	vector<double> dv2 (x);
	cout<< "made it through doubles"<< endl;
	vector<string> sv1 {"hi", "everyone"};
	vector <string> sv2 = {"hello", "everyone"};
	cout<< "made it through strings"<< endl;
	
	for(int i = 0; i < iv1.size(); i++)
		cout << iv1[i] << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
	for(auto i:iv2)	// This is equivalent to the above for loop
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
	for(auto i:iv3)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
	for(auto i:dv1)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
	for(auto i:dv2)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
	for(auto i:sv1)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
	for(auto i:sv2)
		cout << i << endl;
	cout << "\n------------------------------------------------------------------" << endl;
	
	cout<< "---------------------------Example 3.14---------------------------------------"<<endl;
	vector <int> intv1 (5);
	cout<< "Enter 5 integers:"<< endl;
	for (int i = 0; i < 5; i++)
	{
		cin >> intv1[i] ;
	}
	for (auto i:intv1)
	{
		cout << i;
	}
	
	cout << endl;
	
	cout<< "---------------------------Example 3.15---------------------------------------"<<endl;
	vector <string> strv1 (5);
	cout<< "Enter 5 strings:"<< endl;
	for (int i = 0; i < 5; i++)
	{
		cin >> strv1[i] ;
	}
	 cout <<endl;
	for (auto i:strv1)
	{
		cout<< i << endl;
	}
		
// ***********************************************************************
// Try all the wasy to initializa a vector shown in Table 3.4. Use the
// vectors above and/or declare new vectors.
// Some of those operations have already been used, but write your
// own examples.

// Do exercises 3.14 and 3.15 from Lippman (page 102)

// Try all the vector operations shown in table 3.5. Use the vectors above
// or define new ones. Try different types.
// ***********************************************************************

	return 0;
}