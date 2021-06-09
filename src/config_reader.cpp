#include "./include/config_reader.hpp"


ConfigReader::ConfigReader()
:FileRW("./assets/config.txt")
{}

ConfigReader::~ConfigReader(){
    configurations.clear();
}

ConfigReader* ConfigReader::getInstance(){
    static ConfigReader conf;
    return &conf;
}

void ConfigReader::read(){
    try{
        this->open();
    }catch(std::exception& e){
        std::cout<<e.what()<<"\nLoading defaul values..."<<std::endl;
        configurations.insert(std::pair<std::string,int>("cellHeigth", 32));
        configurations.insert(std::pair<std::string,int>("cellWidth", 32));
    }
    
    std::string line;
    while(readWithDelimiter(line)){
        std::stringstream ss(line);
        std::string key, value;
        getline(ss, key, '=');
        getline(ss, value);

        configurations.insert(std::pair<std::string,int>(key, std::stoi(value)));
        line.clear();
        key.clear();
        value.clear();
    }

    this->close();
}

void ConfigReader::write(){
}

int ConfigReader::getValue(std::string key)const{
    return this->configurations.find(key)->second;    
}