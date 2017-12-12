#pragma once
class Cell
{
public:
	Cell(bool status = false);
	~Cell();
private:
	bool status;
	bool nextStatus;
public:
	void setStatus(bool status);
	void setNextStatus(bool nextStatus);
	bool getStatus() const;
	void nextRound();
	void setCell(Cell& cell);
};

