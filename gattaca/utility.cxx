#include "utility.h"
#include <math.h>

int loadPredictionsFromFile(char* filePath, std::vector<Prediction>* predictions)
	{
	std::ifstream gattacaFile(filePath);
	
	if(!gattacaFile.is_open())
		return COULD_NOT_OPEN_FILE;
	
	std::string sLinebuff;
	int nDNAStringLength = 0;
	
	std::getline(gattacaFile, sLinebuff);
	nDNAStringLength = atoi(sLinebuff.c_str());
	
	for(int i = 0; i < ceil(nDNAStringLength / 80.0); i++)
		{
		std::getline(gattacaFile, sLinebuff);
		}

	std::getline(gattacaFile, sLinebuff);
	int nPredictionTrippleCount = atoi(sLinebuff.c_str());
	
	for(int i = 0; i < nPredictionTrippleCount; i++)
		{
		std::getline(gattacaFile, sLinebuff);
		int nStartPoint = atoi(sLinebuff.c_str());
		int nStopPoint = atoi(sLinebuff.substr(sLinebuff.find_first_of(' ')).c_str());
		int nScore = atoi(sLinebuff.substr(sLinebuff.find_last_of(' ')).c_str());
		predictions->push_back(Prediction(nStartPoint, nStopPoint, nScore));
		}
	
	return 0;
	}
