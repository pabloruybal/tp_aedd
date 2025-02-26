#include <iostream>
#include <windows.h>

using namespace std;

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
	
