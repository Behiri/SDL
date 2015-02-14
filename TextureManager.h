#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>
#include <map>
using namespace std;

class TextureManager
{
public:
	bool load(string, string, SDL_Renderer*);
	void draw(string, int, int, int, int, SDL_Renderer*, SDL_RendererFlip);
	void drawFrame(string, int, int, int, int, int, int, SDL_Renderer*, SDL_RendererFlip);
	map<std::string, SDL_Texture*> m_textureMap;
};

bool TextureManager::load(string fileName, string id, SDL_Renderer* pRenderer)
{
	SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
	if (pTempSurface == 0)
	{
		cout << "failed to load surface image" << endl;
		return false;
	}
	else
	{
		SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
		SDL_FreeSurface(pTempSurface);
		if(pTexture != 0)
		{
			m_textureMap[id] = pTexture;
		}
		return false;
	}
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
  SDL_Rect srcRect;
  SDL_Rect destRect;

  srcRect.x = 0;
  srcRect.y = 0;
  srcRect.w = destRect.w = width;
  srcRect.h = destRect.h = height;
  destRect.x = x;
  destRect.y = y;

  SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, 
  &destRect, 0, 0, flip);
}


void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *pRenderer, SDL_RendererFlip flip)
{
  SDL_Rect srcRect;
  SDL_Rect destRect;
  srcRect.x = width * currentFrame;
  srcRect.y = height * (currentRow - 1);
  srcRect.w = destRect.w = width;
  srcRect.h = destRect.h = height;
  destRect.x = x;
  destRect.y = y;

  SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, 
  &destRect, 0, 0, flip);
}

