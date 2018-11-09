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
		rgba = ((r & 0xff) << 24) + ((g & 0xff) << 16) + ((b & 0xff) << 8) + 0x000000FF;
	}
	Color(uint8_t r, uint8_t g, uint8_t b, uint8_t alpha) {
		rgba = ((r & 0xff) << 24) + ((g & 0xff) << 16) + ((b & 0xff) << 8) + (alpha & 0xff);
	}

	char getColor() const {
		switch (rgba) {
			case 0xFF0000FF: return 'R';
			case 0x00FF00FF: return 'G';
			case 0x0000FFFF: return 'B';
			case 0x000000FF: return 'b';
			case 0xFFFFFFFF: return 'W';
			case 0x00000000: return '-';
			default: return 'U';
		}
	}

	friend std::ostream& operator <<(std::ostream& s, const Color& color) {
		// return s << color.rgba;
		return s << color.getColor();
	}
};
