#include <iostream>
using namespace std;
int A[100][100], dem = 0;
bool grid[9][9], row[9][9], col[9][9];
void print(){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cout << A[i][j] << ' ';
		}
		cout << endl;
	}
}
void Try(int x, int y){
	if(A[x][y]){
		dem++;
		Try(x+(y+1)/9, (y+1)%9);
		return;
	}
	for(int i = 1; i <= 9; i++){
		if(grid[3*(x/3)+y/3][i] && row[x][i] && col[y][i]){
			dem++;
			A[x][y] = i;
			if(dem==81) print();
			else{
				grid[3*(x/3)+y/3][i] = row[x][i] = col[y][i] = false;
				Try(x+(y+1)/9, (y+1)%9);
				grid[3*(x/3)+y/3][i] = row[x][i] = col[y][i] = true;
			}
			dem--;
		}
	}
}
int main(){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cin >> A[i][j];
			if(A[i][j]) row[i][A[i][j]] = col[j][A[i][j]] = grid[3*(i/3)+j/3][A[i][j]] = false;
			else row[i][A[i][j]] = col[j][A[i][j]] = grid[3*(i/3)+j/3][A[i][j]] = true;
		}
	}
	Try(0,0);
	return 0;
}

