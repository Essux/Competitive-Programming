#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

map<string, int> wordIndex;

bool areTransformable(string s1, string s2){
    if (s1.size()!=s2.size()) return false;
    int diffs = 0;
    for (int i = 0; i < s1.size(); i++){
        if (s1[i] != s2[i]) diffs++;
        if (diffs>1) return false;
    }
    return true;
}

int shortestPath(vector<int> graph[], int from, int to, int n){
    bool visited[n];
    int distance[n];
    for (int i = 0; i<n; i++) {
        visited[i] = false;
        distance[i] = -1;
    }
    queue<int> q;
    q.push(from);
    distance[from] = 0;
    while (!q.empty()){
        int curNode = q.front();
        //cout << "Revising " << curNode << " Distance: " << distance[curNode] << endl;
        q.pop();
        if (curNode==to) return distance[curNode];
        for (int i = 0; i < graph[curNode].size(); i++){
            int nextNode = graph[curNode][i];
            if (!visited[nextNode]) {
                q.push(nextNode);
                distance[nextNode] = distance[curNode]+1;
                visited[nextNode] = true;
                //cout << "Next: " << nextNode << " Distance: " << distance[nextNode] << endl;
            }
        }
    }
    return -1000;
}

int main(){
    int n;
    cin >> n;
    string garbage;
    getline(cin, garbage);
    while (n--){
        string word;
        int count = 0;
        wordIndex.clear();
        while (cin >> word && word != "*"){
            //cout << word << ":" << count << endl;
            wordIndex[word] = count++;
        }
        vector<int> graph[count];
        for (map<string, int>::iterator it = wordIndex.begin(); it != wordIndex.end(); it++){
            map<string, int>::iterator it2 = it;
            it2++;
            for (; it2 != wordIndex.end(); it2++){
                if (areTransformable(it->first, it2->first)){
                    graph[it->second].push_back(it2->second);
                    graph[it2->second].push_back(it->second);
                }
            }
        }
        getline(cin, word);
        while (getline(cin, word)  && !word.empty()){
            //cout << ((int)word[0]);
            //cout << '{' << word << '}' << endl;
            //word.erase(word.length()-1);
            int sep = word.find(" ");
            string word2 = word.substr(sep+1, word.length()-sep);
            word = word.substr(0, sep);
            int dis = shortestPath(graph, wordIndex[word], wordIndex[word2], count);
            cout << word << " " << word2 << " "<< dis << endl;
        }
        if (n!=0) cout << endl;
    }
}