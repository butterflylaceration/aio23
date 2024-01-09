/*
QUESTION:
You are a painter retiring in N days time and would like to plan the rest of your career. You currently
have an artistic skill of s = 1, but can attend free art classes to increase it.
There are two types of days, represented by an uppercase character:
• C: There is an art class today. You can choose to attend the art class and increase your skill s by
1, or you can spend the day painting, earning s dollars.
• M: There is no art class today. You must spend the day painting, earning s dollars.
What is the most money (in dollars) you can retire with? You are guaranteed that this number will not
exceed 2 000 000 000.
Input
• The first line of input contains the integer N.
• The second line of input contains a string of N characters, describing the days.
Output
Your program must output the most money (in dollars) you can retire with.
*/


#include <bits/stdc++.h>
using namespace std;

int N = 1;

char days[100005]; // type of day


int answer;
int main(void) {
    FILE *input_file = fopen("bankin.txt", "r");
    FILE *output_file = fopen("bankout.txt", "w");

    fscanf(input_file, "%d", &N);
    fscanf(input_file, "%s", days);
    vector<bool> yes; // vector that stores whether you take a class or not
    int skill = 1; // skill

    for (int i = 0; i < N; i++){
        if (days[i]=='M'){
            yes.push_back(false);
        }
        else if (days[i]=='C'){
            if ((N-i)*skill > (N-i-1)*(skill+1)){
                yes.push_back(false);
            } else {
                yes.push_back(true);
                skill++;
            }
        }
    }
    skill = 1;
    for (int i = 0; i < N; i++){
        if (yes[i] == false){
            answer += skill;
        }
        else {
            skill++;
        }
    }
    fprintf(output_file, "%d\n", answer);

    fclose(input_file);
    fclose(output_file);

    return 0;
}
// trans rights
