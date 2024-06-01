#pragma once
#include <iostream>
using namespace System;
using namespace std;

ref class TxCrearEsdeveniment
{
private:

    int numeroid;
    String^ nom;
    DateTime data;
    String^ hora;
    String^ propietari;
    int mascota;
    int centre;
    String^ tipus;
    String^ tipus_public;

public:

    void crear(String^ _nom, int numeroid, DateTime _data, String^ _hora, String^ _propietari, int _mascota, int _centre, String^ _tipus, String^ _tipus_public);
    void executar();

};

