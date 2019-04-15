#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

// finish this code; add functions, classes, data as needed
const float RADIUS = 5.0;
const float SIDE = 10.0;
// DrawingShape should be an abstract base class 
// for Circle and Square

struct Record
{
	Vector2f position;
	int color;
	ShapeEnum shape;
};

class DrawingShape 
{
public:
	virtual void draw(RenderWindow& win) = 0;
	virtual Record getRecordInfo() = 0;
};

// add Circle, Square classes below. These are derived from DrawingShape

class Circle : public DrawingShape
{
private:
	CircleShape circle;
public:
	//=======================================================
	// Creates a circle at the set location with proper color
	//=======================================================
	Circle(Vector2f pos, Color color)
	{
		circle.setPosition(pos);
		circle.setRadius(RADIUS);
		circle.setOutlineColor(color);
		circle.setOutlineThickness(2);
		circle.setFillColor(color);
	}

	//=================================
	// Draws the circle
	//=================================
	void draw(RenderWindow& win)
	{
		win.draw(circle);
	}

	//==========================================================
	// Records the information for a circle and returns the record
	//==========================================================
	Record getRecordInfo()
	{
		Record record;
		record.position = circle.getPosition();
		record.color = circle.getFillColor().toInteger();
		record.shape = CIRCLE;
		return record;
	}
};

class Square : public DrawingShape
{
private:
	RectangleShape square;
public:
	//=======================================================
	// Creates a square at the set location with proper color
	//=======================================================
	Square(Vector2f pos, Color color)
	{
		square.setPosition(pos);
		square.setOutlineColor(color);
		square.setOutlineThickness(2);
		square.setFillColor(color);
		square.setSize(Vector2f(SIDE, SIDE));
	}
	//=================================
	// draws the square
	//=================================
	void draw(RenderWindow& win)
	{
		win.draw(square);
	}

	//==========================================================
	// Records the information for a circle and returns the record
	//==========================================================
	Record getRecordInfo()
	{
		Record record;
		record.position = square.getPosition();
		record.color = square.getFillColor().toInteger();
		record.shape = SQUARE;
		return record;
	}
};



