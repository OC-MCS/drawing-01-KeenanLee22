#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"
#include <fstream>
#include "Shape.h"
using namespace std;
using namespace sf;

// finish the ShapeMgr class.

class ShapeMgr
{
private:
	vector<DrawingShape*> shapes;
public:
	//=================================
	// Default Constructor, left empty
	//=================================
	ShapeMgr()
	{

	}
	//=======================================================
	// Adds shape to be drawn, using color and shape selected
	//=======================================================
	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		if (whichShape == CIRCLE)
		{
			Circle *circle;
			circle = new Circle(pos, color);
			shapes.push_back(circle);
		}
		else if (whichShape == SQUARE)
		{
			Square *square;
			square = new Square(pos, color);
			shapes.push_back(square);
		}
	}

	//=================================
	// Load shapes from the binary file
	//=================================
	void load(fstream &binFile)
	{
		Record temp;
		while (binFile.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
		{
			addShape(temp.position, temp.shape, Color(temp.color));
		}
	}

	//=================================
	// Saves all shapes to binary file
	//=================================
	void save(fstream &binFile)
	{
		Record temp;
		for (unsigned int count = 0; count < shapes.size(); count++)
		{
			temp = shapes[count]->getRecordInfo();
			binFile.write(reinterpret_cast<char*>(&temp), sizeof(temp));
		}
	}

	//=====================================================================
	// returns a pointer to a vector of pointers for other functions to use
	//=====================================================================
	vector<DrawingShape*> *returnVector()
	{
		return &shapes; 
	}
};
