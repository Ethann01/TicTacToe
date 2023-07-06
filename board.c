#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"

char rows[3][4] = {{"   "}, {"   "}, {"   "}};  


void printboard(){
    printf("\n");
    printf("%s\n", rows[0]);
    printf("%s\n",rows[1]);
    printf("%s\n",rows[2]);
}

int game_over(){
    for(int i=0;i<3;i++){
        if(rows[i][0] == rows[i][1] && rows[i][1] == rows[i][2]){
            char test[2] = {rows[i][0], '\0'};
            if(strcmp(" ", test) != 0){
                return 0;
            }
        }
        if(rows[0][i] == rows[1][i] && rows[1][i] == rows[2][i]){
            char test[2] = {rows[0][i], '\0'};
            if(strcmp(" ", test) != 0){
                return 0;
            }
        }
    }
    if(rows[0][0] == rows[1][1] && rows[1][1] == rows[2][2]){
        char test[2] = {rows[0][0], '\0'};
        if(strcmp(" ", test) != 0){
            return 0;
        }
    }
    if(rows[0][2] == rows[1][1] && rows[1][1] == rows[2][0]){
        char test[2] = {rows[0][2], '\0'};
        if(strcmp(" ", test) != 0){
            return 0;
        }
    }
    return 1;
}



int check_spot(char *coordinates){
    char *s;
    int row, col;
    row = strtol(coordinates, &s, 10);
    col = strtol(s, NULL, 10);
    char test[2] = {rows[row - 1][col - 1], '\0'};
    if(strcmp(" ", test) == 0){
        return 0;
    }
    return 1;
}

void update(char *coordinates, int turn){
    char *s;
    int row = strtol(coordinates, &s, 10);
    int col = strtol(s, NULL, 10);

    char square[2] = {rows[row - 1][col - 1], '\0'};
    if(turn == 0 && strcmp(" ", square) == 0){
        rows[row - 1][col - 1] = 'X';
    }
    else if (turn == 1 && strcmp(" ", square) == 0){
        
        rows[row - 1][col - 1] = 'Y';
    }
    
}