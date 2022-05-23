#pragma once
#include "Shop.h"
#include "ActionManager.h"
#include "FileHandler.h"
#include "FilterBase.h"
#include <string>
#define MAX_ERR_CODES 9

using std::string;
using std::to_string;


class CLIController
{
public:
    /// default constructor
    CLIController();
    /// alternate constructor
    /// @param [in] shop Custom controlled shop
    CLIController(const Shop& shop, string handler);
    //getters
    /// Gets the name of the shop
    /// @return A string containing the name of the shop
    string getShopName() const { return this->controlledShop.getName(); }
    // todo: error handler
    /// Handles errors and if needed prints out the errors
    /// @return A string containing a short description of the error and its code if needed, nothing otherwise
    string errorHandle(int errCode);
    Shop getShop(){return this->controlledShop;}
    /// <summary>
    /// Transforms the Items into a string form
    /// </summary>
    /// <returns>String with informations about the Items</returns>
    string getAllStr();
    /// <summary>
    /// Inits the vector and file manager
    /// </summary>
    void init();
    /// <summary>
    /// Loads everything onto a file
    /// </summary>
    void cleanUp();
    /// <summary>
    /// Adds an element and its stock to the inventory
    /// </summary>
    /// <param name="x">Element to be added</param>
    /// <param name="s">Stock of the element</param>
    void addElem(Item* x, int s);
    /// <summary>
    /// Removes an element by its ID
    /// </summary>
    /// <param name="id">ID of the element to be removed</param>
    void removeElem(int id);
    /// <summary>
    /// Filters by type
    /// </summary>
    /// <param name="type">Type to be filtered</param>
    /// <returns>String with the filtered elements</returns>
    string filterType(string type);
    /// <summary>
    /// Filters by price
    /// </summary>
    /// <param name="price">Price to be filtered</param>
    /// <returns>String with the filtered elements</returns>
    vector<pair<Item*,int>> filterTypeV(string type);
    string filterPrice(float price);
    /// <summary>
    /// Filters by price and type
    /// </summary>
    /// <param name="type">Type to be filtered</param>
    /// <param name="price">Price to be filtered</param>
    /// <returns>String with the filtered elements</returns>
    vector<pair<Item*,int>> filterPriceV(float price);
    string filterBoth(string type, float price);
    /// <summary>
    /// Gets the Item* with the given ID
    /// </summary>
    /// <param name="id">Id to be found</param>
    /// <returns>Item*</returns>
    Item* get(int id);
    /// <summary>
    /// Modifies the Item with the given ID
    /// </summary>
    /// <param name="x">Modified Item</param>
    /// <param name="id">ID of the old item</param>
    void modify(pair<Item*, int> x, int id);
    /// <summary>
    /// Undo last action
    /// </summary>
private:
    /// Controlled shop
    Shop controlledShop;
    FileHandler fileHandler; ///< The associated file handler for this app
};
