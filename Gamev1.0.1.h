#include <SDL.h>
#include <iostream>
#include <string>

using namespace std;

class Game
{
public:
	Game();
	void Init(const char* title, int x, int y, int width, int hight, int flag);
	void render(int, int, int);
	void clear();
	void Image();
	SDL_Surface* m_pImage;
	SDL_Surface* gScreenSurface;
	void handleEvents();
	bool Running();
	void Texture();
private:
	SDL_Texture* m_pTexture;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRender;
	bool m_bRunning;
	SDL_Event* m_Event;

};


void Game::Init(const char* title = "behiri", int x = 100, int y = 100, int width = 640, int hight = 480, int flag = 0)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, x, y, width, hight, flag);
		cout << "window Created" << endl;
		if (m_pWindow != 0)
		{
			m_pRender = SDL_CreateRenderer(m_pWindow, -1, 0);
		}
	}
	else
	{
		cout << "error: failed to  Initializing SDL" << endl;
	}
}

void Game::render(int R, int G, int B)
{
	if (m_pWindow != 0)
	{
		SDL_SetRenderDrawColor(m_pRender,R = 0, G = 0, B = 0, 1);
		SDL_RenderClear(m_pRender);
		SDL_RenderPresent(m_pRender);
	}
	else
	{
		cout << "error: failed to create renderer" << endl;
	}
}

Game::Game()
{
	m_pWindow = 0;
	m_pRender = 0;
	m_pImage = 0;
	m_pTexture = 0;
	m_bRunning = true;
};

void Game::clear()
{
	cout << "cleaning the Game" << endl;
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRender);
	SDL_Quit();
}

void Game::Image()
{
	gScreenSurface = SDL_GetWindowSurface( m_pWindow );
	m_pImage = SDL_LoadBMP( "Behiri.bmp" );
	SDL_BlitSurface( m_pImage, NULL, gScreenSurface, NULL );
	SDL_UpdateWindowSurface( m_pWindow );
	SDL_Delay(2000);
}

void Game::handleEvents()
{
	SDL_Event Event;
	if(SDL_PollEvent(&Event))
	{
		switch (Event.type)
		{
		case SDL_QUIT:
			{
				m_bRunning = false;
				break;
			}
		default:
			break;
		}
	}

}

bool Game::Running()
{
	return m_bRunning;
}

void Game::Texture()
{
	SDL_Surface* pTempSurface = SDL_LoadBMP("rider.bmp");
	SDL_Texture* pTexture;
	pTexture = SDL_CreateTextureFromSurface(m_pRender,pTempSurface);
	SDL_FreeSurface(pTempSurface);
}
