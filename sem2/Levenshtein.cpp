#include<iostream>
#include <ctime>
#include <fstream>

using namespace std;

int Minimum(int a, int b, int c) {
    return (a = a < b ? a : b) < c ? a : c;
}

int LevenshteinDistance(string firstWord, string secondWord) {
    int n = firstWord.length() + 1;
    int m = secondWord.length() + 1;
    int matrixD[n][m];

    const int deletionCost = 1;
    const int insertionCost = 1;

    for (int i = 0; i < n; i++) {
        matrixD[i][0] = i;
    }

    for (int j = 0; j < m; j++) {
        matrixD[0][j] = j;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            int substitutionCost = firstWord[i - 1] == secondWord[j - 1] ? 0 : 1;

            matrixD[i][j] = Minimum(matrixD[i - 1][j] + deletionCost,          // удаление
                                    matrixD[i][j - 1] + insertionCost,         // вставка
                                    matrixD[i - 1][j - 1] + substitutionCost); // замена
        }
    }

    return matrixD[n - 1][m - 1];
}


int main() {
    string s1;
    string s2;

    for (int i = 0; i < 60; i++) {
        int n;

        ifstream fin("D://infa/pskda_aicd/sem2/tests/test" + to_string(i + 1) + ".txt");

        fin >> n;

        cout << "******************************" << endl;
        cout << "test #" << i + 1 << endl;
        cout << "n: " << n << endl;

        string word1;
        string word2;

        fin >> word1;
        fin >> word2;

        std::clock_t start;
        double duration;
        start = clock();

        cout << "Levenshtein distance is: " << LevenshteinDistance(word1, word2) << endl;

        duration = (clock() - start) / (double) CLOCKS_PER_SEC;
        cout << "time: " << duration << "s" << endl;
    }
}
