#include <vector>
#include "Prediction.h"
#include "utility.h"

typedef std::vector<Prediction> CPredictionVector;
typedef std::vector<CPredictionVector::iterator> CPredictionIteratorVector;

bool startPosCompare(Prediction firstPrediction, Prediction secondPrediction)
	{
	return firstPrediction.getStartPosition() < secondPrediction.getStartPosition();
	}

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

void leftCombinationElements(CPredictionIteratorVector* combination, CPredictionVector* predictions)
	{
	CPredictionVector::iterator lastElement = *(combination->end()-1);
	
	bool foundCombination = false;
	
	for(CPredictionVector::iterator it = lastElement; it != predictions->end(); ++it)
		{
		if(it->getStartPosition() > lastElement->getStopPosition())
			{
			foundCombination = true;
			CPredictionIteratorVector nextCombination = *combination;
			nextCombination.push_back(it);
			leftCombinationElements(&nextCombination, predictions);
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
	CPredictionVector predictions;
	
	loadPredictionsFromFile(argv[1], &predictions);
	
	sort (predictions.begin(), predictions.end(), startPosCompare);
	

	for(CPredictionVector::iterator it = predictions.begin(); it != predictions.end(); ++it)
		{
		CPredictionIteratorVector combination;
		combination.push_back(it);
		leftCombinationElements(&combination, &predictions);
		}
	
	printf("%i\n", calcCombinationScore(&bestCombination));	
	
	return 0;
	}