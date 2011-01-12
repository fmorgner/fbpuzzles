#include "utility.h"

#include <fstream>
#include <string>
#include <math.h>
#include <algorithm>
#include <stdlib.h>


// Predictions are equal if they span the same part of the DNA
bool operator == ( Prediction first, Prediction second )
	{
	return (first.m_nStartPosition == second.m_nStartPosition) && (first.m_nStopPosition == second.m_nStopPosition);
	}


int loadPredictionsFromFile(char* filePath, CPredictionVector& predictions)
	{
	std::ifstream gattacaFile(filePath);
	if(!gattacaFile.is_open()) return COULD_NOT_OPEN_FILE;
	
	std::string sLinebuff;
	std::getline(gattacaFile, sLinebuff);
	ulong nDNAStringLength = strtoul(sLinebuff.c_str(), 0, 10);

	gattacaFile.seekg( (long)gattacaFile.tellg() + nDNAStringLength + ceil(nDNAStringLength / 80.0) );

	std::getline(gattacaFile, sLinebuff);
	ulong nPredictionTrippleCount = strtoul(sLinebuff.c_str(), 0, 10);

//	const char* szDigits = "0123456789";
	const char* szDelimitters = " \t";
	for(ulong i = 0; i < nPredictionTrippleCount; i++)
		{
		std::getline(gattacaFile, sLinebuff);
		predictions.push_back(Prediction(strtoul(sLinebuff.c_str(), 0, 10),
										 strtoul(sLinebuff.substr(sLinebuff.find_first_of(szDelimitters)).c_str(), 0, 10),
										 strtoul(sLinebuff.substr(sLinebuff.find_last_of (szDelimitters)).c_str(), 0, 10)));
		}

	return 0;
	}
