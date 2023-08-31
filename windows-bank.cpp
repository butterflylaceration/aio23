

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