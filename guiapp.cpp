#include "guiapp.h"
#include "qstring.h"
#include <string>

GUIApp::GUIApp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GUIApp)
{
    ui->setupUi(this);

    ui->itemComboBox->insertItem(1,"CPU",Qt::UserRole);
    ui->itemComboBox->insertItem(2,"GPU",Qt::UserRole);
    ui->itemComboBox->insertItem(3,"RAM",Qt::UserRole);
    ui->itemComboBox->insertItem(4,"PSU",Qt::UserRole);
    ui->itemComboBox->insertItem(5,"Storage",Qt::UserRole);
    ui->itemComboBox->insertItem(6,"MOBO",Qt::UserRole);
    ui->itemComboBox->insertItem(7,"Case",Qt::UserRole);
    hideInputs();
    controller = CLIController(Shop("Denis"), "test.csv");
    //try{
    //controller.init();
    //}
    //catch(int)
    //{
    //    std::cerr<<"File Empty";
    //}
}

GUIApp::~GUIApp()
{
    delete ui;
    //controller.cleanUp();
}

void GUIApp::on_refreshButton_released()
{
    hideInputs();
    int current = ui->itemComboBox->currentIndex();
    switch(current)
    {
    case 0:
        ui->CPUInput->setVisible(true);
        break;
    case -1:
        break;
    }

}

void GUIApp::hideInputs()
{
    ui->CPUInput->setVisible(false);
}

void GUIApp::on_CPUAdd_released()
{
    if(!ui->CPUID->text().isEmpty() && !ui->CPUName->text().isEmpty() && !ui->CPUBrand->text().isEmpty() && !ui->CPUPrice->text().isEmpty() && ui->CPUCore->value() > 0 && ui->CPUFrequency->value() > 0.005)
    {
        int id = (ui->CPUID->text()).toInt();
        float price = (ui->CPUPrice->text()).toFloat();
        string name = (ui->CPUName->text()).toStdString();
        string brand = (ui->CPUBrand->text()).toStdString();
        int coreCount = ui->CPUCore->value();
        float frequency = ui->CPUFrequency->value();
        try{
            controller.get(id);
            manager.addAction(new ActionModify(std::make_pair(controller.get(id),1),std::make_pair(new CPU(id,name,price,brand,coreCount,frequency),1 )));
            controller.modify(std::make_pair(new CPU(id,name,price,brand,coreCount,frequency),1 ),id);
        }
        catch(int)
        {
        controller.addElem(new CPU(id,name,price,brand,coreCount,frequency),1);
        manager.addAction(new ActionAdd(std::make_pair(new CPU(id,name,price,brand,coreCount,frequency),1)));
        }
    }
}


void GUIApp::on_SaveButton_released()
{
    controller.cleanUp();
}


void GUIApp::on_LoadButton_released()
{
    controller.init();
}


void GUIApp::on_UndoButton_released()
{
    try{
    manager.undo(&controller);
    }catch(int)
    {
        return;
    }
}

void GUIApp::on_RedoButton_released()
{
    try{
    manager.redo(&controller);
    }catch(int)
    {
        return;
    }
}


void GUIApp::on_PrintAllButton_released()
{
    ui->ItemList->clear();
    Shop aux = controller.getShop();
    for(int i = 0; i < aux.getSz(); i++)
    {

        ui->ItemList->addItem(QString::fromStdString(aux[i].first->toString()));
    }
}

void GUIApp::on_RemoveButton_released()
{
    if(ui->RemoveID->text().isEmpty())
        return;
    int id = ui->RemoveID->text().toInt();
    try{
        controller.removeElem(id);
        on_PrintAllButton_released();
    }
    catch(int)
    {
        return;
    }
}


void GUIApp::on_FilterTypeButton_released()
{
    if(ui->FilterType->text().isEmpty())
        return;
    std::string type = ui->FilterType->text().toStdString();
    vector<pair<Item*,int>> rez = controller.filterTypeV(type);
    ui->ItemList->clear();
    for(auto& it: rez)
    {
        ui->ItemList->addItem(QString::fromStdString(it.first->toString()));
    }
}


void GUIApp::on_FilterPriceButton_released()
{
    if(ui->FilterPrice->text().isEmpty())
        return;
    float price = ui->FilterPrice->text().toFloat();
    vector<pair<Item*,int>> rez = controller.filterPriceV(price);
    ui->ItemList->clear();
    for(auto& it: rez)
    {
        ui->ItemList->addItem(QString::fromStdString(it.first->toString()));
    }
}

