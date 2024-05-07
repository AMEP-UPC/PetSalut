#pragma once
#include <iostream>
using namespace System;
using namespace std;
ref class TxCrearCentre
{
private:
    String^ numero_ID;
    String^ nom;
    String^ telefon;
    String^ clinica;
    TxCrearCentre(String^ _numero_ID, String^ _nom, String^ _telefon, String^ _clinica);
public:
    // Constructor
    static TxCrearCentre^ crear(String^ _numero_ID, String^ _nom, String^ _telefon, String^ _clinica);
    void ejecutar();

};
