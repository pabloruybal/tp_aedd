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
		cout << setw(40) << right << "Menú Algoritmos Numéricos" << endl;
		cout << "======================================================" << endl << endl;
		cout << "1.- Conversión Binario a Decimal - Solución iterativa." << endl;
		cout << "2.- Conversión Binario a Decimal - Solución recursiva." << endl;
		cout << "3.- ThreeBonacci - Solución iterativa." << endl;
		cout << "4.- ThreeBonacci - Solución recursiva." << endl;
		cout << "9.- Salir de la aplicación." << endl << endl;
		cout << "Ingrese una opción: ";
		
		cin >> opcion1;
		system("cls");
		while(opcion1!=9){
			switch(opcion1){
			case 1: cout << "Algoritmo Conversión Binario a Decimal - Solución iterativa." << endl << endl;
					cout << "============================================================" << endl << endl;
					opcion2 = submenuAlgoritmosNumericos();
					while(opcion2!=9){
						switch(opcion2){
						case 1: definicionBinarioDecimal();
								cout << endl << endl << endl;
								system("pause");
								system("cls");
								cout << "Algoritmo Conversión Binario a Decimal - Solución iterativa." << endl << endl;
								cout << "============================================================" << endl << endl;
								opcion2 = submenuAlgoritmosNumericos();
								break;
						case 2: requisitosBinarioDecimal();
								ejecucionBinarioDecimalIterativo();
								cout << endl << endl << endl;
								system("pause");
								system("cls");
								cout << "Algoritmo Conversión Binario a Decimal - Solución iterativa." << endl << endl;
								cout << "============================================================" << endl << endl;
								opcion2 = submenuAlgoritmosNumericos();
								break;
						case 9: 
								break;
						default: cout << "\nOpción inválida. Vuelva a intentarlo." << endl << endl;
								Sleep(1500);
								system("cls");
								cout << "Algoritmo Conversión Binario a Decimal - Solución iterativa." << endl << endl;
								cout << "============================================================" << endl << endl;
								opcion2 = submenuAlgoritmosNumericos();
								break;
						}
					}			
					menuAlgoritmosNumericos();
					break;
			case 2: cout << "Algoritmo Conversión Binario a Decimal - Solución recursiva." << endl << endl;
					cout << "============================================================" << endl << endl;
					opcion2 = submenuAlgoritmosNumericos();
					while(opcion2!=9){
						switch(opcion2){
						case 1: definicionBinarioDecimal();
								cout << endl << endl << endl;
								system("pause");
								system("cls");
								cout << "Algoritmo Conversión Binario a Decimal - Solución recursiva." << endl << endl;
								cout << "============================================================" << endl << endl;
								opcion2 = submenuAlgoritmosNumericos();
								break;
						case 2: requisitosBinarioDecimal();
								ejecucionBinarioDecimalRecursivo();
								cout << endl << endl << endl;
								system("pause");
								system("cls");
								cout << "Algoritmo Conversión Binario a Decimal - Solución recursiva." << endl << endl;
								cout << "============================================================" << endl << endl;
								opcion2 = submenuAlgoritmosNumericos();
								break;
						case 9: 
								break;
						default: cout << "\nOpción inválida. Vuelva a intentarlo." << endl << endl;
								Sleep(1500);
								system("cls");
								cout << "Algoritmo Conversión Binario a Decimal - Solución recursiva." << endl << endl;
								cout << "============================================================" << endl << endl;
								opcion2 = submenuAlgoritmosNumericos();
								break;
						}
					}			
					menuAlgoritmosNumericos();
					break;
			case 3: cout << "Algoritmo ThreeBonacci - Solución iterativa." << endl;
					cout << "============================================" << endl << endl;
					opcion2 = submenuAlgoritmosNumericos();
					while(opcion2!=9){
						switch(opcion2){
						case 1: definicionThreeBonacci();
								cout << endl << endl << endl;
								system("pause");
								system("cls");
								cout << "Algoritmo ThreeBonacci - Solución iterativa." << endl << endl;
								cout << "============================================" << endl << endl;
								opcion2 = submenuAlgoritmosNumericos();
								break;
						case 2: requisitosThreeBonacci();
								ejecucionThreeBonacciIterativo();
								cout << endl << endl << endl;
								system("pause");
								system("cls");
								cout << "Algoritmo ThreeBonacci - Solución iterativa." << endl << endl;
								cout << "============================================" << endl << endl;
								opcion2 = submenuAlgoritmosNumericos();
								break;
						case 9: 
								break;
						default: cout << "\nOpción inválida. Vuelva a intentarlo." << endl << endl;
								Sleep(1500);
								system("cls");
								cout << "Algoritmo ThreeBonacci - Solución iterativa." << endl << endl;
								cout << "============================================" << endl << endl;
								opcion2 = submenuAlgoritmosNumericos();
								break;
						}
					}			
					menuAlgoritmosNumericos();
					break;
			case 4: cout << "Algoritmo ThreeBonacci - Solución recursiva." << endl;
					cout << "============================================" << endl << endl;
					opcion2 = submenuAlgoritmosNumericos();
					while(opcion2!=9){
						switch(opcion2){
						case 1: definicionThreeBonacci();
								cout << endl << endl << endl;
								system("pause");
								system("cls");
								cout << "Algoritmo ThreeBonacci - Solución recursiva." << endl << endl;
								cout << "============================================" << endl << endl;
								opcion2 = submenuAlgoritmosNumericos();
								break;
						case 2: requisitosThreeBonacci();
								ejecucionThreeBonacciRecursivo();
								cout << endl << endl << endl;
								system("pause");
								system("cls");
								cout << "Algoritmo ThreeBonacci - Solución iterativa." << endl << endl;
								cout << "============================================" << endl << endl;
								opcion2 = submenuAlgoritmosNumericos();
								break;
						case 9: 
								break;
						default: cout << "\nOpción inválida. Vuelva a intentarlo." << endl << endl;
								Sleep(1500);
								system("cls");
								cout << "Algoritmo ThreeBonacci - Solución recursiva." << endl << endl;
								cout << "============================================" << endl << endl;
								opcion2 = submenuAlgoritmosNumericos();
								break;
						}
					}			
					menuAlgoritmosNumericos();
					break;
			case 9: 
					break;
			default: cout << "\nOpcion inválida. Vuelva a intentarlo." << endl << endl;
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
	cout << "1.- Ver definición." << endl;
	cout << "2.- Ejecutar." << endl << endl;
	cout << "9.- Volver al menú anterior." << endl << endl;
	cout << "Ingrese una opción: ";
	
	cin >> opcion;
	Sleep(1500);
	system("cls");
	return opcion;
}
	
void definicionBinarioDecimal(){
	string def1, def2, def3;
	def1="Definición:";
	def2="El sistema binario sólo utiliza dos dígitos: 0 y 1. El valor de cada posición se obtiene de una potencia de base 2, elevada a un exponente igual a la posición del dígito menos uno.";
	def3="Su popularidad radica en que es el utilizado por las computadoras y dispositivos electrónicos, internamente estos equipos usan el cero para inhibir y el uno para generar impulsos eléctricos en su comunicación interna.";
	cout << def1 << endl;
	cout << def2 << endl;
	cout << def3 << endl;
	/*
	cout << "Definición: " << endl;
	cout << "El sistema binario sólo utiliza dos dígitos: 0 y 1. El valor de cada posición se" << endl;
	cout << "obtiene de una potencia de base 2, elevada a un exponente igual a la posición del" << endl;
	cout << "dígito menos uno." << endl;
	cout << "Su popularidad radica en que es el utilizado por las computadoras y dispositivos" << endl;
	cout << "electrónicos, internamente estos equipos usan el cero para inhibir y el uno para" << endl;
	cout << "generar impulsos eléctricos en su comunicación interna." << endl;
	*/
}
void requisitosBinarioDecimal(){
	cout << "Requisitos a cumplir: " << endl;
	cout << "Se debe ingresar un número binario, el mismo se compone unicamente por 0 y 1, caso" << endl;
	cout << "contrario se indicará que el número no es válido." << endl << endl; 
}
void ejecucionBinarioDecimalIterativo(){
	int  resultado=0, longitud, i=0;
	bool cumple=true;
	string binario;
	cout << "\nIngrese el número que desea convertir: ";
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
		cout<< "\nConversión  ->  ";
		for(int i=0; i<longitud; i++)
			cout<<binario[i];
		cout<<"  =  "<<resultado<<endl;
	}
	else
	   cout<<"\nNúmero inválido."<<endl;
}
void ejecucionBinarioDecimalRecursivo(){
	int  resultado=0, longitud, i=0;
	bool cumple=true;
	string binario;
	cout << "\nIngrese el número que desea convertir: ";
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
		cout<< "\nConversión  ->  ";
		for(int i=0; i<longitud; i++)
			cout<<binario[i];
		cout<<"  =  "<<resultado<<endl;
	}
	else
	   cout<<"\nNúmero inválido."<<endl;
}
int calcularDecimal(string binario,int exponente){
	if(exponente<0)
		return 0;
	else
		return (binario[exponente]-'0') * pow(2,binario.length()-1- exponente) + calcularDecimal(binario, exponente - 1);
}
void definicionThreeBonacci(){
	string def1, def2, def3;
	def1="Definición:";
	def2="Un número pertenece a la secuencia ThreeBonacci si pertenece a la secuencia Fibonacci, y satisface al menos uno de los siguientes criterios: contiene al menos un dígito 3 y/o es un múltiplo de 3.";
	def3="Su popularidad radica en que es el utilizado por las computadoras y dispositivos electrónicos, internamente estos equipos usan el cero para inhibir y el uno para generar impulsos eléctricos en su comunicación interna.";
	cout << def1 << endl;
	cout << def2 << endl;
	cout << def3 << endl;
	/*
	cout << "Definición: " << endl;
	cout << "Un número pertenece a la secuencia ThreeBonacci si pertenece a la secuencia Fibonacci," << endl;
	cout << "y satisface al menos uno de los siguientes criterios:" << endl;
	cout << "  - contiene al menos un dígito 3." << endl;
	cout << "  - es un múltiplo de 3." << endl << endl;
	
	cout << "La sucesión de Fibonacci es una sucesión infinita de números naturales, que comienza con" << endl;
	cout << "dos valores de referencia, en nuestro caso 1 y 1, y a partir de estos, «cada término es" << endl;
	cout << "la suma de los dos anteriores», es la relación de recurrencia que la define." << endl;
	*/
}
void requisitosThreeBonacci(){
	cout << "Requisitos a cumplir: " << endl;
	cout << "Cada caso de prueba contiene un número N, siendo 1<=N<=60, caso"<<endl;
	cout << "contrario se indicará que el número no es válido." << endl;
	cout << "La entrada de datos finaliza con: ctrl+z." << endl << endl;
}
void ejecucionThreeBonacciIterativo(){
	int num;
	cout << "\nIngrese el número N: ";
	while(cin>>num){
		if(num>=1 and num<=60){
			cout<< "\nEl enésimo número es  ->  ";
			buscarOrdenNum(num);
		}
		else
			cout<<"\nNúmero inválido."<<endl;
		cout << "\nIngrese el número N: ";
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
	cout << "\nIngrese el número N: ";
	while(cin>>num){
		if(num>=1 and num<=60){
			cout<< "\nEl enésimo número es  ->  ";
			cout<< buscarNumeroRecursivo(num)<< endl;
		}
		else
		   cout<<"\nNúmero inválido."<<endl;
		cout << "\nIngrese el número N: ";
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
