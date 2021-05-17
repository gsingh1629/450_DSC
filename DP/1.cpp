#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> coins={1,2,5};
	int sum=5;
	vector<vector<int>> dp(coins.size()+1,vector<int> (sum+1));
	for(int i=0;i<coins.size()+1;i++){
		dp[i][0]=1;
	}
	for(int i=1;i<sum+1;i++){
		dp[0][i]=0;
	}
	for(int i=1;i<coins.size()+1;i++){
		for(int j=1;j<sum+1;j++){
			if(j>=coins[i-1]){
				dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
			}
			if(j<coins[i-1]){
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	for(int i=0;i<coins.size()+1;i++){
		for(int j=0;j<sum+1;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<dp[coins.size()][sum];
	return 0;
}
