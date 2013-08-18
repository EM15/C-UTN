#include <math.h>
#include <stdio.h>

void aBinario(double decimal, int binario[10]);
int controlaTira(int control[10]);
int valorTira(int control[10]);
void ordenaObjetos();
void calculaProporcion();


struct objeto {
	int vol;
	int valor;
	double proporcion;
	int nroobjeto;
};

struct objeto objetos[10];

void main(){
	int vol_mochi = 4200;
	int max_vol=0;
	int i,k,m;
	int max_precio=0;
	
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

	for(i=0;i<10;i++)
		objetos[i].nroobjeto = i+1;
	
	calculaProporcion();
	ordenaObjetos();

	for (i=0; i<10; i++){  
		if ((max_vol+objetos[i].vol)<=vol_mochi){
                	max_vol = max_vol + objetos[i].vol;
			max_precio = max_precio + objetos[i].valor;
			printf("Objeto %d, volumen: %d, valor: %d\n", objetos[i].nroobjeto, objetos[i].vol, objetos[i].valor);
		}
	} 
	printf("Volumen: %d, precio: %d\n\n", max_vol, max_precio);
}

void calculaProporcion(){
	int i;
	for (i=0;i<10;i++)
		objetos[i].proporcion = objetos[i].valor/objetos[i].vol;   
}

void ordenaObjetos(){
	int i,k;
	struct objeto buffer;
	for(i=0;i<9;i++){
		for(k=1;k<10;k++){
			if(objetos[i].proporcion < objetos[k].proporcion){
				buffer.proporcion = objetos[i].proporcion;
				buffer.vol = objetos[i].vol;
				buffer.valor = objetos[i].valor;
				buffer.nroobjeto=objetos[i].nroobjeto;
                
				objetos[i].vol = objetos[k].vol;
				objetos[i].valor = objetos[k].valor;
				objetos[i].proporcion = objetos[k].proporcion;
				objetos[i].nroobjeto= objetos[k].nroobjeto;                 		

				objetos[k].proporcion = buffer.proporcion;
				objetos[k].vol = buffer.vol;
				objetos[k].valor = buffer.valor;
				objetos[k].nroobjeto=buffer.nroobjeto;
			}
		}
	}
}
