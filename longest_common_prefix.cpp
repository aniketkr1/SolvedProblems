// cpp program to find longest common prefix of among multiple strings
#include<iostream>
#include<string.h>
#include<vector>

using std::string;

string common_string(string str1, string str2)
{
	int min_length;
	int L1 = str1.size();
	int L2 = str2.size();
	if( L1 < L2 )
	{
		min_length = L1;
	}
	else
	{
		min_length = L2;
	}
	string min_str = "";
	for( int i = 0; i < min_length; i++ )
	{
		if( str1[i] == str2[i])
		{
			min_str = min_str + str1[i];
		}
		else
		{
			break;
		}
	}
	return min_str;
	
}


int main()
{
	
	std::vector<string> strs;
	strs.push_back("flower");
	strs.push_back("flow");
	strs.push_back("flight");
	string result = strs[0];
	for( int i = 1; i < strs.size(); i++ )
	{
		result = common_string(result, strs[i]);
	}
	std::cout << "Longest common prefix: " << result << std::endl;

}