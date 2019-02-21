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
	int thickness = pDoc->getThickness();

	glLineWidth((float)thickness);

	//startCoord = Point(target.x, target.y);
	BrushMove(source, target);
}

void LineBrush::BrushMove(const Point source, const Point target)
{
	printf("Line brush accessed\n");
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL) {
		printf("LineBrush::BrushMove  document is NULL\n");
		return;
	}
	int size = pDoc->getSize();
	int lineAngle = 0;
	SetColor(source);

	glVertex2d(target.x, target.y);
	//DrawLine(source, target, size, lineAngle);
	glEnd();
}

void LineBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}

