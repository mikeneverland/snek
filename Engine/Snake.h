#pragma once
#include "Board.h"

class Snake {
public:
	
private:
	class Segment {

	public:
		Segment();
		void InitHead(const Location& in_loc);
		void InitBody(int& index, int& direction);
		void InitGradient();
		void Follow(const Segment& next);
		void MoveBy(const Location& delta);
		void DrawSegment(Board& board);
		const Location& GetLocation() const;

	private:
		Location loc;
		Color c;
		
		static constexpr int cGradientMax = 5;
		Color cGradient[cGradientMax];

	};

public:
	Snake(const Location& loc);
	void MoveBy(const Location& delta);
	void Grow();
	void Draw(Board& board);

	Location GetNextHeadLocation( const Location delta) const;
	bool ContainsLocationExceptLast(const Location& loc) const ;
	bool ContainsLocation(const Location& loc) const ;


private:
	static constexpr int nSegmentsMax = 100;
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Green;
	Segment segments[nSegmentsMax];
	int cGradientIndex = 0;
	int cGradientDirection = 1;
	
	int nSegments = 1;

};