/*
 * Traveling salesman problem using a simple heuristic algorithm
 * Sorry, variable names and comments are in Spanish and I'm too lazy to translate it
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

unsigned int menu();

struct capital{
	char nombre[64];
	int distancia[23];
};

void main(){

	int i,k,dist_min,dist_total,buffer_usados,provincia_inicial,usados[23];
	unsigned int provincia = 24;
	struct capital capitales[23];

	srand(time(NULL));

	/*
	 * Inicializamos el acumulador de distancia
	 */
	dist_total = 0;
	/*
	 * Seteamos el arreglo de capitales "usadas" en 0
	 */
	for(i=0;i<23;i++){
		usados[i] = 0;
	}

	//  0 => La Plata
	//  1 => Jujuy
	//  2 => Salta
	//  3 => Tucumán
	//  4 => Santiago del Estero
	//  5 => Formosa
	//  6 => Resistencia
	//  7 => Santa Fe
	//  8 => Corrientes
	//  9 => Posadas
	// 10 => Paraná
	// 11 => Córdoba
	// 12 => La Rioja
	// 13 => San Juan
	// 14 => San Luis
	// 15 => Catamarca
	// 16 => Mendoza
	// 17 => Santa Rosa
	// 18 => Neuquen
	// 19 => Viedma
	// 20 => Rawson
	// 21 => Rio Gallegos
	// 22 => Ushuaia

	strcpy(capitales[0].nombre,"La Plata");
	strcpy(capitales[1].nombre,"Jujuy");
	strcpy(capitales[2].nombre,"Salta");
	strcpy(capitales[3].nombre,"Tucumán");
	strcpy(capitales[4].nombre,"Santiago del Estero");
	strcpy(capitales[5].nombre,"Formosa");
	strcpy(capitales[6].nombre,"Resistencia");
	strcpy(capitales[7].nombre,"Santa Fe");
	strcpy(capitales[8].nombre,"Corrientes");
	strcpy(capitales[9].nombre,"Posadas");
	strcpy(capitales[10].nombre,"Paraná");
	strcpy(capitales[11].nombre,"Córdoba");
	strcpy(capitales[12].nombre,"La Rioja");
	strcpy(capitales[13].nombre,"San Juan");
	strcpy(capitales[14].nombre,"San Luis");
	strcpy(capitales[15].nombre,"Catamarca");
	strcpy(capitales[16].nombre,"Mendoza");
	strcpy(capitales[17].nombre,"Santa Rosa");
	strcpy(capitales[18].nombre,"Neuquen");
	strcpy(capitales[19].nombre,"Viedma");
	strcpy(capitales[20].nombre,"Rawson");
	strcpy(capitales[21].nombre,"Rio Gallegos");
	strcpy(capitales[22].nombre,"Ushuaia");


	capitales[0].distancia[0] = 0;
	capitales[0].distancia[1] = 1543;
	capitales[0].distancia[2] = 1510;
	capitales[0].distancia[3] = 1203;
	capitales[0].distancia[4] = 1043;
	capitales[0].distancia[5] = 1191;
	capitales[0].distancia[6] = 1023;
	capitales[0].distancia[7] = 478;
	capitales[0].distancia[8] = 940;
	capitales[0].distancia[9] = 1040;
	capitales[0].distancia[10] = 480;
	capitales[0].distancia[11] = 715;
	capitales[0].distancia[12] = 1150;
	capitales[0].distancia[13] = 1110;
	capitales[0].distancia[14] = 790;
	capitales[0].distancia[15] = 1155;
	capitales[0].distancia[16] = 1050;
	capitales[0].distancia[17] = 620;
	capitales[0].distancia[18] = 1158;
	capitales[0].distancia[19] = 960;
	capitales[0].distancia[20] = 1455;
	capitales[0].distancia[21] = 2635;
	capitales[0].distancia[22] = 3228; 

	capitales[1].distancia[0] = 1543;
	capitales[1].distancia[1] = 0;
	capitales[1].distancia[2] = 99;
	capitales[1].distancia[3] = 340;
	capitales[1].distancia[4] = 500;
	capitales[1].distancia[5] = 960;
	capitales[1].distancia[6] = 860;
	capitales[1].distancia[7] = 1107;
	capitales[1].distancia[8] = 883;
	capitales[1].distancia[9] = 1198;
	capitales[1].distancia[10] = 1138;
	capitales[1].distancia[11] = 930;
	capitales[1].distancia[12] = 770;
	capitales[1].distancia[13] = 1220;
	capitales[1].distancia[14] = 1320;
	capitales[1].distancia[15] = 572;
	capitales[1].distancia[16] = 1345;
	capitales[1].distancia[17] = 1530;
	capitales[1].distancia[18] = 2200;
	capitales[1].distancia[19] = 2124;
	capitales[1].distancia[20] = 2385;
	capitales[1].distancia[21] = 3565;
	capitales[1].distancia[22] = 4158; 

	capitales[2].distancia[0] = 1510;
	capitales[2].distancia[1] = 99;
	capitales[2].distancia[2] = 0;
	capitales[2].distancia[3] = 307;
	capitales[2].distancia[4] = 467;
	capitales[2].distancia[5] = 948;
	capitales[2].distancia[6] = 780;
	capitales[2].distancia[7] = 1074;
	capitales[2].distancia[8] = 803;
	capitales[2].distancia[9] = 1118;
	capitales[2].distancia[10] = 1105;
	capitales[2].distancia[11] = 897;
	capitales[2].distancia[12] = 695;
	capitales[2].distancia[13] = 1145;
	capitales[2].distancia[14] = 1245;
	capitales[2].distancia[15] = 539;
	capitales[2].distancia[16] = 1227;
	capitales[2].distancia[17] = 1497;
	capitales[2].distancia[18] = 2082;
	capitales[2].distancia[19] = 2091;
	capitales[2].distancia[20] = 2352;
	capitales[2].distancia[21] = 3532;
	capitales[2].distancia[22] = 4125; 

	capitales[3].distancia[0] = 1203;
	capitales[3].distancia[1] = 340;
	capitales[3].distancia[2] = 307;
	capitales[3].distancia[3] = 0;
	capitales[3].distancia[4] = 160;
	capitales[3].distancia[5] = 936;
	capitales[3].distancia[6] = 768;
	capitales[3].distancia[7] = 767;
	capitales[3].distancia[8] = 791;
	capitales[3].distancia[9] = 1106;
	capitales[3].distancia[10] = 798;
	capitales[3].distancia[11] = 590;
	capitales[3].distancia[12] = 338;
	capitales[3].distancia[13] = 838;
	capitales[3].distancia[14] = 938;
	capitales[3].distancia[15] = 232;
	capitales[3].distancia[16] = 1005;
	capitales[3].distancia[17] = 1190;
	capitales[3].distancia[18] = 1860;
	capitales[3].distancia[19] = 1784;
	capitales[3].distancia[20] = 2045;
	capitales[3].distancia[21] = 3225;
	capitales[3].distancia[22] = 3818; 

	capitales[4].distancia[0] = 1043;
	capitales[4].distancia[1] = 500;
	capitales[4].distancia[2] = 467;
	capitales[4].distancia[3] = 160;
	capitales[4].distancia[4] = 0;
	capitales[4].distancia[5] = 776;
	capitales[4].distancia[6] = 610;
	capitales[4].distancia[7] = 607;
	capitales[4].distancia[8] = 633;
	capitales[4].distancia[9] = 948;
	capitales[4].distancia[10] = 638;
	capitales[4].distancia[11] = 430;
	capitales[4].distancia[12] = 360;
	capitales[4].distancia[13] = 810;
	capitales[4].distancia[14] = 850;
	capitales[4].distancia[15] = 212;
	capitales[4].distancia[16] = 977;
	capitales[4].distancia[17] = 1030;
	capitales[4].distancia[18] = 1567;
	capitales[4].distancia[19] = 1624;
	capitales[4].distancia[20] = 1885;
	capitales[4].distancia[21] = 3065;
	capitales[4].distancia[22] = 3658; 

	capitales[5].distancia[0] = 1191;
	capitales[5].distancia[1] = 960;
	capitales[5].distancia[2] = 948;
	capitales[5].distancia[3] = 936;
	capitales[5].distancia[4] = 776;
	capitales[5].distancia[5] = 0;
	capitales[5].distancia[6] = 168;
	capitales[5].distancia[7] = 713;
	capitales[5].distancia[8] = 191;
	capitales[5].distancia[9] = 506;
	capitales[5].distancia[10] = 744;
	capitales[5].distancia[11] = 1043;
	capitales[5].distancia[12] = 1136;
	capitales[5].distancia[13] = 1543;
	capitales[5].distancia[14] = 1463;
	capitales[5].distancia[15] = 988;
	capitales[5].distancia[16] = 1710;
	capitales[5].distancia[17] = 1523;
	capitales[5].distancia[18] = 2060;
	capitales[5].distancia[19] = 2117;
	capitales[5].distancia[20] = 2378;
	capitales[5].distancia[21] = 3558;
	capitales[5].distancia[22] = 4151; 

	capitales[6].distancia[0] = 1023;
	capitales[6].distancia[1] = 860;
	capitales[6].distancia[2] = 780;
	capitales[6].distancia[3] = 765;
	capitales[6].distancia[4] = 610;
	capitales[6].distancia[5] = 168;
	capitales[6].distancia[6] = 0;
	capitales[6].distancia[7] = 545;
	capitales[6].distancia[8] = 23;
	capitales[6].distancia[9] = 338;
	capitales[6].distancia[10] = 576;
	capitales[6].distancia[11] = 875;
	capitales[6].distancia[12] = 970;
	capitales[6].distancia[13] = 1420;
	capitales[6].distancia[14] = 1295;
	capitales[6].distancia[15] = 822;
	capitales[6].distancia[16] = 1587;
	capitales[6].distancia[17] = 1475;
	capitales[6].distancia[18] = 2012;
	capitales[6].distancia[19] = 2069;
	capitales[6].distancia[20] = 2210;
	capitales[6].distancia[21] = 3390;
	capitales[6].distancia[22] = 3983; 

	capitales[7].distancia[0] = 478;
	capitales[7].distancia[1] = 1107;
	capitales[7].distancia[2] = 1074;
	capitales[7].distancia[3] = 767;
	capitales[7].distancia[4] = 607;
	capitales[7].distancia[5] = 713;
	capitales[7].distancia[6] = 545;
	capitales[7].distancia[7] = 0;
	capitales[7].distancia[8] = 568;
	capitales[7].distancia[9] = 883;
	capitales[7].distancia[10] = 31;
	capitales[7].distancia[11] = 330;
	capitales[7].distancia[12] = 765;
	capitales[7].distancia[13] = 830;
	capitales[7].distancia[14] = 625;
	capitales[7].distancia[15] = 770;
	capitales[7].distancia[16] = 885;
	capitales[7].distancia[17] = 810;
	capitales[7].distancia[18] = 1347;
	capitales[7].distancia[19] = 1404;
	capitales[7].distancia[20] = 1665;
	capitales[7].distancia[21] = 2845;
	capitales[7].distancia[22] = 3438; 

	capitales[8].distancia[0] = 940;
	capitales[8].distancia[1] = 883;
	capitales[8].distancia[2] = 803;
	capitales[8].distancia[3] = 791;
	capitales[8].distancia[4] = 633;
	capitales[8].distancia[5] = 191;
	capitales[8].distancia[6] = 23;
	capitales[8].distancia[7] = 568;
	capitales[8].distancia[8] = 0;
	capitales[8].distancia[9] = 315;
	capitales[8].distancia[10] = 590;
	capitales[8].distancia[11] = 898;
	capitales[8].distancia[12] = 993;
	capitales[8].distancia[13] = 1398;
	capitales[8].distancia[14] = 1318;
	capitales[8].distancia[15] = 845;
	capitales[8].distancia[16] = 1565;
	capitales[8].distancia[17] = 1378;
	capitales[8].distancia[18] = 1989;
	capitales[8].distancia[19] = 2046;
	capitales[8].distancia[20] = 2187;
	capitales[8].distancia[21] = 3367;
	capitales[8].distancia[22] = 3960; 

	capitales[9].distancia[0] = 1040;
	capitales[9].distancia[1] = 1198;
	capitales[9].distancia[2] = 1118;
	capitales[9].distancia[3] = 1106;
	capitales[9].distancia[4] = 948;
	capitales[9].distancia[5] = 506;
	capitales[9].distancia[6] = 338;
	capitales[9].distancia[7] = 883;
	capitales[9].distancia[8] = 315;
	capitales[9].distancia[9] = 0;
	capitales[9].distancia[10] = 820;
	capitales[9].distancia[11] = 1213;
	capitales[9].distancia[12] = 1308;
	capitales[9].distancia[13] = 1758;
	capitales[9].distancia[14] = 1633;
	capitales[9].distancia[15] = 1160;
	capitales[9].distancia[16] = 1925;
	capitales[9].distancia[17] = 1660;
	capitales[9].distancia[18] = 2198;
	capitales[9].distancia[19] = 2000;
	capitales[9].distancia[20] = 2495;
	capitales[9].distancia[21] = 3675;
	capitales[9].distancia[22] = 4268; 

	capitales[10].distancia[0] = 480;
	capitales[10].distancia[1] = 1138;
	capitales[10].distancia[2] = 1105;
	capitales[10].distancia[3] = 798;
	capitales[10].distancia[4] = 638;
	capitales[10].distancia[5] = 744;
	capitales[10].distancia[6] = 576;
	capitales[10].distancia[7] = 31;
	capitales[10].distancia[8] = 590;
	capitales[10].distancia[9] = 820;
	capitales[10].distancia[10] = 0;
	capitales[10].distancia[11] = 361;
	capitales[10].distancia[12] = 796;
	capitales[10].distancia[13] = 861;
	capitales[10].distancia[14] = 656;
	capitales[10].distancia[15] = 801;
	capitales[10].distancia[16] = 916;
	capitales[10].distancia[17] = 841;
	capitales[10].distancia[18] = 1378;
	capitales[10].distancia[19] = 1435;
	capitales[10].distancia[20] = 1696;
	capitales[10].distancia[21] = 2876;
	capitales[10].distancia[22] = 3469; 

	capitales[11].distancia[0] = 715;
	capitales[11].distancia[1] = 930;
	capitales[11].distancia[2] = 897;
	capitales[11].distancia[3] = 590;
	capitales[11].distancia[4] = 430;
	capitales[11].distancia[5] = 1043;
	capitales[11].distancia[6] = 875;
	capitales[11].distancia[7] = 330;
	capitales[11].distancia[8] = 898;
	capitales[11].distancia[9] = 1213;
	capitales[11].distancia[10] = 361;
	capitales[11].distancia[11] = 0;
	capitales[11].distancia[12] = 435;
	capitales[11].distancia[13] = 500;
	capitales[11].distancia[14] = 420;
	capitales[11].distancia[15] = 440;
	capitales[11].distancia[16] = 670;
	capitales[11].distancia[17] = 600;
	capitales[11].distancia[18] = 1137;
	capitales[11].distancia[19] = 1194;
	capitales[11].distancia[20] = 1455;
	capitales[11].distancia[21] = 3635;
	capitales[11].distancia[22] = 3228; 

	capitales[12].distancia[0] = 1150;
	capitales[12].distancia[1] = 770;
	capitales[12].distancia[2] = 695;
	capitales[12].distancia[3] = 388;
	capitales[12].distancia[4] = 360;
	capitales[12].distancia[5] = 1136;
	capitales[12].distancia[6] = 970;
	capitales[12].distancia[7] = 765;
	capitales[12].distancia[8] = 993;
	capitales[12].distancia[9] = 1308;
	capitales[12].distancia[10] = 796;
	capitales[12].distancia[11] = 435;
	capitales[12].distancia[12] = 0;
	capitales[12].distancia[13] = 450;
	capitales[12].distancia[14] = 550;
	capitales[12].distancia[15] = 156;
	capitales[12].distancia[16] = 617;
	capitales[12].distancia[17] = 1035;
	capitales[12].distancia[18] = 1472;
	capitales[12].distancia[19] = 1629;
	capitales[12].distancia[20] = 1890;
	capitales[12].distancia[21] = 3070;
	capitales[12].distancia[22] = 3663; 

	capitales[13].distancia[0] = 1110;
	capitales[13].distancia[1] = 1220;
	capitales[13].distancia[2] = 1145;
	capitales[13].distancia[3] = 838;
	capitales[13].distancia[4] = 810;
	capitales[13].distancia[5] = 1543;
	capitales[13].distancia[6] = 1420;
	capitales[13].distancia[7] = 830;
	capitales[13].distancia[8] = 1398;
	capitales[13].distancia[9] = 1758;
	capitales[13].distancia[10] = 861;
	capitales[13].distancia[11] = 500;
	capitales[13].distancia[12] = 450;
	capitales[13].distancia[13] = 0;
	capitales[13].distancia[14] = 320;
	capitales[13].distancia[15] = 606;
	capitales[13].distancia[16] = 167;
	capitales[13].distancia[17] = 825;
	capitales[13].distancia[18] = 1022;
	capitales[13].distancia[19] = 1419;
	capitales[13].distancia[20] = 1680;
	capitales[13].distancia[21] = 2860;
	capitales[13].distancia[22] = 3453; 

	capitales[14].distancia[0] = 790;
	capitales[14].distancia[1] = 1320;
	capitales[14].distancia[2] = 1245;
	capitales[14].distancia[3] = 938;
	capitales[14].distancia[4] = 850;
	capitales[14].distancia[5] = 1463;
	capitales[14].distancia[6] = 1295;
	capitales[14].distancia[7] = 625;
	capitales[14].distancia[8] = 1318;
	capitales[14].distancia[9] = 1633;
	capitales[14].distancia[10] = 656;
	capitales[14].distancia[11] = 420;
	capitales[14].distancia[12] = 550;
	capitales[14].distancia[13] = 320;
	capitales[14].distancia[14] = 0;
	capitales[14].distancia[15] = 705;
	capitales[14].distancia[16] = 260;
	capitales[14].distancia[17] = 505;
	capitales[14].distancia[18] = 883;
	capitales[14].distancia[19] = 1099;
	capitales[14].distancia[20] = 1360;
	capitales[14].distancia[21] = 2540;
	capitales[14].distancia[22] = 3133; 

	capitales[15].distancia[0] = 1145;
	capitales[15].distancia[1] = 572;
	capitales[15].distancia[2] = 539;
	capitales[15].distancia[3] = 232;
	capitales[15].distancia[4] = 212;
	capitales[15].distancia[5] = 988;
	capitales[15].distancia[6] = 822;
	capitales[15].distancia[7] = 770;
	capitales[15].distancia[8] = 845;
	capitales[15].distancia[9] = 1160;
	capitales[15].distancia[10] = 801;
	capitales[15].distancia[11] = 440;
	capitales[15].distancia[12] = 156;
	capitales[15].distancia[13] = 606;
	capitales[15].distancia[14] = 705;
	capitales[15].distancia[15] = 0;
	capitales[15].distancia[16] = 773;
	capitales[15].distancia[17] = 1040;
	capitales[15].distancia[18] = 1588;
	capitales[15].distancia[19] = 1634;
	capitales[15].distancia[20] = 1895;
	capitales[15].distancia[21] = 3075;
	capitales[15].distancia[22] = 3668; 

	capitales[16].distancia[0] = 1050;
	capitales[16].distancia[1] = 1345;
	capitales[16].distancia[2] = 1227;
	capitales[16].distancia[3] = 1005;
	capitales[16].distancia[4] = 977;
	capitales[16].distancia[5] = 1710;
	capitales[16].distancia[6] = 1587;
	capitales[16].distancia[7] = 885;
	capitales[16].distancia[8] = 1565;
	capitales[16].distancia[9] = 1925;
	capitales[16].distancia[10] = 916;
	capitales[16].distancia[11] = 670;
	capitales[16].distancia[12] = 617;
	capitales[16].distancia[13] = 167;
	capitales[16].distancia[14] = 260;
	capitales[16].distancia[15] = 773;
	capitales[16].distancia[16] = 0;
	capitales[16].distancia[17] = 765;
	capitales[16].distancia[18] = 855;
	capitales[16].distancia[19] = 1359;
	capitales[16].distancia[20] = 1620;
	capitales[16].distancia[21] = 2800;
	capitales[16].distancia[22] = 3393; 

	capitales[17].distancia[0] = 620;
	capitales[17].distancia[1] = 1530;
	capitales[17].distancia[2] = 1497;
	capitales[17].distancia[3] = 1190;
	capitales[17].distancia[4] = 1030;
	capitales[17].distancia[5] = 1523;
	capitales[17].distancia[6] = 1475;
	capitales[17].distancia[7] = 810;
	capitales[17].distancia[8] = 1378;
	capitales[17].distancia[9] = 1660;
	capitales[17].distancia[10] = 841;
	capitales[17].distancia[11] = 600;
	capitales[17].distancia[12] = 1035;
	capitales[17].distancia[13] = 825;
	capitales[17].distancia[14] = 505;
	capitales[17].distancia[15] = 1040;
	capitales[17].distancia[16] = 765;
	capitales[17].distancia[17] = 0;
	capitales[17].distancia[18] = 537;
	capitales[17].distancia[19] = 594;
	capitales[17].distancia[20] = 855;
	capitales[17].distancia[21] = 2035;
	capitales[17].distancia[22] = 2628; 

	capitales[18].distancia[0] = 1158;
	capitales[18].distancia[1] = 2200;
	capitales[18].distancia[2] = 2082;
	capitales[18].distancia[3] = 1860;
	capitales[18].distancia[4] = 1567;
	capitales[18].distancia[5] = 2060;
	capitales[18].distancia[6] = 2012;
	capitales[18].distancia[7] = 1347;
	capitales[18].distancia[8] = 1989;
	capitales[18].distancia[9] = 2198;
	capitales[18].distancia[10] = 1378;
	capitales[18].distancia[11] = 1137;
	capitales[18].distancia[12] = 1472;
	capitales[18].distancia[13] = 1022;
	capitales[18].distancia[14] = 883;
	capitales[18].distancia[15] = 1588;
	capitales[18].distancia[16] = 855;
	capitales[18].distancia[17] = 537;
	capitales[18].distancia[18] = 0;
	capitales[18].distancia[19] = 660;
	capitales[18].distancia[20] = 750;
	capitales[18].distancia[21] = 1930;
	capitales[18].distancia[22] = 2523; 

	capitales[19].distancia[0] = 960;
	capitales[19].distancia[1] = 2124;
	capitales[19].distancia[2] = 2091;
	capitales[19].distancia[3] = 1784;
	capitales[19].distancia[4] = 1624;
	capitales[19].distancia[5] = 2117;
	capitales[19].distancia[6] = 2069;
	capitales[19].distancia[7] = 1404;
	capitales[19].distancia[8] = 2046;
	capitales[19].distancia[9] = 2000;
	capitales[19].distancia[10] = 1435;
	capitales[19].distancia[11] = 1194;
	capitales[19].distancia[12] = 1629;
	capitales[19].distancia[13] = 1419;
	capitales[19].distancia[14] = 1099;
	capitales[19].distancia[15] = 1634;
	capitales[19].distancia[16] = 1359;
	capitales[19].distancia[17] = 594;
	capitales[19].distancia[18] = 660;
	capitales[19].distancia[19] = 0;
	capitales[19].distancia[20] = 495;
	capitales[19].distancia[21] = 1675;
	capitales[19].distancia[22] = 2268; 

	capitales[20].distancia[0] = 1455;
	capitales[20].distancia[1] = 2385;
	capitales[20].distancia[2] = 2352;
	capitales[20].distancia[3] = 2045;
	capitales[20].distancia[4] = 1885;
	capitales[20].distancia[5] = 2378;
	capitales[20].distancia[6] = 2210;
	capitales[20].distancia[7] = 1665;
	capitales[20].distancia[8] = 2187;
	capitales[20].distancia[9] = 2495;
	capitales[20].distancia[10] = 1696;
	capitales[20].distancia[11] = 1455;
	capitales[20].distancia[12] = 1890;
	capitales[20].distancia[13] = 1680;
	capitales[20].distancia[14] = 1360;
	capitales[20].distancia[15] = 1895;
	capitales[20].distancia[16] = 1620;
	capitales[20].distancia[17] = 855;
	capitales[20].distancia[18] = 750;
	capitales[20].distancia[19] = 495;
	capitales[20].distancia[20] = 0;
	capitales[20].distancia[21] = 1180;
	capitales[20].distancia[22] = 1773; 

	capitales[21].distancia[0] = 2635;
	capitales[21].distancia[1] = 3565;
	capitales[21].distancia[2] = 3532;
	capitales[21].distancia[3] = 3225;
	capitales[21].distancia[4] = 3065;
	capitales[21].distancia[5] = 3558;
	capitales[21].distancia[6] = 3390;
	capitales[21].distancia[7] = 2845;
	capitales[21].distancia[8] = 3367;
	capitales[21].distancia[9] = 3675;
	capitales[21].distancia[10] = 2876;
	capitales[21].distancia[11] = 2635;
	capitales[21].distancia[12] = 3070;
	capitales[21].distancia[13] = 2860;
	capitales[21].distancia[14] = 2540;
	capitales[21].distancia[15] = 3075;
	capitales[21].distancia[16] = 2800;
	capitales[21].distancia[17] = 2035;
	capitales[21].distancia[18] = 1930;
	capitales[21].distancia[19] = 1675;
	capitales[21].distancia[20] = 1180;
	capitales[21].distancia[21] = 0;
	capitales[21].distancia[22] = 593;

	capitales[22].distancia[0] = 3228;
	capitales[22].distancia[1] = 4158;
	capitales[22].distancia[2] = 4125;
	capitales[22].distancia[3] = 3818;
	capitales[22].distancia[4] = 3658;
	capitales[22].distancia[5] = 4151;
	capitales[22].distancia[6] = 3983;
	capitales[22].distancia[7] = 3438;
	capitales[22].distancia[8] = 3960;
	capitales[22].distancia[9] = 4268;
	capitales[22].distancia[10] = 3469;
	capitales[22].distancia[11] = 3228;
	capitales[22].distancia[12] = 3660;
	capitales[22].distancia[13] = 3453;
	capitales[22].distancia[14] = 3133;
	capitales[22].distancia[15] = 3668;
	capitales[22].distancia[16] = 3393;
	capitales[22].distancia[17] = 2628;
	capitales[22].distancia[18] = 2523;
	capitales[22].distancia[19] = 2268;
	capitales[22].distancia[20] = 1773;
	capitales[22].distancia[21] = 593;
	capitales[22].distancia[22] = 0; 

	while(provincia > 23)
	 	provincia = menu();

	if(provincia == 23)
		provincia = rand()%22;

	provincia_inicial = provincia;
	usados[provincia] = 1;

	for(i=0;i<22;i++){
		dist_min = 9999;
		for(k=0;k<23;k++){
			if(capitales[provincia].distancia[k] < dist_min && usados[k] == 0){
				dist_min = capitales[provincia].distancia[k];
				buffer_usados = k;
			}
		}
		usados[buffer_usados] = 1;
		dist_total = dist_total+dist_min;
		printf("%s -> %s = %d \n",capitales[provincia].nombre,capitales[buffer_usados].nombre,dist_min);	
		provincia = buffer_usados;
	}
	printf("%s -> %s = %d \n",capitales[provincia].nombre,capitales[provincia_inicial].nombre,capitales[provincia].distancia[provincia_inicial]);
	dist_total = dist_total+capitales[provincia].distancia[provincia_inicial];
	printf("\n\n Dist total: %d \n\n",dist_total);
	
}

unsigned int menu(){
	unsigned int provincia;
	printf("Seleccione una provincia del 0 al 22 o escriba 23 para elegir una provincia aleatoria \n");
	scanf("%d",&provincia);
	return provincia;
}
