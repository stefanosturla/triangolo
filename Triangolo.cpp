#include "Triangolo.h"

/// @brief default constructor 
Triangolo::Triangolo() {

	cout << "Triangolo - constructor - default" << endl;

	Reset();

}

/// @brief copy constructor 
/// @param o reference to the object that should be copied 
Triangolo::Triangolo(const Triangolo& o) {

	cout << "Triangolo - copy constructor" << endl;

	Init(o);
}

/// @brief destructor
Triangolo::~Triangolo() {

	cout << "Triangolo - destructor" << endl;
	Reset();

}


/// @brief sets the value of the four sides 
/// @param s1 side 1 
/// @param s2 side 2 
/// @param s3 side 3
/// @param s4 side 4 
void Triangolo::SetBase(float s1) {

	base = s1;

	return;

}

void Triangolo::SetAltezza(float s1) {

	altezza = s1;

	return;

}

/// @brief overload of operator = 
/// @param o reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
Triangolo& Triangolo::operator=(const Triangolo& o) {

	return *this;

}

/// @brief overload of operator == 
/// @param o reference to the object on the right side of the operator 
/// @return always false 
bool Triangolo::operator==(const Triangolo& o) {

	return false;
}


/// @brief default initialization of the object
void Triangolo::Init() {
	base = altezza = 0.;
}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void Triangolo::Init(const Triangolo& o) {
	Init();
	base = o.base;
	altezza = o.base;

}

/// @brief total reset of the object  
void Triangolo::Reset() {
	base = altezza = 0.;

}


/// @brief get the perimeter of the object
/// @return perimeter 
float Triangolo::GetArea() {

	return (base*altezza)/2;

}

/// @brief get the sides of the object 
/// @param s0 side 0 
/// @param s1 side 1
/// @param s2 side 2
/// @param s3 side 3 
void Triangolo::GetBase(float& s0) {

	s0 = base;

}

void Triangolo::GetAltezza(float& s0) {

	s0 = altezza;

}
/// @brief write an error message 
/// @param string message to be printed
void Triangolo::ErrorMessage(const char* string) {

	cout << endl << "ERROR -- Triangolo --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void Triangolo::WarningMessage(const char* string) {

	cout << endl << "WARNING -- Triangolo --";
	cout << string << endl;

}


/// @brief for debugging: all about the object
void Triangolo::Dump() {

	cout << endl;
	cout << "Base = " << base << endl;
	cout << "Altezza = " << altezza << endl;
	cout << "Area = " << GetArea() << endl;
	cout << endl;

}
