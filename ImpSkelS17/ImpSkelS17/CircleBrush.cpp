//
// CircleBrush.cpp
//
// The implementation of Line Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include <math.h>
#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "CircleBrush.h"

extern float frand();

CircleBrush::CircleBrush(ImpressionistDoc* pDoc, char* name) :
	ImpBrush(pDoc, name)
{
}

void CircleBrush::BrushBegin(const Point source, const Point target)
{

	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();
	glPointSize((float)size);
	//printf("size %d\n", (int)size);

	BrushMove(source, target);
}

void CircleBrush::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL) {
		printf("CircleBrush::BrushMove  document is NULL\n");
		return;
	}

	double radius = pDoc->getSize()/2;
	float DEGINRAD = 3.14159 / 180;
	int num = 360;

	/*int x1 = target.x - size;

	int y1 = target.y;

	int x2 = target.x + 30;

	int y2 = target.y;*/

	SetColor(source); 

	glBegin(GL_TRIANGLE_FAN);

	for (int i = 0; i < num; i++) {
		float degInRad = i* DEGINRAD;
		glVertex2d(cos(degInRad)*radius +target.x, sin(degInRad)*radius + target.y);
	}
	

	glEnd();
}

void CircleBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}

