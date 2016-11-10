// Lab9_strings.cpp
// This program shows some simple string examples, and asks for simple tasks.
// Reference: Lippman, section 3.2

// Author: Luis Rivera

#include <iostream>
#include <string>

using namespace std;

// Main function. Shows a few examples. Complete the assignments stated in the comments.
int main()
{
	string s1, s2("Hello"), s3 = "World";
	cout << "\nEnter a word:" << endl;
	cin >> s1;
	cin.ignore();
	string s4(s1);
	
	cout << s1 << endl
		 << s2 << endl
		 << s3 << endl
		 << s4 << endl;
	
	s1 = s2 + s3;
	cout << s1 << endl;

// ***********************************************************************
// Try all the operations in Table 3.2 using the strings above and
// using new strings that you may declare.
// Some of those operations have already been used, but write your
// own examples.
// ***********************************************************************
	cout << s1 << "\nEnter another string: ";
	cin >> s1;
	cin.ignore();
	cout << "Enter one more: ";
	getline(cin, s2);
	cout << s1 << " " << s2 << endl;
	cout << "s1 empty? " << s1.empty() << endl;
	cout << "Size of s1 is: " << s1.size() << endl;
	cout << "The third charecter in s2 is " << s2[2] << endl;
	
	string sa("Go"), sb(" Cubbies");
	string sc = sa + sb;
	cout << sc << endl;
	
	sa = s3;
	cout << "sa: " << sa << " s3: " << s3 << endl;
	cout << "sa == s3: " << (sa == s3) << endl;
	cout << "sa != s3: " << (sa != s3) << endl;
	cout << "sc > s3: " << (sc > s3) << endl;
// -----------------------------------------------------------------------
	string line;
	cout << "\nEnter some text, finish it with an &" << endl;
	getline(cin, line, '&');
	cout << line << endl;

// ***********************************************************************
// Use a "Range for" (Lippman, page 93) and operations in table 3.3 to:
// 1) change the case of the letters in your input line above (upper to
//    lowercase and vice-versa).
// 2) Replace any whitespace with a dot ('.').
// Print the converted text.
// ***********************************************************************
	for(int i = 0; i < line.size(); i++)
	{
		if(!(isgraph(line[i])))
		{
			line[i] = '.';
		}
		if(islower(line[i]))
		{
			line[i] = toupper(line[i]);
		}
		else if(isupper(line[i]))
		{
			line[i] = tolower(line[i]);
		}
	}
	cout << line << endl;
	return 0;
}
