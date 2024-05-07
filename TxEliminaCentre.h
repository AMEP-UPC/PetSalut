#pragma once
#include <iostream>
using namespace System;
using namespace std;
ref class TxEliminaCentre
{
private:
	int chip;
	TxEliminaCentre();

public:
	static TxEliminaCentre^ crear();
	void ejecutar(String^ numero_ID);
};

