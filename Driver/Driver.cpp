/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for assignment
Fall 2019
Written by Ayse Kucukyilmaz
This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure
you follow that guideline. Also make sure that you don't
change the main body provided to you here.
Otherwise, your code may not pass the test cases...
GOOD LUCK!
------------------------------------------------------ */

#include <iostream>
#include <string>

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Movable.h"


using namespace std;
void strcpy_s(char* destination, int size, const char* source);
void strtok_s(vector<string>& outputVector, char* str);
int main()
{
	string userCommand;         
	vector <Shape*> shapes;    
	vector <string> parameters;

	int x = 0;                 
	int y = 0;                 

	while (userCommand.compare("exit") != 0)
	{
		cout << "Enter the command: ";
		getline(cin, userCommand);

		char* cstr = new char[userCommand.length() + 1];
		strcpy_s(cstr, userCommand.length() + 1, userCommand.c_str());

		
		strtok_s(parameters, cstr);
		string command = parameters[0];


		// in the following code, consider checking for the arguments.
		// in case of too few arguments, you may remind the user the correct format

		if (command.compare("addR") == 0) {
			// get parameters in the correct order
			// The following four lines have a type mismatch error
			// note that the parameters vector contains ascii values
			// HINT: toString() function converts from string to int

			int w = 0;                  // width of the shape
			int h = 0;                  // height of the shape

			x = atoi(parameters[1].c_str()); // fix me! not defined :(
			y = atoi(parameters[2].c_str());
			h = atoi(parameters[3].c_str());
			w = atoi(parameters[4].c_str());

			Rectangle* r = new Rectangle(x, y, h, w);
			shapes.push_back(r);
			cout << r->toString();       /* instead of this, you may implement operator overloading and
											use cout << r which will give you additional points */
		}
		else if (command.compare("addS") == 0) {

			// get parameters
			// ...
			x = atoi(parameters[1].c_str()); // fix me! not defined :(
			y = atoi(parameters[2].c_str());
			int e = atoi(parameters[3].c_str());


			Square* s = new Square(x, y, e);
			shapes.push_back(s);
			cout << s->toString();
		}


		if (command.compare("addC") == 0) {
			// get parameters
			// ...
			x = atoi(parameters[1].c_str()); // fix me! not defined :(
			y = atoi(parameters[2].c_str());
		    int r = atoi(parameters[3].c_str());

			Circle* c = new Circle(x, y, r);
			shapes.push_back(c);
			cout << c->toString();

		}
		else if (command.compare("scale") == 0) {
		}
		else if (command.compare("move") == 0) {
			int shapeNo{}; 
			Movable* m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
			m->move(x, y);
			cout << shapes[shapeNo - 1]->toString();
		}
		else if (command.compare("display") == 0) {
		}

		cout << endl << endl;
	}

	cout << "Press any key to continue...";
	std::getchar();

	return 0;
}


void strcpy_s(char* destination, int size, const char* source) {
	for (int i = 0; i < size; i++) {
		*destination++ = source[i];
	}
	*destination += '\0';
}
void strtok_s(vector<string>& outputVector, char* str)
{
	string temp;
	for (str; *str; ++str) {
		if (*str != ' ')
		{
			temp += *str;
		}
		else
		{
			outputVector.push_back(temp);
			temp = "";
		}
	}
	outputVector.push_back(temp);
}