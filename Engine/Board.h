#pragma once

#include "Graphics.h"
#include "Location.h"


class Board {

public:
	Board(Graphics& in_gfx);
	void DrawCell(const Location& loc, Color c, int border);
	void Board::DrawBorderCell(const Location& loc, Color c);
	void DrawBorder();
	int GetWidth() const;
	int GetHeight() const;
	bool IsInsideBoard(const Location& loc) const;
private:
	


	static constexpr Color borderColor = Colors::LightGray;
	static constexpr Location origin = { 1,1 };
	
	static constexpr int dimension = 18;
	static constexpr int width = 40;
	static constexpr int height = 30;
	Graphics& gfx;

};
