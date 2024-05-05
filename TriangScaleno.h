/*! \file CTriangScaleno.h
	\brief Declaration of the class TriangScaleno

Details.
*/


#ifndef TRIANGSCALENO_H
#define TRIANGSCALENO_H

#include<iostream>

#include "Triangolo.h"

using namespace std;

/// @class TriangScaleno
/// @brief to manage an object with the shape of a TriangScaleno
class TriangScaleno : public Triangolo
{
protected:
	float lato1;
	float lato2;
	float lato3;

public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	TriangScaleno();
	TriangScaleno(float l1, float l2, float l3);
	TriangScaleno(const TriangScaleno& r);

	~TriangScaleno();
	/// @}

	/// @name OPERATORS
	/// @{
	TriangScaleno& operator=(const TriangScaleno& r);
	bool operator==(const TriangScaleno& r);
	/// @}

	/// @name BASIC HANDLING
	/// @{
	void Init();
	void Init(const TriangScaleno& r);
	void Reset();
	/// @}


	/// @name GETTERS / SETTERS
	/// @{
	void SetLato1(float l1);
	void SetLato2(float l2);
	void SetLato3(float l3);
	void SetDim(float l1, float l2, float l3);

	void GetDim(float& l1, float& l2, float& l3);
	float GetLato1();
	float GetLato2();
	float GetLato3();

	float GetPerimetro();
	/// @}


	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char* string);
	void WarningMessage(const char* string);
	void Dump();
	/// @}

};

#endif
