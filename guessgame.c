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
int randomThreshold = 50;
int attempts = 20;
int hasHint = 1;

void main()
{
    	char name[25];
 	printf("========================================\n");
	printf("Welcome to Guess Game!\n");
	printf("========================================\n\n\n");
	printf("Please Specify your Name (Max 25): ");
	scanf("%s", name);
	printf("\nHello, %s!!\n", name);
	printf("Welcome to the Guess game\n");
        mainMenu();
}


void mainMenu()
{
	 int choice;
	 printf("\n\n======== Main Menu ========\n\n");
	 printf("1. Start Game\n");
	 printf("2. Instructions\n");
	 printf("3. Options\n");
	 printf("4. Exit\n");
	 printf("> ");
	 scanf("%d", &choice);
	 switch(choice) {
		case 1:
			printf("\n\nStart Game\n\n");
			startGame();
			break;
		case 2:
			printf("\n\nHow to play\n\n");
			instructions();
			break;
		case 3:
			printf("\n\nChoose Difficulty\n\n");
			options();
			break;
		default:
			printf("\nExit Game\n");
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
	int randomNo, i, guess;
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
				if (guess > randomNo) {
					printf("Hint: Guess Lower.");
				} else {
					printf("Hint: Guess Higher.");
				}
			} else {
				printf("\n> ");
				scanf("%d", &guess);
			}
		}
	}
}


void instructions()
{
	printf("\n--> A random number will be generated\n--> You have to guess the random number in the lowest attempts\n--> The one who guess faster and in lowest attempts wins!!\n\n==>> You can also customize the randomness and number of attempts in the settings menu!!");
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
	printf("\n1.Change Random Threshold \n2.Change No of Attempts \n3.Hints \n4.Change Time Limit \n5.Back to Main Menu");
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
		case 4:
			printf("\nCurrently UnderDevelopment\n\n");
			custom();
			break;
		default:
			mainMenu();
			break;		
	}
}
