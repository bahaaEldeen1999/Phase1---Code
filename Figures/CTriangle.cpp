#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	corner1 = P1;
	corner2 = P2;
	corner3 = P3;
}

void CTriangle::Draw(Output * pOut) 
{
	pOut->DRAWTri(corner1, corner2, corner3, FigGfxInfo, Selected);
}
bool CTriangle:: SelectArea(int x,int y)
{
	float A = area (corner1.x,corner1.y,corner2.x, corner2.y, corner3.x, corner3.y); 
  
      
   float A1 = area (x, y, corner2.x, corner2.y, corner3.x, corner3.y); 
  
   float A2 = area (corner1.x, corner1.y, x, y, corner3.x, corner3.y); 
  
      
   float A3 = area (corner1.x, corner1.x, corner2.x, corner2.y, x, y); 
    
    float test=abs(A1 + A2 + A3 - A)/(x*y);

   return (test>=0 &&test<=1); 
	

}
float CTriangle:: area(int x1, int y1, int x2, int y2, int x3, int y3) 
{ 
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0); 
} 