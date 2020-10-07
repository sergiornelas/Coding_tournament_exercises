#include <iostream>

using namespace std;

int main(){
	int N;
	cin >> N;
    
	//N define la cantidad de arreglos char
	//4 define la longuitud de cada arreglo char (deben ser 20)
	char s[N][20];
    	
	//depositamos los elementos del arreglo de chars
	for(int i=0;i<N;i++){
		for(int j=0;j<20;j++){
			cin >> s[i][j];    
		}
	}
    	
	//char z = char s[N][20];
	
	//cout <<"------"<<endl;
    
	//imprimimos los elementos del arreglo de chars
   	/* 
	for(int i=0;i<N;i++){
		for(int j=0;j<20;j++){
			cout << s[i][j];    
		}
        	cout<<endl;
	}
	cout <<"------"<<endl;
	*/

	int charsParseados[N][20];

	//Convertimos el arreglo de chars a enteros
	for(int i=0;i<N;i++){
                for(int j=0;j<20;j++){
			charsParseados[i][j] = s[i][j] - '0';
			//cout << "PRUEBA: " << charsParseados[i][j] << endl;
                }
        }
	
	int cantidadLetras[N];
	int caracteres[N];

	//Definimos los limites de caracteres que permitira el arreglo dependiendo del número insertado en [N][3]
	for(int i=0;i<N;i++){
        	cantidadLetras[i] = charsParseados[i][3]; //definimos el 4to numero como el limite de letras que contendrá el arreglo
	        //cout<<"numero de Letras que permitirá el string\n" << cantidadLetras[i] << endl;

		caracteres[i]=cantidadLetras[i]* 2; //en base a la cantidad de letras definimos el número de carácteres permitidos. 
        	//cout<<"numero de caracteres que permitirá el string\n"<< caracteres[i] <<endl; 
	}

	//cout <<"------"<<endl;

	//PRIMER PASO:
        //La cantidad que exista de números después del 4to número del arreglo ([3]) coincida con la variable
        //'caracteres', en caso de que no mandar error.

	int bandera=0;
	int L1=4, L2=5;
	int letraNumero;

        for(int i=0;i<N;i++){
        	for(int j=4;j<20;j++){
                	if(charsParseados[i][j] > 0){
				bandera=bandera+1;
                        	//cout << "Arreglo " << i << "-" << j << " tiene numero" << endl;
				if(bandera > caracteres[i]){
					cout<<"Error";
					goto fin;
                        	}					
			}
               	}
		
		//SEGUNDO PASO:
                //tomar de dos en dos los numeros del arreglo (L1,L2), juntarlos  en uno solo (letraAscii)
                //y convertirlo a ASCII para que nos imprima la letra.
		
		for(int x = 0; x<8; x++){ // se repetirá 8 veces (8 letras que permite cada arreglo)
                        int numero = s[i][L1]-'0';
                        int numero2 = s[i][L2]-'0';
			
	                        //cout << numero << endl;
	                        //cout << numero2 << endl;
	
	                if(numero == 0){
                        	goto fin;
                        }
                        if(numero == 6){
                                letraNumero = 54+(numero+numero2);
                        }
                        if(numero == 7){
                                letraNumero = 63+(numero+numero2);
                        }
                        if(numero == 8){
                                letraNumero = 72+(numero+numero2);
                        }
                        if(numero == 9){
                                letraNumero = 81+(numero+numero2);
                        }

				//solo que no hemos limitado a recibir solamente letras A-Z
	                        //cout << letraNumero << endl;
                        
			char letraAscii = char(letraNumero);
                        cout << letraAscii;

                        //cout <<"------"<<endl;
                        L1=L1+2;
                        L2=L2+2;
                }

		fin:
                L1=4;
                L2=5;
		bandera=0;
                //cout <<"---CAMBIO DE FILA---"<<endl;
		cout << endl;
	}
	return 0;
}
