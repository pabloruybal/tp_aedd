#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cmath>
using namespace std;

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
		cout << setw(40) << right << "Men� Algoritmos Num�ricos" << endl;
		cout << "======================================================" << endl << endl;
		cout << "1.- Conversi�n Binario a Decimal - Soluci�n iterativa." << endl;
		cout << "2.- Conversi�n Binario a Decimal - Soluci�n recursiva." << endl;
		cout << "3.- ThreeBonacci - Soluci�n iterativa." << endl;
		cout << "4.- ThreeBonacci - Soluci�n recursiva." << endl;
		cout << "9.- Salir de la aplicaci�n." << endl << endl;
		cout << "Ingrese una opci�n: ";
		
		cin >> opcion1;
		system("cls");
		while(opcion1!=9){
			switch(opcion1){
			case 1: cout << "Algoritmo Conversi�n Binario a Decimal - Soluci�n iterativa." << endl << endl;
					cout << "============================================================" << endl << endl;
					opcion2 = submenuAlgoritmosNumericos();
					while(opcion2!=9){
						switch(opcion2){
						case 1: definicionBinarioDecimal();
								cout << endl << endl << endl;
								system("pause");
								system("cls");
								cout << "Algoritmo Conversi�n Binario a Decimal - Soluci�n iterativa." << endl << endl;
								cout << "============================================================" << endl << endl;
								opcion2 = submenuAlgoritmosNumericos();
								break;
						case 2: requisitosBinarioDecimal();
								ejecucionBinarioDecimalIterativo();
								cout << endl << endl << endl;
								system("pause");
								system("cls");
								cout << "Algoritmo Conversi�n Binario a Decimal - Soluci�n iterativa." << endl << endl;
								cout << "============================================================" << endl << endl;
								opcion2 = submenuAlgoritmosNumericos();
								break;
						case 9: 
								break;
						default: cout << "\nOpci�n inv�lida. Vuelva a intentarlo." << endl << endl;
								Sleep(1500);
								system("cls");
								cout << "Algoritmo Conversi�n Binario a Decimal - Soluci�n iterativa." << endl << endl;
								cout << "============================================================" << endl << endl;
								opcion2 = submenuAlgoritmosNumericos();
								break;
						}
					}			
					menuAlgoritmosNumericos();
					break;
			case 2: cout << "Algoritmo Conversi�n Binario a Decimal - Soluci�n recursiva." << endl << endl;
					cout << "============================================================" << endl << endl;
					opcion2 = submenuAlgoritmosNumericos();
					while(opcion2!=9){
						switch(opcion2){
						case 1: definicionBinarioDecimal();
								cout << endl << endl << endl;
								system("pause");
								system("cls");
								cout << "Algoritmo Conversi�n Binario a Decimal - Soluci�n recursiva." << endl << endl;
								cout << "============================================================" << endl << endl;
								opcion2 = submenuAlgoritmosNumericos();
								break;
						case 2: requisitosBinarioDecimal();
								ejecucionBinarioDecimalRecursivo();
								cout << endl << endl << endl;
								system("pause");
								system("cls");
								cout << "Algoritmo Conversi�n Binario a Decimal - Soluci�n recursiva." << endl << endl;
								cout << "============================================================" << endl << endl;
								opcion2 = submenuAlgoritmosNumericos();
								break;
						case 9: 
								break;
						default: cout << "\nOpci�n inv�lida. Vuelva a intentarlo." << endl << endl;
								Sleep(1500);
								system("cls");
								cout << "Algoritmo Conversi�n Binario a Decimal - Soluci�n recursiva." << endl << endl;
								cout << "============================================================" << endl << endl;
								opcion2 = submenuAlgoritmosNumericos();
								break;
						}
					}			
					menuAlgoritmosNumericos();
					break;
			case 3: cout << "Algoritmo ThreeBonacci - Soluci�n iterativa." << endl;
					cout << "============================================" << endl << endl;
					opcion2 = submenuAlgoritmosNumericos();
					while(opcion2!=9){
						switch(opcion2){
						case 1: definicionThreeBonacci();
								cout << endl << endl << endl;
								system("pause");
								system("cls");
								cout << "Algoritmo ThreeBonacci - Soluci�n iterativa." << endl << endl;
								cout << "============================================" << endl << endl;
								opcion2 = submenuAlgoritmosNumericos();
								break;
						case 2: requisitosThreeBonacci();
								ejecucionThreeBonacciIterativo();
								cout << endl << endl << endl;
								system("pause");
								system("cls");
								cout << "Algoritmo ThreeBonacci - Soluci�n iterativa." << endl << endl;
								cout << "============================================" << endl << endl;
								opcion2 = submenuAlgoritmosNumericos();
								break;
						case 9: 
								break;
						default: cout << "\nOpci�n inv�lida. Vuelva a intentarlo." << endl << endl;
								Sleep(1500);
								system("cls");
								cout << "Algoritmo ThreeBonacci - Soluci�n iterativa." << endl << endl;
								cout << "============================================" << endl << endl;
								opcion2 = submenuAlgoritmosNumericos();
								break;
						}
					}			
					menuAlgoritmosNumericos();
					break;
			case 4: cout << "Algoritmo ThreeBonacci - Soluci�n recursiva." << endl;
					cout << "============================================" << endl << endl;
					opcion2 = submenuAlgoritmosNumericos();
					while(opcion2!=9){
						switch(opcion2){
						case 1: definicionThreeBonacci();
								cout << endl << endl << endl;
								system("pause");
								system("cls");
								cout << "Algoritmo ThreeBonacci - Soluci�n recursiva." << endl << endl;
								cout << "============================================" << endl << endl;
								opcion2 = submenuAlgoritmosNumericos();
								break;
						case 2: requisitosThreeBonacci();
								ejecucionThreeBonacciRecursivo();
								cout << endl << endl << endl;
								system("pause");
								system("cls");
								cout << "Algoritmo ThreeBonacci - Soluci�n iterativa." << endl << endl;
								cout << "============================================" << endl << endl;
								opcion2 = submenuAlgoritmosNumericos();
								break;
						case 9: 
								break;
						default: cout << "\nOpci�n inv�lida. Vuelva a intentarlo." << endl << endl;
								Sleep(1500);
								system("cls");
								cout << "Algoritmo ThreeBonacci - Soluci�n recursiva." << endl << endl;
								cout << "============================================" << endl << endl;
								opcion2 = submenuAlgoritmosNumericos();
								break;
						}
					}			
					menuAlgoritmosNumericos();
					break;
			case 9: 
					break;
			default: cout << "\nOpcion inv�lida. Vuelva a intentarlo." << endl << endl;
					Sleep(1500);
					system("cls");
					menuAlgoritmosNumericos();
					break;
			}
		}
	}
	cout << "\nFin del programa" << endl;
}
int submenuAlgoritmosNumericos(){
	int opcion;
	cout << "1.- Ver definici�n." << endl;
	cout << "2.- Ejecutar." << endl << endl;
	cout << "9.- Volver al men� anterior." << endl << endl;
	cout << "Ingrese una opci�n: ";
	
	cin >> opcion;
	Sleep(1500);
	system("cls");
	return opcion;
}
	
void definicionBinarioDecimal(){
	string def1, def2, def3;
	def1="Definici�n:";
	def2="El sistema binario s�lo utiliza dos d�gitos: 0 y 1. El valor de cada posici�n se obtiene de una potencia de base 2, elevada a un exponente igual a la posici�n del d�gito menos uno.";
	def3="Su popularidad radica en que es el utilizado por las computadoras y dispositivos electr�nicos, internamente estos equipos usan el cero para inhibir y el uno para generar impulsos el�ctricos en su comunicaci�n interna.";
	cout << def1 << endl;
	cout << def2 << endl;
	cout << def3 << endl;
	/*
	cout << "Definici�n: " << endl;
	cout << "El sistema binario s�lo utiliza dos d�gitos: 0 y 1. El valor de cada posici�n se" << endl;
	cout << "obtiene de una potencia de base 2, elevada a un exponente igual a la posici�n del" << endl;
	cout << "d�gito menos uno." << endl;
	cout << "Su popularidad radica en que es el utilizado por las computadoras y dispositivos" << endl;
	cout << "electr�nicos, internamente estos equipos usan el cero para inhibir y el uno para" << endl;
	cout << "generar impulsos el�ctricos en su comunicaci�n interna." << endl;
	*/
}
void requisitosBinarioDecimal(){
	cout << "Requisitos a cumplir: " << endl;
	cout << "Se debe ingresar un n�mero binario, el mismo se compone unicamente por 0 y 1, caso" << endl;
	cout << "contrario se indicar� que el n�mero no es v�lido." << endl << endl; 
}
void ejecucionBinarioDecimalIterativo(){
	int  resultado=0, longitud, i=0;
	bool cumple=true;
	string binario;
	cout << "\nIngrese el n�mero que desea convertir: ";
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
		cout<< "\nConversi�n  ->  ";
		for(int i=0; i<longitud; i++)
			cout<<binario[i];
		cout<<"  =  "<<resultado<<endl;
	}
	else
	   cout<<"\nN�mero inv�lido."<<endl;
}
void ejecucionBinarioDecimalRecursivo(){
	int  resultado=0, longitud, i=0;
	bool cumple=true;
	string binario;
	cout << "\nIngrese el n�mero que desea convertir: ";
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
		cout<< "\nConversi�n  ->  ";
		for(int i=0; i<longitud; i++)
			cout<<binario[i];
		cout<<"  =  "<<resultado<<endl;
	}
	else
	   cout<<"\nN�mero inv�lido."<<endl;
}
int calcularDecimal(string binario,int exponente){
	if(exponente<0)
		return 0;
	else
		return (binario[exponente]-'0') * pow(2,binario.length()-1- exponente) + calcularDecimal(binario, exponente - 1);
}
void definicionThreeBonacci(){
	string def1, def2, def3;
	def1="Definici�n:";
	def2="Un n�mero pertenece a la secuencia ThreeBonacci si pertenece a la secuencia Fibonacci, y satisface al menos uno de los siguientes criterios: contiene al menos un d�gito 3 y/o es un m�ltiplo de 3.";
	def3="Su popularidad radica en que es el utilizado por las computadoras y dispositivos electr�nicos, internamente estos equipos usan el cero para inhibir y el uno para generar impulsos el�ctricos en su comunicaci�n interna.";
	cout << def1 << endl;
	cout << def2 << endl;
	cout << def3 << endl;
	/*
	cout << "Definici�n: " << endl;
	cout << "Un n�mero pertenece a la secuencia ThreeBonacci si pertenece a la secuencia Fibonacci," << endl;
	cout << "y satisface al menos uno de los siguientes criterios:" << endl;
	cout << "  - contiene al menos un d�gito 3." << endl;
	cout << "  - es un m�ltiplo de 3." << endl << endl;
	
	cout << "La sucesi�n de Fibonacci es una sucesi�n infinita de n�meros naturales, que comienza con" << endl;
	cout << "dos valores de referencia, en nuestro caso 1 y 1, y a partir de estos, �cada t�rmino es" << endl;
	cout << "la suma de los dos anteriores�, es la relaci�n de recurrencia que la define." << endl;
	*/
}
void requisitosThreeBonacci(){
	cout << "Requisitos a cumplir: " << endl;
	cout << "Cada caso de prueba contiene un n�mero N, siendo 1<=N<=60, caso"<<endl;
	cout << "contrario se indicar� que el n�mero no es v�lido." << endl;
	cout << "La entrada de datos finaliza con: ctrl+z." << endl << endl;
}
void ejecucionThreeBonacciIterativo(){
	int num;
	cout << "\nIngrese el n�mero N: ";
	while(cin>>num){
		if(num>=1 and num<=60){
			cout<< "\nEl en�simo n�mero es  ->  ";
			buscarOrdenNum(num);
		}
		else
			cout<<"\nN�mero inv�lido."<<endl;
		cout << "\nIngrese el n�mero N: ";
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
	cout << "\nIngrese el n�mero N: ";
	while(cin>>num){
		if(num>=1 and num<=60){
			cout<< "\nEl en�simo n�mero es  ->  ";
			cout<< buscarNumeroRecursivo(num)<< endl;
		}
		else
		   cout<<"\nN�mero inv�lido."<<endl;
		cout << "\nIngrese el n�mero N: ";
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
