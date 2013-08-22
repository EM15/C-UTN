#include <math.h>
#include <stdio.h>

void aBinario(double decimal, int binario[10]);
int controlaTira(int control[10]);
int valorTira(int control[10]);

struct objeto {
	int vol;
	int valor;
};

struct objeto objetos[3];

int main(){
	int control[3],solucion[3];
	int max_vol = 3000;
	double iteraciones = pow(2,3);
	int i,k,m;
	int max_encontrado,max_precio=0;

	

	objetos[0].vol = 1800;
	objetos[0].valor = 72;

	objetos[1].vol = 600;
	objetos[1].valor = 36;

	objetos[2].vol = 1200;
	objetos[2].valor = 60;

	for(i=0;i<3;i++){
		solucion[i] = 0;
	}

	for(k=0;k<iteraciones;k++){
		aBinario(k,control);
		if((controlaTira(control) <= 3000) && (valorTira(solucion) <= valorTira(control))){
			max_encontrado = controlaTira(control);
			for(m=0;m<3;m++){
				solucion[m] = control[m];
				if(control[m] == 1){
                              printf("Objeto %d, volumen: %d, valor: %d \n",m+1,objetos[m].vol,objetos[m].valor);                           
                } 
			}
			printf("Volumen: %d precio: %d \n",max_encontrado,valorTira(solucion));
			printf("\n\n\n");
		}
		
	}
	return 0;
}

int valorTira(int control[10]){
    int buffer = 0, i;
    for(i=0;i<3;i++){
           if(control[i] == 1){
                      buffer = buffer+objetos[i].valor;                 
           }     
    }
    return buffer;
}

int controlaTira(int control[10]){
	int buffer = 0, i;
	for(i=0;i<3;i++){
		if(control[i] == 1){
			buffer = buffer+objetos[i].vol;
		}
	}
	return buffer;
}

void aBinario(double decimal, int binario[10]){
	int i;
	for (i=0; i<3;i++){
		binario[i]=0;
	}
	i=9;
	while (decimal!=0){
		if (decimal>=pow(2,i)){
			binario[i]=1;
			decimal=decimal-pow(2,i);
			}
		i--;
	}
}
