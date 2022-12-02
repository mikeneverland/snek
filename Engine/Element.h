#pragma once

#include "Obstacles.h"
#include "Location.h"
#include "Colors.h"
#include "Snake.h"
#include <random>

class Obstacles;

class Element {

public:
	Element();
	void Init(std::mt19937& rnd, const Board& board, const Snake& snake, Obstacles* obstacles);
	void Draw(Board& board) const;
	const Location& GetLocation() const;

private:
	Location loc;
	static constexpr Color c = Colors::LightGray;
};