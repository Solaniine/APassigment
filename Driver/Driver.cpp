
#include <iostream>
#include <string>
#include <vector>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Movable.h"


using namespace std;

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
void strcpy_s(char *destination, int size, const char *source);

void strtok_s(vector<string>& outputVector, char* str);



int main()
{
	vector <Shape*> shapes;
	vector <string> parameters;
	string userCommand;
    int x = 0;
    int y = 0;           

	while (userCommand.compare("exit") != 0)
	{
		cout << "Enter the command: ";
		getline(cin, userCommand);

		char * cstr = new char[userCommand.length() + 1];

        // this function copies the string 'userCommand' into 'cstr'
        strcpy_s(cstr, userCommand.length()+1, userCommand.c_str());
        strtok_s(parameters, cstr);

		string command = parameters[0];



		if (command.compare("addR") == 0) {


			int w = 0; int h = 0;

			x = atoi(parameters[1].c_str()); 
			y = atoi(parameters[2].c_str());
			h = atoi(parameters[3].c_str());
			w = atoi(parameters[4].c_str());

			Rectangle* r = new Rectangle(x, y, h, w);
			shapes.push_back(r);
			cout << r;
		}
		else if (command.compare("addS") == 0) {

            x = atoi(parameters[1].c_str());
            y = atoi(parameters[2].c_str());
            int e = atoi(parameters[3].c_str());

			Square* s = new Square(x, y, e);
			shapes.push_back(s);
			cout << s;
		}

		if (command.compare("addC") == 0) {
			// get parameters
			// ...
            x = atoi(parameters[1].c_str()); 
            y = atoi(parameters[2].c_str());
            int r = atoi(parameters[3].c_str());

			Circle* c = new Circle(x, y, r);
			shapes.push_back(c);
			cout << c;

		}
		else if (command.compare("scale") == 0) {

			int shapeNo = atoi(parameters[1].c_str());
			float scaleX = atoi(parameters[2].c_str());
			float scaleY = atoi(parameters[3].c_str());

			Movable* m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
			m->scale(scaleX, scaleY);

			cout << shapes[shapeNo - 1]->toString();
		}
		else if (command.compare("move") == 0) {
			int shapeNo = atoi(parameters[1].c_str());
			Movable *m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
            x = atoi(parameters[2].c_str());
            y = atoi(parameters[3].c_str());
            m->move(x, y);
		}
		else if (command.compare("display") == 0) {
            for (auto shape : shapes) {
                cout << shape << "\n" << endl;
            }
        }
        else if (command.compare("exit") == 0){break;}
        parameters.clear();
        cout << endl << endl;
        delete[] cstr;
        userCommand = "";

	//	std::getchar();

    }

	cout << "Press any key to continue...";

	return 0;
}
