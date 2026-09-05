#include <iostream>
using namespace std;

int length(char s[]) {
    int count = 0;

    while (s[count] != '\0') {
        count++;
    }

    return count;
}

void concat(char s1[], char s2[], char result[]) {
    int i = 0;
    int j = 0;

    while (s1[i] != '\0') {
        result[i] = s1[i];
        i++;
    }

    while (s2[j] != '\0') {
        result[i] = s2[j];
        i++;
        j++;
    }

    result[i] = '\0';
}

void substring(char s[], int start, int len, char result[]) {
    int j = 0;

    for (int i = start; i < start + len; i++) {
        result[j] = s[i];
        j++;
    }

    result[j] = '\0';
}

int index(char T[], char P[]) {
    int n = length(T);
    int m = length(P);

    for (int i = 0; i <= n - m; i++) {
        int j;

        for (j = 0; j < m; j++) {
            if (T[i + j] != P[j]) {
                break;
            }
        }

        if (j == m) {
            return i;
        }
    }

    return -1;
}

// A2: Delete every occurrence of P from T
void A2(char T[], char P[], char result[]) {
    char left[100];
    char right[100];
    char temp[100];
    char empty[] = "";
    int position;
    int n;
    int m = length(P);

    // Initially result = T
    concat(T, empty, result);
    position = index(result, P);
    while (position != -1) {
        n = length(result);

        // before P
        substring(result, 0, position, left);

        // after P
        substring(result, position + m, n - position - m, right);

        // join left,right after deleting p
        concat(left, right, temp);

        //putting it into result
        concat(temp, empty, result);

        // again check 
        position = index(result, P);
    }
}

int main() {
    char T[] = "abcNEDUETabc";
    char P[] = "abc";
    char result[100];
    A2(T, P, result);
    cout << "Text: " << T << endl;
    cout << "Result: " << result << endl;

    return 0;
}