#pragma once
#include "../GameManager/Singleton.h"

class ScoreManager{
public:
	ScoreManager();

	void UpdateHighScore(int m_ccurrentScore);

	void readFile();
	void writeFile();

	int* getHighScore();
	int getNum();
	int getScore() { return m_currentScore; }
private:
	int m_HighScore[10];
	int m_Num;
	int m_currentScore;
};