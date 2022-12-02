#include "Snake.h"

Snake::Snake(const Location& loc) {

	segments[0].InitHead(loc);

}

void Snake::MoveBy(const Location& delta) {

	for (int i = nSegments - 1; i > 0; i--) {
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta);

}

void Snake::Grow() {
	if (nSegments < nSegmentsMax) {
		nSegments++;
	}
	segments[nSegments - 1].InitBody(cGradientIndex, cGradientDirection);


}

void Snake::Draw(Board& board) {
	for (int i = 0; i < nSegments; i++) {
		segments[i].DrawSegment(board);
	}
}

Location Snake::GetNextHeadLocation(const Location delta) const {
	Location l_temp = segments[0].GetLocation();
	l_temp.Add(delta);
	return l_temp;
}

bool Snake::ContainsLocationExceptLast(const Location& loc) const {
	for (int i = 0; i < nSegments - 1; i++) {
		Location tmp_loc;
		tmp_loc = segments[i].GetLocation();
		if (tmp_loc == loc) {
			return true;
		}
	}
	return false;
}

bool Snake::ContainsLocation(const Location& loc) const  {
	for (int i = 0; i < nSegments; i++) {
		Location tmp_loc;
		tmp_loc = segments[i].GetLocation();
		if (tmp_loc == loc) {
			return true;
		}
	}
	return false;
}

Snake::Segment::Segment() {
	InitGradient();
}

void Snake::Segment::InitHead(const Location& in_loc) {
	loc = in_loc;
	c = Snake::headColor;
}

void Snake::Segment::InitBody(int& index, int& direction) {
	//c = Snake::bodyColor;
	
	c = cGradient[index];
	//char buffer[100];
	//sprintf_s(buffer, "check it out: %i\n", cGradientIndex);
	//OutputDebugStringA(buffer);
	index += direction;
	//char buffer1[100];
	//sprintf_s(buffer1, "check it out1: %i\n", cGradientIndex);
	//OutputDebugStringA(buffer1);
	if (index <= 0 || index >= cGradientMax - 1) {
		direction = -direction;
	}
	
}

void Snake::Segment::InitGradient() {
	const int greenMin = 128;
	const int greenMax = 255;

	for (int i = 0; i < cGradientMax; i++) {
		const int greenColor = greenMin + ((greenMax - greenMin) / cGradientMax) * i;
		Color color = Colors::MakeRGB(0, greenColor, 0);
		cGradient[i] = color;
	}
}

void Snake::Segment::Follow(const Segment& next) {
	loc = next.loc;
}

void Snake::Segment::MoveBy(const Location& delta) {

	loc.Add(delta);
}

void Snake::Segment::DrawSegment(Board& board) {

	board.DrawCell(loc, c, 1);

}

const Location& Snake::Segment::GetLocation() const {
	return loc;
}
