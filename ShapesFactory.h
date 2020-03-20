#pragma once
#include "Shapes.h"

enum Shapes_id {Point_id, Circle_id, Rect_id, Square_id, Polyline_id, Polygon_id};

double randomDouble(double a, double b) 
{
	double random = ((double)rand()) / (double)RAND_MAX;
	double diff = b - a;
	double r = random * diff;
	return a + r;
}

class ShapesFactory
{
public:
	static std::shared_ptr<Shape> createShape(Shapes_id const id) 
	{
		std::shared_ptr<Shape> ptr = nullptr;
		switch (id)
		{
		case Point_id:
		{
			double x = randomDouble(0, 20), y = randomDouble(0, 20);
			ptr = std::shared_ptr<Shape>(new Point("", x, y));
			break;
		}
		case Circle_id:
		{
			double x = randomDouble(0, 20), y = randomDouble(0, 20), radius = randomDouble(0.1, 20);
			ptr = std::shared_ptr<Shape>(new Circle("", Point("", x, y), radius));
			break;
		}
		case Rect_id:
		{
			double x1 = randomDouble(0, 20), y1 = randomDouble(0, 20), x2 = randomDouble(0, 20), y2 = randomDouble(0, 20);
			ptr = std::shared_ptr<Shape>(new Rect("", Point("", x1, y1), Point("", x2, y2)));
			break;
		}
		case Square_id:
		{
			double x = randomDouble(0, 20), y = randomDouble(0, 20), side = randomDouble(1, 20);
			ptr = std::shared_ptr<Shape>(new Square("", Point("", x, y), side));
			break;
		}
		case Polyline_id:
		{
			ptr = std::shared_ptr<Shape>(new Polyline(""));
			unsigned int countOfPoints = rand() % 8 + 2;
			for (unsigned int i = 0; i < countOfPoints; i++)
			{
				double x = randomDouble(0, 20), y = randomDouble(0, 20);
				static_cast<Polyline*>(ptr.get())->AddPoint(new Point("", x, y));
			}
			break;
		}
		case Polygon_id:
		{
			ptr = std::shared_ptr<Shape>(new Polygon(""));
			unsigned int countOfPoints = rand() % 8 + 2;
			for (unsigned int i = 0; i < countOfPoints; i++)
			{
				double x = randomDouble(0, 20), y = randomDouble(0, 20);
				static_cast<Polygon*>(ptr.get())->AddPoint(new Point("", x, y));
			}
			break;
		}
		default:
		{
			throw std::runtime_error("impossible case");
		}
		}
		return ptr;
	}
};