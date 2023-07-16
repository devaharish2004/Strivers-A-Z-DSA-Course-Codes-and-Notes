string sortByFrequency(int n, string& s)
{
	// Write Your Code here
	string ans = "";
	unordered_map<char,int>mp;
	for(int i = 0; i < n; i++)
	{
		mp[s[i]]++;
	}
	priority_queue<pair<int,char>>pq;
	for(auto it : mp)
	{
		pq.push(make_pair(it.second,it.first));
	}
	while(!pq.empty())
	{
		auto temp = pq.top();
		ans += string(temp.first,temp.second);
		pq.pop();
	}
	return(ans);
}
