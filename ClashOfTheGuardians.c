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
				
		printf("Cartas activas: %d", cartas-1); //Valor exacto de las cartas en juego
		printf("\n");

		printf("	>1< Agregar una carta a la lista\n");
		printf("	>2< Iniciar partida\n");
		printf("	>3< Ver el historial\n");
		printf("	>4< Para ver las cartas activas\n");
		printf("	>5< Salir\n");
		printf("\n");
		
}

//Funcion para crear nuevas cartas
int NewCard(int cardnumber){
	
	//Iniciar variable
	Guardians Mazo;
	
	//Ingresar datos de la carta nueva
	Mazo.CardCode = cardnumber;
	printf("Ingrese el nombre de la carta: ");	scanf("%s",	Mazo.name);			fflush(stdin);
	printf("Ingrese el tipo de guardian: ");	scanf("%s",	Mazo.type); 		fflush(stdin); 	
	printf("Ingrese el HP: "); 					scanf("%d", &Mazo.HP);			fflush(stdin);
	printf("Ingrese el DMG: "); 				scanf("%d", &Mazo.DMG); 		fflush(stdin);	
	printf("Ingrese la DEF: "); 				scanf("%d", &Mazo.DEF); 		fflush(stdin); 	printf("\n");
	
	//Iniciar carga de la carta al archivo de texto
	FILE *file = fopen("CARDS.txt", "a");
	if(file == NULL){
		printf("No se pudo cargar el archivo.\n");
		return 1;
	}
	
	fprintf(file, "%d,%s,%s,%d,%d,%d\n", Mazo.CardCode, Mazo.name,Mazo.type,Mazo.HP,Mazo.DMG, Mazo.DEF);
    
	fclose(file);
	printf("Carta creada exitosamente!!\n");
    
	system("cls");
}

//Inicializar el mazo
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
	
	//Recorrido de impresion
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
		
	while(winner != 1 && winner != 2){ //Hasta ver que jugador gana
	
	//Presentación del juego
	
	
		GameMenu(Cartasactivas);
					
		printf("Ingrese su opcion: "); fflush(stdout);
        scanf("%d", &opcion);		   fflush(stdin);	
        
		if(opcion != 1 || opcion != 2 || opcion != 3 || opcion != 4 || opcion != 5){
			printf("Escoja una opcion valida >:c \n");
			system("pause");
			system("cls");
		}
		switch(opcion){
			
			case 1:	//Añadir una carta
				NewCard(Cartasactivas);
				//Carga del mazo actualizado y la cantidad de cartas activas
				Cartasactivas = DeckBuild();
				
				break;
			
			case 2:	// Iniciar el juego
				printf("En mantenimiento, vuelva pronto\n");
				break;
				
			case 3:	//Ver el historialde ganadores
				printf("En mantenimiento, vuelva pronto\n");
				break;
			
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
