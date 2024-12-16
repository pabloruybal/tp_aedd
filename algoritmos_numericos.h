#ifndef ALGORITMOS_NUMERICOS_H
#define ALGORITMOS_NUMERICOS_H
#include <string>
using std::string;

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

#endif
