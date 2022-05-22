#include "MapManager.h"

MapManager::MapManager()
{
	// 0: Up  1: Left  2: Right  3: Down
	turn[0] = { 0, -1 };
	turn[1] = { -1, 0 };
	turn[2] = { 1, 0 };
	turn[3] = { 0, 1 };
	Reset();
	m_currentTime = 0;

}
MapManager::~MapManager()
{
}
void MapManager::DFS(int i, int j, int fi, int fj)
{
	if (m_Connect[i][j] == 1) return;
	std::vector<std::pair<std::pair<int, int>, int> > m_CanMove;
	for (int k = 0; k < 4; k++)
	{
		int tmpi = i + turn[k].first;
		int tmpj = j + turn[k].second;
		if (tmpi >= 0 && tmpj >= 0 && tmpi < 12 && tmpj < 6)
			m_CanMove.push_back({ {tmpi, tmpj}, k });
	}
	int N = rand() % m_CanMove.size();
	DFS(m_CanMove[N].first.first, m_CanMove[N].first.second, fi, fj);
	if (check)
	{
		m_Connect[i][j] = 1;
		m_Matrix[i][j][m_CanMove[N].second] = 1;
		m_Matrix[m_CanMove[N].first.first][m_CanMove[N].first.second][3 - m_CanMove[N].second] = 1;
	}
	if (fi == i && fj == j) check = 0;
}



void MapManager::Reset()
{
	for (int i = 0; i < 12; i++){
		for (int j = 0; j < 6; j++)
		{
			m_Connect[i][j] = 0;
			for (int k = 0; k < 4; k++)m_Matrix[i][j][k] = 0;
		}
	}
	m_Connect[0][0] = 1;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++)
		{
			check = 1;
			DFS(i, j, i, j);
		}
	}
}

bool MapManager::getPositionTurnRight(int i, int j)
{
	return m_Matrix[i][j][2];
}

bool MapManager::getPositionTurnDown(int i, int j)
{
	return m_Matrix[i][j][3];
}
