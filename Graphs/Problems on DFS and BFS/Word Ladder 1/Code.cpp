#include <bits/stdc++.h>

int wordLadder(string begin, string end, vector<string> &dict) 
{
	// Write your code here
	queue<pair<string,int>>q; //string is the modified value and int is the level
	//BFS traversal
	q.push({begin,1});
	//take a set from the given dict for easily finding if the word is present or not
	//unordered_set takes minimal time 
	unordered_set<string> st(dict.begin(),dict.end());
	//whenever we find a word in the set, we remove it from the set
	st.erase(begin);

	while(!q.empty())
	{
		string word = q.front().first;
		int steps = q.front().second;
		q.pop();

		if(word == end) return steps;

		//iterate through the letters of the word
		for(int i = 0; i < word.size(); i++)
		{
			//initial letter to be changed
			char letter = word[i];

			//change from 'a' to 'z'
			for(char x = 'a'; x <= 'z'; x++)
			{
				word[i] = x;
				//check if the word exists
				if(st.find(word) != st.end()) //if it exists
				{
					st.erase(word);
					q.push({word,steps+1});
				}
			}

			//change the word to the original word
			word[i] = letter;
		}
	}

	//if the queue becomes empty and no word is found
	return -1;


}