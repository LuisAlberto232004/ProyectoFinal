#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;

struct agendar {
	int numc=0;
	string nombre;
	string hora;
	string tratamiento;
	string des;
	float pt=0.0;
	float ct=0.0;
	float t=0.0;
	agendar* anterior = nullptr;
	agendar* siguiente = nullptr;
};

int citaactual = 0;

agendar* primercita = nullptr;
agendar* ultimacita = nullptr;
agendar* auxcita = nullptr;

int main()
{
	int opcion = 0,opc,e;
	
	while (opcion != 5) {
		cout << "\nBienvenido a la pagina de citas dental" << endl;
		cout << "¿Que desea hacer?" << endl;
		cout << "1.Agendar una cita" << endl;
		cout << "2.Modificar una cita" << endl;
		cout << "3.Eliminar una cita" << endl;
		cout << "4.Lista de citas vigentes" << endl;
		cout << "5.SALIR" << endl;
		cout << "Dijite una opcion: ";
		cin >> opcion;
		system("cls");

		switch (opcion) {
		case 1: {
			agendar* nuevacita = new agendar;

			cout << "Agendando Cita" << endl;
			
			cout << "Ingresar el nombre del paciente: ";
			cin.ignore();
			getline(cin, nuevacita->nombre);

			cout << "Hora de inicio del tratamiento (formato 24hrs): ";
			getline(cin, nuevacita->hora);

			cout << "Nombre del tratamiento: ";
			getline(cin, nuevacita->tratamiento);

			cout << "Descripcion: ";
			getline(cin, nuevacita->des);

			cout << "Precio Unitario tratamiento: ";
			cin >> nuevacita->pt;

			cout << "Cantidad del tratamiento: ";
			cin >> nuevacita->ct;

			nuevacita->t = nuevacita->ct * nuevacita->pt;
			cout << "El total es de: " <<nuevacita->t << "$";

			citaactual++;
			nuevacita->numc = citaactual;

			if (citaactual==1) {
				primercita = nuevacita;
				ultimacita = nuevacita;
			}
			else {
				nuevacita->anterior = ultimacita;
				ultimacita->siguiente = nuevacita;
				ultimacita=nuevacita;
			}
			

			cin.ignore();
			cout << "\nPresiona ENTER para volver al menu";
			cin.get();
			system("cls");
			break;
		}

		case 2: {
			auxcita = primercita;
			if (!auxcita) {
				cout << "No Existen citas registradas";
			}
			else {
				while (auxcita) {
					cout << "Cita " <<auxcita->numc<< endl;
					cout << "Nombre del paciente: " << auxcita->nombre << endl;
					cout << "Hora de su tratamiento: " << auxcita->hora << endl << endl;
					auxcita = auxcita->siguiente;
				}
				cout << "\nElige el numero de cita que quieres modificar (ingrese 0 si deseea regresar al menu): ";
				cin >> e;
				auxcita = primercita;

				for (int i = 1; i < e; i++) {
					auxcita = auxcita->siguiente;
				}
				
				if (e != 0) {
						system("cls");

						cout << "Cita " << auxcita->numc << endl;
						cout << "Nombre del paciente: " << auxcita->nombre << endl;
						cout << "Hora de su tratamiento: " << auxcita->hora << endl;
						cout << "Nombre del tratamiento: " << auxcita->tratamiento << endl;
						cout << "Descripcion: " << auxcita->des << endl;
						cout << "El precio unitario del tratamiento es de: " << auxcita->pt << "$" << endl;
						cout << "Numero de dosis: " << auxcita->ct << endl;
						cout << "Total: " << auxcita->t << "$" << endl << endl;

						cout << "\n¿Que parte de la cita desea modificar? " << endl;
						cout << "1.Nombre del paciente." << endl;
						cout << "2.Hora de su tratamiento." << endl;
						cout << "3.Tipo de tratamiento." << endl;
						cout << "4.Numero de dosis." << endl;

						cout << "Elije una opcion: ";
						cin >> opc;
						system("cls");
					
				
					switch (opc) {

					case 1: {
						cout << "Nuevo nombre del paciente: ";
						cin.ignore();
						getline(cin, auxcita->nombre);
						break;
					}

					case 2: {
						cout << "Nueva hora de tratamiento: ";
						cin.ignore();
						getline(cin, auxcita->hora);
						break;
					}

					case 3: {
						cout << "Nuevo tratamiento: ";
						cin.ignore();
						getline(cin, auxcita->tratamiento);

						cout << "Descripcion: ";
						getline(cin, auxcita->des);

						cout << "Precio Unitario: ";
						cin >> auxcita->pt;

						auxcita->t = auxcita->ct * auxcita->pt;
						break;
					}

					case 4: {
						cout << "Nuevo numero de dosis: ";
						cin >> auxcita->ct;
						auxcita->t = auxcita->ct * auxcita->pt;
						break;
					}

					default: {
						cout << "Numero no valido";
					}
					}
				}

			}

			cin.ignore();
			cout << "\nPresiona ENTER para volver al menu";
			cin.get();
			system("cls");
			break;
		}
		

		case 3: {
			auxcita = primercita;
			if (!auxcita) {
				cout << "No Existen citas registradas";
			}
			else {
				while (auxcita) {
					cout << "Cita " << auxcita->numc << endl;
					cout << "Nombre del paciente: " << auxcita->nombre << endl;
					cout << "Hora de su tratamiento: " << auxcita->hora << endl << endl;
					auxcita = auxcita->siguiente;
				}
				cout << "\nElige el numero de cita que quieres eliminar (ingrese 0 si deseea regresar al menu): ";
				cin >> e;
				auxcita = primercita;

				for (int i = 1; i < e; i++) {
					auxcita = auxcita->siguiente;
				}
				if (e != 0) {
					system("cls");
					if(auxcita != primercita && auxcita != ultimacita){
						auxcita->anterior->siguiente = auxcita->siguiente;
						auxcita->siguiente->anterior = auxcita->anterior;

						delete auxcita;
						citaactual--;
					}
					if (auxcita==primercita) {
						if(auxcita->siguiente != nullptr){
							primercita = auxcita->siguiente;
						}
						else {
							primercita = nullptr;
						}
						delete auxcita;
						citaactual--;
					}
					if (auxcita == ultimacita) {
						if (auxcita->anterior != nullptr) {
							ultimacita = auxcita->anterior;
						}
						else {
							ultimacita = nullptr;
						}
						delete auxcita;
						citaactual--;
					}
					

				}
			}
			
			cin.ignore();
			cout << "\nPresiona ENTER para volver al menu";
			cin.get();
			system("cls");
			break;
		}

		case 4: {
			auxcita = primercita;

			if (!auxcita) {
				cout << "No Existen citas registradas";
			}
			else {
				while (auxcita) {
					cout << "Cita " <<auxcita->numc<< endl;
					cout << "Nombre del paciente: " << auxcita->nombre << endl;
					cout << "Hora de su tratamiento: " << auxcita->hora << endl;
					cout << "Nombre del tratamiento: " << auxcita->tratamiento << endl;
					cout << "Descripcion: " << auxcita->des << endl;
					cout << "El precio unitario del tratamiento es de: " << auxcita->pt << "$" << endl;
					cout << "Numero de dosis: " << auxcita->ct << endl;
					cout << "Total: " << auxcita->t << "$" << endl << endl;
					auxcita = auxcita->siguiente;
				}
			}
			cin.ignore();
			cout << "\nPresiona ENTER para volver al menu";
			cin.get();
			system("cls");
			break;
		}

		case 5: {
			opcion = 5;
			break;
		}

		default: {
			cout << "Numero no valido";
			cin.ignore();
			cout << "\nPresiona ENTER para volver al menu";
			cin.get();
			system("cls");

		}

		}
	}
	cout << "Usted salio del menu";
	ofstream archivo;
	archivo.open("registros.txt");

	if (archivo.is_open()) {
		auxcita = primercita;
		while (auxcita) {
			archivo << auxcita->numc << endl;
			archivo << auxcita->nombre << endl;
			archivo << auxcita->hora << endl;
			archivo << auxcita->tratamiento << endl;
			archivo << auxcita->des << endl;
			archivo << auxcita->pt << endl;
			archivo << auxcita->ct << endl;
			auxcita = auxcita->siguiente;
		}
		archivo.close();
	}
	else {
		cout << "Error "<<endl;
	}

	return 0;
}