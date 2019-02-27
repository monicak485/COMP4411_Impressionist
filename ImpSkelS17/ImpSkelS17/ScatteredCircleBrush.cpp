//
// ScatteredCircleBrush.cpp
//
// The implementation of Scattered Circle Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include <math.h>
#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "ScatteredCircleBrush.h"

extern float frand();

ScatteredCircleBrush::ScatteredCircleBrush(ImpressionistDoc* pDoc, char* name) :
	CircleBrush(pDoc, name)
{
}
void ScatteredCircleBrush::BrushBegin(const Point source, const Point target)
{

	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();
	glPointSize((float)size);
	//printf("size %d\n", (int)size);

	BrushMove(source, target);
}


void ScatteredCircleBrush::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL) {
		printf("ScatteredCircleBrush::BrushMove  document is NULL\n");
		return;
	}

	int size = pDoc->getSize();
	int count = 2 + rand() * 3; // randomly choose between 2, 3 or 4 lines
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glBegin(GL_POINTS);

	for (int i = 0; i < count; ++i) {
		int x = rand() % size - size / 2;
		int y = rand() % size - size / 2;

		Point p1 = Point((source.x + x), (source.y + y));
		Point p2 = Point((target.x + x), (target.y + y));
		CircleBrush::BrushMove(p1, p2);
	}
}

void ScatteredCircleBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}

