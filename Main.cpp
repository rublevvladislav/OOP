#include "Shapes.h"
#include "ShapesFactory.h"
#include <time.h>
#include <iostream>

int Shape::shapesCount = 0;

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	Vector<std::shared_ptr<Shape>> ptrs;
	for (unsigned int i = 0; i < 20; i++)
	{
		unsigned int shapeID = rand() % 6;
		ptrs.push_back(ShapesFactory::createShape(Shapes_id(shapeID)));
	}
	std::cout << Shape::GetCount() << std::endl;
	for (unsigned int i = 0; i < 20; i++)
	{
		ptrs[i]->Print(std::cout);
	}
	for (unsigned int i = 0; i < 20; i++)
	{
		ptrs.pop_back();
	}
	std::cout << Shape::GetCount() << std::endl;
	return 0;
}