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
	void DrawLine(const Point source, const Point target, const int size, const int angle);
	char* BrushName(void);

	//test
	int getBrushDirection();
	int calculateAngle(const int startX, const int startY, const int endX, const int endY);
	int getGradientX(const Point source);
	int getGradientY(const Point source);
	double getPixelIntensity(const int x, const int y);

	Point prevPoint;
};

#endif
