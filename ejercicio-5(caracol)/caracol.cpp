#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	//input
	int L, X, Y, dias = 1;
	cin >> L >> X >> Y;
	// En caso de que el caracol cae más por la noche de lo que puede subir.
	if(X <= Y){
		// En caso de que el caracol sube menos en un día de lo que mide la pared (recuerda
		// que seguimos en el if anterior)
		if(X < L){
			cout << "-1";
		}
		// si X > L el caracol puede subir toda la pared en un solo día.
		else{
			cout << "1";
		}
	}
	//El caracol puede subir más de lo que cae en la noche, entonces va a poder subir la pared
	else{
		// el total de lo que sube el caracol (un día y una noche)
		int estadoActual = X - Y;

		//Esta es la parte más importante, cuando el caracol llegue a la cima de la pared ya 				  //no va a caer, porque ya esta hasta arriba, por eso le ponemos que la altura
		//inicial va a ser X

		int alturaRecorrida = X; //cuando ya se encuentre hasta arriba.
		while(alturaRecorrida < L){
			dias ++;
			alturaRecorrida += estadoActual;
		}
		cout << dias << endl;
	}	

	return 0; 
}
