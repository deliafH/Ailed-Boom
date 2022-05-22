#pragma once
#include<iostream>
#include<vector>
class MapManager
{
public:
	MapManager();
	~MapManager();

	void Reset();
	void DFS(int i, int j, int fi, int fj);
	bool getPositionTurnRight(int i, int j);
	bool getPositionTurnDown(int i, int j);

private:
	bool m_Matrix[15][10][5];
	bool m_Connect[15][10];
	bool check = 0;
	float m_currentTime;
	std::pair<int, int> turn[5];
};