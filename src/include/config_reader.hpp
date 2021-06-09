#pragma once
#include<map>
#include<sstream>
#include<iostream>
#include"file_rw.hpp"
/**
 * Singleton class that reads the config file in the assets
 * Loads default values if the file is not found
 */
class ConfigReader: public FileRW{
    std::map<std::string, int> configurations;

    ConfigReader();
public: 
    /**
     * Method for instantiating the ConfigReader
     */
    static ConfigReader* getInstance();
    
    /**
     * Destructor
     */
    ~ConfigReader();

    /**
     * Method for reading the configuration file
     */
    void read();
    void write();
    
    /**
     * Method for getting the value of given key
     */
    int getValue(std::string key) const;
};