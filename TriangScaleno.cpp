/// \file TriangScaleno.cpp
///	\brief class TriangScaleno: implementation of the functions
///
///	Details.
///

#include <math.h>
#include<iostream>
#include "TriangScaleno.h"

/// @brief default constructor 
TriangScaleno::TriangScaleno() {

	cout << "TriangScaleno - constructor - default" << endl;

	Init();

}

/// @brief constructor 
/// @param w width of the TriangScaleno
/// @param h height of the TriangScaleno
TriangScaleno::TriangScaleno(float l1, float l2, float l3) {

	Init();

	cout << "TriangScaleno - constructor" << endl;

	if (l1 <= 0. || l2 <= 0. || l3<= 0.) {
		WarningMessage("constructor: height and side should be > 0");
		SetDim(0,0,0);
	}
	else if (l1 < l2+l3 || l2 < l1+l3 || l3 < l1+l2)
	/*in un triangolo ogni lato deve essere minore della somma degli altri due*/ 
	{
		WarningMessage("constructor: height and side should be > 0");
		SetDim(0,0,0);
	}
	else
		SetDim(l1,l2,l3);

}

/// @brief destructor 
TriangScaleno::~TriangScaleno() {

	cout << "TriangScaleno - destructor" << endl;
	Reset();

}

/// @brief copy constructor 
/// @param o reference to the object that should be copied 
TriangScaleno::TriangScaleno(const TriangScaleno& r) {

	cout << "TriangScaleno - copy constructor" << endl;

	Init(r);

}

/// @brief overload of operator = 
/// @param o reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
TriangScaleno& TriangScaleno::operator=(const TriangScaleno& r) {

	cout << "TriangScaleno - operator =" << endl;

	Init(r);

	return *this;

}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two objects have the same width and the same length  
bool TriangScaleno::operator==(const TriangScaleno& r) {

	if (r.lato1 == lato1 && r.lato2 == lato2 && r.lato3 == lato3)
		return true;

	return false;
}

/// @brief default initialization of the object
void TriangScaleno::Init() {
	SetDim(0,0,0);

}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void TriangScaleno::Init(const TriangScaleno& r) {
	Init();
	SetDim(r.lato1, r.lato2, r.lato3);
}

/// @brief total reset of the object  
void TriangScaleno::Reset() {

	SetDim(0,0,0);

}


void TriangScaleno::SetLato1(float l1) {

	if (l1 < 0. && l1< lato2+lato3) {
		WarningMessage("SetSide: side should be > 0");
		return;
	}

	SetDim(l1,lato2, lato3);

}

void TriangScaleno::SetLato2(float l2) {

	if (l2 < 0. && l2 < lato1 + lato3) {
		WarningMessage("SetSide: side should be > 0");
		return;
	}

	SetDim(lato1, l2, lato3);

}

void TriangScaleno::SetLato3(float l3) {

	if (l3 < 0. && l3 < lato1 + lato2) {
		WarningMessage("SetSide: side should be > 0");
		return;
	}

	SetDim(lato1, lato2, l3);

}

float TriangScaleno::GetLato1() {

	return lato1;
}

float TriangScaleno::GetLato2() {

	return lato2;
}

float TriangScaleno::GetLato3() {

	return lato3;
}

/// @brief set width and length of the object
/// @param w width 
/// @param h height
void TriangScaleno::SetDim(float l1, float l2, float l3) {

	lato1 = l1;
	lato2 = l2;
	lato3 = l3;
	float p = (lato1 + lato2 + lato3) / 2;
	float area = sqrt(p * (p - lato1) * (p - lato2) * (p - lato3));
	Triangolo::SetBase(lato1);
	Triangolo::SetAltezza((2*area)/lato1);

	return;
}

/// @brief get width and length of the object
/// @param w width 
/// @param h height
void TriangScaleno::GetDim(float& l1, float& l2, float& l3) {

	l1 = lato1;
	l2 = lato2;
	l3 = lato3;
	return;
}

/// @brief computes the area of the object
/// @return the area 
float TriangScaleno::GetPerimetro() {

	return lato1+lato2+lato3;
}


/// @brief write an error message 
/// @param string message to be printed
void TriangScaleno::ErrorMessage(const char* string) {

	cout << endl << "ERROR -- TriangScaleno --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void TriangScaleno::WarningMessage(const char* string) {

	cout << endl << "WARNING -- TriangScaleno --";
	cout << string << endl;

}


/// @brief for debugging: all about the object
void TriangScaleno::Dump() {
	cout << endl;
	cout << "---TriangScaleno---" << endl;
	cout << endl;

	cout << "Lato1 = " << lato1 << endl;
	cout << "Lato2 = " << lato2 << endl;
	cout << "Lato3 = " << lato3 << endl;
	Triangolo::Dump();

	cout << endl;

}