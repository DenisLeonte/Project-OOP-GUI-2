#pragma once
#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::cout;

class Item
{
    /// @class Item
    /// Base class for every Item/Item
    ///
    /// Almost everything (except constructors) can be overloaded.<br> This is intentional such that more functionalities
    /// can be added during development
public:
    /// Default constructor
    Item();
    /// Alternate constructor
    /// @param [in] id ID of the Item
    /// @param [in] name Name of the Item
    /// @param [in] price Price of the Item
    Item(int id, string name, float price);
    //getters
    /// Gets the ID
    /// @return Integer containing the Item's ID
    int getId() const { return this->id; }
    /// Overloaded function to get the type of the Item
    /// @return The output can vary between "CPU", "GPU", etc etc. The default is "ITEM"
    virtual string getType() const { return "ITEM"; };
    /// Overloaded function to get the string representation of the Item
    /// @return The output can vary between object type but its always a string
    virtual string toString();
    virtual string toCSV();
    float getPrice() { return this->price; }
    string getName() { return this->name; }
    //operators
    /// Overloaded == operator
    /// @param [in] a First Item to be compared
    /// @param [in] b Second Item to be compared
    /// @return True if they are equal, false otherwise
    friend bool operator==(const Item a, const Item b);

protected:
    int id;         ///< ID of the Item
    string name;    ///< Name of the Item
    float price;    ///< Price of the Item
};

class CPU : public Item
{
    /// @class CPU
    /// Class that contains common parameters for a CPU.<br>
    /// CPU stands for Central Processing Unit.<br>
    /// Derived off the Item class.
public:
    /// Default constructor for the CPU class
    CPU();
    /// Alternate constructor for the CPU class
    /// @param [in] brand Brand of the CPU
    /// @param [in] coreCount Number of cpu cores
    /// @param [in] frequency Default frequency of the CPU
    CPU(int id,string name, float price, string brand, int coreCount, float frequency);
    /// Gets the string form of the CPU, ready for output
    /// @return String containing CPU information's
    string toString();
    string toCSV();
    /// Gets the type of the Item
    /// @return Always returns "CPU"
    string getType() const { return "CPU"; };
private:
    int coreCount;     ///< Number of cores
    float frequency;   ///< Default frequency in gHz
    string brand;      ///< Self-explanatory
};

class GPU : public Item
{
    /// @class GPU
    /// Class that contains common parameters for a GPU.<br>
    /// GPU stands for Graphical Processing Unit.<br>
    /// Derived off the Item class.<br>
public:
    /// Default constructor
    GPU();
    /// Alternate constructor
    /// @param [in] brand Brand of the GPU
    /// @param [in] frequency Frequency of the GPU
    /// @param [in] VRAM Amount of Video Ram of the GPU
    GPU(int id, string name, float price, string brand, int frequency, int VRAM);
    /// Gets the string form of the GPU, ready for output
    /// @return String containing GPU information's
    string toString();
    string toCSV();
    /// Gets the type of the Item
    /// @return Always returns "GPU"
    string getType() const { return "GPU"; };
private:
    int frequency;    ///< Frequency of the GPU expressed in Hz
    int VRAM;         ///< Amount of Video Ram of the GPU, expressed in Gb
    string brand;     ///< Self-explanatory
};

class RAM : public Item
{
    /// @class RAM
    /// Class that contains the common parameters for RAM's.<br>
    /// RAM stands for Random Access Memory.<br>
    /// Derived off the Item class.
public:
    /// Default constructor
    RAM();
    /// Alternate constructor
    /// @param [in] brand Brand of the DRAM
    /// @param [in] frequency Frequency of the DRAM
    /// @param [in] DRAM Memory of the RAM
    /// @param [in] modules Number of "sticks" the RAM comes with
    RAM(int id, string name, float price, string brand, int frequency, int DRAM, int modules);
    /// Gets the string form of the RAM, ready for output
    /// @return String containing RAM information's
    string toString();
    string toCSV();
    /// Gets the type of the Item
    /// @return Always returns "RAM"
    string getType() const { return "RAM"; };
private:
    int frequency;    ///< Default frequency of the RAM
    int DRAM;         ///< Amount of memory, expressed in Gb
    int modules;      ///< number of modules the RAM comes with
    string brand;     ///< Self-explanatory
};

class PSU : public Item
{
    /// @class PSU
    /// Class that contains common parameters for a PSU.<br>
    /// PSU stands for Power Supply Unit.<br>
    /// Derived off the Item class
public:
    /// Default constructor
    PSU();
    /// Alternate constructor
    /// @param [in] brand Brand of the PSU
    /// @param [in] wattage Maximum wattage allowed by the PSU
    /// @param [in] rating String that follows a pattern. Google it
    PSU(int id, string name, float price, string brand, int wattage, string rating);
    /// Gets the string form of the PSU, ready for output
    /// @return String containing PSU information's
    string toString();
    string toCSV();
    /// Gets the type of the Item
    /// @return Always returns "PSU"
    string getType() const { return "PSU"; };
private:
    int wattage;     ///< Max operational wattage
    string rating;   ///< Rating of the PSU. It tells the customer how efficient their PSU is.
                     ///< This does not mean that the PSU will output less watts, it means that its less efficient.
                     ///< Usually the rating is 80+ and one of the following - bronze, silver, gold, platinum, titanium.
                     ///< There exists 80+ rated PSU's but I dont recommend them. Also dont ever think about buying a PSU without at least an 80+ rating
    string brand;    ///< Self-explanatory
};

class Storage : public Item
{
    /// @class Storage
    /// Class that contains common parameters for an HDD / SSD.<br>
    /// HDD stands for Hard Disk Drive and SSD stands for Solid State Drive.<br>
    /// Derived off the Item class.
public:
    /// Constructor
    Storage();
    /// Alternate constructor
    /// @param [in] brand Brand of the Storage
    /// @param [in] size Size of the Storage
    /// @param [in] type Type of the storage
    Storage(int id, string name, float price, string brand, int size, int type);
    /// Gets the string form of the Storage, ready for output
    /// @return String containing Storage's information's
    string toString();
    string toCSV();
    /// Gets the type of the Item
    /// @return Always returns "Storage"
    string getType() const { return "Storage"; };
private:
    string brand; ///< Self-explanatory
    int size;     ///< Size of the Storage, expressed in Gb
    int type;     ///< Type of the Storage, 1 for SSD and 0 for HDD
};

class MOBO : public Item
{
    /// @class MOBO
    /// Class that contains common parameters for a MotherBoard.<br>
    /// MOBO stands for MotherBoard.<br>
    /// Derived off the Item class.
public:
    /// Constructor
    MOBO();
    /// Alternate constructor
    /// @param [in] brand Brand of the MOBO
    /// @param [in] platform Technology used by the MOBO
    /// @param [in] formFactor Size of the MOBO
    MOBO(int id, string name, float price, string brand, string platform, string formFactor);
    /// Gets the string form of the MOBO, ready for output
    /// @return String containing MOBO's information's
    string toString();
    string toCSV();
    /// Gets the type of the Item
    /// @return Always returns "MOBO"
    string getType() const { return "MOBO"; };
private:
    string brand;        ///< Self-explanatory
    string platform;     ///< It can be either Intel or AMD.
                         ///< ARM and smaller manufacturers can be found too but they are far too uncommon.
    string formFactor;   ///< Generalized size of the MOBO. Some time ago producers manufactured motherboards as big/small
                         ///< as they wanted or in other strange sizes. This led to the standardization of the motherboard size.<br>
                         ///< Common motherboard standards are : ATX, mATX, ITX, eATX etc etc.<br>
                         ///< This led to a later standardization of cases too.
};

class Case : public Item
{
    /// @class Case
    /// Class that contains common parameters for a Case.<br>
    /// Derived off the Item class
public:
    /// Constructor
    Case();
    /// Alternate constructor
    /// @param [in] brand Brand of the Case
    /// @param [in] formFactor Max size this Case can handle
    Case(int id, string name, float price, string brand, string formFactor);
    /// Gets the string form of the Case, ready for output
    /// @return String containing Case's information's
    string toString();
    string toCSV();
    /// Gets the type of the Item
    /// @return Always returns "Case"
    string getType() const { return "Case"; }
private:
    string brand;       ///< Self-explanatory
    string formFactor;  ///< Maximum size for the Case to handle. This can be expressed in the same way
                        ///< we express size for motherboards.
};
