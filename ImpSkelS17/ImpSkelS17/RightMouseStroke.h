//
// RightMouseStroke.h
//
// The header file for Right Mouse Stroke. 
//

#ifndef POINTBRUSH_H
#define POINTBRUSH_H

#include "ImpBrush.h"

class RightMouseStroke : public ImpBrush
{
public:
	RightMouseStroke(ImpressionistDoc* pDoc = NULL, char* name = NULL);

	Point* mouseStart;

	void BrushBegin(const Point source, const Point target);
	void BrushMove(const Point source, const Point target);
	void BrushEnd(const Point source, const Point target);
	char* BrushName(void);
};

#endif
