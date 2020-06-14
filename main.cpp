#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <regex>

using std::vector;
using std::string;
using std::set;
using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::regex;

bool checkIfCharLetter (char a) {
    if((int(a) > 32 && int(a) < 65) || (int(a) > 90 && int(a)  < 97) || (int(a) > 122 && int(a) < 127))
        return false;
    else
        return true;
}

vector<int> Insert(vector<int> wordCount, int n)
{
    vector<int> WordCount = wordCount;
    WordCount.push_back(1);
    for(int i=WordCount.size()-1; i>n; i--)
    {
        WordCount[i]=WordCount[i-1];
    }
    WordCount[n]=1;
    return WordCount;
}

void findLines(vector<int> &Lines, string word, int n)
{
    bool check = false;
    regex url("https://www.*\\..*"), URL("www.*\\..*");
    string zodis, fillableString="";
    int indexOfLine=0;
    ifstream fd;
    fd.open("input.txt");
    while(getline(fd, zodis))
    {
        stringstream sstream(zodis);
        while(!sstream.eof())
        {
            sstream >> zodis;
            if(zodis[zodis.length()-1]=='.')
                zodis.erase(zodis.end()-1);
            else if(regex_match(zodis, url) || regex_match(zodis, URL))
                continue;
            else
            {
                fillableString = "";
                for(int i=0; i<zodis.length(); i++)
                {
                    if(!checkIfCharLetter(zodis[i]))
                    {

                        if(word == fillableString)
                        {
                            Lines.push_back(indexOfLine);
                            if(n == Lines.size())
                                check = true;
                            break;
                        }
                        fillableString = "";
                    }
                    else
                        fillableString += zodis[i];
                }
            }

            if(check)
                break;
            else if(word == fillableString)
            {
                Lines.push_back(indexOfLine);
                if(n == Lines.size())
                    check = true;
                break;
            }
        }
        if(check)
            break;
        indexOfLine++;
    }
}

void insertWord (set<string> &Words, int temp, string fillableString, vector<int> &WordCount) {
    int indexOfWord=0;
    Words.insert(fillableString);

    if (Words.size() > temp) {
            indexOfWord=0;
            for(set<string>::iterator it = Words.begin(); it!=Words.end(); ++it)
            {
                if(*it == fillableString)
                    break;
                indexOfWord++;
            }
        WordCount = Insert(WordCount, indexOfWord);
    }
    else {
        indexOfWord=0;
        for(set<string>::iterator it = Words.begin(); it!=Words.end(); ++it)
        {
            if(*it == fillableString)
            {
                WordCount[indexOfWord]++;
                break;
            }
            indexOfWord++;
        }
    }
}

int main()
{
    // words - skirtingus zodzius talpinantis masyvas
    int indexOfWord=0, temp, n, quantity = 0;
    regex url("https://www.*\\..*"), URL("www.*\\..*");
    set<string> Words, URLS;
    vector<int> WordCount, Lines;
    string zodis, fillableString;
    stringstream buffer;
    ifstream fd;
    ofstream fr("output.txt");
    fd.open("input.txt");
    if(fd)
    {
        buffer << fd.rdbuf();
        fd.close();
        while (!buffer.eof())
        {
            quantity++;
            zodis.clear();
            buffer >> zodis;
            temp = Words.size();

            if(int(zodis[zodis.length()-1] == 46))
                zodis.erase(zodis.end()-1);
            else if(regex_match(zodis, url))
            {
                URLS.insert(zodis);
                continue;
            }
            else if(regex_match(zodis, URL))
            {
                URLS.insert(zodis);
                continue;
            }
            else {
                fillableString = "";
                for(int i=0; i<zodis.length(); i++)
                {
                    if(!checkIfCharLetter(zodis[i]))
                    {
                        if(fillableString!="")
                        {
                            insertWord(Words, temp, fillableString, WordCount);
                            fillableString="";
                        }
                    }
                    else {
                        fillableString += zodis[i];
                        if(i+1==zodis.length())
                            insertWord(Words, temp, fillableString, WordCount);
                    }
                }
            }
        }
    }

    indexOfWord=0;

    // SPAUSDINIMAS REZULTATU
    fr << "Number of words in the text: " << quantity << '\n';
    fr << "Number of different words in the text: " <<Words.size() <<"\n\n";
    fr.width(25);
    fr << "Word";
    fr.width(2);
    fr << "|";
    fr.width(6);
    fr << "Qty";
    fr.width(16);
    fr << "| Line numbers\n";
    fr << "------------------------------------------------------------------\n";
    for (set<string>::iterator it=Words.begin(); it!=Words.end(); ++it)
    {
        if(WordCount[indexOfWord] > 1)
        {
            fr.width(25);
            fr << *it;
            fr.width(2);
            fr << "|";
            fr.width(6);
            fr << WordCount[indexOfWord];
            fr << " | ";
            findLines(Lines, *it, WordCount[indexOfWord]);

            for(vector<int>::iterator ite = Lines.begin(); ite!=Lines.end(); ite++)
                fr << *ite <<" ";

            fr <<'\n';
            Lines.clear();
        }
         indexOfWord++;
    }

    fr <<"\n\n";
    fr.width(25);
    fr << "Visi rasti URL'ai:\n\n";
    for(set<string>::iterator it=URLS.begin(); it!=URLS.end(); ++it)
        fr <<" "<< *it <<'\n';

    return 0;
}
