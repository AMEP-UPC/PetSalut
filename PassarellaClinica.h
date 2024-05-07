#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace System;
using namespace std;
ref class PassarellaClinica
{
private:
	String^ username;

public:
	PassarellaClinica::PassarellaClinica() : PassarellaClinica("") {}

	PassarellaClinica(String^ _username);

	PassarellaClinica^ crear();

	PassarellaClinica(const PassarellaClinica^ p);

	property String^ Username {
		String^ get() { return username; }
		void set(String^ value) { username = value; }
	}
	vector<String^> obtenerCentres();
};

