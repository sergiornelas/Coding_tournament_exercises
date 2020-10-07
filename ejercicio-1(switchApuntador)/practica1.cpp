/*
 Opción [A]: Leer dos cadenas de carácteres, enviarlos a una función
 como parámetros y por medio de punteros recorrer las cadenas, la primera
 de izquierda a derecha y la segunda de derecha a izquierda. Imprimir como 
 salida si son iguales o diferentes
 Opción [B]: Leer cadena de carácteres con una longuitud máxima de 50,
 recorrer la cadena por medio de punteros e imprimir de salida cuantas
 consonantes se encuentran en ella.
 Opción [S]: Salir del programa.
 * */

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

//prototipo para invertir cadena con punteros
string invertir(char palabra[20]);

int main(){
	char opcion[0];
	//A
	char Cadena1[50];
	char Cadena2[50];
	//B
	char CadenaB[50];
	char *punt ;
	punt = CadenaB;
	int count = 0;
	
	cout<<"Escoge una opción"<<"\n";
	cout<<"[a] Igualdad [b] Consonantes [s] Salir\n";
	cin>>opcion;
	
	bool loopSwitch = false;
	do{
		switch(opcion[0]){
			case 'a':{
				cout<<"Ingresa la primer palabra: ";
				cin>>Cadena1;
				cout<<"Ingresa la segunda palabra: ";
				cin>>Cadena2;
				string palindromo = invertir(Cadena1);
				//strcmp = string comparation
				if(strcmp(Cadena1, Cadena2)==0){
					cout<<"\nSon iguales!\n";
					cout <<palindromo<<" = "<<Cadena2<<"\n";
					loopSwitch=true;
				}
				else{
					cout<<"\nSon diferentes!\n";
					cout<<palindromo<<" != "<<Cadena2<<"\n";
					loopSwitch=true;
				}
				break;
				}
	
			case 'b':{
				cout<<"Ingresa una cadena, máximo 50 caracteres\n";
				cin>>CadenaB;

				for(punt;(*punt) != '\0'; punt++) {
			  	      if (*punt != 'a' && *punt != 'e' && *punt != 'i' && *punt != 'o' && *punt != 'u') {
				         count++;
			        	}
				}
				cout << "\nConsonantes en la cadena:" << count<<"\n";
				loopSwitch=true;
				break;
				}
			case 's':
				 return 0;
				 break;
			default:
				 cout<<"Ingrese un caracter correcto: [a], [b], [s]\n";
				 cin>>opcion;
				 break;
		}
	} while(!loopSwitch);
}

string invertir(char palabra[50])
{
    char a='a';
    char b='b';
    char *frente=&a; //almacenamos direccion de la variable de a
    char *posterior=&b;
    //strlen = longuitud del string
    for (int i=0;i< (strlen(palabra)/2);i++)
    {
            *frente=palabra[i];
            *posterior=palabra[strlen(palabra)-1-i];
            palabra[i]=*posterior;
            palabra[strlen(palabra)-1-i]=*frente;
    }
    return palabra;
}

/*
 *	:%s/\<foo\>/bar/g
	Cambia la palabra completa 'foo' por 'bar'.
 * */
