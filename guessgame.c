#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void mainMenu();
void startGame();
void game();
void instructions();
void options();
void easy();
void medium();
void hard();
void custom();
FILE *fptr;
int guessCount;
int randomThreshold = 50;
int attempts = 20;
int hasHint = 1;
int timeLimit = 5;

void main()
{
    	char name[25];


    // printf(" ██████╗ ██╗   ██╗███████╗███████╗███████╗     ██████╗  █████╗ ███╗   ███╗███████╗\n");
    // printf("██╔════╝ ██║   ██║██╔════╝██╔════╝██╔════╝    ██╔════╝ ██╔══██╗████╗ ████║██╔════╝\n");
    // printf("██║  ███╗██║   ██║█████╗  ███████╗███████╗    ██║  ███╗███████║██╔████╔██║█████╗  \n");
    // printf("██║   ██║██║   ██║██╔══╝  ╚════██║╚════██║    ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  \n");
    // printf("╚██████╔╝╚██████╔╝███████╗███████║███████║    ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗\n");
    // printf(" ╚═════╝  ╚═════╝ ╚══════╝╚══════╝╚══════╝     ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝\n");
    // printf("                                                                                  \n");	

    printf("==============================================\n");
    printf(" _____                    _____               \n");
    printf("|   __|_ _ ___ ___ ___   |   __|___ _____ ___ \n");
    printf("|  |  | | | -_|_ -|_ -|  |  |  | .'|     | -_|\n");
    printf("|_____|___|___|___|___|  |_____|__,|_|_|_|___|\n");	
    printf("                                              \n");
	printf("==============================================\n\n\n");
	printf("Please Specify your Name (Max 25): ");
	scanf("%s", name);
	printf("\nHello, %s!!\n", name);
	printf("Welcome to the Guess game\n");
        mainMenu();
}


void mainMenu()
{
	 int choice;
	 printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
	 printf("░░░░░░░░░░░░🅼░🅰░🅸░🅽░░░🅼░🅴░🅽░🆄░░░░░░░░░░░░\n");
	 printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n");
	 printf("\n1. START GAME\n");
	 printf("\n2. HOW TO PLAY\n");
	 printf("\n3. CHOOSE DIFFICULTY\n");
	 printf("\n4. EXIT GAME\n");
	 printf("\n> ");
	 scanf("%d", &choice);
	 switch(choice) {
		case 1:
	 		printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
	 		printf("░░░░░░░░░░░░░░░🅂🅃🄰🅁🅃░🄶🄰🄼🄴░░░░░░░░░░░░░░░\n");
	 		printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n");
			startGame();
			break;
		case 2:
			printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
	 		printf("░░░░░░░░░░░░░░░🄷🄾🅆░🅃🄾░🄿🄻🄰🅈░░░░░░░░░░░░░░\n");
	 		printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n");
			instructions();
			break;
		case 3:
			printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
	 		printf("░░░░░░░░░🄲🄷🄾🄾🅂🄴░🄳🄸🄵🄵🄸🄲🅄🄻🅃🅈░░░░░░░░░░\n");
	 		printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n");
			options();
			break;
		default:
			printf("\nExiting Game...\n");
			exit(0);
			break;
	 }

}


void startGame()
{
	int choice;
	int randomNo;
	srand(time(0));
	printf("\n========= Current Configurations ========\n");
	printf("\nNo of Attempts: %d", attempts);
	printf("\nRandomness Value: %d", randomThreshold);
	if (hasHint){
		printf("\nHints: Yes");
	} else {
		printf("\nHints: No");	
	}
	printf("\nTime Limit: %d", timeLimit);
	printf("\n\n========================================");
	printf("\n\n");
	printf("\nAre you Ready ? \n1.Yes \n2.Back to Main Menu \n3.Exit Game");
	printf("\n> ");
	scanf("%d", &choice);
	switch(choice) {
		case 1:
			printf("\nAlright Get Ready!");
			game();
			break;
		case 2:
			printf("\nOk, Back to Main Menu...\n\n");
			mainMenu();
			break;
		default:
			printf("\nExit Game\n");
			exit(0);
			break;
	}
}

void game()
{
	int randomNo, i, guess, choice;
	guessCount = attempts;
	srand(time(0));
	printf("\n\nGenerating Random Number between 1 to %d...", randomThreshold);
	randomNo = rand()%randomThreshold + 1;
	sleep(rand()%5 + 1);
	printf("\nRandom Number Generated Successfully.\n");
	printf("\nGuess the Random Number!!\n");
	
	for(i =0; i<attempts; i++){
		if(guess == randomNo){
			printf("\nCongo! You have guess the right answer\n");
			break;
		} else {
			if(hasHint){
				printf("\n> ");
				scanf("%d", &guess);
				guessCount--;
				if (guessCount == 0)
				{
					printf("You failed to Guess..\n");
					printf("Do you want to play again ?\n");
					printf("1.Play Again\n2.Choose Difficulty\n3.Main Menu\n4.Exit Game");
					printf("\n> ");
					scanf("%d", &choice);
					switch(choice)
					{
						case 1:
							game();
							break;
						case 2:
							options();
							break;
						case 3:
							mainMenu();
							break;
						default:
							exit(0);
							break;
					}				
				} else
				{
					printf("You have %d guesses left.", guessCount);	
				}
				if (guess > randomNo) {
					printf("\nHint: Guess Lower.");
				} else {
					printf("\nHint: Guess Higher.");
				}
			} else {
				printf("\n> ");
				scanf("%d", &guess);
				guessCount--;
				if (guessCount == 0)
				{
					printf("You failed to Guess..\n");
					printf("Do you want to play again ?\n");
					printf("1.Play Again\n2.Choose Difficulty\n3.Main Menu\n4.Exit Game");
					printf("\n> ");
					scanf("%d", &choice);
					switch(choice)
					{
						case 1:
							game();
							break;
						case 2:
							options();
							break;
						case 3:
							mainMenu();
							break;
						default:
							exit(0);
							break;
					}				
				} else
				{
					printf("You have %d guesses left.", guessCount);	
				}
				
			}
		}
	}
}


void instructions()
{
	printf("\n--> A random number will be generated.\n--> You have to guess the random number in the limited attempts.\n--> The one who guess the number within the given attempts wins!!\n--> Try hints if you feel like it\'s hard.");
	mainMenu();
}


void options() {
	int choice;
	printf("Please Select the Difficulty below\n\n");
	printf("1.EASY (default)\n2.MEDIUM\n3.HARD\n4.CUSTOM\n5.Back");
	printf("\n> ");
	scanf("%d", &choice);
	switch(choice) {
		case 1:
			easy();
			break;
		case 2:
			medium();
			break;
		case 3:
			hard();
			break;
		case 4:
			custom();
			break;
		default:
			mainMenu();
			break;	
	}
}


void easy() {
	printf("\n\nDifficulty Choosen: Easy\n\n");
	randomThreshold = 50;
	attempts = 20;
	hasHint = 1;
	mainMenu();
}

void medium() {
	printf("\n\nDifficulty Choosen: Medium\n\n");
	randomThreshold = 100;
	attempts = 15;
	hasHint = 1;
	mainMenu();
}

void hard() {
	printf("\n\nDifficulty Choosen: Hard\n\n");
	randomThreshold = 150;
	attempts = 10;
	hasHint = 0;
	mainMenu();
}

void custom()
{
	int choice;
	printf("\n\nDifficulty Choosen: Custom\n\n");
	printf("Choose Your custom difficulty, by entering custom values in the below options..\n\n");
	printf("\n1.Change Random Threshold \n2.Change No of Attempts \n3.Hints\n4.Back to Main Menu");
	printf("\n> ");
	scanf("%d", &choice);
	switch(choice) {
		case 1:
			printf("\nCurrent Threshold Value: %d", randomThreshold);
			printf("\nEnter your Random Threshold Value: ");
			scanf("%d", &randomThreshold);
			printf("Saving Settings...\n");
			custom();
			break;
		case 2:
			printf("\nCurrent No of Attempts: %d", attempts);
			printf("\nEnter your No of Attempts Value: ");
			scanf("%d", &attempts);
			printf("Saving Settings...\n");
			custom();
			break;
		case 3:
			printf("\nDo want hints ?");
			printf("\n1.Yes \n2.No");
			printf("\n> ");
			scanf("%d", &choice);
			switch(choice){
				case 1:
					hasHint = 1;
					printf("\nHints Enabled\n");
					custom();
					break;
				case 2:
					hasHint = 0;
					printf("\nHints Disabled");
					custom();
					break;
				default:
					custom();
					break;		
			}
			break;
		default:
			mainMenu();
			break;		
	}
}


