/*! \file CTriangEquilatero.h
	\brief Declaration of the class TriangEquilatero

	Details.
*/


#ifndef TRIANGEQUILATERO_H
#define TRIANGEQUILATERO_H

#include<iostream>

#include "Triangolo.h"

using namespace std;

/// @class TriangEquilatero
/// @brief to manage an object with the shape of a TriangEquilatero
class TriangEquilatero : public Triangolo
{
protected:
	float lato;

public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	TriangEquilatero();
	TriangEquilatero(float l, float h);
	TriangEquilatero(const TriangEquilatero& r);

	~TriangEquilatero();
	/// @}

	/// @name OPERATORS
	/// @{
	TriangEquilatero& operator=(const TriangEquilatero& r);
	bool operator==(const TriangEquilatero& r);
	/// @}

	/// @name BASIC HANDLING
	/// @{
	void Init();
	void Init(const TriangEquilatero& r);
	void Reset();
	/// @}


	/// @name GETTERS / SETTERS
	/// @{
	void SetLato(float l);
	void SetDim( float l);

	void GetDim(float& l);
	float GetLato();

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
