#include "pch.h"
#include "TxRegistraUsu.h"

void TxRegistraUsu::crear(String^ usernameS, String^ contrasenyaS, String^ nomComplertS, String^ telefonS, String^ tipusS, String^ correuElectronicS, String^ descripcioS, String^ dataS)
{

    username = usernameS;
    contrasenya = contrasenyaS;
    nomComplert = nomComplertS;
    telefon = telefonS;
    tipus = tipusS;
    correuElectronic = correuElectronicS;
    descripcio = descripcioS;
    data = dataS;

}

void TxRegistraUsu::executar()
{
    try {

        PassarellaUsuari usu(username, nomComplert, contrasenya, correuElectronic, telefon, tipus, descripcio);
        usu.crear();

       if (tipus == "propietari") {

            PassarellaPropietari prop(data, username);
            prop.crear();

        }

    }

    catch (Exception^ ex) {

        throw ex;

    }

}
