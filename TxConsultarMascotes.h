#pragma once
#include <string>
#include "PasarellaPropietari.h"
using namespace System;
using namespace std;

ref class TxConsultarMascotes
{
private:
    PasarellaPropietari^ propietari;
    // Constructor
    TxConsultarMascotes(PasarellaPropietari^ _propietari);

public:
  
    
    // Funci�n para crear una instancia de TxConsultarMascotes
    static TxConsultarMascotes^ crear(PasarellaPropietari^ _propietari);
    vector<int> obteResultat();
 

};
