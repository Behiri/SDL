#include "Game.h"

int main(int argc, char* args[])
{
	Game* m_Game = 0;
	m_Game = new Game();
	m_Game->Image();
	m_Game->Init("behix");
	while(m_Game->Running())
	{
		m_Game->handleEvents();
		m_Game->render(120, 52, 86);
	}
		SDL_Delay(0);
		m_Game->clear();
	return 1;
}
