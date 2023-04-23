#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
//read the sentence and split it into words

using namespace std;

class Compare {
public:
    bool operator()(const pair<string, int>&p1, const pair<string, int>&p2)
    {
		if (p1.second > p2.second)
			return false;
        if (p1.second < p2.second)
            return true;
        if (p1.first < p2.first)
            return false;
        return true;
	}
};

int main()
{
    //read from the input file
    string inputString;
    ifstream file("input.txt");
    if (!file)
    {
        printf("eroare la deschiderea fisierului");
    }
    if (!getline(file, inputString))
    {
        printf("eroare la citire");
        return 0;
    }
    //afisare de string
    printf("%s", inputString.c_str());
    cout << endl; 
    //impartire in cuvinte - doi indecsi care sa determine pozitia cuvantului
    size_t beginpos, endpos;
    beginpos = 0;
    vector <string> words;
    map<string, int> wordmap;
    do{
        endpos = inputString.find_first_of(" .,?!", beginpos);
        if (endpos != beginpos && endpos!=string::npos)
        {
            string tokenized;
            tokenized = inputString.substr(beginpos, endpos - beginpos);
            string lowercaseString(tokenized.size(), ' ');
            transform(tokenized.begin(), tokenized.end(), lowercaseString.begin(), tolower);
            words.push_back(lowercaseString);
            wordmap[lowercaseString]++;
            //cout << lowercaseString << endl;
        }
        beginpos = endpos + 1;
    }while (endpos!= string::npos);
    priority_queue < pair<string, int>, vector<pair<string, int>>, Compare > myQueue;
    for (auto iterator : wordmap)
    {
        myQueue.push(iterator);
        //cout << iterator.first << " " << iterator.second << endl;
    }
    while (!myQueue.empty())
    {
        printf("%s %d", myQueue.top().first.c_str(), myQueue.top().second);
        cout << endl;
        myQueue.pop();
    }
    return 0;
}