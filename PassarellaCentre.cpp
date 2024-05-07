#include "pch.h"
#include "PassarellaCentre.h"
#include "DBConnection.h" // <-- Importaci�
#include <string>

using namespace System::Collections::Generic;
using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace System::Windows::Forms;//Per mostrar MessageBox::Show una caixa amb el missatge d'error

PassarellaCentre^ PassarellaCentre::crear(String^ _numero_ID, String^ _nom, String^ _telefon, String^ _clinica)
{

    MySqlConnection^ conn = (gcnew DBConnection())->getConnection(); // <-- Declaraci�

    String^ sql = "INSERT INTO centre (numero_ID, nom, telefon, telefon, clinica) VALUES (@numero_ID, @nom, @telefon, @telefon, @clinica)";

    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);

    // Establecer los par�metros de la consulta con los valores proporcionados
    cmd->Parameters->AddWithValue("@numero_ID", _numero_ID);
    cmd->Parameters->AddWithValue("@nom", _nom);
    cmd->Parameters->AddWithValue("@telefon", _telefon);
    cmd->Parameters->AddWithValue("@clinica", _clinica);

    try {
        // obrim la connexi�
        conn->Open();
        cmd->ExecuteNonQuery();

    }
    catch (Exception^ ex) {
        // codi per mostrar l�error en una finestra
        MessageBox::Show("Error al insertar el centre en la base de datos: " + ex->Message);
    }
    finally {
        // si tot va b� es tanca la connexi�
        conn->Close();
    }
    return gcnew PassarellaCentre(_numero_ID, _nom, _telefon, _clinica);

}

PassarellaCentre^ PassarellaCentre::eliminar(String^ _numero_ID) {

    MySqlConnection^ conn = (gcnew DBConnection())->getConnection(); // <-- Declaraci�

    String^ sql = "DELETE FROM centre WHERE numero_ID = @numero_ID";

    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);

    // Establecer el parámetro de la consulta con el valor proporcionado
    cmd->Parameters->AddWithValue("@numero_ID", _numero_ID);

    try {
        // Abrir la conexión
        conn->Open();
        cmd->ExecuteNonQuery(); // Ejecutar la consulta para eliminar la mascota
    }
    catch (Exception^ ex) {
        // Manejar cualquier excepción y mostrar un mensaje de error
        MessageBox::Show("Error al eliminar el centre de la base de datos: " + ex->Message);
    }
    finally {
        // Cerrar la conexión independientemente de si hubo un error o no
        conn->Close();
    }

    // No necesitamos devolver nada, ya que estamos eliminando la mascota, no creándola
    return nullptr;
}


PassarellaCentre::PassarellaCentre(String^ _numero_ID, String^ _nom, String^ _telefon, String^ _clinica) {
    numero_ID = _numero_ID;
    nom = _nom;
    telefon = _telefon;
    clinica = _clinica;   
}

