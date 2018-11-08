/* 
Authors: Justin Trugman & Charles Bethin

Reference: https://www.geeksforgeeks.org/bresenhams-line-generation-algorithm/

*/

#include <iostream>
#include "Color.hh"
using namespace std;

class Bitmap{
private:
	uint32_t x,y;
	Color **p;

	void regLine(uint32_t x1, uint32_t x2, const Color& col){
		for (uint32_t i = x1; i <= x2; i++){
			p[i][i] = col;
		}
	}

	void bresenhamLine(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, const Color& col){
		int m_new = 2 * (y2 - y1); 
   		int slope_error_new = m_new - (x2 - x1); 

  		for (int x = x1, y = y1; x <= x2; x++) 
		{ 
			p[x][y] = col;
			slope_error_new += m_new; 
		
		
			if (slope_error_new >= 0) 
			{ 
				y++; 
				slope_error_new  -= 2 * (x2 - x1); 
			} 
		} 
	}


public:
	Bitmap(uint32_t horizontal, uint32_t vertical) : x(horizontal), y(vertical), p(new Color[x]) {
		for (uint32_t i = 0; i < y; i++){
			p[i] = new Color [y];
		}
	}

	void line(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, const Color& col){
		uint32_t dx = x2 - x1;
		uint32_t dy = y2 - y1;

		double dxdy = dy / dx;

		if(dxdy == 1){
			regLine(x1, x2, col);
		} else {
			bresenhamLine(x1, y1, x2, y2, col);
		}
	}

};




int main() {
	Bitmap b(30,20); // 30 pixels across, 20 pixels high, each pixel RGBA
	// top left pixel = (0,0)
	Color RED(255,0,0); // all red, no green, no blue (fully opaque)
	Color BLUE(0,255,0);
	Color GREEN(0,0,255);
	Color WHITE(255,255,255);
	
	
	b.line(0,0,   19,19, RED);
	b.line(0,5,   29,10, BLUE); //Bresenham algorithm
	//https://en.wikipedia.org/wiki/Bresenham's_line_algorithm

	// https://en.wikipedia.org/wiki/Xiaolin_Wu%27s_line_algorithm
	//TODO: b.line(0,100, 100,50, BLUE); //Wu algorithm
	b.horizLine(0, 20, 19, GREEN); // from x=0 to x=20 at y=19
	b.vertLine(5, 0,19, GREEN); // from y = 0 to y=19 at x = 5
	b.fillRect(10,10, 4, 3,BLACK); // x = 10, y =10 w=4, h=3
	b.drawRect(10,10, 4, 3,WHITE); // x = 10, y =10 w=4, h=3
  b.ellipse(15,0, 8, 5, RED);    // ellipse centered at (15,0) w= 8, h=5
	cout << b;
	/*
R
 R
  R
   R
    R
BBB
   BBBBB
        BBBBBB


	 */
}



	
