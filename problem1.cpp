#include <bits/stdc++.h>
using namespace std;

ifstream dictionary("dictionary.txt");
vector <string> vec;
int counter = 0;
bool isInDictionary (string word) {
    string nextWord;
    dictionary.clear();
    dictionary.seekg(0, ios::beg);
    while (!dictionary.eof()) {
        dictionary >> nextWord;
        if (word == nextWord)
            return true;
    }
    return false;
}

void rec (string soFar, string rest ){    
    
    if (isInDictionary (soFar)) {
        vec.push_back(soFar);
        soFar = "";
        if (rest == "")
        {
            return;
        }
        rec("",rest);
    }
    else if(rest == "")
    {
        rest = soFar.substr(1);
        soFar = vec[vec.size()-1] + soFar[0];
        vec.pop_back();
        rec(soFar, rest );
    }
    else {
        soFar = soFar + rest[0];
        rest = rest.substr(1);
        rec(soFar, rest);
    }
}

void print()
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }

}


int main () {
    rec ("", "Iwearmyshoes");
    print();
}
