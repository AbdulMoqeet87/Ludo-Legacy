#pragma once

class Cell;

class home
{
private:
	int InitialPos;
	int SafeSpot;
	Cell** C;
public:
	void getSafeSpot();
};

