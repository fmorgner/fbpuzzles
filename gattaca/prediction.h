#ifndef PREDICTION_H
#define PREDICTION_H

class Prediction
	{
	public:
		Prediction();
		Prediction(int startPosition, int stopPosition, int score);
	
		int getScore();
		int getStartPosition();
		int getStopPosition();
		
		void setScore(int newScore);
		void setStartPosition(int newStartPosition);
		void setStopPosition(int newStopPosition);
	
	protected:
		int startPosition;
		int stopPosition;
		int score;
	};

#endif
