//
// Created by Denis Leonte on 29/04/2022.
//

#pragma once
#include <string>
#include <fstream>
#include "Shop.h"

using std::string;
using std::ifstream;
using std::ofstream;

class FileHandler {
    /// @class FileHandler
    /// Handles files, saves and loads.
public:
    FileHandler();
    /// Constructor
    /// @param [in] path Path to the handled file
    FileHandler(string path);
    /// <summary>
    /// Dumps everything onto the file as a CSV format
    /// </summary>
    /// <param name="x">Shop to be dumped</param>
    void save(Shop x);
    /// <summary>
    /// Loads everything from a CSV file
    /// </summary>
    /// <param name="x">Shop that receives the information</param>
    void load(Shop& x);

private:
    string filePath;
};
