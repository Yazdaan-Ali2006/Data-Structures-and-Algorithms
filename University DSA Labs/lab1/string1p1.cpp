#include <iostream>
using namespace std;

// A1: Length
int A1(char s[])
{   int len = 0;
    while (s[len] != '\0')
    { len++; }
    return len;
}
// A2: Concatenate
void A2(char s1[], char s2[], char result[])
{  int i = 0;
   int j = 0;
    while (s1[i] != '\0') {
        result[i] = s1[i];
        i++;}
    while (s2[j] != '\0')
    {
    result[i] = s2[j];
     i++;
    j++;
    }
    result[i] = '\0';}

// A3: Substring
void A3(char s[], int ip, int len, char result[])
{    int j = 0;
    for (int i = ip; i < ip + len; i++)
    {  result[j] = s[i];
       j++;
    }

    result[j] = '\0';
}
// A4: Index
int A4(char T[], char P[])
{   int n = A1(T);
    int m = A1(P);
    for (int i = 0; i <= n - m; i++)
    {  //(n-m)-->for boundary
        int j;
        for (j = 0; j < m; j++)
        {
            if (T[i + j] != P[j])
            {
                break;
            }
        }
        if (j == m)
        {
            return i;
        }}
      return -1;
 }

int main()
{
    char s1[] = "A computer is an idiot machine";
    char s2[] = "Data Structures is a prerequisite for compiler construction";

    cout << "A1: LENGTH" << endl;
    cout << s1 << " = " << A1(s1) << endl;
    cout << s2 << " = " << A1(s2) << endl;


    // A2 Test Cases
    char a1[] = "But";
    char a2[] = "ter";
    char result1[100];

    char a3[] = "Symmetric";
    char a4[] = "Multiprocessing";
    char result2[100];

    cout << "\nA2: CONCATENATE" << endl;

    A2(a1, a2, result1);
    cout << a1 << " + " << a2 << " = " << result1 << endl;

    A2(a3, a4, result2);
    cout << a3 << " + " << a4 << " = " << result2 << endl;


    // A3 Test Cases
    char b1[] = "Cray is a supercomputer";
    char b2[] = "Unix is a multi-user operating system";

    char sub1[100];
    char sub2[100];

    cout << "\nA3: SUBSTRING" << endl;

    A3(b1, 16, 8, sub1);
    cout << "Substring = " << sub1 << endl;

    A3(b2, 24, 6, sub2);
    cout << "Substring = " << sub2 << endl;


    // A4 Test Cases
    char T1[] = "Artificial Intelligence";
    char P1[] = "tell";

    char T2[] = "clearly";
    char P2[] = "early";

    char T3[] = "Parallel Processing";
    char P3[] = "rock";

    cout << "\nA4: INDEX" << endl;

    cout << "Index = " << A4(T1, P1) << endl;
    cout << "Index = " << A4(T2, P2) << endl;
    cout << "Index = " << A4(T3, P3) << endl;

    return 0;
}