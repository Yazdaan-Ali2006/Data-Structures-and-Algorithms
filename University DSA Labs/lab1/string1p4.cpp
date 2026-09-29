#include <iostream>
using namespace std;

int length(char s[])
{
    int len = 0;

    while (s[len] != '\0')
    {
        len++;
    }

    return len;
}

void A3(char s[], int ip, int len, char result[])
{ // check
    if ((ip >= length(s)) || ip < 0 || len < 0 || ip + len > length(s))
    {
        cout << "Not Possible for these values.." << endl;
        return;
    }

    int j = 0;

    for (int i = ip; i < ip + len; i++)
    {
        result[j] = s[i];
        j++;
    }

    result[j] = '\0';
}

int main()
{  
    char s[] = "NEDUET";
    char result[100];
    int ip = 3;
    int len = 6;
   /*The substring will start from s[3] and need 6 characters here
    the string has only 6 characters in total so it goes out of range*/
    A3(s, ip, len, result);

    return 0;
}