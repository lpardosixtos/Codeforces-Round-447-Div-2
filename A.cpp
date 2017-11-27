#include <bits/stdc++.h>

using namespace std;

int main(void){

	string s;
	cin >> s;
	int n=s.length();
	int A[n][2];
	A[0][0]=0;
	A[0][1]=0;

	if(s[0]=='Q') A[0][0]++;
	else if(s[0]=='A') A[0][1]++;

	for(int i=1; i<n; i++){
		if(s[i]=='Q'){
			A[i][0]=A[i-1][0]+1;
			A[i][1]=A[i-1][1];
		}
		else{
			A[i][0]=A[i-1][0];
			if(s[i]=='A') A[i][1]=A[i-1][1]+1;
			else A[i][1]=A[i-1][1];
		}


	}
	int ans=0;

	if(A[0][0]!=0){
		for(int j=1; j<n; j++){
			if(A[j][1]>A[j-1][1]){
				ans+=A[n-1][0]-A[j-1][0];
			}
		}
	}



	for(int i=1; i<n; i++){
		if(A[i][0]>A[i-1][0]){
			for(int j=i+1; j<n; j++){
				if(A[j][1]>A[j-1][1]){
					ans+=A[n-1][0]-A[j-1][0];

				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}