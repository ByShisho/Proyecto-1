# Clash of the guardians
Primer pryecto de Algoritmos y estructuras de datos

## Proposito:
Debiamos crear un juego de cartas (a partir de un mazo de min 30 cartas) en el cual inicie con un menu interactivo
y le permita al jugador elegir entre crear una carta nueva, iniciar el juego, ver el historial de partidas, ver las cartas existentes
y finalmente le permita salir del programa

## Enlace al video explicativo
https://drive.google.com/drive/folders/1B3WbScET7HDbAibaImFJjPQIGVdouEn-?usp=sharing

### Detalles del juego
El juego consiste en luchar contra otro jugador con los guardianes (cartas) con una mano compuesta por 15 cartas, existiendo 4 tipos de 
guardianes:
        - Vikingos
        - Bestias
        - Magos
        - Nigromantes
El primero en restarle los puntos de vida al enemigo gana, en este caso se lucha contra la CPU

 ## Funciones principales:
 Funciones aplicadas para el uso del juego

 ### DeckBuild();
 Esta funcion lo que permite es generar el mazo, leyendo el archivo de texto "CARDS.txt" e implementando a la memoria de un arreglo los datos
 correspondientes a cada guardian existente en la lista, tambien ocurre cuando se crea una carta, solo basta con llamar a esta funcion una vez
 creada una carta nueva para que esta se aniada al espacio de memoria

 ### NewCard();
 Esta funcion crea una nueva carta, solicitando los datos basicos de cada una:
        - Nombre
        - Tipo
        - HP, DMG, DEF
Luego entra al archivo de texto y las crea en el espacio correspondiente

### PrintCards();
Esta funcion permite conocer cada carta aniadida al juego, imprime cada una de ellas para que el usuario sea capaz de conocerlas y saber cual poder
crear en caso de que necesite/quiera

# Funciones no implementadas
Por motivos de fuerza mayor (Salud mental personal), centrados en cuadros de ansiedad, solo pude implementar las funciones para la creacion de las 
cartas y el aniadir estas, por ende, las funciones/aplicaciones para jugar y crear historiales no se encuentran creadas ni implementadas
  