/*! \file CTriangIsoscele.h
	\brief Declaration of the class TriangIsoscele

	Details.
*/


#ifndef TRIANGISOSCELE_H
#define TRIANGISOSCELE_H

#include<iostream>

#include "Triangolo.h"

using namespace std;

/// @class TriangIsoscele
/// @brief to manage an object with the shape of a TriangIsoscele
class TriangIsoscele : public Triangolo
{
protected:
	float base;
	float altezza;
	float lato;

public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	TriangIsoscele();
	TriangIsoscele(float w, float h, float l);
	TriangIsoscele(const TriangIsoscele& r);

	~TriangIsoscele();
	/// @}

	/// @name OPERATORS
	/// @{
	TriangIsoscele& operator=(const TriangIsoscele& r);
	bool operator==(const TriangIsoscele& r);
	/// @}

	/// @name BASIC HANDLING
	/// @{
	void Init();
	void Init(const TriangIsoscele& r);
	void Reset();
	/// @}


	/// @name GETTERS / SETTERS
	/// @{
	void SetAltezza(float h);
	void SetBase(float w);
	void SetLato(float l);
	void SetDim(float w, float h, float l);

	void GetDim(float& w, float& h, float& l);
	float GetAltezza();
	float GetBase();
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
