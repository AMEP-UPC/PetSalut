#include "pch.h"
#include "CercadoraCentre.h"
#include "DBConnection.h" 
#include <string>
using namespace System::Collections::Generic;
using namespace System;
using namespace std;

PassarellaCentre^ CercadoraCentre::cercaCentre(String^ numero_ID)
{
    PassarellaCentre^ centreTrobat = nullptr;

    MySqlConnection^ conn = (gcnew DBConnection())->getConnection();

    String^ sql = "SELECT * FROM centre WHERE numero_ID = @numero_ID";

    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);

    cmd->Parameters->AddWithValue("@numero_ID", numero_ID);

    try {
        conn->Open();
        MySqlDataReader^ reader = cmd->ExecuteReader();

        if (reader->Read()) {
            // Si se encontró una mascota, crea un objeto PassarellaMascota con los datos obtenidos
            String^ _numero_ID = reader["numero_ID"]->ToString();
            String^ _nom = reader["nom"]->ToString();
            String^ _telefon = reader["telefon"]->ToString();
            String^ _clinica = reader["clinica"]->ToString();

            centreTrobat = gcnew PassarellaCentre(_numero_ID, _nom, _telefon, _clinica);
        }

        reader->Close();
    }
    catch (Exception^ ex) {
        throw gcnew Exception("Hi ha hagut un error amb el numero de identificació");
    }
    finally {
        conn->Close();
    }

    return centreTrobat;
}