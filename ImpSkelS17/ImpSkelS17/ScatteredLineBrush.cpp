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
	double xLine = (int)size * cos(((double)angle) * 3.16 / 360);
	double yLine = (int)size * sin(((double)angle) * 3.16 / 360);
	int thickness = pDoc->getThickness();
	glLineWidth((float)thickness);

	int x1 = target.x - (int)xLine / 2;
	int y1 = target.y - (int)yLine / 2;
	int x2 = target.x + (int)xLine / 2;
	int y2 = target.y + (int)yLine / 2;

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	for (int i = 0; i < 4; i++) {
		

		glBegin(GL_LINES);

			int Xoffset = rand() % (2 * size) - size;
			int Yoffset = rand() % (2 * size) - size;
			SetColor(Point(source.x + Xoffset, source.y + Yoffset), pDoc->m_pUI->getAlpha());
			glVertex2d(x2 + Xoffset, y1 + Yoffset);
			glVertex2d(x1 + Xoffset, y2 + Yoffset);

			glEnd();
	}

}

void ScatteredLineBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}

