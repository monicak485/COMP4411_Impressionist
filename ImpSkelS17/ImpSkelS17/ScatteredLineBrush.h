//
// ScatteredLineBrush.h
//
// The header file for Line Brush. 
//

#ifndef SCATTEREDLINEBRUSH_H
#define SCATTEREDLINEBRUSH_H

#include "ImpBrush.h"

class ScatteredLineBrush : public ImpBrush
{
public:
	ScatteredLineBrush(ImpressionistDoc* pDoc = NULL, char* name = NULL);

	void BrushBegin(const Point source, const Point target);
	void BrushMove(const Point source, const Point target);
	void BrushEnd(const Point source, const Point target);
	void DrawLine(const Point source, const Point target, const int size, const int angle);
	char* BrushName(void);
};

#endif
