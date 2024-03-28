#pragma once
#include "pch.h"
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include <windows.h>
#include <string>
#include "DBConnection.h"

using namespace System;

ref class PasarellaUsuari {



public:

	String^ nom;
	String^ username;
	String^ contrasenya;
	String^ data_naixement;
	String^ correu_electronic;
	String^ descripcio;
	String^ telefon;

	PasarellaUsuari();
	void insereix();
	void esborra();

};