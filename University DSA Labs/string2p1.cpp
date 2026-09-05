#include <iostream>
using namespace std;
int length(char s[]) {
    int len = 0;

    while (s[len] != '\0') {
        len++;
    }

    return len;}
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
void substring(char s[], int ip, int len, char result[]) {
    int j = 0;

    for (int i = ip; i < ip + len; i++) {
        result[j] = s[i];
        j++;
    }

    result[j] = '\0';
}
// Algorithm A1: Insert P into T at position ip
void A1(char T[], int ip, char P[], char result[]) {
    char left[100];
    char right[100];
    char temp[100];

    int n = length(T);
     // before ip
    substring(T, 0, ip, left);
    //from ip till end
    substring(T, ip, n - ip, right);
    
    concat(left, P, temp);
    concat(temp, right, result);
}

// Algorithm A2: delete L characters from T starting at position ip
void A2(char T[], int ip, int L, char result[]) {
    char left[100];
    char right[100];

    int n = length(T);
    //putting the string in L  before deleting part 
    substring(T, 0, ip, left);
    //putting the string after deletion into right part
    substring(T, ip + L, n - (ip + L), right);
    
    concat(left, right, result);
}

int main() {
    //insertion
    char result1[100];
    //deletion
    char result2[100];

    char T1[] = "The founder of our country was Quaid-e-Azam";
    char P[] = "and first Governor General ";

    A1(T1, 12, P, result1);

    cout << "A1: INSERT" << endl;
    cout << "Original T: " << T1 << endl;
    cout << "P: " << P << endl;
    cout << "Result: " << result1 << endl;
    char T2[] ="Database Management Systems";

    A2(T2, 9, 10, result2);

    cout << "A2: DELETE" << endl;
    cout << "Original T: " << T2 << endl;
    cout << "Result: " << result2 << endl;

    return 0;
}