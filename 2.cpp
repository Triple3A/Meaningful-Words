#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const string file = "words.txt";

bool is_word(string word)
{
    string f_word;
    ifstream myfile;
    myfile.open(file);
    while(myfile >> f_word)
    {
        if(f_word == word)
        {
            myfile.close();
            return true;
        }
    }
    myfile.close();
    return false;
}
bool create_word(string line, int i, vector <string>& words)
{
    char word[40];
    string check;
    int j = 0, f = 0;
    if(i == line.size())
    {
        for(int k = 0; k < words.size(); k++)
            cout << words[k] << ' ';
        cout << endl;
        words.pop_back();
        return true;
    }
    for(; i < line.size(); i++)
    {
        word[j] = line[i];
        word[j + 1] = '\0';
        if(is_word(word))
        {
            if(words.size() != 0)
                if(f == 1 || words[words.size() - 1] == check)
                {
                    words.pop_back();
                    f = 0;
                }
            words.push_back(word);
            if(!create_word(line, i + 1, words))
            {
                words.pop_back();
                check = word;
            }
            else
                f = 1;
            if(i == line.size() - 1)
                return true;
        }
        j++;
    }
    return false;
}
int main()
{
    string line;
    vector <string> input, words;
    while(cin >> line)
        input.push_back(line);
    for(int i = 0; i < input.size(); i++)
    {
        create_word(input[i], 0, words);
        words.clear();
        cout << "***" << endl;
    }
    return 0;
}
