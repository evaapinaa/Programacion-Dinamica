#include <iostream>
#include <algorithm> // Add the missing include statement

using namespace std;

int cambioMonedas(int* coins, int amount, int n) {

    int dp[n][amount+1];

    for(int i=0; i<n; i++) {
        dp[i][0] = 0;
    }

    for(int i=0; i<n; i++) {
        for(int j=1; j<=amount; j++) {
            if(i == 0) {
                if(j % coins[i] == 0) {
                    dp[i][j] = j / coins[i];
                } else {
                    dp[i][j] = 0;
                }
            } else {
                if(j < coins[i]) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = std::min(dp[i-1][j], 1 + dp[i][j-coins[i]]); // Replace min with std::min
                }
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<=amount; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int x[n] = {0}; // x[i] = número de monedas usadas de cada tipo
    int i = n-1;
    int j = amount;
    while(i != 0 && j != 0) {
        if(dp[i][j] == dp[i-1][j]) {
            i--;
        } else {
            x[i]++;
            j -= coins[i];
        }
    }

    for(int i=0; i<n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;

    return dp[n-1][amount];
}

int main() {

    int coins[] = {1, 4, 6};
    int amount = 12;
    int n = sizeof(coins) / sizeof(coins[0]);

    int resultado = cambioMonedas(coins, amount, n);
    cout << endl;
    cout << resultado;

    return 0;
}