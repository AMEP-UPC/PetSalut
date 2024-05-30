#include "pch.h"
#include "CercadoraValoracio.h"
#include "DBConnection.h" 

PassarellaValoracio^ CercadoraValoracio::cercaValoracio(int numeroid_centre, int numeroid_privat)
{
    PassarellaValoracio^ valoracioEncontrada = nullptr;

    MySqlConnection^ conn = (gcnew DBConnection())->getConnection();

    String^ sql = "SELECT * FROM valoracio WHERE numeroid_centre = @numeroid_centre AND numeroid_privat = @numeroid_privat";

    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);

    cmd->Parameters->AddWithValue("@numeroid_centre", numeroid_centre);
    cmd->Parameters->AddWithValue("@numeroid_privat", numeroid_privat);

    try {
        conn->Open();
        MySqlDataReader^ reader = cmd->ExecuteReader();

        if (reader->Read()) {
            // Si se encontró una valoración, crea un objeto PassarellaValoracio con los datos obtenidos
            int _numeroid_centre = Convert::ToInt32(reader["numeroid_centre"]);
            int _numeroid_privat = Convert::ToInt32(reader["numeroid_privat"]);
            String^ _propietari = reader["propietari"]->ToString();
            int _valor = Convert::ToInt32(reader["valor"]);

            valoracioEncontrada = gcnew PassarellaValoracio(_numeroid_centre, _numeroid_privat, _propietari, _valor);
        }

        reader->Close();
    }
    catch (Exception^ ex) {
        throw gcnew Exception("Hi ha hagut un error amb la cerca de la valoració: " + ex->Message);
    }
    finally {
        conn->Close();
    }

    return valoracioEncontrada;
}
