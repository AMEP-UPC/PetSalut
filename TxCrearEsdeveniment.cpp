#include "pch.h"
#include "TxCrearEsdeveniment.h"
#include <iostream>
#include "PassarellaEsdeveniments.h"
#include "PassarellaVisites.h"
#include "PassarellaPublic.h"

using namespace System;
using namespace std;

void TxCrearEsdeveniment::crear(String^ _nom, int _numeroid, DateTime _data, String^ _hora, String^ _propietari, int _mascota, int _centre, String^ _tipus, String^ _tipus_public)
{
    nom = _nom;
    numeroid = _numeroid;
    data = _data;
    hora = _hora;
    propietari = _propietari;
    mascota = _mascota;
    centre = _centre;
    tipus = _tipus;
    tipus_public = _tipus_public;

}

void TxCrearEsdeveniment::executar() {

    try {

        PassarellaEsdeveniments esde(numeroid, nom, data, hora, propietari, tipus);
        esde.crear();

        if (tipus == "Public") {
            PassarellaPublic prop(tipus_public, numeroid);
            prop.crear();
        }
        else if (tipus == "Privat") {
            PassarellaVisites^ visitacreat = PassarellaVisites::crear(numeroid, mascota, centre);
        }

    }

    catch (Exception^ ex) {
        throw ex;
    }
   
}
