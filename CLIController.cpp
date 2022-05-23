#include "CLIController.h"
#include <fstream>
#include <sstream>

using std::ifstream;
using std::getline;
using std::stringstream;

CLIController::CLIController() : fileHandler("temp.csv")
{
    this->controlledShop = Shop();
}

CLIController::CLIController(const Shop& shop, string handler) : fileHandler(handler)
{
    this->controlledShop = shop;
}

string CLIController::errorHandle(int errCode)
{
    if (errCode < 0)
        return "";
    int aux;
    ifstream in("err_codes.txt");
    while (in >> aux)
    {
        string aux1;
        getline(in, aux1);
        aux1[0] = '\0';
        if (aux == errCode)
        {
            aux1 += " - error code: " + to_string(errCode);
            errCode = -1;
            return aux1;
        }
    }
    in.close();
    return "Unhandled error - please contact the developer of this app";
}

string CLIController::getAllStr()
{
    stringstream buff;
    buff << "";
    for (int i = 0; i < this->controlledShop.getSz(); i++)
    {
        string aux = this->controlledShop[i].first->toString();
        buff << aux << " - " << this->controlledShop[i].second << " left in stock\n";
    }
    return buff.str();
}

void CLIController::init()
{
    this->fileHandler.load(this->controlledShop);
}

void CLIController::cleanUp()
{
    this->fileHandler.save(this->controlledShop);
}

void CLIController::addElem(Item* x, int s)
{
    this->controlledShop.addElem(x, s);
}

void CLIController::removeElem(int id)
{
    if (this->controlledShop.getElemById(id) != nullptr)
    {
        this->controlledShop.remElem(id);
        return;
    }
    throw(8);
}

Item* CLIController::get(int id)
{
    if (this->controlledShop.getElemById(id) != nullptr)
    {
        return this->controlledShop.getElemById(id);
    }
    throw(4);
}

void CLIController::modify(pair<Item*, int> x, int id)
{
    for (int i = 0; i <= this->controlledShop.getSz(); i++)
    {
        if (this->controlledShop[i].first->getId() == id)
        {
            this->controlledShop[i] = x;
            return;
        }
    }
}

string CLIController::filterType(string type)
{
    FilterType a(type);
    vector<pair<Item*, int>> arr = this->controlledShop.getList();
    vector<pair<Item*, int>> rez = a.filter(arr);
    stringstream buff("");
    for (int i = 0; i < rez.size(); i++)
    {
        buff << rez[i].first->toString() << " - stock " << rez[i].second<<"\n";
    }
    return buff.str();
}

vector<pair<Item*, int>> CLIController::filterTypeV(string type)
{
    FilterType a(type);
    vector<pair<Item*, int>> arr = this->controlledShop.getList();
    vector<pair<Item*, int>> rez = a.filter(arr);
    return rez;
}

string CLIController::filterPrice(float price)
{
    FilterPrice a(price);
    vector<pair<Item*, int>> arr = this->controlledShop.getList();
    vector<pair<Item*, int>> rez = a.filter(arr);
    stringstream buff("");
    for (int i = 0; i < rez.size(); i++)
    {
        buff << rez[i].first->toString() << " - stock " << rez[i].second << "\n";
    }
    return buff.str();
}

vector<pair<Item*, int>> CLIController::filterPriceV(float price)
{
    FilterPrice a(price);
    vector<pair<Item*, int>> arr = this->controlledShop.getList();
    vector<pair<Item*, int>> rez = a.filter(arr);
    return rez;
}

string CLIController::filterBoth(string type, float price)
{
    FilterType* A = new FilterType(type);
    FilterPrice* B = new FilterPrice(price);
    FilterAnd a(A,B);
    vector<pair<Item*, int>> arr = this->controlledShop.getList();
    vector<pair<Item*, int>> rez = a.filter(arr);
    stringstream buff("");
    for (int i = 0; i < rez.size(); i++)
    {
        buff << rez[i].first->toString() << " - stock " << rez[i].second << "\n";
    }
    return buff.str();
}
