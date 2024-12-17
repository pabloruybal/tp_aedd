#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cmath>
using namespace std;

void inicio();
void menuAlgoritmosNumericos();
int submenuAlgoritmosNumericos();
void definicionBinarioDecimal();
void requisitosBinarioDecimal();
void ejecucionBinarioDecimalIterativo();
void ejecucionBinarioDecimalRecursivo();
int calcularDecimal(string binario,int exponente);
void definicionThreeBonacci();
void requisitosThreeBonacci();
void ejecucionThreeBonacciIterativo();
void ejecucionThreeBonacciRecursivo();
void buscarOrdenNum(int num);
bool contiene3(unsigned long long int c);
unsigned long long int buscarNumeroRecursivo(int n, unsigned long long int a = 1, unsigned long long int b = 1);
bool contiene3Rec(unsigned long long int c);

void menuAlgoritmosNumericos(){
	int opcion1, opcion2;
	while(opcion1 != 9){
		cout << setw(40) << right << "Menu Algoritmos Numericos" << endl;
		cout << "======================================================" << endl << endl;
		cout << "1.- Conversion Binario a Decimal - Solucion iterativa." << endl;
		cout << "2.- Conversion Binario a Decimal - Solucion recursiva." << endl;
		cout << "3.- ThreeBonacci - Solucion iterativa." << endl;
		cout << "4.- ThreeBonacci - Solucion recursiva." << endl;
		cout << "9.- Volver al menu principal." << endl << endl;
		cout << "Ingrese una opcion: ";
		
		cin >> opcion1;
		system("cls");
		switch(opcion1){
		case 1: cout << "Algoritmo Conversion Binario a Decimal - Solucion iterativa." << endl << endl;
		cout << "============================================================" << endl << endl;
		opcion2 = submenuAlgoritmosNumericos();
		while(opcion2!=9){
			switch(opcion2){
			case 1: definicionBinarioDecimal();
			cout << endl << endl << endl;
			system("pause");
			system("cls");
			cout << "Algoritmo Conversion Binario a Decimal - Solucion iterativa." << endl << endl;
			cout << "============================================================" << endl << endl;
			opcion2 = submenuAlgoritmosNumericos();
			break;
			case 2: requisitosBinarioDecimal();
			ejecucionBinarioDecimalIterativo();
			cout << endl << endl << endl;
			system("pause");
			system("cls");
			cout << "Algoritmo Conversion Binario a Decimal - Solucion iterativa." << endl << endl;
			cout << "============================================================" << endl << endl;
			opcion2 = submenuAlgoritmosNumericos();
			break;
			case 9: 
				break;
			default: cout << "\nOpcion invalida. Vuelva a intentarlo." << endl << endl;
			Sleep(1500);
			system("cls");
			cout << "Algoritmo Conversion Binario a Decimal - Solucion iterativa." << endl << endl;
			cout << "============================================================" << endl << endl;
			opcion2 = submenuAlgoritmosNumericos();
			break;
			}
		}			
		break;
		case 2: cout << "Algoritmo Conversion Binario a Decimal - Solucion recursiva." << endl << endl;
		cout << "============================================================" << endl << endl;
		opcion2 = submenuAlgoritmosNumericos();
		while(opcion2!=9){
			switch(opcion2){
			case 1: definicionBinarioDecimal();
			cout << endl << endl << endl;
			system("pause");
			system("cls");
			cout << "Algoritmo Conversion Binario a Decimal - Solucion recursiva." << endl << endl;
			cout << "============================================================" << endl << endl;
			opcion2 = submenuAlgoritmosNumericos();
			break;
			case 2: requisitosBinarioDecimal();
			ejecucionBinarioDecimalRecursivo();
			cout << endl << endl << endl;
			system("pause");
			system("cls");
			cout << "Algoritmo Conversion Binario a Decimal - Solucion recursiva." << endl << endl;
			cout << "============================================================" << endl << endl;
			opcion2 = submenuAlgoritmosNumericos();
			break;
			case 9: 
				break;
			default: cout << "\nOpcion invalida. Vuelva a intentarlo." << endl << endl;
			Sleep(1500);
			system("cls");
			cout << "Algoritmo Conversion Binario a Decimal - Solucion recursiva." << endl << endl;
			cout << "============================================================" << endl << endl;
			opcion2 = submenuAlgoritmosNumericos();
			break;
			}
		}			
		break;
		case 3: cout << "Algoritmo ThreeBonacci - Solucion iterativa." << endl;
		cout << "============================================" << endl << endl;
		opcion2 = submenuAlgoritmosNumericos();
		while(opcion2!=9){
			switch(opcion2){
			case 1: definicionThreeBonacci();
			cout << endl << endl << endl;
			system("pause");
			
			system("cls");
			cout << "Algoritmo ThreeBonacci - Solucion iterativa." << endl << endl;
			cout << "============================================" << endl << endl;
			opcion2 = submenuAlgoritmosNumericos();
			break;
			case 2: requisitosThreeBonacci();
			ejecucionThreeBonacciIterativo();
			cout << endl << endl << endl;
			system("pause");
			cin.clear();
			system("cls");
			cout << "Algoritmo ThreeBonacci - Solucion iterativa." << endl << endl;
			cout << "============================================" << endl << endl;
			opcion2 = submenuAlgoritmosNumericos();
			break;
			case 9: 
				break;
			default: cout << "\nOpcion invalida. Vuelva a intentarlo." << endl << endl;
			Sleep(1500);
			system("cls");
			cout << "Algoritmo ThreeBonacci - Solucion iterativa." << endl << endl;
			cout << "============================================" << endl << endl;
			opcion2 = submenuAlgoritmosNumericos();
			break;
			}
		}			
		break;
		case 4: cout << "Algoritmo ThreeBonacci - Solucion recursiva." << endl;
		cout << "============================================" << endl << endl;
		opcion2 = submenuAlgoritmosNumericos();
		while(opcion2!=9){
			switch(opcion2){
			case 1: definicionThreeBonacci();
			cout << endl << endl << endl;
			system("pause");
			system("cls");
			cout << "Algoritmo ThreeBonacci - Solucion recursiva." << endl << endl;
			cout << "============================================" << endl << endl;
			opcion2 = submenuAlgoritmosNumericos();
			break;
			case 2: requisitosThreeBonacci();
			ejecucionThreeBonacciRecursivo();
			cout << endl << endl << endl;
			system("pause");
			cin.clear();
			system("cls");
			cout << "Algoritmo ThreeBonacci - Solucion iterativa." << endl << endl;
			cout << "============================================" << endl << endl;
			opcion2 = submenuAlgoritmosNumericos();
			break;
			case 9: 
				break;
			default: cout << "\nOpcion invalida. Vuelva a intentarlo." << endl << endl;
			Sleep(1500);
			system("cls");
			cout << "Algoritmo ThreeBonacci - Solucion recursiva." << endl << endl;
			cout << "============================================" << endl << endl;
			opcion2 = submenuAlgoritmosNumericos();
			break;
			}
		}			
		break;
		case 9: 
			break;
		default: cout << "\nOpcion invalida. Vuelva a intentarlo." << endl << endl;
		Sleep(1500);
		system("cls");
		break;
		}
	}
	cout << "\nVolviendo al menu principal..." << endl;
	Sleep(1500);
	system("cls");
}
int submenuAlgoritmosNumericos(){
	int opcion;
	cout << "1.- Ver definicion." << endl;
	cout << "2.- Ejecutar." << endl << endl;
	cout << "9.- Volver al menu anterior." << endl << endl;
	cout << "Ingrese una opcion: ";
	
	cin >> opcion;
	Sleep(1500);
	system("cls");
	return opcion;
}

void definicionBinarioDecimal(){
	string def1, def2, def3;
	def1="Definicion:";
	def2="El sistema binario solo utiliza dos digitos: 0 y 1. El valor de cada posicion se obtiene de una potencia de base 2, elevada a un exponente igual a la posicion del digito menos uno.";
	def3="Su popularidad radica en que es el utilizado por las computadoras y dispositivos electronicos, internamente estos equipos usan el cero para inhibir y el uno para generar impulsos electricos en su comunicacion interna.";
	cout << def1 << endl;
	cout << def2 << endl;
	cout << def3 << endl;
	/*
	cout << "Definicion: " << endl;
	cout << "El sistema binario solo utiliza dos digitos: 0 y 1. El valor de cada posicion se" << endl;
	cout << "obtiene de una potencia de base 2, elevada a un exponente igual a la posicion del" << endl;
	cout << "digito menos uno." << endl;
	cout << "Su popularidad radica en que es el utilizado por las computadoras y dispositivos" << endl;
	cout << "electronicos, internamente estos equipos usan el cero para inhibir y el uno para" << endl;
	cout << "generar impulsos electricos en su comunicacion interna." << endl;
	*/
}

void requisitosBinarioDecimal(){
	cout << "Requisitos a cumplir: " << endl;
	cout << "Se debe ingresar un numero binario, el mismo se compone unicamente por 0 y 1, caso" << endl;
	cout << "contrario se indicara que el numero no es valido." << endl << endl; 
}

void ejecucionBinarioDecimalIterativo(){
	int  resultado=0, longitud, i=0;
	bool cumple=true;
	string binario;
	cout << "\nIngrese el numero que desea convertir: ";
	cin.ignore(1000, '\n');
	getline(cin, binario);
	longitud = binario.length();
	
	while(i<longitud and cumple){
		if(binario[i]!='1' and binario[i]!='0')
			cumple=false;
		else
			resultado+=(binario[i]-'0')* pow(2,longitud-i-1);
		i++;
	}
	if(cumple){
		cout<< "\nConversion  ->  ";
		for(int i=0; i<longitud; i++)
			cout<<binario[i];
		cout<<"  =  "<<resultado<<endl;
	}
	else
	   cout<<"\nNumero invalido."<<endl;
}

void ejecucionBinarioDecimalRecursivo(){
	int  resultado=0, longitud, i=0;
	bool cumple=true;
	string binario;
	cout << "\nIngrese el numero que desea convertir: ";
	cin.ignore(1000, '\n');
	getline(cin, binario);
	longitud = binario.length();
	
	while(i<longitud and cumple){
		if(binario[i]!='1' and binario[i]!='0')
			cumple=false;
		i++;
	}
	if(cumple){
		resultado = calcularDecimal(binario,longitud-1);
		cout<< "\nConversion  ->  ";
		for(int i=0; i<longitud; i++)
			cout<<binario[i];
		cout<<"  =  "<<resultado<<endl;
	}
	else
	   cout<<"\nNumero invalido."<<endl;
}

int calcularDecimal(string binario,int exponente){
	if(exponente<0)
		return 0;
	else
		return (binario[exponente]-'0') * pow(2,binario.length()-1- exponente) + calcularDecimal(binario, exponente - 1);
}

void definicionThreeBonacci(){
	string def1, def2, def3;
	def1="Definicion:";
	def2="Un numero pertenece a la secuencia ThreeBonacci si pertenece a la secuencia Fibonacci, y satisface al menos uno de los siguientes criterios: contiene al menos un digito 3 y/o es un multiplo de 3.";
	def3="Su popularidad radica en que es el utilizado por las computadoras y dispositivos electronicos, internamente estos equipos usan el cero para inhibir y el uno para generar impulsos electricos en su comunicacion interna.";
	cout << def1 << endl;
	cout << def2 << endl;
	cout << def3 << endl;
	/*
	cout << "Definicion: " << endl;
	cout << "Un numero pertenece a la secuencia ThreeBonacci si pertenece a la secuencia Fibonacci," << endl;
	cout << "y satisface al menos uno de los siguientes criterios:" << endl;
	cout << "  - contiene al menos un digito 3." << endl;
	cout << "  - es un multiplo de 3." << endl << endl;
	
	cout << "La sucesion de Fibonacci es una sucesion infinita de numeros naturales, que comienza con" << endl;
	cout << "dos valores de referencia, en nuestro caso 1 y 1, y a partir de estos, «cada termino es" << endl;
	cout << "la suma de los dos anteriores», es la relacion de recurrencia que la define." << endl;
	*/
}

void requisitosThreeBonacci(){
	cout << "Requisitos a cumplir: " << endl;
	cout << "Cada caso de prueba contiene un numero N, siendo 1<=N<=60, caso"<<endl;
	cout << "contrario se indicara que el numero no es valido." << endl;
	cout << "La entrada de datos finaliza con: ctrl+z." << endl << endl;
}

void ejecucionThreeBonacciIterativo(){
	int num;
	cout << "\nIngrese el numero N: ";
	while(cin>>num){
		if(num>=1 and num<=60){
			cout<< "\nEl enesimo numero es  ->  ";
			buscarOrdenNum(num);
		}
		else
		   cout<<"\nNumero invalido."<<endl;
		cout << "\nIngrese el numero N: ";
	}
}

void buscarOrdenNum(int num){
	unsigned long long int  a=1, b=1, c=0;
	int contador=0;
	
	while(contador!=num){
		c=a+b;
		if(contiene3(c) or c%3==0)
			contador++;
		a=b;
		b=c;
	}
	cout<<c<<endl;
}

bool contiene3(unsigned long long int c){
	bool cumple=false;
	unsigned long long int aux;
	while(c>0){ 
		aux=c%10;
		c/=10; 
		if(aux==3)
			cumple=true;
	}
	return cumple;
}

void ejecucionThreeBonacciRecursivo(){
	int num;
	cout << "\nIngrese el numero N: ";
	while(cin>>num){
		if(num>=1 and num<=60){
			cout<< "\nEl enesimo numero es  ->  ";
			cout<< buscarNumeroRecursivo(num)<< endl;
		}
		else
		   cout<<"\nNumero invalido."<<endl;
		cout << "\nIngrese el numero N: ";
	}
}

unsigned long long int buscarNumeroRecursivo(int n, unsigned long long int a, unsigned long long int b){
	unsigned long long int next = a + b;
	
	if(contiene3Rec(next) || next%3 == 0){
		if(n==1)
			return next;
		return buscarNumeroRecursivo(n-1, b, next);
	}
	return buscarNumeroRecursivo(n, b, next);
}

bool contiene3Rec(unsigned long long int c){
	if(c == 0) return false;
	if(c % 10 == 3) return true;
	return contiene3Rec(c / 10);
}
