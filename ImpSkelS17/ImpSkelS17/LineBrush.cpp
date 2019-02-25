//
// LineBrush.cpp
//
// The implementation of Line Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "LineBrush.h"

extern float frand();

LineBrush::LineBrush(ImpressionistDoc* pDoc, char* name) :
	ImpBrush(pDoc, name)
{
}

void LineBrush::BrushBegin(const Point source, const Point target)
{

	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();
	glPointSize((float)size);
	

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
	GLfloat thickness = (GLfloat) pDoc->getThickness();
	int angle = pDoc->getAngle();

	printf("Thickness %d\nAngle %d\n", thickness, angle);
	int x1 = target.x - size;

	int y1 = target.y;

	int x2 = target.x + 30;

	//Adding to the y adds to the angle but also makes it longer?
	int y2 = target.y + angle;
	
	SetColor(source);
	glBegin(GL_LINES);
	glLineWidth(thickness);
	glVertex2d(x1, y1);
	glVertex2d(x2, y2);

	glEnd();
}

void LineBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}

