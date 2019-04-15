#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

// finish this code; add functions, data as needed
const float WIDTH = 550.0;
const float LENGTH = 370.0;

class DrawingUI
{
private:
	RectangleShape drawingCanvas;
public:
	//==========================================================
	// Sets the drawing canvas position and color
	//==========================================================
	DrawingUI(Vector2f p)
	{
		drawingCanvas.setPosition(p);
		drawingCanvas.setOutlineColor(Color::White);
		drawingCanvas.setOutlineThickness(2);
		drawingCanvas.setSize(Vector2f(WIDTH, LENGTH));
		drawingCanvas.setFillColor(Color::White);
	}

	//==========================================================
	// Draws the drawing canvas and shapes
	//==========================================================
	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		vector<DrawingShape*> *shapes;
		shapes = mgr->returnVector();
		win.draw(drawingCanvas);
		for (unsigned int count = 0; count < shapes->size(); count++)
		{
			(*shapes)[count]->draw(win);
		}
	}
	
	//==========================================================
	// Determines if the mouse is in drawing canvas
	//==========================================================
	bool isMouseInCanvas(Vector2f mousePos)
	{
		bool inCanvas;
		if (drawingCanvas.getGlobalBounds().contains(mousePos) && drawingCanvas.getGlobalBounds().contains(Vector2f(mousePos.x + SIDE, mousePos.y + SIDE)))
		{
			inCanvas = true;
		}
		else
		{
			inCanvas = false;
		}
		return inCanvas;
	}

};

