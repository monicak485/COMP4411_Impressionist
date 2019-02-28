//
// RightMouseStroke.h
//
// The header file for Right Mouse Stroke. 
//

#ifndef RIGHTMOUSESTROKE_H
#define RIGHTMOUSESTROKE_H

#include "ImpBrush.h"

class RightMouseStroke : public ImpBrush
{
public:
	RightMouseStroke(ImpressionistDoc* pDoc = NULL, char* name = NULL);

	Point* mouseStart;
	Point* mouseEnd;

	void BrushBegin(const Point source, const Point target);
	void BrushMove(const Point source, const Point target);
	void BrushEnd(const Point source, const Point target);
};

#endif
