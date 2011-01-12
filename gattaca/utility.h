#ifndef UTILITY_H
#define UTILITY_H

#include "prediction.h" // for CPredictionVector

#define COULD_NOT_OPEN_FILE -1

int loadPredictionsFromFile(char* filePath, CPredictionVector& predictions);

#endif
