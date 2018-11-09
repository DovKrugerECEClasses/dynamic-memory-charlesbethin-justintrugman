#pragma once
#include <iostream>

class Color {
private:
  uint32_t rgba;
public:
	Color() {
		rgba = 0;
	}
	Color(uint8_t r, uint8_t g, uint8_t b) {
		rgba = ((r & 0xff) << 24) + ((g & 0xff) << 16) + ((b & 0xff) << 8) + (255 & 0xff);
	}
	Color(uint8_t r, uint8_t g, uint8_t b, uint8_t alpha) {
		rgba = ((r & 0xff) << 24) + ((g & 0xff) << 16) + ((b & 0xff) << 8) + (alpha & 0xff);
	}

	friend std::ostream& operator <<(std::ostream& s, const Color& color) {
		// return s << color.rgba;
		return s << (color.rgba > 0 ? 1 : 0);
	}
};
