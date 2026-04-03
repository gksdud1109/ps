#include <bits/stdc++.h>
using namespace std;

bool cmp_song(pair<int, int>& a, pair<int, int>& b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

bool cmp_genre(pair<string, int>& a, pair<string, int>&b){
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string, int> most_gen;
    unordered_map<string, vector<pair<int,int>>> most_stream;
    
    for(int i=0; i<genres.size(); i++){
        most_gen[genres[i]] += plays[i];
        most_stream[genres[i]].push_back({plays[i], i});
    }
    
    vector<pair<string, int>> sorted_genres(most_gen.begin(), most_gen.end());
    sort(sorted_genres.begin(), sorted_genres.end(), cmp_genre);
    
    for(auto& g: sorted_genres){
        string genre_name = g.first;
        
        auto& song_list = most_stream[genre_name];
        sort(song_list.begin(), song_list.end(), cmp_song);
        
        for(int i=0; i<song_list.size() && i<2; i++){
            answer.push_back(song_list[i].second);
        }
    }
    
    return answer;
}