//
// LineBrush.h
//
// The header file for Line Brush. 
//

#ifndef LINEBRUSH_H
#define LINEBRUSH_H

#include "ImpBrush.h"

class LineBrush : public ImpBrush
{
public:

	LineBrush(ImpressionistDoc* pDoc = NULL, char* name = NULL);

	Point* mouseStart;
	Point* mouseEnd;

	void BrushBegin(const Point source, const Point target);
	void BrushMove(const Point source, const Point target);
	void BrushEnd(const Point source, const Point target);

	Point prevPoint;
};

#endif
