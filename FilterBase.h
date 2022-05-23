#pragma once
#include <vector>
#include <string>
#include "Item.h"

using std::vector;
using std::pair;
using std::string;

class FilterBase
{
/// <summary>
/// Base class for the filtering
/// </summary>
public:
    /// <summary>
    /// Virtual method to filter out the Items
    /// </summary>
    /// <param name="v">The array to be filtered</param>
    /// <returns>Filtered array</returns>
    virtual vector<pair<Item*, int>> filter(vector<pair<Item*, int>>& v) { return v; };
};

class FilterType : public FilterBase
{
public:
    FilterType(string type) { this->type = type; }
    /// <summary>
    /// Filters by type
    /// </summary>
    /// <param name="v">Array to be filtered</param>
    /// <returns>Filtered array</returns>
    vector<pair<Item*, int>> filter(vector<pair<Item*, int>>& v);
private:
    string type;
};

class FilterPrice : public FilterBase
{
public:
    FilterPrice(float price) { this->price = price; }
    /// <summary>
    /// Filters by price
    /// </summary>
    /// <param name="v">Array to be filtered</param>
    /// <returns>Filtered array</returns>
    vector<pair<Item*, int>> filter(vector<pair<Item*, int>>& v);
private:
    float price;
};

class FilterAnd : public FilterBase
{
public:
    /// <summary>
    /// Constructor to the FilterAnd class
    /// </summary>
    /// <param name="a">Filter paramether. Should be any filter derived by the filter class</param>
    /// <param name="b">Same as a</param>
    FilterAnd(FilterBase* a, FilterBase* b) { this->a = a; this->b = b; };
    ~FilterAnd()
    {
        delete this->a;
        delete this->b;
    }
    /// <summary>
    /// Filters by 2 filters
    /// </summary>
    /// <param name="v">Array to be filtered</param>
    /// <returns>Filtered array</returns>
    vector<pair<Item*, int>> filter(vector<pair<Item*, int>>& v);
private:
    FilterBase* a;
    FilterBase* b;
};
