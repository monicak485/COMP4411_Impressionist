//
// ScatteredPointBrush.h
//
// The header file for Point Brush. 
//

#ifndef SCATTEREDPOINTBRUSH_H
#define SCATTEREDPOINTBRUSH_H

#include "PointBrush.h"

class ScatteredPointBrush : public PointBrush
{
public:
	ScatteredPointBrush(ImpressionistDoc* pDoc = NULL, char* name = NULL);

	void BrushBegin(const Point source, const Point target);
	void BrushMove(const Point source, const Point target);
	void BrushEnd(const Point source, const Point target);
	char* BrushName(void);
};

#endif
