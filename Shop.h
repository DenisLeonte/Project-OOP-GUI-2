#pragma once
#include <vector>
#include <string>
#include "Item.h"

using std::vector;
using std::string;
using std::pair;
using std::make_pair;

class Shop
{
public:
    /// Default constructor
    Shop();
    /// Alternate constructor
    /// @param [in] name String containing the name of the shop
    Shop(string name);
    /// Alternate constructor
    /// @param [in] name String containing the name of the shop
    /// @param [in] vec Vector of pairs. Each pair contains a pointer to an Item (can be derived) and its stock (int). This is made for testing and initializing purposes only and will be removed
    Shop(string name, vector<pair<Item*, int> > vec);
    /// Copy constructor
    /// @param [in] other Shop to be copied from
    Shop(const Shop& other);
    /// Adds an element and its stock to the repository
    /// @param [in] c Pointer to the Item to be added
    /// @param [in] stock Stock of the Item to be added
    /// @param [out] err_c Error code. If anything happens, like the stock is negative (even if that's not really possible by design) the error code will change and the program will handle it accordingly
    void addElem(Item* c, int stock);
    /// Search for a given element and return its position in the vector
    /// @param [in] c Item to be searched for
    /// @return the index of the item if found, -1 otherwise
    int internalSearch(Item c);
    // getters
    /// Gets the name
    /// @return String containing the shop's name
    string getName() const { return this->name; }
    /// Gets the size
    /// @return Integer containing the current size of the shop
    int getSz() const { return this->sz; }
    /// Gets a pair containing an item and its stock from an index
    /// @param [in] x Index of the pair
    /// @param [out] err_c Error code if needed
    /// @return Pair of pointer of Item and int
    pair<Item*,int>& operator[](int x);
    /// = operator
    /// @param [in] other Shop to copy from
    /// @return This shop
    Shop operator=(const Shop other);
    /// <summary>
    /// Gets the entire list
    /// </summary>
    /// <returns>List with Items* and stocks</returns>
    vector<pair<Item*, int>> getList() const { return this->sell; }
    /// <summary>
    /// Gets an element with the given ID
    /// </summary>
    /// <param name="id">ID to be searched</param>
    /// <returns>Item* if found</returns>
    Item* getElemById(int id);\
    /// <summary>
    /// Removes an element with the ID
    /// </summary>
    /// <param name="id">ID to be removed</param>
    void remElem(int id);
private:
    string name; ///< Name of the shop
    int sz; ///< Size of the vector
    vector<pair<Item*, int> > sell; ///< The vector will remember both the Item type and the stock status of the Item

};

