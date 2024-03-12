#include "connection.h"
#include <iostream>

using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace std;

int main() {
	Connection initConnection = Connection();
	MySqlConnection^ conn = initConnection.getConnection();
	
	
	String^ sql = "SELECT * FROM professors WHERE nom = 'Lidia'";
	MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
	MySqlDataReader^ dataReader;
	
	try{
		// obrim la connexi�
		conn->Open();
		// executem la comanda (cmd) que s�ha creat abans del try
		dataReader = cmd->ExecuteReader();
		if (dataReader->Read()) {
			// Es llegeix la informaci� per crear un objecte de tipus Professor
			// Agafarem les columnes per �ndex, la primera �s la 0
			String^ id = dataReader->GetString(0);
			String^ name = dataReader->GetString(1);
			String^ surname = dataReader->GetString(2);
			printf("%s\n", id);
			printf("%s\n", name);
			printf("%s\n", surname);
		}
	} catch (Exception^ ex) {
		// codi per mostrar l�error en una finestra
		MessageBox::Show(ex->Message);
	} finally{
		// si tot va b� es tanca la connexi�
		conn->Close();

	}

}