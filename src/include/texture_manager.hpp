#pragma once
#include<string>
#include<map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include"config_reader.hpp"
#include "position2d.hpp"


/**
 * Singleton Texture manager
 * @param textures - map of textures with ids
 */
class TextureManager{


    std::map<std::string, SDL_Texture*> textures;

    /** 
     * Private default constructor
     */
    TextureManager();

public:
    /**
     * Destructor
     */
    ~TextureManager();

    /**
     * Method that returns static instace of the manager
     */
    static TextureManager* getInstance();


    /**
     * Deleted assign operator and copy constructor
     */
    TextureManager(const TextureManager& other) = delete;  
    TextureManager& operator=(const TextureManager& other) = delete;


    /**
     * Method that loads texture from given path
     * @param path - the path of the image
     * @param id - the id on which to be saved
     * @param renderer 
     * 
     * @throw invalid_argument if the id already exists or invalid path provided
     * @throw runtime_error if the texture creation failed
     */
    bool load(const std::string& path,const std::string& id, SDL_Renderer* renderer);


    /** 
     * Method that draws the texture with the given id to the given position on the screen
     * @param id - the ID of the texture
     * @param row - the from row where the copy of the image should be taken
     * @param col - the from col where the copy of the image should be taken
     * @param dstPos - the postion on the screen
     * @param dstWidth - the width of the destination rectangle
     * @param dstHeight - the height of the destination rectangle
     * @param renderer - the renderer
     * 
     * @throw invalid argument when invalid id passed
     * @throw runtime_error when rendering fails
     */
    void draw(const std::string& id, int row, int col ,const Position2D& dstPos, int dstWidth, int dstHeight,SDL_Renderer* renderer);
};