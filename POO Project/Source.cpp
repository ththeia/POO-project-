#include "BuildingClasses.h"
#include <iostream>
#include<string>


using namespace std;

class Validate : public exception {
public:
	Validate(string message) : exception(message.c_str()) {

	}
};


int main() {
	
}
