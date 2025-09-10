/*
 * Problem: "UVa 10196 - Check The Check"
 *  Author: "Jia_coding"
 * 
 *     Tag: 模擬(Simulation), 棋盤(Board)
**/

#include <bits/stdc++.h>
using namespace std;

string S;

vector<vector<char>> G(8, vector<char>(8, ' '));

bool inGrid(int x, int y) {
	return (0 <= x) && (x < 8) && (0 <= y) && (y < 8);
}

bool White, Black;
int attack(char Chess, int x, int y) {
	//Pawn
	if (Chess == 'p') {
		int pdx[2] = {1, 1};
		int pdy[2] = {-1, 1};
		for (int i = 0; i < 2; i++) {
			int tx = x + pdx[i];
			int ty = y + pdy[i];
			if (inGrid(tx, ty) && G[tx][ty] == 'K') return 1;
		}
	}
	if (Chess == 'P') {
		int Pdx[2] = {-1, -1};
		int Pdy[2] = {-1, 1};
		for (int i = 0; i < 2; i++) {
			int tx = x + Pdx[i];
			int ty = y + Pdy[i];
			if (inGrid(tx, ty) && G[tx][ty] == 'k') return -1;
		}
	}
	
	//Knight
	if (Chess == 'n' || Chess == 'N') {
	  	int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
	  	int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
	  	
		int flag = (Chess == 'n') ? 1 : -1;
		char King = (Chess == 'n') ? 'K' : 'k';
	  
		for (int i = 0; i < 8; i++) {
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (inGrid(tx, ty) && G[tx][ty] == King) return flag;  
		}
	}
	
	//Bishop, Queen
	if (Chess == 'b' || Chess == 'B' || Chess == 'q' || Chess == 'Q') {
		int dx[4] = {-1, -1, 1, 1};
		int dy[4] = {-1, 1, -1, 1};

		int flag = (Chess == 'b' || Chess == 'q') ? 1 : -1;
		char King = (Chess == 'b' || Chess == 'q') ? 'K' : 'k';
		
		for (int i = 0; i < 4; i++) {
			int tx = x;
			int ty = y;
			for (int j = 0; j < 8; j++) {
				tx += dx[i];
				ty += dy[i];

				if (!inGrid(tx, ty) ) break;
				
				if (inGrid(tx, ty) && G[tx][ty] == King) return flag;  

				if (G[tx][ty] != '.') break;
			}
		}
	}
	
	//Rook, Queen
	if (Chess == 'r' || Chess == 'R' || Chess == 'q' || Chess == 'Q') {
		int dx[4] = {-1, 0, 0, 1};
		int dy[4] = {0, -1, 1, 0};

		int flag = (Chess == 'r' || Chess == 'q') ? 1 : -1;
		char King = (Chess == 'r' || Chess == 'q') ? 'K' : 'k';
			

		for (int i = 0; i < 4; i++) {
			int tx = x;
			int ty = y;
			for (int j = 0; j < 8; j++) {
				tx += dx[i];
				ty += dy[i];

				if (!inGrid(tx, ty)) break;
				
				if (inGrid(tx, ty) && G[tx][ty] == King) return flag;  

				if (G[tx][ty] != '.') break;
			}
		}
	}
	return 0;
}

int main () {
	int Case = 1;
	while (cin >> S) {
		//input
	  	for (int j = 0; j < 8; j++) G[0][j] = S[j];
		for (int i = 1; i < 8; i++) {
		  	cin >> S;
		  	for (int j = 0; j < 8; j++) G[i][j] = S[j];
		}
		
		//break
    	bool flag = true;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (G[i][j] != '.') {
				  flag = false;
				  break;
				}
			}
		}
		if (flag) break;

		//check
		White = 0, Black = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (G[i][j] == '.') continue;
				if (attack(G[i][j], i, j) ==  1) White = 1;
				if (attack(G[i][j], i, j) == -1) Black = 1;
			}
		}

		printf("Game #%d: ", Case++);
		if (Black) printf("black king is in check.\n");
		else if (White) printf("white king is in check.\n");
		else printf("no king is in check.\n");
	}
	return 0;
}