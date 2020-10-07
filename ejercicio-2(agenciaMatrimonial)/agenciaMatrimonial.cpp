#include <iostream>
#include <stdio.h>

using namespace std;

void descendente(int a[], int);

int main()
{
    int n;
    cin>>n;
    int hombres[n];
    int mujeres[n];
    int aux;
    int comparacion[n];
    int maxima=0;
    int minima=0;

    //capturar hombres
    for(int i=0;i<n;i++){
        cin >> hombres[i];
    }
    //capturar mujeres
    for(int i=0;i<n;i++){
        cin >> mujeres[i];
    }

    descendente(hombres, n);

    //Ordenar mujeres ascendentemente (de menor a mayor)
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
                if(mujeres[i] > mujeres[j]){
                        aux=mujeres[i];
                        mujeres[i] = mujeres[j];
                        mujeres[j]=aux;
                }
        }
    }

    //Comparar numeros de hombres y mujeres, sumar diferencia
    for(int i=0; i<n; i++){
        comparacion[i]=hombres[i]-mujeres[i];
        //Si la diferencia es un numero negativo
        if(comparacion[i]<0){
                comparacion[i]=comparacion[i]*-1;
        }
        maxima=comparacion[i]+maxima;
    }

    descendente(mujeres, n);
//Comparar nuevamente numeros de hombres y mujeres, sumar diferencia
    for(int i=0; i<n; i++){
        comparacion[i]=hombres[i]-mujeres[i];
        //Si la diferencia es un numero negativo
        if(comparacion[i]<0){
                comparacion[i]=comparacion[i]*-1;
        }
        minima=comparacion[i]+minima;
    }

    cout << minima << " " << maxima;

    return 0;
}

void descendente (int a[], int n){
int aux;
        for(int i=0; i<n; i++){
                for(int j=i+1; j<n; j++){
                        if(a[i] < a[j]){
                                aux=a[i];
                                a[i] = a[j];
                                a[j]=aux;
                        }
                }
        }
}
