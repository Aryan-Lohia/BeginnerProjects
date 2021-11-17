#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define USERNAME_SIZE 255
#define USERINPUT_SIZE 10

int main()
{
  int userScore = 0, computerScore = 0;
  char user[USERNAME_SIZE];

  printf("Enter Player's first Name\n");
  scanf("%s", user);

  int rounds_to_play;
  printf("How many rounds do you wanna play?\n");
  scanf("%d", &rounds_to_play);
  getchar();

  char *valid_input[] = { "rock", "paper", "scissors" };
  for (int i = 0; i < rounds_to_play;i++)
  {
    srand(time(NULL));
    char user_input[USERINPUT_SIZE];
    char *pc_input;

    int is_valid_input = 0;
    while (!is_valid_input){
      printf("Enter rock,paper or scissors\n");
      scanf("%s", user_input);
      getchar();
    
      for (int input_idx = 0; 
          input_idx < sizeof(valid_input)/sizeof(valid_input[0]);
          input_idx++){
        if (strcmp(user_input, valid_input[input_idx]) == 0) is_valid_input = 1;
      }

      if (!is_valid_input) printf("Wrong Input Please try again\n");
    }

    int p = rand() % 3;
    pc_input = valid_input[p];

    printf("%s : %s \n computer: %s\n",user, user_input, pc_input);

#if 0
    // incase if both roll the same
    if (strcmp(c, d) == 0) {
      printf("TIE");
    }else 
      if(( (strcmp(c,"rock")  ==0) && (strcmp(d,"scissors")==0))||
        ((strcmp(c,"scissors")==0) && (strcmp(d,"paper")   ==0))||
        ((strcmp(c,"paper")   ==0) && (strcmp(d,"rock"))   ==0))
    {
      userScore++;
      printf("User has won\n Points are: %s : %d Computer : %d\n", user, userScore, computerScore); 
    }
    else
      if(((strcmp(d,"rock")   ==0) && (strcmp(c,"scissors")==0))||
        ((strcmp(d,"scissors")==0) && (strcmp(c,"paper")   ==0))||
        ((strcmp(d,"paper")   ==0) && (strcmp(c,"rock"))   ==0))
    {
      computerScore++;
      printf("Computer has won\n Points are: %s : %d Computer : %d\n\n", user, userScore, computerScore);
    }
#else

    int user_is_winner = 0; 
    int pc_is_winner = 0; 
    if (strcmp(user_input, "rock") == 0) {
      if (strcmp(pc_input, "rock") == 0) {}
      if (strcmp(pc_input, "paper") == 0) pc_is_winner = 1;
      if (strcmp(pc_input, "scissors") == 0) user_is_winner = 1;
    }else if (strcmp(user_input, "paper") == 0) {
      if (strcmp(pc_input, "rock") == 0) user_is_winner = 1;
      if (strcmp(pc_input, "paper") == 0) {}
      if (strcmp(pc_input, "scissors") == 0) pc_is_winner = 1;
    }else if (strcmp(user_input, "scissors") == 0) {
      if (strcmp(pc_input, "rock") == 0) pc_is_winner = 1;
      if (strcmp(pc_input, "paper") == 0) user_is_winner = 1;
      if (strcmp(pc_input, "scissors") == 0) {}
    }

    if (pc_is_winner) printf("Computer has won\n Points are: %s : %d Computer : %d\n\n", user, userScore, ++computerScore);
    else if (user_is_winner) printf("%s has won\n Points are: %s : %d Computer : %d\n\n", user, user, ++userScore, computerScore);
    else printf("TIE\n");
#endif
    printf("Press Enter to continue.");
    getchar();

  }
  printf("Game has Ended\n");
  if(userScore > computerScore)
    printf("%s has won", user);
  else if (userScore == computerScore)
    printf("Tie");
  else
    printf( "Computer Has won");

}
