#include <iostream>
#include <cstring>
#include <chrono>
using namespace std;
using namespace chrono;

int A1(char s[])
{
    int len = 0;
    while (s[len] != '\0') 
    {
        len++;
    }
    return len;
}

void A2(char s1[], char s2[], char result[])
{
    int i = 0, j = 0;
    while (s1[i] != '\0') 
    { 
        result[i] = s1[i]; 
        i++; 
    }
    while (s2[j] != '\0') {
         result[i] = s2[j];
          i++;
           j++; }
    result[i] = '\0';
}

void A3(char s[], int ip, int len, char result[])
{
    int j = 0;
    for (int i = ip; i < ip + len; i++) 
    { 
        result[j] = s[i];
         j++;
     }
    result[j] = '\0';
}

int A4(char T[], char P[])
{
    int n = A1(T);
    int m = A1(P);

    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
            if (T[i + j] != P[j]) break;

        if (j == m) return i;
    }
    return -1;
}

int main()
{  //A1 vs strlen
    char s1[] = "A computer is an idiot machine";
    auto start = high_resolution_clock::now();
    cout << "A1 Length = " << A1(s1) << endl;
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Execution time A1: " << duration.count() << " microseconds"<<endl;

    auto start2 = high_resolution_clock::now();
    cout << "strlen Length = " << strlen(s1) << endl;
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(end2 - start2);
    cout << "Execution time strlen(): " << duration2.count() << " microseconds"<<endl;

    //A2 vs strcat
    char a1[] = "But";
    char a2[] = "ter";
    char result1[100];

    auto start3 = high_resolution_clock::now();
    A2(a1, a2, result1);
    cout << "A2 Result = " << result1 << endl;
    auto end3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(end3 - start3);
    cout << "Execution time A2: " << duration3.count() << " microseconds"<<endl;

    char a3[] = "But";
    auto start4 = high_resolution_clock::now();
    strcat(a3, a2);
    cout << "strcat Result = " << a3 << endl;
    auto end4 = high_resolution_clock::now();
    auto duration4 = duration_cast<microseconds>(end4 - start4);
    cout << "Execution time strcat(): " << duration4.count() << " microseconds"<<endl;
    
    //A3 vs substr
    char b1[] = "Cray is a supercomputer";
    char sub1[100];

    auto start5 = high_resolution_clock::now();
    A3(b1, 16, 8, sub1);
    cout << "A3 Substring = " << sub1 << endl;
    auto end5 = high_resolution_clock::now();
    auto duration5 = duration_cast<microseconds>(end5 - start5);
    cout << "Execution time A3: " << duration5.count() << " microseconds"<<endl;

    string sb1 = b1;
    auto start6 = high_resolution_clock::now();
    cout << "substr Result = " << sb1.substr(16, 8) << endl;
    auto end6 = high_resolution_clock::now();
    auto duration6 = duration_cast<microseconds>(end6 - start6);
    cout << "Execution time substr(): " << duration6.count() << " microseconds"<<endl;
   
    //A4 vs strstr
    char T1[] = "Artificial Intelligence";
    char P1[] = "tell";
   
    auto start7 = high_resolution_clock::now();
    cout << "A4 Index = " << A4(T1, P1) << endl;
    auto end7 = high_resolution_clock::now();
    auto duration7 = duration_cast<microseconds>(end7 - start7);
    cout << "Execution time A4: " << duration7.count() << " microseconds"<<endl;

    auto start8 = high_resolution_clock::now();
    cout << "strstr Index = " << (strstr(T1, P1) - T1) << endl;
    auto end8 = high_resolution_clock::now();
    auto duration8 = duration_cast<microseconds>(end8 - start8);
    cout << "Execution time strstr(): " << duration8.count() << " microseconds"<<endl;
    return 0;}