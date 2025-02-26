#include <iostream>
#include <windows.h>

#include "stdpanel.h"

using namespace std;

void mostrarOpciones(){
	cout << "Bienvenido, selecione una opcion:" << endl;
	cout << "	1. Simulacion de encuentro entre Mario y Luigi" << endl;
	cout << "	2. Simulacion de busqueda de Princesa Peach" << endl;
	cout << "	9. Volver al menu anterior" << endl;
}

void mostrarTablero(char tablerovacio[][20]){
	system("cls");
	cout<<"  i ";
	for(int i=0;i<20;i++){
		if(i<10)cout<<"   "<<i;
		else cout<<"  "<<i;
	}
	cout<<endl;
	for(int i=0; i<10; i++){
		cout<<"  "<<i<<"    ";
		
		for(int j=0;j<20;j++){
			if( (tablerovacio[i][j] == 'X' or tablerovacio[i][j] == '_' or tablerovacio[i][j] == '.' or tablerovacio[i][j] == '^') and (j<10) )
				cout<< tablerovacio[i][j]<<"   ";
			else if( (tablerovacio[i][j] == 'X' or tablerovacio[i][j] == '_' or tablerovacio[i][j] == '.' or tablerovacio[i][j] == '^') and(j>=10) )
				cout<< tablerovacio[i][j]<<"   ";
			else if( tablerovacio[i][j] != 'X' and tablerovacio[i][j] != '_' and tablerovacio[i][j] != '.' and tablerovacio[i][j] != '^' and j<10 )
				cout<<tablerovacio[i][j]<<"    ";
			else if( tablerovacio[i][j] != 'X' and tablerovacio[i][j] != '_' and tablerovacio[i][j] != '.' and tablerovacio[i][j] != '^' and j>=10 ) 
				cout<< tablerovacio[i][j]<<"    ";
				
			if (i==9 and j==19)cout<<"  j";
		}
		cout<<endl;
	}
}

bool pedirCoord(int & coord1, int & coord2){
	cout<<"Ingresa el valor de la coordenada i (o 99 para terminar el juego): ";
	cin>>coord1;
	if(coord1 == 99) return true;
	while(coord1 > 9 || coord1 < 0){
		cout << "Reingresa el valor de la coordenada i correctamente: ";
		cin>>coord1;
	}
	
	cout<<"Ingresa el valor de la coordenada j: ";
	cin>>coord2;
	
	while(coord2 > 19 || coord2 < 0){
		cout << "Reingresa el valor de la coordenada j correctamente: ";
		cin>>coord2;
	}
	
	return false;
}

void mostrarMarcador(int & intentos, int & aciertos, int & fallos){
	cout<<endl;
	cout<<" Debes descubrir los obstaculos indicando las coordenadas i y j en las que se encuentran!"<<endl<<endl;
	cout<<"---------- Marcador ----------"<<endl;
	cout<<"=============================="<<endl;
	cout<<"| Intentos:"<<intentos<<"                 |"<<endl;
	cout<<"| Aciertos:"<<aciertos<<"                 |"<<endl;
	cout<<"| Fallos:"<<fallos<<"                   |"<<endl;
	cout<<"=============================="<<endl;
}
	
void procesarEntrada(char tablero[][20], char tablerovacio[][20], int & intentos, int & aciertos, int & fallos, int & coord1, int & coord2){
	if(tablero[coord1][coord2] == 'X' || tablero[coord1][coord2] == '^') {
		aciertos++;
		cout << "Acertaste a un";
		if(tablero[coord1][coord2] == 'X')
			cout << "a piedra!";
		else
			cout << " pajaro!";
		cout << endl;
	}
	else{
		cout << "Fallaste, sigue intentando!" << endl;
		fallos++;
	}	
	intentos++;
	
	
	tablerovacio[coord1][coord2] = tablero[coord1][coord2];
	Sleep(1500);
}

void tierraAire(char tablero[][20]){
	for(int i=0; i<10; i++){
		for(int j=0; j<20; j++){
			if(tablero[i][j] == ' '){
				if(i == 9)
					tablero[i][j] = '_';
				else
					tablero[i][j] = '.';
			}
		}
	}
}

void ActualizarSalida(char matriz[10][20], bool direccion, char personaje){
	system("cls");
	cout<<"  i ";
	for(int i=0;i<20;i++){
		if(i<10)cout<<"   "<<i;
		else cout<<"  "<<i;
	}
	cout<<endl;
	for(int i=0;i<10;i++){
		cout<<"  "<<i<<"    ";
		
		for(int j=0;j<20;j++){
			cout<<matriz[i][j]<<"   ";
			if (i==9 and j==19)cout<<"  j";
		}
		cout<<endl;
	}
	
	cout<<endl;
	cout<<"Simulacion! Turno de ";
	if(personaje==77)
		cout<<"Mario. ";
	else
		cout<<"Luigi. ";
	
	cout<<"Su orientacion es: ";
	
	if(direccion==1)
		cout<<"Derecha"<<endl;
	else
		cout<<"Izquierda"<<endl;
	
	Sleep(700);
}

void Final(char matriz[10][20]){
	system("cls");
	cout<<"  i ";
	for(int i=0;i<20;i++){
		if(i<10)cout<<"   "<<i;
		else cout<<"  "<<i;
	}
	cout<<endl;
	for(int i=0;i<10;i++){
		cout<<"  "<<i<<"    ";
		
		for(int j=0;j<20;j++){
			cout<<matriz[i][j]<<"   ";
			if (i==9 and j==19)cout<<"  j";
		}
		cout<<endl;
	}
	Sleep(700);
}

void avanzar(char matriz[10][20], bool &direccion, int &movimientos, int &pos, char personaje){
	int i=9;
	
	if(direccion==1){ // 1 --> derecha
		int altura=0;
		if(pos==19){
			direccion=0;
			movimientos++;
			ActualizarSalida(matriz,direccion,personaje);
		}
		else if(matriz[9][pos+1] == 88){
			
			for(int p=7; p<=9; p++){
				
				if(matriz[p][pos+1] == 88){
					altura++;
				}
			}
			movimientos += altura;
			movimientos++;
			
			if(altura == 3){
				
				matriz[8][pos] = personaje;//M
				matriz[9][pos] = 95;//tierra
				
				ActualizarSalida(matriz,direccion,personaje);
				
				matriz[7][pos] = personaje;
				matriz[8][pos] = 46;//cielo
				
				ActualizarSalida(matriz,direccion,personaje);
				
				matriz[6][pos+1] = personaje;
				matriz[7][pos] = 46;
				
				ActualizarSalida(matriz,direccion,personaje);
				
				matriz[9][pos+2] = personaje;
				matriz[6][pos+1] = 46;
				
				ActualizarSalida(matriz,direccion,personaje);
				
			}else if(altura == 2){
				matriz[8][pos] = personaje;
				matriz[9][pos] = 95;
				
				ActualizarSalida(matriz,direccion,personaje);
				
				matriz[7][pos+1] = personaje;
				matriz[8][pos] = 46;
				
				ActualizarSalida(matriz,direccion,personaje);
				
				matriz[9][pos+2] = personaje;
				matriz[7][pos+1] = 46;
				
				ActualizarSalida(matriz,direccion,personaje);
				
			}else if(altura == 1){
				matriz[8][pos+1] = personaje;
				matriz[9][pos] = 95;
				
				ActualizarSalida(matriz,direccion,personaje);
				
				matriz[9][pos+2] = personaje;
				matriz[8][pos+1] = 46;
				
				ActualizarSalida(matriz,direccion,personaje);
			}
			pos+=2;
			
		}else{
			matriz[9][pos+1]=personaje;
			matriz[9][pos]=95;
			pos++;
			movimientos++;
			ActualizarSalida(matriz,direccion,personaje);
		}
	}
	else{ // 0 --> izquierda
		int altura=0;
		if(pos==0){
			direccion=1;
			movimientos++;
			ActualizarSalida(matriz,direccion,personaje);
		}else if(matriz[i][pos-1] == 88){
			
			for(int p=7; p<=9; p++){
				
				if(matriz[p][pos-1] == 88){
					altura++;
				}
			}
			movimientos += altura;
			movimientos++;
			
			if(altura == 3){
				
				matriz[(8)][pos] = personaje;
				matriz[9][pos] = 95;
				
				ActualizarSalida(matriz,direccion,personaje);
				
				matriz[7][pos] = personaje;
				matriz[8][pos] = 46;
				
				ActualizarSalida(matriz,direccion,personaje);
				
				matriz[6][pos-1] = personaje;
				matriz[7][pos] = 46;
				
				ActualizarSalida(matriz,direccion,personaje);
				
				matriz[9][pos-2] = personaje;
				matriz[6][pos-1] = 46;
				
				ActualizarSalida(matriz,direccion,personaje);
				
			}else if(altura == 2 and i==9){
				matriz[8][pos] = personaje;
				matriz[9][pos] = 95;
				
				ActualizarSalida(matriz,direccion,personaje);
				
				matriz[7][pos-1] = personaje;
				matriz[8][pos] = 46;
				
				ActualizarSalida(matriz,direccion,personaje);
				
				matriz[9][pos-2] = personaje;
				matriz[7][pos-1] = 46;
				
				ActualizarSalida(matriz,direccion,personaje);
			}else if(altura == 1){
				matriz[8][pos-1] = personaje;
				matriz[9][pos] = 95;
				
				ActualizarSalida(matriz,direccion,personaje);
				
				matriz[9][pos-2] = personaje;
				matriz[8][pos-1] = 46;
				
				ActualizarSalida(matriz,direccion,personaje);
			}
			pos-=2;
			
		}else{
			matriz[9][pos-1]=personaje;
			matriz[9][pos]=95;
			pos--;
			movimientos++;
			ActualizarSalida(matriz,direccion,personaje);
		}
	}
}

void SimularEncuentro(char matriz[10][20]){
	bool mario=1, luigi=1;
	int aleatorio=0, i=9, posM, posL;
	char Mario=77,Luigi=76,Brothers=66;
	
	while(mario!=0 or luigi!=0){
		for (int j=0; j<20; j++){
			aleatorio = (rand()%5);
			if(aleatorio==0 and matriz[i][j]!=88 and matriz[i][j]!=76 and mario!=0){
				matriz[i][j] = Mario;
				mario = 0;
				posM = j;
			}
			if(aleatorio==1 and matriz[i][j]!=88 and matriz[i][j]!=77 and luigi!=0){
				matriz[i][j] = Luigi;
				luigi = 0;
				posL = j;
			}
		}
	}
	
	cout<<"  i ";
	for(int i=0;i<20;i++){
		if(i<10)cout<<"   "<<i;
		else cout<<"  "<<i;
	}
	cout<<endl;
	for(int i=0;i<10;i++){
		cout<<"  "<<i<<"    ";
		
		for(int j=0;j<20;j++){
			cout<<matriz[i][j]<<"   ";
			if (i==9 and j==19)cout<<"  j";
		}
		cout<<endl;
	}
	system("pause");
	
	int movimientosM=0, movimientosL=0, turno, encontrados=0;
	bool direccionM,direccionL; // direc = 1 --> derecha
	
	turno = (rand()%2); 
	direccionM = (rand()%2);
	direccionL = (rand()%2); // randomizamos
	
	while(encontrados==0){
		
		if(turno%2==0){ // MARIO
			
			avanzar(matriz, direccionM, movimientosM, posM, Mario);
			
			
		}
		else { //LUIGI
			
			avanzar(matriz, direccionL, movimientosL, posL, Luigi);
			
		}
		
		if(posM==posL){
			matriz[9][posM]=Brothers;
			encontrados=1;
		}
		
		turno++;
		
	}
	Final(matriz);
	cout<<endl;
	cout<<"Los hermanos se han unido!"<<endl;
	cout<<"Hola, soy Mario!"<<endl;
	cout<<"Hola, soy Luigi!"<<endl<<endl;
	
	cout<<"Cantidad de movimientos de Mario: "<<movimientosM<<endl;
	cout<<"Cantidad de movimientos de Luigi: "<<movimientosL<<endl<<endl;
	
	
	if(movimientosL<movimientosM)
		cout<<"El ganador es: Luigi"<<endl;
	else if(movimientosL>movimientosM)
		cout<<"El ganador es: Mario"<<endl;
	
	if(movimientosL==movimientosM)
		cout<<"Es un empate!"<<endl;
	
	system("pause");
	
}

void MyL(char tablero[10][20]){
	char tablerovacio[10][20];
	tierraAire(tablero);
	int intentos = 0, aciertos = 0, fallos = 0, coord1 = -1, coord2;
	
	for(int i=0;i<10;i++){
		for(int j=0;j<20;j++){
			tablerovacio[i][j]=0;
		}
	}
	
	system("cls");
	while(coord1 != 99 && aciertos < 21){
		mostrarTablero(tablerovacio);
		mostrarMarcador(intentos, aciertos, fallos);
		if(!pedirCoord(coord1, coord2)){
			procesarEntrada(tablero, tablerovacio, intentos, aciertos, fallos, coord1, coord2);
		}
	}
	
	mostrarTablero(tablero);
	mostrarMarcador(intentos, aciertos, fallos);
	
	system("pause");
	cout << endl << endl << "Ahora vamos a realizar la simulacion de los hermanos!" << endl;
	Sleep(1500);
	system("cls");
	
	SimularEncuentro(tablero);
	
}
	
void explicarJuego(){
	system("cls");
	cout << "Imagina que tienes un tablero oculto donde se han escondido aves '^' en el cielo" << endl;
	cout << "(en las primeras filas) y piedras 'X' que pueden ocupar varias celdas en la parte baja" << endl;
	cout << "(con alturas variables)." << endl << endl;
	
	cout << "Tu tarea es ingresar coordenadas para descubrir las celdas:" << endl << endl;
	
	cout << "-----------------------------------------------------" << endl;
	cout << "Si adivinas correctamente (es decir, si en esa celda hay una parte de un objeto)," << endl;
	cout << "se te mostrara el simbolo correspondiente y se sumara un punto a tu puntaje." << endl;
	cout << "Si fallas, veras un mensaje que te indicara \"Aire\" o \"Tierra\" segun corresponda," << endl;
	cout << "y la celda se revelara mostrando el entorno." << endl;
	cout << "-----------------------------------------------------" << endl << endl;
	
	cout << "El reto es ir descubriendo la mayor cantidad de objetos hasta revelar todo el tablero" << endl;
	cout << "o decidir terminar antes, para conocer tu puntaje." << endl;
	cout << "Una vez completada esta etapa, el Reino Champinon va a quedar visible" << endl;
	cout << "y se va a dar paso a la simulacion en la que intervienen los personajes Mario y Luigi." << endl << endl;
	system("pause");
}

void opcionesMyL(){
	cout << "Super Mario Bros: Juegos y Simulaciones" << endl << endl;
	cout << "============================================================" << endl << endl;
	cout << "1.- Ver definicion." << endl;
	cout << "2.- Ejecutar." << endl << endl;
	cout << "9.- Volver al menu anterior." << endl << endl;
}

void menuMyL(char tablero[][MAXIMO]){
	system("cls");
	int opcion=-1;
	
	while(opcion != 9){
		opcionesMyL();
		
		cout << "Digite su eleccion: ";
		cin >> opcion;
		
		switch(opcion){
		case 1: 
			explicarJuego();
			break;
		case 2:
			cargarTablero(tablero, 10, 20);
			MyL(tablero);
			break;
		case 9:
			cout << "Volviendo..." << endl;
			break;
		default:
			cout << "ERROR - Revise el valor ingresado" << endl;
			break;
		}
		Sleep(1500);
		system("cls");
	}
}

void menuJuego(){
	char tablero[10][20];
	int opcion=-1;
	
	while(opcion != 9){
		mostrarOpciones();
		
		cout << "Digite su eleccion: ";
		cin >> opcion;
		
		switch(opcion){
			case 1: 
				menuMyL(tablero);
				break;
			case 2:
				cout << "Actualmente esta opcion no esta disponible." << endl;
				break;
			case 9:
				cout << "Volviendo al menu..." << endl;
				break;
			default:
				cout << "ERROR - Revise el valor ingresado" << endl;
				break;
		}
		if(opcion != 1) Sleep(1500);
		system("cls");
	}
}
