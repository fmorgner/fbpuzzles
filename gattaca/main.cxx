#include "prediction.h"
#include "utility.h"
#include <stdlib.h>
#include <algorithm>
#include <stdio.h>

bool startStartPosCompare(Prediction firstPrediction, Prediction secondPrediction)
	{
	return firstPrediction.m_nStartPosition < secondPrediction.m_nStartPosition;
	}

CPredictionVector g_oPredictions;

int main (int argc, char *argv[])
	{
	if(argc != 2) exit(0);

	loadPredictionsFromFile(argv[1], g_oPredictions);

	sort(g_oPredictions.begin(), g_oPredictions.end(), startStartPosCompare);

	// Find each g_oPredictions last overlap
	ulong  nCurrentStopPosition;
	size_t nFirstNonOverlap;
	size_t count = g_oPredictions.size();
	for (size_t n = 0; n < count; n++)
		{
		Prediction& roPrediction = g_oPredictions[n];
		nCurrentStopPosition = roPrediction.m_nStopPosition;
		for (nFirstNonOverlap = n+1; nFirstNonOverlap < count; nFirstNonOverlap++)
			{
			if ( g_oPredictions[nFirstNonOverlap].m_nStartPosition > nCurrentStopPosition ) break;
			}
		roPrediction.m_nLastOverlapIndex = nFirstNonOverlap - 1;
		}

	// Find best path
	ulong  nIntermediateScore = 0;
	ulong  nNonOverlapScore;
	ulong  nHighScore = 0;
	size_t nHighestOverlapIndex = 0;
	for (size_t i = 0; i < count; i++)
		{
		Prediction& roPrediction = g_oPredictions[i];
		if ( roPrediction.m_nLastOverlapIndex > nHighestOverlapIndex )
			{
			nIntermediateScore = g_oPredictions[nHighestOverlapIndex].m_nScore;
			for (size_t n = nHighestOverlapIndex + 1; n <= roPrediction.m_nLastOverlapIndex; n++)
				{
				g_oPredictions[n].m_nScore = nIntermediateScore;
				}
			nHighestOverlapIndex = roPrediction.m_nLastOverlapIndex;
			}

		nNonOverlapScore = nHighScore + roPrediction.m_nWeight;
		if ( nNonOverlapScore > g_oPredictions[roPrediction.m_nLastOverlapIndex].m_nScore )
			{
			for (size_t n = roPrediction.m_nLastOverlapIndex; n <= nHighestOverlapIndex; n++)
				{
				Prediction& roOverlapPrediction = g_oPredictions[n];
				if (nNonOverlapScore > roOverlapPrediction.m_nScore)
					{
					roOverlapPrediction.m_nScore = nNonOverlapScore;
					}
				}
			}
		nHighScore = roPrediction.m_nScore;
		} // for (size_t i = 0; i < g_oPredictions.size(); i++)

	printf("%lu\n", nHighScore);

	return 0;
  } // main( ... )
