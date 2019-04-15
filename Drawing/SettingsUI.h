#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"

// finish this code; add functions, data as needed

class SettingsUI
{
private:
	SettingsMgr *ptr;
	CircleShape blueBtn, redBtn, greenBtn, circleBtn;
	RectangleShape squareBtn;
public:
	//==========================================================
	// Initializes the buttons on the settings UI
	//==========================================================
	SettingsUI(SettingsMgr *mgr)
	{
		initializeButtons(blueBtn, Color::Blue, Vector2f(100, 70));
		initializeButtons(redBtn, Color::Red, Vector2f(100, 100));
		initializeButtons(greenBtn, Color::Green, Vector2f(100, 130));
		initializeButtons(circleBtn, Color::White, Vector2f(100, 190));
		squareBtn.setOutlineColor(Color::White);
		squareBtn.setSize(Vector2f(20, 20));
		squareBtn.setPosition(Vector2f(100, 220));
		squareBtn.setFillColor(Color::Transparent);
		squareBtn.setOutlineThickness(2);
		ptr = mgr;
	}
	//==========================================================
	// Sets the shape with correct color on mouse cursor
	//==========================================================
	void handleMouseUp(Vector2f mouse)
	{
		if (blueBtn.getGlobalBounds().contains(mouse))
			ptr->setCurColor(Color::Blue);
		else if (redBtn.getGlobalBounds().contains(mouse))
			ptr->setCurColor(Color::Red);
		else if (greenBtn.getGlobalBounds().contains(mouse))
			ptr->setCurColor(Color::Green);
		if (circleBtn.getGlobalBounds().contains(mouse))
			ptr->setCurShape(CIRCLE);
		else if (squareBtn.getGlobalBounds().contains(mouse))
			ptr->setCurShape(SQUARE);
	}

	//==========================================================
	// Draws text and shapes with correct color
	//==========================================================
	void draw(RenderWindow& win)
	{
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("Failure loading font");
		Text titleColor("Selected Color", font, 22);
		titleColor.setPosition(30, 30);
		win.draw(titleColor);
		if (ptr->getCurColor() == Color::Blue)
		{
			blueBtn.setFillColor(Color::Blue);
			redBtn.setFillColor(Color::Transparent);
			greenBtn.setFillColor(Color::Transparent);
		}
		else if (ptr->getCurColor() == Color::Red)
		{
			blueBtn.setFillColor(Color::Transparent);
			redBtn.setFillColor(Color::Red);
			greenBtn.setFillColor(Color::Transparent);
		}
		else if (ptr->getCurColor() == Color::Green)
		{
			blueBtn.setFillColor(Color::Transparent);
			redBtn.setFillColor(Color::Transparent);
			greenBtn.setFillColor(Color::Green);
		}
		if (ptr->getCurShape() == CIRCLE)
		{
			circleBtn.setFillColor(Color::White);
			squareBtn.setFillColor(Color::Transparent);
		}
		else if (ptr->getCurShape() == SQUARE)
		{
			circleBtn.setFillColor(Color::Transparent);
			squareBtn.setFillColor(Color::White);
		}

		win.draw(blueBtn);
		win.draw(redBtn);
		win.draw(greenBtn);

		Text titleShape("Selected Shape:", font, 22);
		titleShape.setPosition(30, 160);
		win.draw(titleShape);
		win.draw(circleBtn);
		win.draw(squareBtn);
	}

	//==========================================================
	// Exits program with error message
	//==========================================================
	void die(string msg)
	{
		cout << msg << endl;
		exit(-1);
	}

	//==========================================================
	// Initializes buttons with correct color and position
	//==========================================================
	void initializeButtons(CircleShape &button, Color color, Vector2f pos)
	{
		button.setRadius(10);
		button.setOutlineColor(color);
		button.setOutlineThickness(2);
		button.setFillColor(Color::Transparent);
		button.setPosition(pos);
	}
};
