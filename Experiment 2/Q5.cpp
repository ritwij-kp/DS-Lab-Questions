#include <iostream>
#include <cstring>
#include<fstream>
#include <cmath>
#include <stack>
using namespace std;
int main(){
    ofstream fpw("newtext.txt");
    cout<<"Enter text to be written into file:"<<endl;
    string text;
    getline(cin,text);
    fpw<<text;
    ifstream fpr("newtext.txt");
    fpw.seekp(0,ios::beg);
    cout<<"Enter word to be searched:"<<endl;
    string str,word;
    getline(cin,str);
    while (fpr>>word)
    {
        if (str.compare(word)==0)
        {
            cout<<"Word found";
            break;
        }
    }
}
