#pragma once
#include "PassarellaCentre.h"
#include <string>
using namespace System::Collections::Generic;
using namespace System;
using namespace std;
ref class CercadoraCentre
{
public:

	static PassarellaCentre^ cercaCentre(String^ numero_ID);

};

