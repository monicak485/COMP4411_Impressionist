//
//RightMouseStroke.cpp
//
// The implementation of RightMouseStroke Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "RightMouseStroke.h"
#include "PaintView.h"

extern float frand();

RightMouseStroke::RightMouseStroke(ImpressionistDoc* pDoc, char* name) :
	ImpBrush(pDoc, name)
{
	mouseStart = NULL;
	mouseEnd = NULL;
}

void RightMouseStroke::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();

	mouseStart = new Point(source.x, source.y);
	pDoc->setMouseStart(*mouseStart);
	glPointSize((float)size);
	glColor3f(1.0, 1.0, 1.0);
	BrushMove(source, target);
}

void RightMouseStroke::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL) {
		printf("RightMouseStroke::BrushMove  document is NULL\n");
		return;
	}

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glBegin(GL_LINES);
	SetColor(source, pDoc->m_pUI->getAlpha());
	//printf("alpha %d\n", pDoc->m_pUI->getAlpha());
	glVertex2d(mouseStart->x, mouseStart->y);
	glVertex2d(target.x, target.y);
	mouseEnd = new Point(target.x, target.y);
	pDoc->setMouseEnd(*mouseEnd);
	glEnd();
}

void RightMouseStroke::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
	delete mouseStart;
	mouseStart = NULL;
}


