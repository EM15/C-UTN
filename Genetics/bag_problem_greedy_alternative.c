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

struct objeto objetos[3];

int main(){
	int vol_mochi = 3000;
	int max_vol=0;
	int i,k,m;
	int max_precio=0;
	
	printf("\n");

	objetos[0].vol = 1800;
	objetos[0].valor = 72;

	objetos[1].vol = 600;
	objetos[1].valor = 36;

	objetos[2].vol = 1200;
	objetos[2].valor = 60;

	for(i=0;i<3;i++)
		objetos[i].nroobjeto = i+1;
	
	calculaProporcion();
	ordenaObjetos();

	for (i=0; i<3; i++){  
		if ((max_vol+objetos[i].vol)<=vol_mochi){
                	max_vol = max_vol + objetos[i].vol;
			max_precio = max_precio + objetos[i].valor;
			printf("Objeto %d, volumen: %d, valor: %d\n", objetos[i].nroobjeto, objetos[i].vol, objetos[i].valor);
		}
	} 
	printf("Volumen: %d, precio: %d\n\n", max_vol, max_precio);
	return 0;
}

void calculaProporcion(){
	int i;
	for (i=0;i<3;i++)
		objetos[i].proporcion = (float)objetos[i].valor/(float)objetos[i].vol;   
}

void ordenaObjetos(){
	int i,k;
	struct objeto buffer;
	for(i=0;i<2;i++){
		for(k=i+1;k<3;k++){
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
