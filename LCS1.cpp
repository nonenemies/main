#include<iostream>
using namespace std;
const int mxN = 2500;
int c;
bool filling[mxN][mxN];
int visited[mxN][mxN];
int x4[] = {0,1,0,-1};
int y4[] = {-1,0,1,0};
bool valid(int x,int y){
	return(x>=0&&x<c&&y>=0&&y<c);
}
void dfs(int u,int v){
	filling[u][v] = true;
	for(int i=0;i<4;i++){
		int x = u+x4[i];
		int y = v+y4[i];
		if(!filling[x][y]&&visited[x][y]==0&&valid(x,y)){
			dfs(x,y);
		}
	}
}
int main(){
	freopen("ZONE.INP","r",stdin);
    freopen("ZONE.OUT","w",stdout);
	int a,b,d;
	cin >> a >> b >> c >> d;
	a-=1;
	b-=1;
	int steps[d+1];
	for(int i=0;i<d;i++){
		cin >> steps[i];
	}
	for(int i=0;i<c;i++){
		for(int j=0;j<c;j++){
			visited[i][j] = 0;
		}
	}
	int x = a;
	int y = b;
	int x1 = a;
	int y1 = b;
	int st1;
	int st2;
	visited[x][y] = 1;
	for(int i=0;i<d;i++){
		if(steps[i]==1){
			x-=1;
			if(visited[x][y]==1){
				st1=x;
				st2=y;
				break;
			}
			else{
				visited[x][y] = 1;
			}
		}
		else if(steps[i]==2){
			y+=1;
			if(visited[x][y]==1){
				st1=x;
				st2=y;
				break;
			}
			else{
				visited[x][y] = 1;
			}
		}
		else if(steps[i]==3){
			x+=1;
			if(visited[x][y]==1){
				st1=x;
				st2=y;
				break;
			}
			else{
				visited[x][y] = 1;
			}
		}
		else if(steps[i]==4){
			y-=1;
			if(visited[x][y]==1){
				st1=x;
				st2=y;
				break;
			}
			else{
				visited[x][y] = 1;
			}
		}
	}
	int count = 0;
	for(int i=0;i<d;i++){
		if(steps[i]==1){
			x1-=1;
		}
		else if(steps[i]==2){
			y1+=1;
		}
		else if(steps[i]==3){
			x1+=1;
		}
		else if(steps[i]==4){
			y1-=1;
		}
		count+=1;
		if(x1==st1&&y1==st2){
			break;
		}
    }
	cout << d-count << endl;
	bool fill[c+1][c+1];
	for(int i=0;i<c;i++){
		for(int j=0;j<c;j++){
			fill[i][j] = false;
		}
	}
	dfs(0,0);
	for(int i=0;i<c;i++){
		for(int j=0;j<c;j++){
			if(!filling[i][j]){
				visited[i][j] = 1;
			}
		}
	}
	int squares = 0;
	for(int i=0;i<c;i++){
		for(int j=0;j<c;j++){
			if(visited[i][j]==1&&visited[i+1][j]==1&&visited[i][j+1]==1&&visited[i+1][j+1]==1){
				squares+=1;
			}
		}
	}
	cout << squares;
}

