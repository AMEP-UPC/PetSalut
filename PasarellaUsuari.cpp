#include "PasarellaUsuari.h"

using namespace std;
using namespace System::IO;
using namespace MySql::Data::MySqlClient;

PasarellaUsuari::PasarellaUsuari() {

    string nom = "";
    string sobrenom = "";
    string contrasenya = "";
    string data_naixament = "";
    string correu_electronic = "";
    string descripcio = "";
    string telefon = "";

}


void PasarellaUsuari::insereix()
{

    MySqlConnection^ conn = (gcnew DBConnection())->getConnection();

    String^ sql = "INSERT INTO propietaris VALUES (@username, @nom, @contrasenya, @correu, @telefon, @descripcio);";

    MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);

    cmd->Parameters->AddWithValue("@username", username);
    cmd->Parameters->AddWithValue("@nom", nom);
    cmd->Parameters->AddWithValue("@contraseya", contrasenya);
    cmd->Parameters->AddWithValue("@correu", correu_electronic);
    cmd->Parameters->AddWithValue("@telefon", telefon);
    cmd->Parameters->AddWithValue("@descripcio", descripcio);

    MySqlDataReader^ dataReader;

}

void PasarellaUsuari::esborra()
{



}
