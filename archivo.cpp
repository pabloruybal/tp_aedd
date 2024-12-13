#include <iostream>
#include <iomanip>
#include <windows.h>
#include <fstream> 
#include <ctime>
using namespace std;

struct Fecha{
	int dia, mes, anio;
};
struct Usuarios{
	char nombre_usuario[11];
	char clave[37];
	Fecha ultimo_acceso;
}usuario[100];

void menu();
void registro();
bool iniciarSesion();
//void algoritmosNumericos();
//void juegoSMB();
bool existenciaNombre(Usuarios usuario[], char nombre[], int TL);
bool validacionNombre(char nombre[]);
bool validacionContrasenia(char contrasenia[]);
void calculoFecha(int & dia, int & mes, int & anio);
void cargarRegistro(char nombre[], char contrasenia[], int & TL);
bool encontrarUyC(Usuarios usuario[], char nombre[], char contrasenia[], int & dia, int & mes, int & anio);

int main(){
	
	menu();
	
	return 0;
}
	
void menu(){
	int opcion;
	bool sesion_iniciada=false;
	
	while(opcion != 9){
		cout << setw(20) << right << "Menu de acceso" << endl;
		cout << "==========================" << endl << endl;
		cout << "1.- Registro" << endl;
		cout << "2.- Iniciar sesion" << endl;
		cout << "3.- Algoritmos Numericos" << endl;
		cout << "4.- Juego Super Mario Bros" << endl;
		cout << "9.- Salir de la aplicacion" << endl << endl;
		cout << "Ingrese una opcion: ";
		
		cin >> opcion;
		system("cls");
		switch(opcion){
		case 1: cout << "COMIENZA EL REGISTRO!" << endl << endl;
				registro();
				break;
		case 2: cout << "INICIO DE SESION!" << endl;
				sesion_iniciada = iniciarSesion();
				break;
		case 3: if(sesion_iniciada)
					cout << "ALGORITMOS NUMERICOS!" << endl;
				else
					cout << "Primero inicie sesion" << endl;
				//algoritmosNumericos();
				break;
		case 4: if(sesion_iniciada)
					cout << "JUEGO SUPER MARIO BROS!" << endl;
				else
					cout << "Primero inicie sesion" << endl;
				//juegoSMB();
				break;
		case 9: 
				break;
		default: cout << "\nOpcion invalida. Vuelva a intentarlo." << endl << endl;
				Sleep(1500);
				system("cls");
				break;
		}
	}
	cout << "\nFin del programa" << endl;
}
	
void registro(){
	char nombre[11], contrasenia[37], contraseniaVerif[37];
	int TL=0, entrar;
	cout << "Requisitos usuario:" << endl;
	cout << "  - Tener entre 6 y 10 caracteres." << endl;
	cout << "  - Comenzar con una letra minuscula." << endl;
	cout << "  - Tener al menos dos letras mayusculas." << endl;
	cout << "  - Tener un maximo de tres digitos." << endl;
	cout << "  - Puede contener: +, -, *, /." << endl << endl;
	cout << "Requisitos contrasenia:" << endl;
	cout << "  - Tener entre 6 y 32 caracteres." << endl;
	cout << "  - Tener al menos una letra minuscula." << endl;
	cout << "  - Tener al menos una letra mayuscula." << endl;
	cout << "  - Tener al menos un digito." << endl;
	cout << "  - No puede contener caracteres especiales." << endl << endl;
	cout << " --------------------" << endl << endl;
	cout << "Ingrese un usuario: ";
	cin.ignore(1000, '\n');
	cin.getline(nombre, 11, '\n');
	cout << "Ingrese una contrasenia: ";
	cin.getline(contrasenia, 37, '\n');
	
	if(existenciaNombre(usuario, nombre, TL)){
		cout << "El usuario ya existe." << endl;
		Sleep(1500);
		system("cls");
		menu();
	}
	else{
		if(validacionNombre(nombre) and validacionContrasenia(contrasenia)){
			cout << "Repita la contrasenia: ";
			cin.getline(contraseniaVerif, 37, '\n');
			system("cls");
			if(strcmp(contrasenia,contraseniaVerif)==0){
				cargarRegistro(nombre, contrasenia, TL);
				cout << "Registro exitoso." << endl << endl;
				while(entrar != 2 && entrar != 1){
					cout << "¿Quieres iniciar sesion?" << endl;
					cout << "1.- Si" << endl;
					cout <<	"2.- No" << endl;
					cin >> entrar;
					system("cls");
					switch (entrar){
					case 1: 
						iniciarSesion();
						break;
					case 2:
						cout << "Volviendo al menu..." << endl << endl;
						Sleep(1500);
						system("cls");
						break;
					default:
						cout << "Opcion invalida." << endl << endl;
						Sleep(1500);
						system("cls");
						break;
					}
				}
			}
			else{
				cout << "\nNo se pudo realizar el registro." << endl << endl;
				Sleep(1500);
				system("cls");
				menu();
			}
		}
		else{
			cout << "\nUsuario y/o contrasenia invalidos." << endl << endl;
			Sleep(1500);
			system("cls");
			menu();
		}
	}
}
bool iniciarSesion(){
	char nombre[11], contrasenia[37];
	int i=0, dia, mes, anio;
	bool encontrado=false;
	cin.ignore(1000, '\n');
	cout << "Ingrese su usuario: ";
	cin.getline(nombre, 11, '\n');
	cout << "Ingrese su contrasenia: ";
	cin.getline(contrasenia, 37, '\n');
	while(i<3 and !encontrado){
		if(encontrarUyC(usuario, nombre, contrasenia, dia, mes, anio)){
			encontrado=true;
			Sleep(1500);
			system("cls");
			cout << "Bienvenida/o "<< nombre << endl;
			cout << "========================" << endl;
			cout << "Ultimo acceso a la aplicacion: "<<dia<<"/"<<mes<<"/"<<anio<<endl;
			return true;
		}
	}
}
//void algoritmosNumericos();
//void juegoSMB();
bool existenciaNombre(Usuarios usuario[], char nombre[], int TL){
	int i=0;
	bool encontrado=false;
	fstream uR;
	uR.open("Usuarios.dat", ios::binary | ios::in);
	if(!uR) cout<< "Error al abrir el archivo." << endl;
	else{
		uR.read((char*)(&usuario), sizeof(Usuarios)*100);
		while(i<TL and !encontrado){	
			cout<<nombre<< " " << usuario[i].nombre_usuario << " " << encontrado<<endl;
			i++;
			if(strcmp(nombre, usuario[i].nombre_usuario)==0) encontrado=true;
			i++;
		}
		uR.close();
	}
	return encontrado;
}
bool validacionNombre(char nombre[]){
	int largo=0, i=0, contMayus=0, contDig=0; 
	largo = strlen(nombre);
	bool dimension=false, inicial=false, cumple=true;
	if(largo>=6 and largo<=10) dimension=true;
	if(islower(nombre[0])) inicial=true;
	while(i<largo and dimension and inicial and cumple){
		if(isdigit(nombre[i]))	contDig++;
		if(isupper(nombre[i]))	contMayus++;
		if(!(isalnum(nombre[i]) or nombre[i]=='+' or nombre[i]=='-' or nombre[i]=='/' or nombre[i]=='*')) cumple=false;
		i++;
	}
	return (contDig<=3 and contMayus>=2 and cumple);
}
bool validacionContrasenia(char contrasenia[]){
	int largo = strlen(contrasenia);
	bool dimension=false, caracteres=true, digito=false, mayuscula=false, minuscula=false;
	
	if(6<=largo and largo<=32) dimension=true;
	
	for(int i=0; i<largo; i++)
		if(!isalnum(contrasenia[i])) caracteres=false;
	
	if(dimension and caracteres){
		for(int i=0; i<largo; i++){
			if(isdigit(contrasenia[i]))	digito=true;
			if(isupper(contrasenia[i]))	mayuscula=true;
			if(islower(contrasenia[i]))	minuscula=true;
		}
	}
	return (digito and mayuscula and minuscula);
}
void calculoFecha(int & dia, int & mes, int & anio){
	time_t fechaHoy = time(nullptr);
	tm *fechaLocal = localtime(&fechaHoy);
	dia = fechaLocal->tm_mday;
	mes = fechaLocal->tm_mon + 1;
	anio = 1900 + fechaLocal->tm_year;
}
void cargarRegistro(char nombre[], char contrasenia[], int & TL){
	int dia, mes, anio;
	fstream uR;
	uR.open("Usuarios.dat", ios::binary | ios::app);
	if(!uR) cout<< "Error al abrir el archivo" << endl;
	else{
		calculoFecha(dia, mes, anio);
		strcpy(usuario[TL].nombre_usuario, nombre);
		strcpy(usuario[TL].clave, contrasenia);
		usuario[TL].ultimo_acceso.dia = dia;
		usuario[TL].ultimo_acceso.mes = mes;
		usuario[TL].ultimo_acceso.anio = anio;
		uR.write((char*)(&usuario), sizeof(Usuarios)*100);
		uR.close();
		TL++;
	}
}
bool encontrarUyC(Usuarios usuario[], char nombre[], char contrasenia[], int & dia, int & mes, int & anio){
	int i=0;
	bool encontrado=false;
	ifstream uR;
	uR.open("Usuarios.dat");
	if(!uR) cout<< "Error al abrir el archivo" << endl;
	else{
		while(!uR.eof() and !encontrado){	
			uR.read((char*)(&usuario), sizeof(Usuarios)*100);
			if(strcmp(nombre, usuario[i].nombre_usuario) and strcmp(contrasenia, usuario[i].clave)) encontrado=true;
			dia=usuario[i].ultimo_acceso.dia;
			mes=usuario[i].ultimo_acceso.mes;
			anio=usuario[i].ultimo_acceso.anio;
			i++;
		}
		uR.close();
	}
	return encontrado;
}
