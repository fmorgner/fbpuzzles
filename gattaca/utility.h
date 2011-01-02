#ifndef UTILITY_H
#define UTILITY_H

#include <vector>
#include <string>
#include <fstream>
#include "prediction.h"

#define COULD_NOT_OPEN_FILE -1

int loadPredictionsFromFile(char* filePath, std::vector<Prediction>* predictions);

#endif
