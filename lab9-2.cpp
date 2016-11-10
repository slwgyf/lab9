//============================================================================
// Name        : lab7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>


using namespace std;


class Signal
{
	private:
		
		double mean, maxV;//private members of the class
		
		vector <double> data;//this was made a vector instead of an array
		//means we no longer need a length member
	public:
		//public members of the class to be called
		Signal();//constructors
		Signal(int num);
		Signal(string name);
		~Signal();//destructor
		void centerSig();
		void normalSig();
		void statistics();
		void sigInfo();
		void saveSig(string name);
		void menu();//called to print the menu
		void operator+(double val);
		void operator*(double val);
		int getLength ();
		vector <double> getInfo(double *max);
		void setData (vector<double> stuff);
		void setMax (double max);
};

Signal::Signal()//default constructors
{
	mean = 0.0;
	maxV = 0.0;
	
}
Signal::Signal(int num)//contructor to be called if an integer is sent
{
	
	FILE *fp;
	char fname[16] = "Raw_data_nn.txt";//default name of files, nn to be over written below
	fname[9] = (num/10)+48;//loads first digit of num into nn
	fname[10] = (num%10)+48;//loads second digit of num into nn
	int length;
	fp = fopen(fname, "r");//open the file
	fscanf(fp, "%d %lf", &length, &maxV);//assign values to length and max
	vector <double> temp (length);

	int i;
	for(i = 0; i < length; i++)
	{
		fscanf(fp, "%lf", &temp[i]);//load the values into the data variable
	}
	fclose(fp);//close the file
	data = temp;//copies the temp to the data of the signal
	
	
}
Signal::Signal(string name)//contructor called if a string is sent
{
	char nameC[name.size()+1];//as 1 char space for null is also required
	strcpy(nameC, name.c_str());
	int length;
	double maxV;
	
	FILE *fp;

	fp = fopen(nameC, "r");

	fscanf(fp, "%d %lf", &length, &maxV);//assign values to length and max
	
	vector<double> temp (length);
	int i;
	for(i = 0; i < temp.size(); i++)
	{
		fscanf(fp, "%lf", &temp[i]);//load the values into the data variable
	}
	fclose(fp);//close the file
	
	data = temp;
	
}
Signal::~Signal()//destructor
{
	//cout << "destructor called" << endl;
	//delete[] data;
}

//void Signal::offset(double val)
void Signal::operator+(double val)
{
	int i;
	//cout << val << endl;
	//cout << data.size << endl;
	for(i = 0; i < data.size(); i++)//offsets each value of the array
	{
		data[i] += val;
	}
}

//void Signal::scale(double val)
void Signal::operator*(double val)
{
	int i;
	for(i = 0; i < data.size(); i++)//scales each number of the data array
	{
		data[i] *= val;
	}
	
}

void Signal::centerSig()
{
	statistics();//updates the stat
	operator+(-mean);//calls the mean with that
}

void Signal::normalSig()
{
	statistics();//updates the statistics
	operator*(1.0/maxV);
}

void Signal::statistics()
{
	int i;
	/*maxV = data[0];
	for(i = 0; i < data.size(); i++)
	{
		if(data[i] > maxV)
			maxV = data[i];
	}
*/
	mean = 0.0;
	for(i = 0; i < data.size(); i++)//recalculates the mean
	{
		mean += data[i];
	}
	mean = (mean / data.size());	
	
	
}

void Signal::sigInfo()
{
	statistics();//updates stats before printing the information
	cout << "The signals length is: " << data.size() <<
			"\nThe signals mean is: " << mean <<
			"\nThe signals max value is: " << maxV << endl;
}

void Signal::saveSig(string name)
{
	char nameC[name.size()+1];//as 1 char space for null is also required
	strcpy(nameC, name.c_str());//copies the string and puts it in type char* 
	FILE* fp;
	fp = fopen(nameC, "w");
	
	//cout << "\nFile Opened\n";
	fprintf(fp, "%d %lf\n", data.size(), maxV);//prints the stats
	//cout << "\nParameters saved\n";
	int i;
	for(i = 0; i < data.size(); i++)//prints the data array to the file
	{
		fprintf(fp, "%.3lf\n", data[i]);
	}
	fclose(fp);
	cout << "\nFile Closed\n";
}


void Signal::menu ()
{
	int c = -1;
	string name;
	double op = 0.0;
	while(1)
	{
		cout << "\nEnter a command:"
				"\n1) Offset		2) Scale"
				"\n3) Center		4) Normalize"
				"\n5) Statistic		6) Print Signal"
				"\n7) Save Signal		8) Exit" 
				"\n> ";
		cin >> c;
		//cout << "from menu" << endl;

		switch(c)
		{
			case 1:
				cout << "Choose a value to offset by: ";
				cin >> op;
				operator+(op);
				cout << "\nSignal has been offset" << endl;
				break;
			case 2:
				cout << "Choose a value to scale by: ";
				cin >> op;
				operator*(op);
				cout << "\nSignal has been scaled" << endl;
				break;
			case 3:
				centerSig();
				cout << "Signal has been centered" << endl;
				break;
			case 4:
				normalSig();
				cout << "Signal has been normalized" << endl;
				break;
			case 5:
				statistics();
				cout << "Signal's statistics updated" << endl;
				break;
			case 6:
				sigInfo();
				break;
			case 7:
				cout << "Enter a name for the new file: ";
				cin.ignore(1000, '\n');//makes sure it doesn't take in the newline
				getline (cin,name);
				cout << "\nName loaded\n";
				saveSig(name);
				cout << "Signal saved to the file " << name << endl;
				break;
			case 8:
				cout << "Exiting program" << endl;
				return;
			default:
				cout << "Please enter a command number" << endl;
				break;
			
		}
		//cin.ignore (1000,'\n');
	}
}
//these functions were needed because the data members are private so the non-member operator couldn't access them
int Signal::getLength ()
{
	int len = data.size();
	return len;
}
vector <double> Signal::getInfo(double *max)
{
	*max = maxV;
	return data;
}
void Signal::setData (vector<double> stuff)
{
	data = stuff;

}
void Signal:: setMax (double max)
{
	maxV = max;
	
}

//---------------------------------------------Non-Member Operator----------------------------------------------------

Signal operator+(Signal sig1, Signal sig2)
{
	//this function adds signals together element by element and keeps the max value to be the largest of the two signals before adding
	Signal sig3;
	double max1, max2, max3;
	int len1 = sig1.getLength (), i;
	int len2 = sig2.getLength ();
	if (len1 != len2)//checks to make sure the signals are the same size
	{
		cout << "Signals must have the same length"<< endl;
		return sig3;
	}
	vector <double> data1 (len1);
	vector <double> data2 (len2);
	vector <double> data3 (len1);
	
	data1 = sig1.getInfo(&max1);
	data2 = sig2.getInfo (&max2);
	for (i = 0; i < data1.size(); i++ )
	{
		data3[i] = data1[i] + data2[i];
	}
	
	if (max1 > max2)
	{
		max3 = max1;
	}
	else 
		max3 = max2;
	

	sig3.setData (data3);
	sig3.statistics();
	sig3.setMax (max3);
	
	
	
	return sig3;
	
}



int main(int argc, char* argv[])
{
	int c, num;
	string name;
	//this part demonstrates how the non member operator works
	Signal sig2(1), sig3(1), sig4;
	sig4 = sig2 + sig3;
	sig4.sigInfo();
	
	//this demonstrates how the member operator works
	if (argc == 1)//if there are no command line arguements
	{
		cout << "\nEnter signal by (1)number or (2)name?" << endl;
		cin >> c;
		cin.ignore (1000, '\n');
		
		if (c == 1)//to choose file with a number
		{
			cout << "Enter the file number:";
			cin >> num;
			Signal sig1 (num);
			sig1.menu();
			
		}
		else if (c ==2)
		{
			cout << "Enter the file name:";
			getline (cin, name);
			Signal sig1(name);
			sig1.menu ();
		}
		else
		{
			Signal sig1;
			cout << "signal set to default" << endl;
			sig1.menu();
			}
	}
	else if((strcmp(argv[1], "-n")) == 0)//if there is a -n command line arguement
	{
		if(argv[2][0] >= '0' && argv[2][0] <= '9')
		{
			num = atoi(argv[2]);
			//cout << num << endl;
			Signal sig1 (num);
			sig1.menu();
		}
	}
	else if((strcmp(argv[1], "-f")) == 0)//if there is a if command line arguement
	{
		if(argv[2] != '\0' && argv[2] != NULL)
		{
			name = argv[2];
			Signal sig1 (name);
			sig1.menu ();
		}
	}
	
	return 0;
}
