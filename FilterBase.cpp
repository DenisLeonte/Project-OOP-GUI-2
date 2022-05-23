#include "FilterBase.h"

vector<pair<Item*, int>> FilterType::filter(vector<pair<Item*, int>>& v)
{
    vector<pair<Item*, int>> rez;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].first->getType() == this->type)
        {
            rez.push_back(v[i]);
        }
    }
    return rez;
}

vector<pair<Item*, int>> FilterPrice::filter(vector<pair<Item*, int>>& v)
{
    vector<pair<Item*, int>> rez;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].first->getPrice() >= this->price)
        {
            rez.push_back(v[i]);
        }
    }
    return rez;
}

vector<pair<Item*, int>> FilterAnd::filter(vector<pair<Item*, int>>& v)
{
    vector<pair<Item*, int>> rez1 = a->filter(v);
    vector<pair<Item*, int>> rez2 = b->filter(rez1);
    return rez2;
}
