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

bool TextureManager::load(const std::string& path,const std::string& id, SDL_Renderer* renderer){
    
    if(this->textures.count(id)!=0){
        throw std::invalid_argument("Texture with the given ID already exists!");
    }
    
    //Loads into serface the image from the path specified
    SDL_Surface* surface = IMG_Load(path.c_str());

    //Checks if the surface is created
    if(!surface){
        throw std::invalid_argument(SDL_GetError());
    }

    //Creates the texture from the surface
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);

    //Checks if the texture is successcfully created
    if(!texture){
        throw std::runtime_error(SDL_GetError());
    }

    //Adds the created texture in the map
    this->textures.insert(std::pair<std::string, SDL_Texture*>(id, texture));
    return true;


}

void TextureManager::draw(const std::string& id, int row, int col ,const Position2D& dstPos, int dstWidth, int dstHeight,SDL_Renderer* renderer){
    if(this->textures.count(id) == 0){
        throw std::invalid_argument("The given ID does not exist");
    }
    ConfigReader* reader = ConfigReader::getInstance();
    reader->read();
    int srcWidth = reader->getValue("cellWidth");
    int srcHeight = reader->getValue("cellHeight");

    SDL_Rect src, dst;

    src.w = srcWidth;
    src.h = srcHeight;
    src.x = col * srcWidth;
    src.y = row* srcHeight;

    dst.w = dstWidth;
    dst.h = dstHeight;
    dst.x = dstPos.getX();
    dst.y = dstPos.getY();

    if(SDL_RenderCopy(renderer,this->textures[id],&src,&dst)!=0){
        throw std::runtime_error("Error when rendering!");
    }

}