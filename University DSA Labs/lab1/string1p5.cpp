#include <iostream>
using namespace std;

void display_occurrences(string s,char ch){
    int i=0;
    while(s[i]!='\0'){
        if(s[i]==ch)
        {
            cout<<"Index:"<<i<<endl;

        }
        i++;
    }
}
int main()
{  string s="atlantic ocean";
   char ch='a'; 
   display_occurrences(s,ch);
    
    return 0;
}