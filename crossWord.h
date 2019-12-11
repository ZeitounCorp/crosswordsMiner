//
// Created by Lenny Zeitoun on 28/11/2019.
//

#ifndef CROSSWORD_H
#define CROSSWORD_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MATRIX_SIZE 4

int count = 0;
char s[100] = {0}; //Buffer
char *finalWords[1000];
char *token;
int k = 0;


void add_char_to_str(char character) {
    s[strlen(s) + 1] = '\0';
    s[strlen(s)] = character;
}

void sub_char_to_str() {
    s[strlen(s) - 1] = '\0';
}

bool isWord(char s[]) {

    return (!strcmp(s, "CAT") ||
            !strcmp(s, "CATS") ||
            !strcmp(s, "TRAM") ||
            !strcmp(s, "TRAMS") ||
            !strcmp(s, "TAME") ||
            !strcmp(s, "CAR") ||
            !strcmp(s, "CARS") ||
            !strcmp(s, "RAT") ||
            !strcmp(s, "RATS") ||
            !strcmp(s, "RAMP") ||
            !strcmp(s, "ART") ||
            !strcmp(s, "CART") ||
            !strcmp(s, "STAMP") ||
            !strcmp(s, "TAKEN") ||
            !strcmp(s, "MEN") ||
            !strcmp(s, "MAKE") ||
            !strcmp(s, "TAKE") ||
            !strcmp(s, "ATE") ||
            !strcmp(s, "START") ||
            !strcmp(s, "SELL") ||
            !strcmp(s, "STEEL") ||
            !strcmp(s, "RAKE"));
}

int isAdded(char *token) {
    int i = 0;
    while (finalWords[i] != NULL) {
        if (strcmp(finalWords[i], token) == 0) {
            return 1;
        }
        i++;
    }
    return -1;
}


void findWordsUtil(char mat[MATRIX_SIZE][MATRIX_SIZE], int visited[MATRIX_SIZE][MATRIX_SIZE], int i, int j, char d[]) {
    visited[i][j] = 1;
    add_char_to_str(mat[i][j]);
    int isfind = isWord(d);

    if (isfind == 1) {
        token = strtok(d, " \t\n");
        while (token != NULL) {
            if (isAdded(token) != 1) {
                count++;
                finalWords[k] = (char *) malloc(strlen(token) + 1);
                strcpy(finalWords[k], token);
                printf(" %s : %i \n ", finalWords[k], count);
                k++;
            }
            token = strtok(NULL, " \t\n");
        }
    }

    int dx, dy;
    for (dx = (i <= 0 ? 0 : -1); dx <= (i >= MATRIX_SIZE - 1 ? 0 : 1); dx++) {
        for (dy = (j <= 0 ? 0 : -1); dy <= (j >= MATRIX_SIZE ? 0 : 1); dy++) {
            if ((dx != -1 && dy != 1) || (dx != 1 && dy != -1)) {
                if (isfind == -1) { printf("%s\n", d); }
                if (!visited[dx + i][dy + j] && (isfind == -2 || isfind > -1)) {
                    findWordsUtil(mat, visited, dx + i, dy + j, d);
                }
            }
        }
    }

    sub_char_to_str();
    visited[i][j] = 0;
}


void printWords(char mat[MATRIX_SIZE][MATRIX_SIZE]) {
    int visited[MATRIX_SIZE][MATRIX_SIZE] = {{0}};

    int i, j;
    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < MATRIX_SIZE; j++) {
            findWordsUtil(mat, visited, i, j, s);
        }

    }
}


#endif //CROSSWORD_H
