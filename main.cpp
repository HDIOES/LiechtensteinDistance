#include <iostream>

int min(int m1, int m2, int m3);

int main() {
    std::string s1 = "mamama";
    std::string s2 = "makama";

    int mas[s1.length()][s2.length()];

    for (int i = 0; i < s1.length(); i++) {
        for (int j = 0; j < s2.length(); j++) {
            if (i == 0 && j == 0) {
                mas[i][j] = 0;
                continue;
            }
            if (i > 0 && j == 0) {
                mas[i][j] = i;
                continue;
            }
            if (i == 0 && j > 0) {
                mas[i][j] = j;
                continue;
            }
            if (i > 0 && j > 0) {
                if ((char)s1.at(i - 1) == (char)s2.at(j - 1)) {
                    mas[i][j] = mas[i - 1][j - 1];
                } else {
                    mas[i][j] = min(mas[i - 1][j - 1], mas[i][j - 1], mas[i - 1][j]) + 1;
                }
            }
        }
    }
    std::cout << mas[s1.length() - 1][s2.length() - 1];
    return 0;
}

int min(int m1, int m2, int m3) {
    if (m1 < m2) {
        if (m3 < m1) {
            return m3;
        } else {
            return m1;
        }
    } else {
        if (m3 < m2) {
            return m3;
        } else {
            return m2;
        }
    }
}