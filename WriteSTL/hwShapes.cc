/*
	Cube
	Cylinder
	Sphere (optional)
https://en.wikipedia.org/wiki/STL_(file_format)
	
 */
#include "Shapes.hh"
#include "Design.hh"
#include "vector"

int main() {
	Design d;
	double s = 10;
	Cube c(s);

	double x, y, z = 0;
	c.translate(x,y,z);
	// rotate??
	cout << c.volume() << '\n';
	c.write("out.stl"); // how to get all my shapes into the same file
  	d.add(c);
	double r = 10, height  = 20;
	Cylinder cyl(r, height);
	cyl.translate(30, 30, 30);
	d.add(cyl);
	d.write("test.stl");
}