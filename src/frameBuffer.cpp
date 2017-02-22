#include "frameBuffer.h"
void frameBuffer::setup()
{
	_img.allocate(1024, 768, ofImageType::OF_IMAGE_COLOR_ALPHA);
	clear(ofColor::black);
}

void frameBuffer::update()
{
}

void frameBuffer::draw()
{
	/*for (int x = 0; x < 1024; x++) {
	putpixel(x, 768 / 2, ofColor::green);
	}*/
}

void frameBuffer::putpixel(const int & x, const int & y, const ofColor & color)
{
	_img.setColor(x, y, color);
	_img.update();
	_img.draw(ofPoint(0, 0, 0));
}

void frameBuffer::clear(const ofColor & color)
{
	for (int y = 0; y < 768; y++)
		for (int x = 0; x < 1024; x++)
			FASTputpixel(x, y, color);
	_img.update();
	_img.draw(ofPoint(0, 0, 0));
}



void frameBuffer::circle(int x, int y, int r)
{
	int d = 1 - r;
	int x1 = 0;
	int y1 = r;
	x = 0;
	y = 0;
	int xc = ofGetWidth() / 2;
	int yc = ofGetHeight() / 2;


	ofColor color(0, 255, 0);
	putpixel((x + x1 + xc), (y + y1 + yc), color);
	putpixel((x - x1 + xc), (y + y1 + yc), color);
	putpixel((x + x1 + xc), (y - y1 + yc), color);
	putpixel((x - x1 + xc), (y - y1 + yc), color);
	putpixel((x + y1 + xc), (y + x1 + yc), color);
	putpixel((x - y1 + xc), (y + x1 + yc), color);
	putpixel((x + y1 + xc), (y - x1 + yc), color);
	putpixel((x - y1 + xc), (y - x1 + yc), color);


	while (x1 < y1) {
		int DeltaCE = 2 * x1 + 3;
		int DeltaCSE = 2 * (x1 - y1) + 5;

		if (d <= 0) {
			d += DeltaCE;
		}
		else {
			d += DeltaCSE;
			y1--;
		}
		x1++;


		ofColor color(0, 255, 0);


		putpixel((x + x1 + xc), (y + y1 + yc), color);
		putpixel((x - x1 + xc), (y + y1 + yc), color);
		putpixel((x + x1 + xc), (y - y1 + yc), color);
		putpixel((x - x1 + xc), (y - y1 + yc), color);
		putpixel((x + y1 + xc), (y + x1 + yc), color);
		putpixel((x - y1 + xc), (y + x1 + yc), color);
		putpixel((x + y1 + xc), (y - x1 + yc), color);
		putpixel((x - y1 + xc), (y - x1 + yc), color);
	}

}

void frameBuffer::FASTputpixel(const int & x, const int & y, const ofColor & color)
{
	_img.setColor(x, y, color);
}
#include "frameBuffer.h"

