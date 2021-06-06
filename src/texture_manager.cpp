#include "./include/texture_manager.hpp"

TextureManager::TextureManager(){

}

TextureManager::~TextureManager(){
    //Destrys each texture in the map
    for(auto it = this->textures.begin(); it != this->textures.end(); ++it){
        SDL_DestroyTexture(it->second);
    }
}

TextureManager* TextureManager::getInstance(){
    static TextureManager textureManager;
    return &textureManager;
}

bool TextureManager::load(const std::string path, std::string id, SDL_Renderer* renderer){
    
    if(this->textures.count(id)!=0){
        throw std::invalid_argument("Texture with the given ID already exists!");
    }
    
    //Loads into serface the image from the path specified
    SDL_Surface* surface = IMG_Load(path.c_str());

    //Checks if the surface is created
    if(!surface){
        throw std::invalid_argument("Invalid path provided!");
    }

    //Creates the texture from the surface
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);

    //Checks if the texture is successcfully created
    if(!texture){
        throw std::runtime_error("Error during texture creation!");
    }

    //Adds the created texture in the map
    this->textures.insert(std::pair<std::string, SDL_Texture*>(id, texture));
    return true;


}

void TextureManager::draw(std::string& id, int row, int col ,int dstx, int dsty, int width, int height,SDL_Renderer* renderer){
    if(this->textures.count(id) == 0){
        throw std::invalid_argument("The given ID does not exist");
    }

    SDL_Rect src, dst;

    src.w = dst.w = width;
    src.h = dst.h = height;

    src.x = row * width;
    src.y = col* height;

    dst.x = dstx;
    dst.y = dsty;

    if(SDL_RenderCopy(renderer,this->textures[id],&src,&dst)!=0){
        throw std::runtime_error("Error when rendering!");
    }

}