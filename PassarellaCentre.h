#pragma once
#include <iostream>
#include <string>
using namespace System::Collections::Generic;
using namespace System;
using namespace std;

ref class PassarellaCentre
{
private:
    String^ numero_ID;
    String^ nom;
    String^ telefon;
    String^ clinica;
  

public:
    // Constructor
    PassarellaCentre(String^ _numero_ID, String^ _nom, String^ _telefon, String^ _clinica);
    static PassarellaCentre^ crear(String^ _numero_ID, String^ _nom, String^ _telefon, String^ _clinica);
    static PassarellaCentre^ eliminar(String^ _numero_ID);
    // Getters y setters
    property String^ Numero_ID {
        String^ get() { return numero_ID; }
        void set(String^ value) { numero_ID = value; }
    }

    property String^ Nom {
        String^ get() { return nom; }
        void set(String^ value) { nom = value; }
    }

    property String^ Telefon {
        String^ get() { return telefon; }
        void set(String^ value) { telefon = value; }
    }

    property String^ Clinica {
        String^ get() { return clinica; }
        void set(String^ value) { clinica = value; }
    }
};