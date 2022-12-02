#pragma once

class Location {

public:
	void Add(const Location& value) {
		x += value.x;
		y += value.y;
	}

	bool operator== (const Location& rightSide) {
		return x == rightSide.x && y == rightSide.y;
	}

	int x;
	int y;

};