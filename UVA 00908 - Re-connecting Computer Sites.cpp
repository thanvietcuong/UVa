#include<bits/stdc++.h>
#define For(i, a, b) for(int i = a; i <= b; ++i)
#define Read(a) scanf("%d", &a)
#define ll long long
#define vi vector<int >
#define vii vector<ii>
#define ii pair<int, int>
#define weight first
#define X second.first
#define Y second.second
using namespace std;

vector<pair<int, ii> > edges;
int parent[1000001];
vii r;

int Init(int N){
	edges.clear();
	For(i, 1, N) parent[i] = i;
}

int anc(int i){
	if(parent[i] == i) return i;
	return parent[i] = anc(parent[i]);
}

bool Check(int i, int j){
	return (anc(i) != anc(j));
}

void kruskal(int &result){
	sort(edges.begin(), edges.end());
	int L = edges.size();
	for(pair<int, ii> t : edges){
		if(Check(t.X, t.Y)){
			parent[anc(t.Y)] = t.X;
			result += t.weight;
		}
	}
}

int main(){
	int N;
	while(scanf("%d", &N) != EOF){
		int result_before = 0, result_after = 0;
		int a, b, c;
		Init(N);
		For(i, 1, N - 1){
			Read(a), Read(b), Read(c);
			result_before += c;
		}
		
		int K;
		Read(K);
		For(i, 1, K){
			Read(a); Read(b); Read(c);
			edges.push_back({c, {a, b}});
		}
		int M;
		Read(M);
		For(i, 1, M){
			Read(a); Read(b); Read(c);
			edges.push_back({c, {a, b}});
		}
		kruskal(result_after);
		r.push_back({result_before, result_after});
	}
	bool first = false;
	for(ii t: r){
		if(first) printf("\n");
		else first = true;
		printf("%d\n%d\n", t.first, t.second);
	}
	return 0;
}
