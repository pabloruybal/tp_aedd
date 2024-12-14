#include <iostream>
#include <iomanip>
#include <windows.h>
#include <fstream> 
#include <ctime>
#include <conio.h>
#include <cstring>
using namespace std;

struct Fecha{
	int dia, mes, anio;
};
struct Usuario{
	char nombre_usuario[11];
	char clave[37];
	Fecha ultimo_acceso;
};

void traerInformacion(Usuario [], int &);
void actualizarRegistro(Usuario [], int &);
void menu(Usuario [], int &);
void registro(Usuario [], int &);
void encriptar(string &);
void sumarAlpha(string &, int);
void invertir(string &, int);
void restarMitad(string &, int);
bool iniciarSesion(Usuario [], int);
//void algoritmosNumericos();
//void juegoSMB();
bool existenciaNombre(Usuario [],string, int);
bool validacionNombre(string);
bool validacionContrasenia(string);
void calculoFecha(int &, int &, int &);
void crearUsuario(Usuario [], string, string, int &);
bool encontrarUyC(Usuario [], string, string, int &, int &, int &, int);

int main(){
	Usuario usuarios[100];
	int TL=0;
	
	traerInformacion(usuarios, TL);
	
	menu(usuarios, TL);
	
	return 0;
}

void traerInformacion(Usuario usuarios[], int &TL) {
	ifstream Entrada("Usuarios.dat", ios::binary);
	
	if (!Entrada) {
		cerr << "Error al abrir el fichero" << endl;
		return;
	}
	
	TL = 0;
	
	Usuario temp;
	while (Entrada.read((char*)(&temp), sizeof(Usuario))) {
		if (TL < 100) {
			usuarios[TL++] = temp;
			/*cout << temp.nombre_usuario << " " << temp.clave << " "
				<< temp.ultimo_acceso.dia << "/" << temp.ultimo_acceso.mes << "/"
				<< temp.ultimo_acceso.anio << endl;*/
		} else {
			cerr << "Capacidad máxima alcanzada, algunos usuarios no se cargaron." << endl;
			break;
		}
	}
	
	Entrada.close();
	//cout << "Cantidad de usuarios cargados: " << TL << endl;
}
	
void actualizarRegistro(Usuario usuarios[], int &TL) {
	ofstream Archivo("Usuarios.dat", ios::binary | ios::trunc);
	
	if (!Archivo) {
		cerr << "Error al abrir el fichero" << endl;
		return;
	}
	
	if (TL > 0) {
		Archivo.write((char*)(usuarios), sizeof(Usuario) * TL);
		if (!Archivo) {
			cerr << "Error al escribir en el archivo." << endl;
		}
	}
	
	Archivo.close();
}
	
void menu(Usuario usuarios[], int &TL){
	int opcion;
	bool sesion_iniciada=false;
	
	while(opcion != 9){
		cout << setw(20) << right << "Menu de acceso" << endl;
		cout << "==========================" << endl << endl;
		cout << "1.- Registro" << endl;
		cout << "2.- Iniciar sesion" << endl;
		cout << "3.- Algoritmos Numericos";
		if(!sesion_iniciada) cout<<" (primero debe iniciar sesion)";
		cout << endl;
		cout << "4.- Juego Super Mario Bros";
		if(!sesion_iniciada) cout<<" (primero debe iniciar sesion)";
		cout << endl;
		cout << "9.- Salir de la aplicacion" << endl << endl;
		cout << "Ingrese una opcion: ";
		
		cin >> opcion;
		system("cls");
		switch(opcion){
		case 1: cout << "COMIENZA EL REGISTRO!" << endl << endl;
				registro(usuarios, TL);
				break;
		case 2: cout << "INICIO DE SESION!" << endl;
				sesion_iniciada = iniciarSesion(usuarios, TL);
				break;
		case 3: if(sesion_iniciada)
					cout << "ALGORITMOS NUMERICOS!" << endl;
				else
					cout << "Inicie sesion por favor" << endl;
				//algoritmosNumericos();
				break;
		case 4: if(sesion_iniciada)
					cout << "JUEGO SUPER MARIO BROS!" << endl;
				else
					cout << "Inicie sesion por favor" << endl;
				//juegoSMB();
				break;
		case 9: actualizarRegistro(usuarios, TL);
				break;
		default: cout << "\nOpcion invalida. Vuelva a intentarlo." << endl << endl;
				Sleep(1500);
				system("cls");
				break;
		}
	}
	cout << "\nFin del programa" << endl;
}
	
void mostrarRequisitos() {
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
}

string leerContrasenia() {
	string contrasenia;
	char ch;
	
	while ((ch = _getch()) != '\r') {
		if (ch == '\b') {
			if (!contrasenia.empty()) {
				cout << "\b \b";
				contrasenia.pop_back();
			}
		} else {
			contrasenia.push_back(ch);
			cout << '*';
		}
	}
	
	encriptar(contrasenia);
	
	return contrasenia;
}

void registro(Usuario usuarios[], int &TL) {
	string nombre, contrasenia, contraseniaVerif;
	int entrar;
	
	do {
		system("cls");
		mostrarRequisitos();
		cout << "Ingrese un usuario: ";
		cin.ignore(1000, '\n');
		getline(cin, nombre);
		
		while(existenciaNombre(usuarios, nombre, TL)) {
			system("cls");
			mostrarRequisitos();
			cout << "ERROR: Este nombre de usuario ya existe." << endl;
			cout << "Ingrese un usuario: ";
			cin.ignore(1000, '\n');
			getline(cin, nombre);
		}
		
		while(!validacionNombre(nombre)){
			system("cls");
			mostrarRequisitos();
			cout << "ERROR: Nombre de usuario no valido." << endl;
			cout << "Ingrese un usuario: ";
			cin.ignore(1000, '\n');
			getline(cin, nombre);
		}
	} while (!validacionNombre(nombre) || existenciaNombre(usuarios, nombre, TL));
	
	do {
		system("cls");
		mostrarRequisitos();
		cout << "Ingrese un usuario: " << nombre << endl;
		cout << "Ingrese una contrasenia: ";
		contrasenia = leerContrasenia();
		cout << endl;
		
		if (!validacionContrasenia(contrasenia)) {
			cout << "ERROR: Contrasenia no valida." << endl;
			system("cls");
		}
	} while (!validacionContrasenia(contrasenia));
	
	
	cout << "Repita la contrasenia: ";
	contraseniaVerif = leerContrasenia();
	cout << endl;
	
	if (contrasenia != contraseniaVerif) {
		cout << "ERROR: Las contrasenias no coinciden." << endl;
		Sleep(500);
		cout << "Volviendo al menu..." << endl;
		Sleep(1500);
	} else{
		crearUsuario(usuarios, nombre, contrasenia, TL);
		cout << "Registro exitoso." << endl;
		
		do {
			cout << "Quieres iniciar sesion?" << endl;
			cout << "1.- Si" << endl;
			cout << "2.- No" << endl;
			cin >> entrar;
			
			switch (entrar) {
			case 1:
				iniciarSesion(usuarios, TL);
				break;
			case 2:
				cout << "Volviendo al menu..." << endl;
				Sleep(1500);
				break;
			default:
				cout << "Opcion invalida. Intente de nuevo." << endl;
			}
		} while (entrar != 1 && entrar != 2);
	}
	system("cls");
}

void encriptar(string &contrasenia){
	int largo=contrasenia.length();
	
	sumarAlpha(contrasenia, largo);
	invertir(contrasenia, largo);
	restarMitad(contrasenia, largo);
}

void sumarAlpha(string & texto, int largo){
	for(int c=0; c<largo; c++){
		if(isalpha(texto.at(c)))
			texto[c]+=3;
	}
}

void invertir(string & texto, int largo){
	string inversa;
	for(int j=0; j<largo; j++)
		inversa +=texto.at(largo-1-j);
	for(int k=0; k<largo; k++)
		texto.at(k)=inversa.at(k);
}

void restarMitad(string & texto, int largo){
	for(int c=largo/2; c<largo; c++)
		texto.at(c)-=1;
}

bool iniciarSesion(Usuario usuarios[], int TL) {
	string nombre, contrasenia;
	int dia, mes, anio, intentos = 3;
	
	while (intentos > 0) {
		if(intentos == 3) cin.ignore(1000, '\n');
		cout << "Ingrese su usuario: ";
		getline(cin, nombre);
		cout << "Ingrese su contrasenia: ";
		contrasenia = leerContrasenia();
		
		if (encontrarUyC(usuarios, nombre, contrasenia, dia, mes, anio, TL)) {
			cout << "\nBienvenida/o " << nombre << endl;
			cout << "========================" << endl;
			cout << "Ultimo acceso a la aplicacion: " << dia << "/" << mes << "/" << anio << endl;
			Sleep(1500);
			return true;
		} else {
			intentos--;
			cout << "\nERROR - Verifique los datos ingresados. Le quedan " << intentos << " intentos." << endl;
		}
	}
	
	cout << "Ha excedido el numero máximo de intentos, se te redirigira al menu." << endl;
	Sleep(1500);
	system("cls");
	
	return false;
}
	
//void algoritmosNumericos();
	
//void juegoSMB();
	
bool existenciaNombre(Usuario usuarios[], string nombre, int TL){
	bool band=false;
	
	for(int i=0; i<TL && !band; i++){
		if(strncmp(usuarios[i].nombre_usuario, nombre.c_str(), nombre.length()) == 0) band=true;
	}
	
	return band;
}
	
bool validacionNombre(string usuario){
	int largo=0, i=0, contMayus=0, contDig=0; 
	largo = usuario.length();
	bool dimension=false, inicial=false, cumple=true, esValido=false;
	if(largo>=6 and largo<=10)
		dimension=true;
	if(islower(usuario[0]))
		inicial=true;
	while(i<largo and dimension and inicial and cumple){
		if(isdigit(usuario[i]))
			contDig++;
		if(isupper(usuario[i]))
			contMayus++;
		if(!(isalnum(usuario[i]) or usuario[i]=='+' or usuario[i]=='-' or usuario[i]=='/' or usuario[i]=='*'))
			cumple=false;
		i++;
	}
	if(contDig<=3 and contMayus>=2 and cumple)
		  esValido=true;
	return esValido;
}
	
bool validacionContrasenia(string contrasenia){
	int largo = contrasenia.length();
	bool dimension=false, caracteres=true, digito=false, mayuscula=false, minuscula=false;
	
	if(6<=largo and largo<=32)
		dimension=true;
	
	for(int i=0; i<largo; i++){
		if(!isalnum(contrasenia[i]))
			caracteres=false;
	}
	if(dimension and caracteres){
		for(int i=0; i<largo; i++){
			if(isdigit(contrasenia[i]))
				digito=true;
			if(isupper(contrasenia[i]))
				mayuscula=true;
			if(islower(contrasenia[i]))
				minuscula=true;
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
	
void crearUsuario(Usuario usuarios[], string nombre1, string contrasenia1, int & TL){
	int dia, mes, anio;
	
	strcpy(usuarios[TL].nombre_usuario, nombre1.c_str());
	strcpy(usuarios[TL].clave, contrasenia1.c_str());
	calculoFecha(dia, mes, anio);
	usuarios[TL].ultimo_acceso.dia = dia;
	usuarios[TL].ultimo_acceso.mes = mes;
	usuarios[TL].ultimo_acceso.anio = anio;
	TL++;
	
	actualizarRegistro(usuarios, TL);
}
	
bool encontrarUyC(Usuario usuarios[], string nombre, string contrasenia, int & dia, int & mes, int & anio, int TL){
	int i=0, pos;
	bool Uencontrado=false, iniciar=false;
	
	if(nombre.empty() || contrasenia.empty()) return false;
	
	for(int i=0; i<TL && !Uencontrado; i++){
		if(strncmp(usuarios[i].nombre_usuario, nombre.c_str(), nombre.length()) == 0) Uencontrado=true;
		pos = i;
	}
	
	if(Uencontrado){
		if(strncmp(usuarios[i].clave, contrasenia.c_str(), contrasenia.length()) == 0) iniciar=true;
	}
	
	if(iniciar){
		dia = usuarios[pos].ultimo_acceso.dia;
		mes = usuarios[pos].ultimo_acceso.mes;
		anio = usuarios[pos].ultimo_acceso.anio;
	}
	
	return iniciar;
}
