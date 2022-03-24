//Pig game made by Ruth A 20322406
//assuming the player is asked for input at the beginning of every turn
//assuming a fair six-sided die is used.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
//function prototypes
int roll_die(void);
int play_game(int player, int player_score);
int main(void){
  srand(time(NULL));
	int player_1_score = 0;
	int player_2_score = 0;
	int player_1 = 1;
	int player_2 = 2;
	int current_player = player_1;
	int player_score = 0;
	bool game_done = false;

  //Game explanation
	printf("Welcome to the game of Pig!\n");
	printf("Here's how to play!\n");
	printf("If the player rolls a 1, they score nothing and it becomes the next player's turn.\n");
	printf("If the player rolls any other number, it is added to their turn total and the player's turn continues.\n");
	printf("If a player chooses to \"hold\", their turn total is added to their score, and it becomes the next player's turn.\n");
	printf("The first player to score 100 or more points wins.\n");
	printf("\nPlayer 1!\n");

  //In my main function I keep track of the game status
  //ie if the game has been won,or if it's the other players turn
	while(!game_done){
    //I use a boolean value to loop over the game until there is a winner

		if(current_player == player_1){
      //before I enter my play_game function, I make sure to update the player_score
			player_score = player_1_score;
			player_1_score = play_game(current_player, player_score);
      //once player_1 finishes their turn I first check to see if they have won the game_done
      //if they have not, it becomes player_2's turn
			if(player_1_score >= 100){
				printf("Player 1 wins!");
				game_done = true;
			}
			else{
				printf("\nPlayer 2!\n");
				current_player = player_2;
			}
	}
    //I do the same for player_2_score//I first update the player_score to player_2's current turn_score
    //I then let them play their game
    //and If they get 100pts or more they win; otherwise it becomes player_1's turn again
		else if(current_player == player_2){
     player_score = player_2_score;
		 player_2_score = play_game(current_player, player_score);
			if(player_2_score >= 100){
				printf("Player 2 wins!");
				game_done = true;
			}
			else{
				printf("\nPlayer 1!\n");
				current_player = player_1;
			}
		}

	}

}
//in this function I play the game
//I take as input the currents player (1 or 2) and their current score

int play_game(int player, int player_score){
  //I initialize all my variables to 0.
	int input = 0, die_result = 0, turn_result = 0;
  //I use the boolean turn_over to loop over the player's turn until their turn is over
	bool turn_over = false;
	while(!turn_over){
  	while(input < 1 || input > 2 ){
				printf("Please input \"1\" to roll the dice or \"2\" to hold: \n");
        scanf("%d" ,&input);
				getchar();
		}

	 if(input == 1){
     //I call my function roll_die to get the player's dice result
		roll_die();
		die_result = roll_die();
		printf("You rolled a %d!\n\n" ,die_result);
    //If they roll a 1,as per the rules, their result for this turn is 0, and their turn is over
		 if(die_result == 1){
			printf("Oh no! Because you rolled a 1 your turn is now over and your score stays at %d\n" ,player_score);
			turn_result = 0;
			turn_over = true;
		 }
     //however if they don't roll a 1, their dice result is added to their result for this current turn.
		 else{
			turn_result += die_result;
		 }
	 }
   //once they decide to hold, their results for their turn is added to their overall player score
	 else if (input == 2){
		printf("You chose to hold.Your total score after this turn is %d.\n" ,turn_result);
		turn_over = true;
		player_score += turn_result;
		printf("Your overall total score is now %d.\n" ,player_score);
	 }
	input = 0;

 }
 //play_game returns the updated player_score of the current player
  return player_score;
}
//My function rollDie simply rolls the die assuming that the die is a fair six-sided die.
int roll_die(void){
		int dice = 1 + (rand() % 6);
    //it returns the value of the dice
			return dice;
}
