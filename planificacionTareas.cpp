#include <iostream>
#include <algorithm> // Add the missing include statement
#include <vector>
#include <climits> // Add the missing include statement for INT_MIN

using namespace std;

int planificacionTareas(int* tiempos, int* beneficios, int d, int n) {

    int dp[n+1][d+1] = {0};

    for(int j=0; j<=d; j++) { // Modify the loop condition to j<=d
        dp[0][j] = 0;
    }
    for(int i=0; i<=n; i++) { // Modify the loop condition to i<=n
        dp[i][0] = 0;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=d; j++) {
            if(j < tiempos[i-1]) {
                dp[i-1][j-1] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], beneficios[i-1] + dp[i-1][j-tiempos[i-1]]);
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= d; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    vector<int> tasks;
    int i = n, j = d;
    while (i > 0 && j > 0) {
        if (dp[i][j] == dp[i - 1][j]) {
            // No se usó la tarea i
            i--;
        } else {
            // Se usó la tarea i
            tasks.push_back(i);
            j -= tiempos[i - 1];  // Reducimos el tiempo utilizado por la tarea i
        }
    }

    reverse(tasks.begin(), tasks.end());
    for (int task : tasks) {
        cout << task << " ";
    }
    cout << endl;

    return dp[n][d];
}

int main() {

    int tiempos[] = {2, 3, 4, 5};
    int beneficios[] = {1, 2, 2, 3};
    int d = 10;
    int n = 4;

    int resultado = planificacionTareas(tiempos, beneficios, d, n);
    cout << endl;
    cout << resultado;

    return 0;
}
