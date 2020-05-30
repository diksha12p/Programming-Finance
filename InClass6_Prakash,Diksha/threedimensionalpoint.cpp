#include "threedimensionalpoint.h"

ThreeDimensionalPoint::ThreeDimensionalPoint() {
	setx(0);
	sety(0);
	setz(0);
}

ThreeDimensionalPoint::ThreeDimensionalPoint(int xin, int yin, int zin) {
	setx(xin);
	sety(yin);
	setz(zin);
}
int ThreeDimensionalPoint::getz() {
	return z;
}
void ThreeDimensionalPoint::setz(int zin) {
	//please implement this function to set z value
	z = zin;
}

void ThreeDimensionalPoint::addPoints(ThreeDimensionalPoint pointin) {
	//please implement this function to add the x,y and z values of point1 to values of the calling instance of the object
	int resultX, resultY, resultZ;
	resultX = Point::getx() + pointin.Point::getx();
	resultY = Point::gety() + pointin.Point::gety();
	resultZ = getz() + pointin.getz();

	setx(resultX);
	sety(resultY);
	setz(resultZ);
}
