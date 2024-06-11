#include <bits/stdc++.h>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string isBalanced(string s) {
    map<char, char> braces = {{']','['}, {'}', '{'}, {')','('}};
    stack<char> bal;
    for(char ch: s)
    {
        if(ch == '[' || ch == '{' || ch == '(')
            bal.push(ch);
        if(ch == ']' || ch == '}' || ch == ')')
        {
            if(!bal.empty())
            {   if(bal.top() == braces[ch])
                    bal.pop();
                else {
                    return "NO";
                }
            }
            else {
                return "NO";
            }
        }
        
    }
    if(!bal.empty())
        return "NO";
    return "YES";
}

int main(void)
{
	int n;
	string str;
	vector<string> strArgs;
	cin>>n;
	
	for(int i = 0 ; i < n; i++)
	{
		cin>>str;
		strArgs.push_back(str);
	}
	for(auto str : strArgs)
	{
		cout<<isBalanced(str)<<"\n";
	}
}