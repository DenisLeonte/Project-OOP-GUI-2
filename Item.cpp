#include "Item.h"
#include <sstream>
#include <iomanip>

using std::stringstream;
using std::setprecision;
using std::fixed;

Item::Item()
{
    this->id = -1;
    this->name = "";
    this->price = -1;
}

Item::Item(int id, string name, float price)
{
    this->id = id;
    this->name = name;
    this->price = price;
}

bool operator==(const Item a, const Item b)
{
    return a.id == b.id;
}

string Item::toString()
{
    stringstream buff;
    buff << this->id << " - " << this->name << ", " << fixed << setprecision(2) << this->price << "$";
    return buff.str();
}

string Item::toCSV()
{
    stringstream buff;
    buff << this->id << "," << this->name << "," << this->price;
    return buff.str();
 }

CPU::CPU() : Item()
{
    this->name = "";
    this->id = -1;
    this->price = -1;
    this->coreCount = 0;
    this->frequency = 0;
    this->brand = "";
}

CPU::CPU(int id, string name, float price, string brand, int coreCount, float frequency) : Item(id, name, price)
{
    this->brand = brand;
    this->coreCount = coreCount;
    this->frequency = frequency;
}

string CPU::toString()
{
    stringstream buff;
    buff << this->id << " - " << this->brand << " " << this->name << ", " << this->coreCount;
    buff << " cores, @" << fixed << setprecision(2) << this->frequency << " gHz, " << this->price << "$";
    return buff.str();
}

string CPU::toCSV()
{
    stringstream buff;
    buff << this->id << "," << this->name << "," << this->price << "," << this->brand << "," << this->coreCount << "," << this->frequency;
    return buff.str();
}

GPU::GPU() : Item()
{
    this->name = "";
    this->id = -1;
    this->price = -1;
    this->brand = "";
    this->frequency = -1;
    this->VRAM = -1;
}

GPU::GPU(int id, string name, float price, string brand, int frequency, int VRAM) : Item(id, name, price)
{
    this->brand = brand;
    this->frequency = frequency;
    this->VRAM = VRAM;
}

string GPU::toString()
{
    stringstream buff;
    buff << this->id << " - " << this->brand << " " << this->name << ", @";
    buff << this->frequency << "hz, with " << this->VRAM << " GB of VRAM, " << fixed << setprecision(2) << this->price << "$";
    return buff.str();
}

string GPU::toCSV()
{
    stringstream buff;
    buff << this->id << "," << this->name << "," << this->price << "," << this->brand << "," << this->frequency << "," << this->VRAM;
    return buff.str();
}

RAM::RAM() : Item()
{
    this->name = "";
    this->id = -1;
    this->price = -1;
    this->brand = "";
    this->frequency = -1;
    this->DRAM = -1;
    this->modules = -1;
}

RAM::RAM(int id, string name, float price, string brand, int frequency, int DRAM, int modules) : Item(id, name, price)
{
    this->brand = brand;
    this->frequency = frequency;
    this->DRAM = DRAM;
    this->modules = modules;
}

string RAM::toString()
{
    stringstream buff;
    buff << this->id << " - " << this->brand << " " << this->name << ", @";
    buff << this->frequency << "hz, with " << this->DRAM << " GB of DRAM, with a " << this->DRAM / this->modules << "*" << this->modules << " configuration, " << fixed << setprecision(2) << this->price << "$";
    return buff.str();
}

string RAM::toCSV()
{
    stringstream buff;
    buff << this->id << "," << this->name << "," << this->price << "," << this->brand << "," << this->frequency << "," << this->DRAM << "," << this->modules;
    return buff.str();
}

PSU::PSU() : Item()
{
    this->name = "";
    this->id = -1;
    this->price = -1;
    this->brand = "";
    this->wattage = -1;
    this->rating = "";
}

PSU::PSU(int id, string name, float price, string brand, int wattage, string rating) : Item(id, name, price)
{
    this->wattage = wattage;
    this->brand = brand;
    this->rating = rating;
}

string PSU::toString()
{
    stringstream buff;
    buff << this->id << " - " << this->brand << " " << this->name << ", ";
    buff << this->wattage << "W, rated " << this->rating << ", " << fixed << setprecision(2) << this->price << "$";
    return buff.str();
}

string PSU::toCSV()
{
    stringstream buff;
    buff << this->id << "," << this->name << "," << this->price << "," << this->brand << "," << this->wattage << "," << this->rating;
    return buff.str();
}

Storage::Storage() : Item()
{
    this->name = "";
    this->id = -1;
    this->price = -1;
    this->brand = "";
    this->size = -1;
    this->type = -1;
}

Storage::Storage(int id, string name, float price, string brand, int size, int type) : Item(id, name, price)
{
    this->brand = brand;
    this->size = size;
    this->type = type;
}

string Storage::toString()
{
    stringstream buff;
    buff << this->id << " - " << this->brand << " " << this->name<<", ";
    switch (this->type)
    {
    case 0:
        buff << "hdd ";
        break;
    case 1:
        buff << "ssd ";
        break;
    default:
        break;
    }
    buff << "of size " << this->size << ", " << fixed << setprecision(2) << this->price << "$";
    return buff.str();
}

string Storage::toCSV()
{
    stringstream buff;
    buff << this->id << "," << this->name << "," << this->price << "," << this->brand << "," << this->size << "," << this->type;
    return buff.str();
}

MOBO::MOBO() : Item()
{
    this->name = "";
    this->id = -1;
    this->price = -1;
    this->brand = "";
    this->formFactor = "";
    this->platform = "";
}

MOBO::MOBO(int id, string name, float price, string brand, string platform, string formFactor) : Item(id, name, price)
{
    this->brand = brand;
    this->formFactor = formFactor;
    this->platform = platform;
}

string MOBO::toString()
{
    stringstream buff;
    buff << this->id << " - " << this->brand << " " << this->name << ", ";
    buff << this->platform << " based motherboard, " << this->formFactor << " format, " << this->price << "$";
    return buff.str();
}

string MOBO::toCSV()
{
    stringstream buff;
    buff << this->id << "," << this->name << "," << this->price << "," << this->brand << "," << this->platform << "," << this->formFactor;
    return buff.str();
}

Case::Case() : Item()
{
    this->name = "";
    this->id = -1;
    this->price = -1;
    this->brand = "";
    this->formFactor = "";
}

Case::Case(int id, string name, float price, string brand, string formFactor) : Item(id, name, price)
{
    this->brand = brand;
    this->formFactor = formFactor;
}

string Case::toString()
{
    stringstream buff;
    buff << this->id << " - " << this->brand << " " << this->name << ", up to ";
    buff << this->formFactor << " format, " << this->price << "$";
    return buff.str();
}

string Case::toCSV()
{
    stringstream buff;
    buff << this->id << "," << this->name << "," << this->price << "," << this->brand << "," << this->formFactor;
    return buff.str();
}
