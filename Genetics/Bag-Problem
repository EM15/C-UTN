#include <math.h>
#include <stdio.h>

void aBinario(double decimal, int binario[10]);
int controlaTira(int control[10]);
int valorTira(int control[10]);

struct objeto {
	int vol;
	int valor;
};

struct objeto objetos[10];

void main(){
	int control[10],solucion[10];
	int max_vol = 4200;
	double iteraciones = pow(2,10);
	int i,k,m;
	int max_encontrado,max_precio=0;

	printf("\n");

	objetos[0].vol = 150;
	objetos[0].valor = 20;

	objetos[1].vol = 325;
	objetos[1].valor = 40;

	objetos[2].vol = 600;
	objetos[2].valor = 50;

	objetos[3].vol = 805;
	objetos[3].valor = 36;

	objetos[4].vol = 430;
	objetos[4].valor = 25;

	objetos[5].vol = 1200;
	objetos[5].valor = 64;

	objetos[6].vol = 770;
	objetos[6].valor = 54;

	objetos[7].vol = 60;
	objetos[7].valor = 18;

	objetos[8].vol = 930;
	objetos[8].valor = 46;

	objetos[9].vol = 353;
	objetos[9].valor = 28;

	for(i=0;i<10;i++){
		solucion[i] = 0;
	}

	for(k=0;k<iteraciones;k++){
		aBinario(k,control);
		if((controlaTira(control) < 4200) && (valorTira(solucion) <= valorTira(control))){
			max_encontrado = controlaTira(control);
			for(m=0;m<10;m++){
				solucion[m] = control[m];
				if(control[m] == 1)
					printf("Objeto %d, volumen: %d, valor: %d \n",m+1,objetos[m].vol,objetos[m].valor);
			}
			printf("Volumen: %d precio: %d \n",max_encontrado,valorTira(solucion));
			printf("\n");
		}
		
	}
}

int valorTira(int control[10]){
	int buffer = 0, i;
	for(i=0;i<10;i++){
		if(control[i] == 1){
			buffer = buffer+objetos[i].valor;                 
		}
	}
	return buffer;
}
int controlaTira(int control[10]){
	int buffer = 0, i;
	for(i=0;i<10;i++){
		if(control[i] == 1){
			buffer = buffer+objetos[i].vol;
		}
	}
	return buffer;
}
void aBinario(double decimal, int binario[10]){
	int i;
	for (i=0; i<10;i++){
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
