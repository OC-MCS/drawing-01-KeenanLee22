#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

// finish this code; add functions, data as needed

class SettingsMgr
{
private:
	Color color;
	ShapeEnum shape;
public:
	//==========================================================
	// Base Constructor
	//==========================================================
	SettingsMgr(Color startingColor, ShapeEnum startingShape )
	{
		color = startingColor;
		shape = startingShape;
	}

	//==========================================================
	// returns color
	//==========================================================
	Color getCurColor()
	{
		return color; 
	}
	
	//==========================================================
	// sets color
	//==========================================================
	void setCurColor(Color startingColor)
	{
		color = startingColor;
	}

	//==========================================================
	// returns shape
	//==========================================================
	ShapeEnum getCurShape()
	{
		return shape; 
	}

	//==========================================================
	// sets shape
	//==========================================================
	void setCurShape(ShapeEnum startingShape)
	{
		shape = startingShape;
	}
	
	//==========================================================
	// loads color and shape from binary file
	//==========================================================
	void load(fstream& binFile)
	{
		unsigned int colorNumber;
		binFile.read(reinterpret_cast<char*>(&colorNumber), sizeof(colorNumber));
		Color aColor(colorNumber);
		color = aColor;
		binFile.read(reinterpret_cast<char*>(&shape), sizeof(shape));
	}

	//==========================================================
	// saves color and shape to binary file
	//==========================================================
	void save(fstream &binFile)
	{
		unsigned int colorNumber = color.toInteger();
		binFile.write(reinterpret_cast<char*>(&colorNumber), sizeof(colorNumber));
		binFile.write(reinterpret_cast<char*>(&shape), sizeof(shape));
	}
};
