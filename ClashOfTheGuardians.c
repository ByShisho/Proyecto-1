//Nombre: Mauricio Sepulveda
//RUT:21.171.003-9

#include <stdio.h>
#include <stdlib.h>

//Iniciar estructura de las cartas
typedef struct cartas{
	
	char *name;
	char *type;
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
int GameMenu(){
	
	int opcion;
	
		printf("-----------------------\n");
		printf("|CLASH OF THE GUARDIANS|\n");
		printf("-----------------------\n");
		printf("\n");
		

		printf("	>1< Agregar una carta a la lista\n");
		printf("	>2< Iniciar partida\n");
		printf("	>3< Ver el historial\n");
		printf("	>4< Salir\n");
		
		printf("Ingrese su opcion: ");		scanf("%d", &opcion);	fflush(stdin);
		
	return opcion;
}

int NewCard(){
	
	FILE *file;
	file = fopen("CARDS.txt", "ab");
	
	if(file==NULL){
		printf("Error con el archivo");
		return 1;
	}
	Guardians Mazo;
	
	printf("Ingrese el nombre de la carta: ");	scanf("%s", Mazo.name); 	fflush(stdin); 	printf("\n");
	printf("Ingrese el tipo de guardian: ");	scanf("%s", Mazo.type); 	fflush(stdin); 	printf("\n");
	printf("Ingrese el HP: "); 					scanf("%d", &Mazo.HP);		fflush(stdin);	printf("\n");
	printf("Ingrese el DMG: "); 				scanf("%d", &Mazo.DMG); 	fflush(stdin);	printf("\n");
	printf("Ingrese la DEF: "); 				scanf("%d", &Mazo.DEF); 	fflush(stdin); 	printf("\n");
	
	fwrite(&Mazo, sizeof(Guardians), 1, file);
}

int main(){
	
	int read = 0, cardload = 0;
	
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
	do{
		read = fscanf(file,
						"%59[^,], %39[^,], %d, %d, %d\n",
						Mazo[cardload].name,
						Mazo[cardload].type,
						&Mazo[cardload].HP,
						&Mazo[cardload].DMG,
						&Mazo[cardload].DEF);
		
		if(read == 5) cardload++;
		
	}while(!feof(file));
	
	
	while(){ //Hasta ver que jugador gana
	
	//Presentación del juego
		GameMenu();
		
		int	opcion = GameMenu();
		
		switch(opcion){
			
			case opcion 1:	//Añadir una carta
				NewCard();
				break;
			
			case opcion 2:	// Iniciar el juego
				
				break;
				
			case opcion 3:	//Ver el historialde ganadores
				
				break;
				
			case opcion 4:	//Salir
				printf("Vuelve pronto :D");
				return 0;
				break;
		}
		 
	}	
	
	return 0;
}
