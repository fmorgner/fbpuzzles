#include "prediction.h"

Prediction::Prediction(ulong nStartPosition, ulong nStopPosition, ulong nWeight)
	:	m_nStartPosition(nStartPosition),
		m_nStopPosition(nStopPosition),
		m_nWeight(nWeight),
		m_nLastOverlapIndex(0),
		m_nScore(0)
	{}
