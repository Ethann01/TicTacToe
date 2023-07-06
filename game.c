#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"

void input(int turn){
    printboard();
    char p_input[4];
    int valid = 1;
    while(valid != 0){
        printf("Enter number coordinates separated by a space: ");
        fgets(p_input, 4, stdin);    
        valid = check_spot(p_input);
        fflush(stdin);
    }
    update(p_input, turn);
}

void run(){
    int status = game_over();
    while(status != 0){
        input(0);
        status = game_over();
        if(status == 0){
            printboard();
            break;
        }
        input(1);
        status = game_over();
    }
    printf("You win!\n");
}

int main(int argc, char *argv[]){
    run();
    return 0;
}