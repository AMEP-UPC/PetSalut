#include "pch.h"
#include "TxCrearCentre.h"
#include <iostream>
#include "PassarellaCentre.h"
using namespace System;
using namespace std;
// Implementaci�n de la funci�n para crear una nueva mascota
TxCrearCentre^ TxCrearCentre::crear(String^ _numero_ID, String^ _nom, String^ _telefon, String^ _clinica) {
    return gcnew TxCrearCentre(_numero_ID, _nom, _telefon, _clinica);
}

void TxCrearCentre::ejecutar()
{
    PassarellaCentre::crear(numero_ID, nom, telefon, clinica);
}

// Constructor privado para evitar instanciaci�n directa
TxCrearCentre::TxCrearCentre(String^ _numero_ID, String^ _nom, String^ _telefon, String^ _clinica) {
    numero_ID = _numero_ID;
    nom = _nom;
    telefon = _telefon;
    clinica = _clinica;

}