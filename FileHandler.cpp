//
// Created by Denis Leonte on 29/04/2022.
//

#include "FileHandler.h"
#include <sstream>

using std::stringstream;
using std::getline;

FileHandler::FileHandler()
{
    this->filePath = "test.csv";
}

FileHandler::FileHandler(string path)
{
    this->filePath = path;
}

void FileHandler::save(Shop x)
{
    ofstream out(this->filePath.c_str());
    int aux_sz = x.getSz();
    for(int i = 0; i < aux_sz; i++)
    {
        out<< x[i].first->getType() << "," << x[i].first->toCSV() << "," << x[i].second << "\n";
    }
    out.close();
}

void FileHandler::load(Shop& x)
{
    ifstream in(this->filePath.c_str());
    string line;
    string type;
    while (!in.eof())
    {
        getline(in, line);
        stringstream buff(line);
        getline(buff, type, ',');
        if (type == "CPU")
        {
            int id, coreCount, stock;
            float price, frequency;
            string brand, name, aux;
            getline(buff, aux, ',');
            id = stoi(aux);
            getline(buff, name, ',');
            getline(buff, aux, ',');
            price = stof(aux);
            getline(buff, brand, ',');
            getline(buff, aux, ',');
            coreCount = stoi(aux);
            getline(buff, aux, ',');
            frequency = stof(aux);
            getline(buff, aux, ',');
            stock = stoi(aux);
            x.addElem(new CPU(id, name, price, brand, coreCount, frequency), stock);
        }
        else if (type == "GPU")
        {
            int id, VRAM, stock, frequency;
            float price;
            string brand, name, aux;
            getline(buff, aux, ',');
            id = stoi(aux);
            getline(buff, name, ',');
            getline(buff, aux, ',');
            price = stof(aux);
            getline(buff, brand, ',');
            getline(buff, aux, ',');
            frequency = stoi(aux);
            getline(buff, aux, ',');
            VRAM = stoi(aux);
            getline(buff, aux, ',');
            stock = stoi(aux);
            x.addElem(new GPU(id, name, price, brand, frequency, VRAM), stock);
        }
        else if (type == "RAM")
        {
            int id, DRAM, modules, stock, frequency;
            string name, brand, aux;
            float price;
            getline(buff, aux, ',');
            id = stoi(aux);
            getline(buff, name, ',');
            getline(buff, aux, ',');
            price = stof(aux);
            getline(buff, brand, ',');
            getline(buff, aux, ',');
            frequency = stoi(aux);
            getline(buff, aux, ',');
            DRAM = stoi(aux);
            getline(buff, aux, ',');
            modules = stoi(aux);
            getline(buff, aux, ',');
            stock = stoi(aux);
            x.addElem(new RAM(id, name, price, brand, frequency, DRAM, modules), stock);
        }
        else if (type == "PSU")
        {
            int id, wattage, stock;
            string name, brand, aux, rating;
            float price;
            getline(buff, aux, ',');
            id = stoi(aux);
            getline(buff, name, ',');
            getline(buff, aux, ',');
            price = stof(aux);
            getline(buff, brand, ',');
            getline(buff, aux, ',');
            wattage = stoi(aux);
            getline(buff, rating, ',');
            getline(buff, aux, ',');
            stock = stoi(aux);
            x.addElem(new PSU(id, name, price, brand, wattage, rating), stock);
        }
        else if (type == "Storage")
        {
            int id, storage, type, stock;
            string name, brand, aux;
            float price;
            getline(buff, aux, ',');
            id = stoi(aux);
            getline(buff, name, ',');
            getline(buff, aux, ',');
            price = stof(aux);
            getline(buff, brand, ',');
            getline(buff, aux, ',');
            storage = stoi(aux);
            getline(buff, aux, ',');
            type = stoi(aux);
            getline(buff, aux, ',');
            stock = stoi(aux);
            x.addElem(new Storage(id, name, price, brand, storage, type), stock);
        }
        else if (type == "MOBO")
        {
            int id, stock;
            string name, brand, aux, format, platform;
            float price;
            getline(buff, aux, ',');
            id = stoi(aux);
            getline(buff, name, ',');
            getline(buff, aux, ',');
            price = stof(aux);
            getline(buff, brand, ',');
            getline(buff, platform, ',');
            getline(buff, format, ',');
            getline(buff, aux, ',');
            stock = stoi(aux);
            x.addElem(new MOBO(id, name, price, brand, platform, format), stock);
        }
        else if (type == "Case")
        {
            int id, stock;
            string name, brand, aux, format;
            float price;
            getline(buff, aux, ',');
            id = stoi(aux);
            getline(buff, name, ',');
            getline(buff, aux, ',');
            price = stof(aux);
            getline(buff, brand, ',');
            getline(buff, format, ',');
            getline(buff, aux, ',');
            stock = stoi(aux);
            x.addElem(new Case(id, name, price, brand, format), stock);
        }
        else if ( line != "")
        {
            throw(7);
        }
    }


}
