//Nombre: Mauricio Sepulveda
//RUT:21.171.003-9

#include <stdio.h>
#include <stdlib.h>

//Iniciar estructura de las cartas
typedef struct cartas{
	
	int CardCode;
	char name[70];
	char type[50];
	int HP;
	int DMG;
	int DEF;
	
}Guardians; 

//Iniciar estructura de los jugadores
typedef struct jugadores{
	
	int no;
	int life;
	int cards;
	
}Player;

	//Menú de inicio
void GameMenu(int cartas){
	
		printf("-----------------------\n");
		printf("|CLASH OF THE GUARDIANS|\n");
		printf("-----------------------\n");
		printf("\n");
				
		printf("Cartas activas: %d", cartas);
		printf("\n");

		printf("	>1< Agregar una carta a la lista\n");
		printf("	>2< Iniciar partida\n");
		printf("	>3< Ver el historial\n");
		printf("	>4< Para ver las cartas activas\n");
		printf("	>5< Salir\n");
		
}

void NewCard(){
	
	int cardload;
	Guardians Mazo[100];
	
	FILE *file;
	file = fopen("CARDS.txt", "r");
	
		while(fscanf(file,"%d ,%99[^,], %99[^,], %d ,%d ,%d\n",
						&Mazo[cardload].CardCode,
						Mazo[cardload].name,
						Mazo[cardload].type,
						&Mazo[cardload].HP,
						&Mazo[cardload].DMG,
						&Mazo[cardload].DEF)==6){
							cardload++;
						}
	fclose(file);
	
	file = fopen("CARDS.txt", "ab");

	
	printf("Ingrese el nombre de la carta: ");	scanf("%s",	Mazo[cardload].name);			fflush(stdin);	printf("\n");
	printf("Ingrese el tipo de guardian: ");	scanf("%s",	Mazo[cardload].type); 			fflush(stdin); 	printf("\n");
	printf("Ingrese el HP: "); 					scanf("%d", &Mazo[cardload].HP);			fflush(stdin);	printf("\n");
	printf("Ingrese el DMG: "); 				scanf("%d", &Mazo[cardload].DMG); 			fflush(stdin);	printf("\n");
	printf("Ingrese la DEF: "); 				scanf("%d", &Mazo[cardload].DEF); 			fflush(stdin); 	printf("\n");
	
	fwrite(&Mazo, sizeof(Guardians), 1, file);
    
	fclose(file);
}

//Regarcar el mazo para cada vez que se añadan cartas
int DeckBuild(){
	
	int cardload = 0;
	//Lectura del archivo con las cartas
	FILE *file;	
	file = fopen("CARDS.txt", "r");
	//Carga incorrecta
	if (file == NULL){
	printf("ERROR CON EL ARCHIVO");
	return 1;
	}
	//Iniciar arreglo con el mazo
	Guardians Mazo[100];
	//Carga correcta de las cartas	
	
	while(fscanf(file,"%d ,%99[^,], %99[^,], %d ,%d ,%d\n",
						&Mazo[cardload].CardCode,
						Mazo[cardload].name,
						Mazo[cardload].type,
						&Mazo[cardload].HP,
						&Mazo[cardload].DMG,
						&Mazo[cardload].DEF)==6){
							cardload++;
						}
						
	
	fclose(file);
	return cardload;
}


void PrintCards(){

	//Iniciar variables para el mazo
	Guardians Mazo[100];
	int cardload = 0;
	//Lectura del archivo con las cartas
	FILE *file;	
	file = fopen("CARDS.txt", "r");
		
	//Carga correcta de las cartas	
	while(fscanf(file," %d ,%99[^,] , %99[^,] , %d ,%d ,%d \n",
						&Mazo[cardload].CardCode,
						Mazo[cardload].name,
						Mazo[cardload].type,
						&Mazo[cardload].HP,
						&Mazo[cardload].DMG,
						&Mazo[cardload].DEF)==6){
							cardload++;
						}
						
	fclose(file);
	
	for(int i = 0 ; i < cardload ; i++){
		
		printf("--------------------\n");
		printf("No: %d\n", Mazo[i].CardCode);
		printf("Nombre: %s\n", Mazo[i].name);
		printf("Tipo: %s\n", Mazo[i].type);
		printf("HP: %d\n", Mazo[i].HP);
		printf("DMG: %d\n", Mazo[i].DMG);
		printf("DEF: %d\n", Mazo[i].DEF);
		
	}
	
}
int main(){
		
	int Cartasactivas = DeckBuild();
	int winner = 0;
	int opcion;
	
	PrintCards();
	
	while(winner != 1 && winner != 2){ //Hasta ver que jugador gana
	
	//Presentación del juego
	
	
		GameMenu(Cartasactivas);
					
		printf("Ingrese su opcion: "); fflush(stdout);
        scanf("%d", &opcion);		   fflush(stdin);	
		
		switch(opcion){
			
			case 1:	//Añadir una carta
				NewCard(Cartasactivas);
				//Carga del mazo actualizado y la cantidad de cartas activas
				Cartasactivas = DeckBuild();
				
				break;
			
			//case 2:	// Iniciar el juego
				
			//	break;
				
			//case 3:	//Ver el historialde ganadores
				
			//	break;
			
			case 4:	//Imprimir cartas activas
				
				PrintCards();
				
				break;
				
			case 5:	//Salir
				printf("Vuelve pronto :D");
				return 0;
				break;
			}
		}
		 
		
	
	return 0;
}
