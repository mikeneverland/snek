#include "Graphics.h"
#include "Board.h"
#include "Location.h"
#include <assert.h>


Board::Board(Graphics& in_gfx) : gfx(in_gfx) {
	OutputDebugString(L"Board class is inicialized\n");
}

void Board::DrawCell(const Location& loc, Color c, int border) {
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);
	gfx.DrawRectDim(origin.x * dimension + loc.x * dimension + border , origin.y * dimension + loc.y * dimension + border, dimension - 2 * border, dimension - 2 * border, c);
}

void Board::DrawBorderCell(const Location& loc, Color c) {
	assert(loc.x >= -1);
	assert(loc.x < width + 1);
	assert(loc.y >=  -1 );
	assert(loc.y < height + 1);	
	gfx.DrawRectDim(origin.x * dimension + loc.x * dimension, origin.y * dimension + loc.y * dimension, dimension, dimension, c);
}

void Board::DrawBorder() {
	for (int x = -1; x < + 1 + width; x++) {
		int y = -1;
		Location tmp_loc = { x,y };
		DrawBorderCell(tmp_loc, borderColor);
		y = height;
		tmp_loc = { x,y };
		DrawBorderCell(tmp_loc, borderColor);
	}
	
	for (int y = 0; y < height; y++) {
		int x = -1;
		Location tmp_loc = { x, y };
		DrawBorderCell(tmp_loc, borderColor);
		x = width;
		tmp_loc = { x, y };
		DrawBorderCell(tmp_loc, borderColor);
	}
	
}

int Board::GetWidth() const {
	return width;
}

int Board::GetHeight() const {
	return height;
}

bool Board::IsInsideBoard(const Location& loc) const {
	return loc.x >= 0  && loc.x < width && loc.y >= 0 && loc.y < height;
}
