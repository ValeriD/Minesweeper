#pragma once

#include<fstream>

/**
 * Class for file operations
 */
class FileRW{

    std::string path;
    bool isBinary;
    std::fstream stream;

public:
    /**
     * Constructor for setting up the file path and file type
     * @param path
     * @param isBinary
     */
    FileRW(const std::string& path, bool isBinary=false);
    
    /**
     * Virtual destructor
     */
    virtual ~FileRW();

    /**
     * Method for opening the file at the provided path
     * @throws invalid_argument if file not found
     */
    void open();

    /**
     * Method for closing the opened file
     */
    void close();

    /**
     * Pure virtual functions for reading and writing to the file
     */
    virtual void read() =0;
    virtual void write() = 0;

    /**
     * Function for reading from the file by the given delimiter
     * @param str
     * @param delimiter
     */
    std::istream& readWithDelimiter(std::string& str, char delimiter = '\n');

    /**
     * Function for writing to the file with given delimiter 
     * @param str
     * @param delimiter
     */
    void writeWithDelimiter(const std::string& str, char delimiter = '\n');

};