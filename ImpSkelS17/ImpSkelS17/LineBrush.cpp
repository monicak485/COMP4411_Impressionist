//
// LineBrush.cpp
//
// The implementation of Line Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"

#include "impressionistUI.h"

#include "LineBrush.h"

#include <iostream>

using namespace std;

extern float frand();

LineBrush::LineBrush(ImpressionistDoc* pDoc, char* name) :
	ImpBrush(pDoc, name)
{
	//test
	mouseStart = NULL;
	mouseEnd = NULL;
}

void LineBrush::BrushBegin(const Point source, const Point target)
{

	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();
	glPointSize((float)size);
	
	int thickness = pDoc->getThickness();
	glLineWidth((float)thickness);

	Point prevPoint = Point(target);
	//test
	mouseStart = new Point(target.x, target.y);

	BrushMove(source, target);
}

void LineBrush::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL) {
		printf("LineBrush::BrushMove  document is NULL\n");
		return;
	}
	

	int size = pDoc->getSize();
	int angle = pDoc->getAngle();
	double xLine, yLine; 
	Point startGradient, endGradient;

	int thickness = pDoc->getThickness();
	glLineWidth((float)thickness);

	// Stroke Direction Stuff
	int direction = pDoc->getStrokeDirectionType();
	// GRADIENT
	if (direction == 1) {
		startGradient = Point(0, 0);
		endGradient = Point(pDoc->getGradientX(source), pDoc->getGradientY(source));
		int diffX = endGradient.x - startGradient.x;
		int diffY = endGradient.y - startGradient.y;
		//intf("endGradient.x %d Y %d\n", endGradient.x, endGradient.y);
		angle = (int)(atan2(diffY, diffX) / 3.16 * 360);
		xLine = (int)size * cos(((double)angle) * 3.16 / 360);
		yLine = (int)size * sin(((double)angle) * 3.16 / 360);
	}
	// MOUSE DIRECTION
	else if (direction == 2) {
		int diffX = target.x - prevPoint.x;
		int diffY = target.y - prevPoint.y;
		angle = (int)(atan2(diffY, diffX) / 3.16 * 360);
		xLine = (int)size * cos(((double)angle) * 3.16 / 360);
		yLine = (int)size * sin(((double)angle) * 3.16 / 360);
		prevPoint.x = target.x;
		prevPoint.y = target.y;
	}
	else {
		xLine = (int)size * cos(((double)angle) * 3.16 / 360);
		yLine = (int)size * sin(((double)angle) * 3.16 / 360);
	}

	int x1 = target.x - (int)xLine/2;
	int y1 = target.y - (int)yLine/2;
	int x2 = target.x + (int)xLine/2;
	int y2 = target.y + (int)yLine/2;
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glBegin(GL_LINES);
		SetColor(source, pDoc->m_pUI->getAlpha());
		glVertex2d(x1, y1);
		glVertex2d(x2, y2);

	glEnd();
}

void LineBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}



