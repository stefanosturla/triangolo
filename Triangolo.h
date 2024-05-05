/*! \file Triangolo.h
	\brief Declaration of the general class Triangolo

	Details.
*/


#ifndef TRIANGOLO_H
#define TRIANGOLO_H

#include<iostream>

using namespace std;

/// @class Triangolo
/// @brief an abstract base class for Triangolo
class Triangolo {
protected: 

	float base;
	float altezza;

	void SetBase(float s1);
	void SetAltezza(float s1);



public:  

/// @name CONSTRUCTORS/DESTRUCTOR
/// @{
	Triangolo();
	Triangolo(const Triangolo& o);
	virtual ~Triangolo();
	/// @}

	/// @name OPERATORS
	/// @{
	Triangolo& operator=(const Triangolo& o);
	bool operator==(const Triangolo& o);
	/// @}

	/// @name BASIC HANDLING
	/// @{
	void Init();
	void Init(const Triangolo& o);
	void Reset();
	/// @}


	/// @name GETTERS
	/// @{
	float GetArea();
	void GetBase(float& s0);
	void GetAltezza(float& s0);
	/// @}

	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char* string);
	void WarningMessage(const char* string);
	void Dump();
	/// @}

};

#endif
