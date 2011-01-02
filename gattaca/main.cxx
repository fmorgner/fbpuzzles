#include <vector>
#include "prediction.h"
#include "utility.h"
#include <stdlib.h>
#include <algorithm>

typedef std::vector<Prediction> CPredictionVector;
typedef std::vector<CPredictionVector::iterator> CPredictionIteratorVector;

bool startPosCompare(Prediction firstPrediction, Prediction secondPrediction)
	{
	return firstPrediction.getStartPosition() < secondPrediction.getStartPosition();
	}

CPredictionVector predictions;
CPredictionIteratorVector bestCombination;

int calcCombinationScore(CPredictionIteratorVector* combination)
	{
	int score = 0;
	
	for(CPredictionIteratorVector::iterator it = combination->begin(); it != combination->end(); ++it)
		{
		score += (*it)->getScore();
		}
	
	return score;
	}

void leftCombinationElements(CPredictionIteratorVector* combination)
	{
	CPredictionVector::iterator lastElement = *(combination->end()-1);
	
	bool foundCombination = false;
	
	for(CPredictionVector::iterator it = lastElement; it != predictions.end(); ++it)
		{
		if(it->getStartPosition() > lastElement->getStopPosition())
			{
			foundCombination = true;
			CPredictionIteratorVector nextCombination = *combination;
			nextCombination.push_back(it);
			leftCombinationElements(&nextCombination);
			}
		}
	if(!foundCombination)
		{
		if(calcCombinationScore(combination) > calcCombinationScore(&bestCombination))
			{
			bestCombination = *combination;
			}
		}
	}

int main (int argc, char *argv[])
	{
	if(argc != 2)
		exit(0);

	loadPredictionsFromFile(argv[1], &predictions);
	
	sort (predictions.begin(), predictions.end(), startPosCompare);
	

	for(CPredictionVector::iterator it = predictions.begin(); it != predictions.end(); ++it)
		{
		CPredictionIteratorVector combination;
		combination.push_back(it);
		leftCombinationElements(&combination);
		}
	
	printf("%i\n", calcCombinationScore(&bestCombination));	
	
	return 0;
	}
