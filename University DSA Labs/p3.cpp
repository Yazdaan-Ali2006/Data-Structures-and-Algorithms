#include <iostream>
#include <string>
using namespace std;
int length(string s)
{
    int len = 0;

    while (s[len] != '\0')
    {
        len++;
    }

    return len;
}
string my_algo(string s, int n)
{
    string resultant;

    while (length(resultant) < n)
    {
        resultant=resultant+s;
    }
    return resultant;
}
int main()
{   
    string s;
    cout<<"Enter String:";
    getline(cin,s);
    int n;
    cout<<"Enter n:";
    cin>>n;
    cout << my_algo(s, n) << endl;

    return 0;
}