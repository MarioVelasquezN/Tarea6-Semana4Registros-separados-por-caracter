#include "person.h"
#include <fstream>
#include <string>
using namespace std;

void Person::writeFile() {
	ofstream personasOut("personas.dat", ios::app);

	if (!personasOut) {
		cout << "Personas archivo no encontrado!!";
		return;
	}
	
	Personaa x;
	int numero = 0;
	int temp = 0;
	cout << "**********ingreso de personas!!**********\n\n";

	cout << "Cuantos alumnos desea ingresar: ";
	cin >> numero;

	for (int i = 1; i <=numero; i++) {
		cout << "Ingrese primer nombre: \n";
		cin >> x.fisrtname;
		strcat_s(x.fisrtname, sizeof(x.fisrtname), ";\r\n");
		cout << "Ingrese apellido: \n";
		cin >> x.lastname;
		strcat_s(x.lastname, sizeof(x.lastname), ";\r\n");
		cout << "Ingrese direccion: \n";
		cin >> x.address;
		strcat_s(x.address, sizeof(x.address), ";\r\n");
		cout << "Ingrese cuidad: \n";
		cin >> x.city;
		strcat_s(x.city, sizeof(x.city), ";\r\n");
		cout << "ingrese Estado: \n";
		cin >> x.state;
		strcat_s(x.state, sizeof(x.state), ";\r\n");
		cout << "ingrese codigo zip: \n";
		cin >> x.zipcode;
		strcat_s(x.zipcode, sizeof(x.zipcode), ";\r\n");
		
		personasOut << x.fisrtname << "\t" << x.lastname << "\t" << x.address << "\t" << x.city << "\t" << x.state << "\t" << x.zipcode << "\t";
	}

	personasOut.close();
}

void Person::readFile() {
	ifstream personIn("personas.dat", ios::in);

	if (!personIn) {
		cout << "error al abrir el archivo!!!";
		return;
	}
	string palabra="0";
	
	cout << "**********************Consulta de personas**********************\n\n";
	//cout << "Primer Nombre" << "|" << "Apellido" << "|" << "Direccion" << "|" << "Cuidad" << "|" << "Estado" << "|" << "ZipCode"<<"\n";

	/*while (personIn >> FirstName >> LastName >> Address >> City >> State >> ZipCode) {
		
		cout <<"Primer Nombre: "<<FirstName << "\n"<<"Apellido: "<< LastName << "\n"<< "Dirreccio: "<< Address << "\n"<<
			"Cuidad: " << City << "\n"<<"Departamento: " << State << "\n"<<"Codigo postal: " << ZipCode << "\r\n";
	}*/
	cout << "Primer Nombre: "<<"\t" << "Apellido: " << "\t" << "Dirreccio: " <<"\t" <<
		"Cuidad: "<< "\t" << "Departamento: "<< "\t" << "Codigo postal: "<< "\n";

	while (getline(personIn,palabra,';')) {
		
		cout << palabra<<"\t\t";

	}

	personIn.close();
}
