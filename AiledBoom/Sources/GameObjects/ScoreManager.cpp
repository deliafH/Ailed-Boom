#include "ScoreManager.h"
#include <algorithm>
#include <fstream>
#include <iostream>

ScoreManager::ScoreManager()
{
	m_Num = 5;
	for (int i = 0; i < m_Num; i++) {
		m_HighScore[i] = 0;
	}
	readFile();
}

void ScoreManager::UpdateHighScore(int m_currentScore)
{
	this->m_currentScore = m_currentScore;
	m_HighScore[m_Num] = m_currentScore;
	std::sort(m_HighScore, m_HighScore + m_Num + 1, [](int a, int b) { return a > b; });
	writeFile();
}

void ScoreManager::readFile()
{
	std::fstream input;
	input.open("../Score.txt", std::ios::binary | std::ios::in);
	for (int i = 0; i < m_Num; i++) input >> m_HighScore[i];
	input.close();
}

void ScoreManager::writeFile()
{
	std::fstream output;
	output.open("../Score.txt", std::ios::binary | std::ios::out);
	for (int i = 0; i < m_Num; i++) output << m_HighScore[i] << std::endl;
	output.close();
}

int* ScoreManager::getHighScore()
{
	return m_HighScore;
}

int ScoreManager::getNum()
{
	return m_Num;
}
