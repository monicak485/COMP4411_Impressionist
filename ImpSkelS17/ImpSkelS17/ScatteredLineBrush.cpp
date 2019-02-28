//
// ScatteredLineBrush.cpp
//
// The implementation of Line Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"

#include "impressionistUI.h"

#include "ScatteredLineBrush.h"

#include <iostream>

using namespace std;

extern float frand();

ScatteredLineBrush::ScatteredLineBrush(ImpressionistDoc* pDoc, char* name) :
	ImpBrush(pDoc, name)
{
}

void ScatteredLineBrush::BrushBegin(const Point source, const Point target)
{

	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();
	glPointSize((float)size);

	int thickness = pDoc->getThickness();
	glLineWidth((float)thickness);
	Point prevPoint = Point(target);

	BrushMove(source, target);
}

void ScatteredLineBrush::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL) {
		printf("ScatteredLineBrush::BrushMove  document is NULL\n");
		return;
	}

	int size = pDoc->getSize();
	int angle = pDoc->getAngle();
	double xLine, yLine;
	int thickness = pDoc->getThickness();
	glLineWidth((float)thickness);
	Point startGradient, endGradient;

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
		int diffX, diffY;
		Point mouseStart = pDoc->getMouseStart();
		Point mouseEnd = pDoc->getMouseEnd();
		if (mouseStart.x != 0) {
			Point endMouse = mouseEnd;
			Point startMouse = mouseStart;
			diffX = endMouse.x - startMouse.x;
			diffY = endMouse.y - startMouse.y;
		}
		else {
			diffX = target.x - source.x;
			diffY = target.y - source.y;
		}
		angle = (int)(atan2(diffY, diffX) / 3.16 * 360);
		printf("angle: %d\n", angle);
		xLine = (int)size * cos(((double)angle) * 3.16 / 180);
		yLine = (int)size * sin(((double)angle) * 3.16 / 180);
	}

	int x1 = target.x - (int)xLine / 2;
	int y1 = target.y - (int)yLine / 2;
	int x2 = target.x + (int)xLine / 2;
	int y2 = target.y + (int)yLine / 2;

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	for (int i = 0; i < 4; i++) {
		glBegin(GL_LINES);
		// random offset for scattering
		int Xoffset = rand() % (2 * size) - size;
		int Yoffset = rand() % (2 * size) - size;
		SetColor(Point(source.x + Xoffset, source.y + Yoffset));
		glVertex2d(x2 + Xoffset, y1 + Yoffset);
		glVertex2d(x1 + Xoffset, y2 + Yoffset);

		glEnd();
	}

}

void ScatteredLineBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}

