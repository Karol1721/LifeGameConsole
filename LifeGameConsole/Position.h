#pragma once
class Position
{
public:
	Position(int x=1, int y=1);
	~Position();
private:
	int x;
	int y;
public:
	void setX(int x);
	void setY(int y);
	int getX() const;
	int getY() const;
	void addX(int x);
	void addY(int y);
	void setPosition(int x = 1, int y = 1);
};

