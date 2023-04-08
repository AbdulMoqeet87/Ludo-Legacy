#pragma once
class home;


class board
{
private:

public:
	board();
	void drawBoard(WindowRender& window);
	bool isValidMove(int sri, int sci, int dri, int dci);
	void Move(int sri, int sci, int dri, int dci);
	void drawHome();


};

