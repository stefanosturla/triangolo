/// \file TriangIsoscele.cpp
///	\brief class TriangIsoscele: implementation of the functions
///
///	Details.
///

#include<iostream>
#include "TriangIsoscele.h"

/// @brief default constructor 
TriangIsoscele::TriangIsoscele() {

	cout << "TriangIsoscele - constructor - default" << endl;

	Init();

}

/// @brief constructor 
/// @param w width of the TriangIsoscele
/// @param h height of the TriangIsoscele
TriangIsoscele::TriangIsoscele(float w, float h, float l) {

	Init();

	cout << "TriangIsoscele - constructor" << endl;

	if (w <= 0. || h <= 0. || l<=0.) {
		WarningMessage("constructor: with, height and side should be > 0");
		SetDim(0, 0, 0);
	}
	else
		SetDim(w, h, l);

}

/// @brief destructor 
TriangIsoscele::~TriangIsoscele() {

	cout << "TriangIsoscele - destructor" << endl;
	Reset();

}

/// @brief copy constructor 
/// @param o reference to the object that should be copied 
TriangIsoscele::TriangIsoscele(const TriangIsoscele& r) {

	cout << "TriangIsoscele - copy constructor" << endl;

	Init(r);

}

/// @brief overload of operator = 
/// @param o reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
TriangIsoscele& TriangIsoscele::operator=(const TriangIsoscele& r) {

	cout << "TriangIsoscele - operator =" << endl;

	Init(r);

	return *this;

}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two objects have the same width and the same length  
bool TriangIsoscele::operator==(const TriangIsoscele& r) {

	if (r.base == base && r.altezza == altezza && r.lato== lato)
		return true;

	return false;
}

/// @brief default initialization of the object
void TriangIsoscele::Init() {
	SetDim(0, 0, 0);

}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void TriangIsoscele::Init(const TriangIsoscele& r) {
	Init();
	SetDim(r.base, r.altezza, r.lato);
}

/// @brief total reset of the object  
void TriangIsoscele::Reset() {

	SetDim(0, 0, 0);

}


/// @brief set width of the object
/// @param w width 
void TriangIsoscele::SetBase(float w) {

	if (w < 0.) {
		WarningMessage("SetWidth: width should be > 0");
		return;
	}

	SetDim(w, altezza, lato);

}

/// @brief set length of the object
/// @param h height 
void TriangIsoscele::SetAltezza(float h) {

	if (h < 0.) {
		WarningMessage("SetHeight: height should be > 0");
		return;
	}

	SetDim(base, h, lato);

}

void TriangIsoscele::SetLato(float h) {

	if (h < 0.) {
		WarningMessage("SetSide: side should be > 0");
		return;
	}

	SetDim(base, altezza, h);

}



/// @brief get width of the object
/// @return width 
float TriangIsoscele::GetBase() {

	return base;

}

/// @brief get length of the object
/// @return height
float TriangIsoscele::GetAltezza() {

	return altezza;
}

float TriangIsoscele::GetLato() {

	return lato;
}

/// @brief set width and length of the object
/// @param w width 
/// @param h height
void TriangIsoscele::SetDim(float w, float h, float l) {

	base = w;
	altezza = h;
	lato = l;
	Triangolo::SetBase(w);
	Triangolo::SetAltezza(h);

	return;
}

/// @brief get width and length of the object
/// @param w width 
/// @param h height
void TriangIsoscele::GetDim(float& w, float& h, float& l) {

	w = base;
	h = altezza;
	l = lato;
	return;
}

/// @brief computes the area of the object
/// @return the area 
float TriangIsoscele::GetPerimetro() {

	return (2*lato)+ base;
}


/// @brief write an error message 
/// @param string message to be printed
void TriangIsoscele::ErrorMessage(const char* string) {

	cout << endl << "ERROR -- TriangIsoscele --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void TriangIsoscele::WarningMessage(const char* string) {

	cout << endl << "WARNING -- TriangIsoscele --";
	cout << string << endl;

}


/// @brief for debugging: all about the object
void TriangIsoscele::Dump() {
	cout << endl;
	cout << "---TriangIsoscele---" << endl;
	cout << endl;

	cout << "Base = " << base << endl;
	cout << "Altezza = " << altezza << endl;
	cout << "Lato = " << lato << endl;


	Triangolo::Dump();

	cout << endl;

}
