//
// ScatteredLineBrush.h
//
// The header file for Line Brush. 
//

#ifndef SCATTEREDLINEBRUSH_H
#define SCATTEREDLINEBRUSH_H

#include "LineBrush.h"

class ScatteredLineBrush : public LineBrush
{
public:
	ScatteredLineBrush(ImpressionistDoc* pDoc = NULL, char* name = NULL);

	void BrushBegin(const Point source, const Point target);
	void BrushMove(const Point source, const Point target);
	void BrushEnd(const Point source, const Point target);
	void DrawLine(const Point source, const Point target, const int size, const int angle);
	char* BrushName(void);
	Point prevPoint;
};

#endif
