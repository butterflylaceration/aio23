#include <bits/stdc++.h>
using namespace std;

int n, point, ans = 0;
string ar;
int houses[200004];
int main(){
  fstream inf("telein.txt");
  fstream ouf("teleout.txt");
  inf >> n;
  inf >> ar;

  point = 100001;
  houses[100001] = 1;
  for(int i = 0; i < n; i++){
    if (ar[i] == 'L') point--;
    if (ar[i] == 'R') point++;
    if (ar[i] == 'T') point = 100001;
    if (houses[point]!=1) {
        houses[point] = 1;
        ans++;
    }
  }
  ouf << (ans+1) << endl;
  return 0;
  }
// trans rights