#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#define MSG_WELCOME "WELCOME TO SORTIFY!"
#define MSG_SORT "Sort the following numbers:"
#define MSG_SORT2 "Please sort the numbers"
#define MSG_WELL "Well done!"
#define MSG_WIN "Congratulations, you win!"
#define MSG_OVER "Game Over."
#define MSG_WRONG "Wrong answer."
#define MSG_MAX "You have reached the maximum number of moves."
#define MSG_BYE "Bye."
#define MSG_UNKNOWN "Unknown option."
/* Use puts() to print constant strings */

int rand_number(const int, const int);
void print_status(const int, const int, const int);
void print_menu(void);
int level_func(int points);
void minmax_gen(int level, int *n, int *z);

int main(int argc, char **argv)
{
    int seed;
    if (argc < 2 || sscanf(argv[1], "%d", &seed) != 1) {
        seed = time(NULL);
    }
    srand(seed);
    //printf("%d %d\n", argc, seed);
	puts(MSG_WELCOME);
	print_menu();
	
	bool numeros_validos;
	int level = 1;
	int points = 0;
	int plays = 0;
	int x = 1;
	while (x == 1)
	    {
	    char menu_input; //definimos a variavél onde iremos guardar o input do menu principal
	    scanf (" %c", &menu_input);
	    
    	    if (menu_input == 'q') { //Trato das funções mais simples primeiro para que o código não fique confuso logo no ínico
    	        
    	        print_status();
    	        printf("Bye");
    	        return 0;
    	    }
    	    
    	    else if (menu_input == 'm') {
    	        
    	        print_menu();
    	    }
    	    
    	    else if (menu_input == 's') {
    	       
    	        print_status(level, points, plays);
    	    }
    	    else if (menu_input == 'p') {
                int tempo;
                int number_input[4];
                int organized_list[4];
                int n, z;
                int j;
    	        int i = 0;
    	        int r[4];
                
    	        puts(MSG_SORT);
                minmax_gen(level, &n, &z); //função da tabela onde estão os valores para cada "level"
                
                for(i = 0; i < 4; i++) {  //um "for" para iterar o processo da função "rand" dar os números randomizados, e de seguida colocamo-los numa lista
                    r[i] = rand_number(n, z);
        	    }
    	        printf("%d, %d, %d, %d\n", r[0], r[1], r[2], r[3]);
    	       
    	        do {  // colocamos um "do" para executar esta parte do código, na qual ficamos até os numeros no array do utilizador serem iguais ao array gerado pelo computador.
    	            numeros_validos = true;
        	        for (i = 0; i < 4; ++i) {
        	            scanf ("%d", &number_input[i]);  //pedimos ao jogador os números
        	        }
        	        for (i = 0; i < 4; ++i) {   // criamos uma lista que irá ser organizada, que é igual á lista dada pelo computador
        	            organized_list[i] = r[i];
        	        }
                    for (i = 0; i < 4; ++i) {   // organizamos a lista criada anteriormente
                        for (j = i + 1; j < 4; ++j) {
                            if (organized_list[i] > organized_list[j]) {
                                tempo = organized_list[i];
                                organized_list[i] = organized_list[j];
                                organized_list[j] = tempo;
                            }
                        }
                    }
                    // Verificamos se os números que o utilizador deu correspondem aos que foram dados pelo jogo
                    for (i = 0; i < 4; i++) {
                        if (number_input[i] == r[0] || number_input[i] == r[1] || number_input[i] == r[2] || number_input[i] == r[3]) {
                        }
                        else {
                            numeros_validos = false;
                            puts(MSG_SORT2);
                            break;
                        }
                    }
    	        } while (numeros_validos == false); // este while pertence ao "do"
            
                //verificamos se os números que o utilizdor estão bem ordenados
                if (number_input[0] == organized_list[0] && number_input[1] == organized_list[1] && number_input[2] == organized_list[2] && number_input[3] == organized_list[3]) {
                    points += 5;
                    plays += 1;
                    puts(MSG_WELL);
                }
                else {
                    plays += 1;
                    puts(MSG_WRONG);
                }
    	    }
    	    else {
    	        puts(MSG_UNKNOWN);
    	    }
    	    // parte final do while primário no qual damos valores a algumas variavies para a próxima jogada e verificamos se o jogo terminou
    	    numeros_validos = true;
    	    level = level_func(points);
    	    if (level == 6) {
    	        puts(MSG_WIN);
    	        print_status(level, points, plays);
    	        puts(MSG_OVER);
    	        x = 3;
    	    }
    	    if (plays == 30) {
    	        puts(MSG_MAX);
    	        print_status(level, points, plays);
    	        puts(MSG_OVER);
    	        x = 2;
    	    }
    	}
return 0;
}
int level_func(int points) //esta função determina o "level" a partir dos pontos que o jogador tem
{
    if (points < 10) {
        return 1;
    }
    else if (points < 20) {
        return 2;
    }
    else if (points < 30) {
        return 3;
    }
    else if (points < 40) {
        return 4;
    }
    else if (points < 50) {
        return 5;
    }
    else if (points == 50) {
        return 6;
    }
    else {
    	return 1;
    }
}

// Tabela de intervalos para a função "rand"
void minmax_gen(int level, int *n, int *z)
{
    switch (level){
        case 1:
            *n = 0;
            *z = 10;
        break;
        case 2:
            *n = 0;
            *z = 30;
        break;
        case 3:
            *n = -50;
            *z = 30;
        break;
        case 4:
            *n = -100;
            *z = 0;
        break;
        case 5:
            *n = -200;
            *z = -100;
        break;
    }
}


/* generate a random integer between min and max */
int rand_number(const int min, const int max)
{
	if (max < min)
	{
		puts("Max must be larger than Min");
		exit(0);
	}
	int n = abs(max - min) + 1;
	return (rand() % n) + min;
}

/* print the game status */
void print_status(const int level, const int score, const int plays)
{
	puts("+-----------------------------+");
	printf("| level:  %02d                  |\n", level);
	printf("| points: %02d                  |\n", score);
	printf("| plays:  %02d                  |\n", plays);
	puts("+-----------------------------+");
}

/* print the option menu */
void print_menu(void)
{
	puts("+-----------------------------+");
	puts("| SORTIFY                     |");
	puts("| p - next chalenge           |");
	puts("| q - quit                    |");
	puts("| m - print this information  |");
	puts("| s - show your status        |");
	puts("+-----------------------------+");
}