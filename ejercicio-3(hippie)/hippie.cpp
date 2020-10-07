#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, bandera=0;
	string seq;
    
	cin >> seq >> N;
	
	for (int i = 0; i < N; i++){
		int count = 0;
		char curr = seq[0];
		string newSeq = "";
		for (int j = 1; j <= seq.length(); j++){
			count++;
			if (curr != seq[j] || j == seq.length()){
				//VectorName.insert (position, value);
				newSeq.insert(newSeq.end(), count+'0');
				newSeq.insert(newSeq.end(), curr);
				count = 0;
				curr = seq[j];
			}
		}
		bandera=bandera+1;
		if(bandera >= N){
		    cout << newSeq << endl;
		}
		seq = newSeq;		
	}
	return 0;
}
