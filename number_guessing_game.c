#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int secretNumber;
    int guess;
    int attempts = 0;
    char playAgain;

    srand(time(0));

    do {
        secretNumber = rand() % 100 + 1;

        printf("Guess the number (1 to 100): ");
    
        while(1){
            scanf("%d", &guess);

            if (guess < 1 || guess > 100){
                printf("Invalid input ! Enter a number between 1 and 100: ");
                continue;
            }
            attempts++;

            if (guess > secretNumber){
                printf("Too high!\n");
                if (guess - secretNumber <=5) printf("Very close!");
                printf("Try again:");
            }else if (guess < secretNumber){
                printf("Too low!\n");
                if (secretNumber - guess <=5) printf("very close!");
                printf("Try again:");
            }else{
                printf("Correct ! You guessed it right in %d attempts.\n",attempts);
                break;
            }
        }

        printf("Do you want to play again? (y/n):");
        scanf(" %c", &playAgain);

    }while (playAgain == 'y' || playAgain == 'Y');
    return 0;
}