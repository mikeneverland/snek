/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"


Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	board(gfx),
	rng(std::random_device()()),
	snake({ 5,5 }),
	food(rng, board, snake)
{

}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel() {

	const bool isUpPressed = wnd.kbd.KeyIsPressed(VK_UP);
	const bool isDownPressed = wnd.kbd.KeyIsPressed(VK_DOWN);
	const bool isLeftPressed = wnd.kbd.KeyIsPressed(VK_LEFT);
	const bool isRightPressed = wnd.kbd.KeyIsPressed(VK_RIGHT);
	const bool isEnterPressed = wnd.kbd.KeyIsPressed(VK_RETURN);
	const bool isGrowPressed = wnd.kbd.KeyIsPressed('G');

	if (isGameStart && isEnterPressed) {
		isGameStart = false;
	}

	if (!isGameOver) {
		
		if (snakeSpeedCounter < snakeSpeed) {
			snakeSpeedCounter++;
			if (isUpPressed) {
				delta = { 0, -1 };
			}

			if (isDownPressed) {
				delta = { 0, 1 };
			}

			if (isLeftPressed) {
				delta = { -1, 0 };
			}

			if (isRightPressed) {
				delta = { 1, 0 };
			}

			if (isGrowPressed) {
				snake.Grow();
			}

		} else {
			
			snakeSpeedCounter = 0;
			
			const Location nextLocation = snake.GetNextHeadLocation(delta);
			
			//bool tmp = board.IsInsideBoard(nextLocation);
			//char buffer[100];
			//sprintf_s(buffer, "check it out: %d\n", tmp);
			//OutputDebugStringA(buffer);

			
			if (!board.IsInsideBoard(nextLocation) || snake.ContainsLocationExceptLast(nextLocation) || obs.ContainsLocation(nextLocation)) {
				isGameOver = true;
			} else {
				const bool isEating = snake.GetNextHeadLocation(delta) == food.GetLocation();

				if (isEating) {
					snake.Grow();
					food.Respawn(rng, board, snake);
					// toto je cast pre dohadzovanie prekazok
					if (obs.obstaclesSnakeIncrementCount < Obstacles::obstaclesSnakeIncrement) {
						obs.obstaclesSnakeIncrementCount++;
					} else {
						obs.obstaclesSnakeIncrementCount = 0;
						obs.Add(rng, board, snake);
					}
					// toto je kod pre zrychlovanie
					if (snakeSpeedTilesIncrementCounter < snakeSpeedTilesIncrement) {
						snakeSpeedTilesIncrementCounter++;
					} else {
						snakeSpeed -= snakeSpeedIncrement;
						if (snakeSpeed < snakeMaxSpeed) {
							snakeSpeed = snakeMaxSpeed;
						}
					}

				}
				snake.MoveBy(delta);
			}
		}
	} 
}


void Game::ComposeFrame() {
	if (isGameStart) {
		SpriteCodex::DrawTitle(0,0, gfx);
	} else {
		board.DrawBorder();
		obs.Draw(board);
		snake.Draw(board);
		food.Draw(board);
		if (isGameOver) {
			SpriteCodex::DrawGameOver(10, 10, gfx);
		}
	}
}
