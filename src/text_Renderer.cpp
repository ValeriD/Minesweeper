#include "./include/text_renderer.hpp"

TextRenderer::TextRenderer(){}

void TextRenderer::renderText(const std::string& text, SDL_Color color, int x, int y, int width, int height){
    TTF_Font* sans = TTF_OpenFont("assets/OpenSans-Regular.ttf", 20);
    if(!sans){
        std::cout << TTF_GetError() << std::endl;
        return;
    }
    
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(sans, text.c_str(), color);
    if(!surfaceMessage){
        std::cout<<"Unable to create text surface"<<std::endl;
        return;
    }

    SDL_Texture* message = SDL_CreateTextureFromSurface(Game::getInstance()->getRenderer(),surfaceMessage);

    if(!message){
        std::cout<<"Unable to create text texture."<<std::endl;
        SDL_FreeSurface(surfaceMessage);
    }
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = width;
    dst.h = height;

    SDL_RenderCopy(Game::getInstance()->getRenderer(), message, NULL, &dst);

    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(message);
}