/// \file TriangEquilatero.cpp
///	\brief class TriangEquilatero: implementation of the functions
///
///	Details.
///

#include <math.h>
#include<iostream>
#include "TriangEquilatero.h"

/// @brief default constructor 
TriangEquilatero::TriangEquilatero() {

	cout << "TriangEquilatero - constructor - default" << endl;

	Init();

}

/// @brief constructor 
/// @param w width of the TriangEquilatero
/// @param h height of the TriangEquilatero
TriangEquilatero::TriangEquilatero(float l, float h) {

	Init();

	cout << "TriangEquilatero - constructor" << endl;

	if (l <= 0. || h <= 0.) {
		WarningMessage("constructor: height and side should be > 0");
		SetDim(0);
	}
	else
		SetDim(l);

}

/// @brief destructor 
TriangEquilatero::~TriangEquilatero() {

	cout << "TriangEquilatero - destructor" << endl;
	Reset();

}

/// @brief copy constructor 
/// @param o reference to the object that should be copied 
TriangEquilatero::TriangEquilatero(const TriangEquilatero& r) {

	cout << "TriangEquilatero - copy constructor" << endl;

	Init(r);

}

/// @brief overload of operator = 
/// @param o reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
TriangEquilatero& TriangEquilatero::operator=(const TriangEquilatero& r) {

	cout << "TriangEquilatero - operator =" << endl;

	Init(r);

	return *this;

}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two objects have the same width and the same length  
bool TriangEquilatero::operator==(const TriangEquilatero& r) {

	if ( r.lato == lato)
		return true;

	return false;
}

/// @brief default initialization of the object
void TriangEquilatero::Init() {
	SetDim(0);

}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void TriangEquilatero::Init(const TriangEquilatero& r) {
	Init();
	SetDim(r.lato);
}

/// @brief total reset of the object  
void TriangEquilatero::Reset() {

	SetDim(0);

}


void TriangEquilatero::SetLato(float l) {

	if (l < 0.) {
		WarningMessage("SetSide: side should be > 0");
		return;
	}

	SetDim(l);

}

float TriangEquilatero::GetLato() {

	return lato;
}

/// @brief set width and length of the object
/// @param w width 
/// @param h height
void TriangEquilatero::SetDim(float l) {

	lato = l;
	Triangolo::SetBase(l);
	Triangolo::SetAltezza((l * sqrt(3) / 2));

	return;
}

/// @brief get width and length of the object
/// @param w width 
/// @param h height
void TriangEquilatero::GetDim(float& l) {

	l = lato;
	return;
}

/// @brief computes the area of the object
/// @return the area 
float TriangEquilatero::GetPerimetro() {

	return 3*lato;
}


/// @brief write an error message 
/// @param string message to be printed
void TriangEquilatero::ErrorMessage(const char* string) {

	cout << endl << "ERROR -- TriangEquilatero --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void TriangEquilatero::WarningMessage(const char* string) {

	cout << endl << "WARNING -- TriangEquilatero --";
	cout << string << endl;

}


/// @brief for debugging: all about the object
void TriangEquilatero::Dump() {
	cout << endl;
	cout << "---TriangEquilatero---" << endl;
	cout << endl;

	cout << "Lato = " << lato << endl;
	Triangolo::Dump();

	cout << endl;

}
