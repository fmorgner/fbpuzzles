#include "prediction.h"

Prediction::Prediction()
	{
	this->startPosition = 0;
	this->stopPosition = 0;
	this->score = 0;
	}

Prediction::Prediction(int startPosition, int stopPosition, int score)
	{
	this->startPosition = startPosition;
	this->stopPosition = stopPosition;
	this->score = score;
	}

int Prediction::getScore()
	{
	return this->score;
	}

int Prediction::getStartPosition()
	{
	return this->startPosition;
	}

int Prediction::getStopPosition()
	{
	return this->stopPosition;
	}

void Prediction::setScore(int newScore)
	{
	this->score = newScore;
	}
	
void Prediction::setStartPosition(int newStartPosition)
	{
	this->startPosition = newStartPosition;
	}

void Prediction::setStopPosition(int newStopPosition)
	{
	this->stopPosition = newStopPosition;
	}
