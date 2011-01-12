#ifndef PREDICTION_H
#define PREDICTION_H

#include <vector> // for CPredictionVector

typedef unsigned long ulong;

class Prediction
	{
	protected:
		Prediction() {}
	public:
		Prediction(ulong nStartPosition, ulong nStopPosition, ulong nWeight);

		ulong  m_nStartPosition;
		ulong  m_nStopPosition;
		ulong  m_nWeight;
		size_t m_nLastOverlapIndex;
		ulong  m_nScore;
	};

typedef std::vector<Prediction> CPredictionVector;

#endif
