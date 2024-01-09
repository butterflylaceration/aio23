/*
 * Solution Template for Distincto's Raffle
 * 
 * Australian Informatics Olympiad 2023
 * 
 * This file is provided to assist with reading and writing of the input
 * files for the problem. You may modify this file however you wish, or
 * you may choose not to use this file at all.
 */

#include <bits/stdc++.h>

/* N is the number of competitors. */
int N;

/* Competitors all submit a number between 1 and K inclusive. */
int K;

/* numbers contains the submitted numbers. */
int numbers[100005];
int algo[100005];

int answer = -1;
int main() {
    /* Open the input and output files. */
    FILE *input_file = fopen("rafflein.txt", "r");
    FILE *output_file = fopen("raffleout.txt", "w");

    /* Read the values of N, K and the submitted numbers from the input file. */
    fscanf(input_file, "%d%d", &N, &K);
    for (int i = 1; i <= N; i++) {
        fscanf(input_file, "%d", &numbers[i]);
    }

    /*
     * TODO: This is where you should compute your solution. Store the winning
     * number, or -1 if there is no winning number, into the variable answer.
     */
    for (int i = 1; i <= K; i++){
      algo[i] = 0;
    }
    for (int i = 1; i <= N; i++){
      algo[(numbers[i])] = algo[(numbers[i])] + 1;
    }
    answer = K + 1;
    for (int i = 1; i <= N; i++){
      if (algo[(numbers[i])] == 1){
        if (numbers[i] < answer){
            answer = numbers[i];
        }
      }
    }
    if (answer == K+1) answer = -1;

    /* Write the answer to the output file. */
    fprintf(output_file, "%d\n", answer);

    /* Finally, close the input/output files. */
    fclose(input_file);
    fclose(output_file);

    return 0;
}
//trans rights
