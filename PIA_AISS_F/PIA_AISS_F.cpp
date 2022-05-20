#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

int i = 0;
int k = 0;

struct Cita {
	string hora;
	string nombre;
	string tratamiento;
	string numero_cita;
	Cita* anterior = nullptr;
	Cita* posterior = nullptr;
	float precio_total = 0, precio_unitario = 0;
};

int cita_actual = 1;
int cita_borrar;
Cita* primer_cita = nullptr;
Cita* ultima_cita = nullptr;
Cita* demo_cita = nullptr;

ifstream archivo_g;
ofstream archivo;

void crear_cita(string nombre) {
	Cita* nueva_cita = new Cita[i];

	nueva_cita->nombre = nombre;

	nueva_cita->numero_cita = to_string(cita_actual);

	if (cita_actual == 1) {
		primer_cita = nueva_cita;
		ultima_cita = nueva_cita;
	}
	else {
		nueva_cita->anterior = ultima_cita;
		ultima_cita->posterior = nueva_cita;
		ultima_cita = nueva_cita;
	}
	cita_actual++;
}

void imprimir_citas() {
	if (primer_cita) {

		demo_cita = primer_cita;

		while (demo_cita) {

			cout << "/nNombre: " << demo_cita->nombre << endl;
			cout << "#" << demo_cita->numero_cita << endl;

			if (demo_cita->anterior) {
				cout << "Nombre anterior de la persona citada: " << demo_cita->anterior->nombre << endl;
			}
			if (demo_cita->posterior) {
				cout << "Nombre posterior de la persona citada: " << demo_cita->posterior->nombre << endl;
			}
			demo_cita = demo_cita->posterior;
		}
	}
}

void guardar_citas() {
	ofstream archivo;

	archivo.open("citas_registro.txt");


	if (archivo.is_open()) {
		demo_cita;
		demo_cita = primer_cita;

		while (demo_cita) {
			archivo << demo_cita->nombre << endl;
			archivo << demo_cita->numero_cita << endl;
			demo_cita = demo_cita->posterior;


		}
		archivo.close();
	}
	else {
		cout << "Ha ocurriodun error, verifique manualmente si el archivo de registro de citas existe\n";
	}
}

bool existen = false;

int main() {
	Cita citas[50];

	int cita = 0, opcion = 1;
	bool repetir = true;

	while (opcion != 0) {

		cout << "**Clinica dental Dentalsa**\n\n";

		cout << "Menu principal\n\n";

		cout << "1. Agendar cita\n";
		cout << "2. Modificar cita\n";
		cout << "3. Eliminar cita\n";
		cout << "4. Lista de citas vigentes\n";
		cout << "0. Salir\n";

		cout << "\nDigite una opcion\n\n";
		cin >> opcion;

		system("cls");

		int j = 1;
		switch (opcion) {
		case 1:

			while (j != 0) {

				archivo.open("citas_registro.txt");

				cout << "Introduzca su nombre completo por favor: \n";
				cin.ignore();
				getline(cin, citas[i].nombre);

				archivo << citas[i].nombre;

				system("cls");

				cout << "Digite la hora de la cita en formato de 24 horas\n(ejemplo; 16:13)?: \n";
				getline(cin, citas[i].hora);

				archivo << citas[i].hora;

				system("cls");

				cout << "Escriba el tratamiento que se desea, junto con su precio: \n\n";
				cout << "1. Empaste $200\n" << "Descripcion: Un sellador de surcos, para devolver la estetica y funcionalidad de un diente\n\n";
				cout << "2. Extarccion $400\n" << "Descripcion: Retiro de una pieza dental\n\n";
				cout << "3. Limpieza $150\n" << "Descripcion: Procedimiento para limpiar la placa y el sarro de sus dientes\n\n";
				getline(cin, citas[i].tratamiento);

				archivo << citas[i].tratamiento;

				system("cls");

				cout << "¿Desea agendar otra cita?: \n\n";
				cout << "1. Si\n";
				cout << "0. No\n\n";
				k++;
				i++;

				guardar_citas();

				existen = true;
				cin >> j;

				archivo.close();

				system("cls");
			}break;

		case 2:
			while (j != 0) {

				archivo.open("citas_registro.txt");

				int cita_mod = 0;
				if (existen == true) {
					cout << "¿Desea modificar la cita mas reciente?, si es asi, digite '1'\n\n";

					for (int i = 0; i <= k; i++) {

						cout << "Cita: " << i + 1 << "\n";

						cout << "Nombre completo del paciente: \n" << citas[i].nombre;
						cout << "\nHora de su cita: \n" << citas[i].hora;
						cout << "\ntratamiento deseado: \n" << citas[i].tratamiento << "\n\n";
					}

					cin >> cita_mod;
					system("cls");

					if (cita_mod = i) {

						cout << "Ingrese el nuevo nombre completo del paciente\n";
						getline(cin, citas[i].nombre);

						archivo << citas[i].nombre;

						system("cls");

						cout << "Digite la nueva hora de la cita en formato de 24 horas\n(ejemplo; 16:13)?: \n";
						getline(cin, citas[i].hora);

						archivo << citas[i].hora;

						system("cls");

						cout << "Escriba el nuevo tratamiento que se desea, junto con su precio: \n\n";
						cout << "1. Empaste $200\n" << "Descripcion: Un sellador de surcos, para devolver la estetica y funcionalidad de un diente\n\n";
						cout << "2. Extarccion $400\n" << "Descripcion: Retiro de una pieza dental\n\n";
						cout << "3. Limpieza $150\n" << "Descripcion: Procedimiento para limpiar la placa y el sarro de sus dientes\n\n";
						getline(cin, citas[i].tratamiento);

						archivo << citas[i].tratamiento;

						system("cls");
					}

				}
				else {
					cout << "Todavia no se ha agendado ninguna cita\n";
				}
				cout << "\nDigite 0 para volver al menu principal: \n\n";
				cin >> j;

				archivo.close();

				system("cls");
			}break;

		case 3:
			while (j != 0) {

				archivo.open("citas_registro.txt");

				if (existen == true) {
					cout << "¿Desea eliminar la cita mas reciente?, si es asi, digite '1'\n\n";

					for (int i = 0; i <= k; i++) {

						cout << "Cita: " << i + 1 << "\n";

						cout << "Nombre completo del paciente: \n" << citas[i].nombre;
						cout << "\nHora de su cita: \n" << citas[i].hora;
						cout << "\ntratamiento deseado: \n" << citas[i].tratamiento << "\n\n";
					}
					cin >> cita_borrar;

					if (cita_borrar = i) {
						citas[i].nombre = "";
						citas[i].hora = "";
						citas[i].tratamiento = "";

						archivo << citas[i].nombre;
						archivo << citas[i].hora;
						archivo << citas[i].tratamiento;

						cita_actual = cita_actual - 1;
						k = k - 1;

						cout << "La cita numero #" << cita_borrar << " se ha borrado correctamente\n";

						system("cls");
					}

					for (i = cita_actual; i < cita_actual - 1; i++) {
						citas[i].nombre = "";
						citas[i].hora = "";
						citas[i].tratamiento = "";

						archivo << citas[i].nombre;
						archivo << citas[i].hora;
						archivo << citas[i].tratamiento;

					}
					citas[i].nombre = "";
					citas[i].hora = "";
					citas[i].tratamiento = "";

					archivo << citas[i].nombre;
					archivo << citas[i].hora;
					archivo << citas[i].tratamiento;

					system("cls");
				}
				else {
					cout << "Todavia no se ha agendado ninguna cita\n";
				}
				cout << "\nDigite 0 para volver al menu principal: \n\n";
				cin >> j;

				archivo.close();

				system("cls");
			}break;

		case 4:
			while (j != 0) {

				if (existen == true) {
					cout << "Citas vigentes: \n\n";
					for (int i = 0; i <= k; i++) {

						cout << "Cita: " << i + 1 << "\n";

						cout << "Nombre completo del paciente: \n" << citas[i].nombre;
						cout << "\nHora de su cita: \n" << citas[i].hora;
						cout << "\ntratamiento deseado: \n" << citas[i].tratamiento << "\n\n";
					}
				}
				else {
					cout << "Todavia no se ha agendado ninguna cita\n";
				}

				cout << "\nDigite 0 para volver al menu principal: \n\n";
				cin >> j;

				system("cls");

			}break;

		case 0:

			cout << "Gracias por usar esta aplicacion :D\n\n";

			return 0;
		};

	}
}