#include "./include/file_rw.hpp"


FileRW::FileRW(const std::string& path ,bool isBinary)
: path(path), isBinary(isBinary)
{}

FileRW::~FileRW(){
    if(stream.is_open()){
        stream.close();
    }
}

void FileRW::open(){
    if(isBinary){
        stream.open(path, std::ios::binary | std::ios::in | std::ios::out);
    }else{
        stream.open(path);
    }

    if(!stream.is_open()){
        throw std::invalid_argument("File not opened");
    }
}

void FileRW::close(){
    stream.close();
}

std::istream& FileRW::readWithDelimiter(std::string& str, char delimiter){
    if(this->stream.is_open()){
        getline(this->stream, str, delimiter);
    }
    return this->stream;
}

void FileRW::writeWithDelimiter(const std::string& str, char delimiter){
    if(this->stream.is_open()){
        this->stream << str << delimiter;
    }
}
